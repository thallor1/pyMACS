import os
import numpy as np
import sample 
import monochromator
import kidney 
import macsdata
import shutil
import copy
import subprocess
import time
import glob
from scripting import import_ng0
from scripting import get_kidney_params
from scripting import get_mono_params
from joblib import Parallel,delayed 
import multiprocessing as mp
from tqdm import tqdm 
from tqdm import tnrange, tqdm_notebook

class virtualMACS(object):
	"""
	This class encompasses the virtual MACS experiment and contains various subclasses to handle 
	the various elements of its operation. The object itself mostly contains information regarding just 
	simulation parameters like neutron simulated count and directories. 

	:param exptName: A string that describes the experiment. Used to make directories for this simulation.
	:type exptName: str, required
	:param cifName: A string that denotes the filename of the .cif file assosciated with your sample. Must be in working directory.
	:type cifName: str, required
	:param useOld: Bool denoting if old instrument files should be preserved. Default False. 
	:type useOld: bool, optional
	:param n_sample: Number of neutrons to simulate at sample position. Default 1e5
	:type n_sample: (int/float) optional
	:param n_mono: (int) Number of neutrons to simulate at monochromator position. Default 1e6
	:type n_mono: (int/float) optional
	:param kidney_angle_resolution: Angular resolution of detectors in the kidney scan / A4 angle, default 1.0 degrees
	:type kidney_angle_resolution: (float) optional
	:param A3_angle: Current sample A3 rotation angle.
	:type A3_angle: float
	
	
	"""
	def __init__(self,exptName,cifName=None,useOld=False):
		""" Constructor method
		"""
		self.exptName=exptName
		if cifName is not None:
			self.sample=sample.Sample(ciffile=cifName)
		else:
			self.sample=sample.Sample()
		self.monochromator=monochromator.Monochromator()
		self.kidney=kidney.Kidney()
		#If it does not exist, make an experiment directory. 
		cwd=os.getcwd()
		if not os.path.exists(cwd+'/'+exptName):
			os.mkdir(cwd+'/'+exptName)
		self.exptdir=cwd+'/'+exptName 
		self.cwd = cwd
		self.data=macsdata.Data(self.sample,self.exptName,kidney_result_dir=self.exptdir+'/Kidney_simulations/')

		#Now some elements that are usually only needed for the simulations
		self.n_sample = 1e5
		self.n_mono = 1e6 
		self.A3_angle = 0.0
		self.kidney_angle_resolution = 1.0 #Should be set by user eventually
		self.repeat_count = 1 
		self.output_dir = self.exptdir+'/macs_kidney_scan_1'
		self.instr_template_dir =None 
		self.kidney_instr_dir=None
		self.monochromator_instr_file = 'MACS_monochromator.instr'
		self.mono_param_dir=None 
		self.kidney_param_dir=None
		self.useOld=useOld
		self.mono_scanList=[] # Will keep track of the scans that have been run. 
		self.kidney_scanList=[]
		self.instr_file_directory = cwd+'/'+self.exptName+'/Instrument_files/' 
		self.modified_kidney_flag=0 #keeps track of if the instr file must be recompiled.
		self.base_ng0 = False
		self.kidsim_dir = cwd+'/'+self.exptName+'/Kidney_simulations/'
		#Name of ramdisk directory for simulation output.
		#self.ramdisk_dir = '/tmp/memory'
		self.ramdisk_dir = '/dev/shm/memory'

		self.ramdisk_size='2G'#This can be changed by user manually if needed but it should never get larger than this. 
		self.sudo_password = 'password' #Plaintext password for sudo access to disk, this needs to be fixed later.
		self.data.kidney_sim_dir=self.ramdisk_dir+'/Kidney_simulations/'
		self.preserve_kidney_scan_files = False #Flag to determine if files are deleted from ramdisk after each scan.
		self.preserve_kidney_param_files= False #Flag to determine if individual kidney parmeter files are preserved. 
		i=2
		while os.path.exists(self.output_dir):
			self.output_dir = self.exptdir+'/macs_kidney_scan_'+str(i) #Prevents default directory from already existing
			i+=1
		
		i=0
		#Some elements specifically used in box_inel_crystal;
		self.inel_reflect_list = None
		self.inel_reflect_omega_list = None 
		self.inel_reflect_SF_list = None 
		return None

	def mount_ramdisk_old(self):
		""" Mounts a disk based in memory. Disk operations are too slow, users are not intended to access
			the ramdisk."""

		if os.path.ismount(self.ramdisk_dir):
			return 1
		else:
			if not os.path.exists(self.ramdisk_dir):
				os.system('echo \''+str(self.sudo_password)+'\' |sudo -S mkdir '+self.ramdisk_dir)
			os.system('echo \''+str(self.sudo_password)+'\' | sudo -S chmod 777 '+str(self.ramdisk_dir))
			os.system('echo \''+str(self.sudo_password)+'\' | sudo -S mount -t tmpfs -o size='+str(self.ramdisk_size)+' mcstasramdisk '+self.ramdisk_dir)
		print('RAMDISK mounted in '+self.ramdisk_dir)
		print('Ensure tmpfs is unmounted safely.')
		return 1

	def mount_ramdisk(self):
		""" Mounts a disk based in memory. Disk operations are too slow, users are not intended to access
			the ramdisk."""
		if os.path.exists(self.ramdisk_dir):
			return 1
		else:
			os.mkdir(self.ramdisk_dir)
			print(self.ramdisk_dir+' successfully mounted.')


	def clear_ramdisk(self):
		""" Unmounts the ramdisk. Should be done after simulation is over to free memory. 
		"""
		if os.path.exists(self.ramdisk_dir):
			os.system('rm -rf '+self.ramdisk_dir)
		return 1

	def unmount_ramdisk(self):
		""" Unmounts the ramdisk. Should be done after simulation is over to free memory. 
		"""
		if os.path.exists(self.ramdisk_dir):
			os.rmdir(self.ramdisk_dir)
		return 1


	def prepare_old_expt_directory(self):
		"""Prepares an experiment using previously generated and/or compiled .instr files. Used to 
		resume a simulation that was interrupted or should be appended.
		"""
		cwd=self.cwd
		if self.useOld==True:
			self.clear_ramdisk()
			self.instr_template_dir=os.path.dirname(__file__)+'/UNION MACS Models/UNION MACS Base/'
			self.kidney_instr_dir = os.path.dirname(__file__)+'/UNION MACS Models/UNION MACS Kidney Files/'
			if self.sample.sample_shape not in ['box','cylinder','powder','spot_box','spot_cylinder','box_inel_crystal']:
				print('WARNING: Only allowed sample shapes are [box, cylinder, powder, spot_box, box_inel_crystal]')
				print('Instr file not written. ')
			if self.sample.sample_shape=='cylinder':
				instr_main_file = 'MACS_sample_kidney_cylinder.instr'
				self.instr_main_file=instr_main_file
			if self.sample.sample_shape=='box':
				instr_main_file = 'MACS_sample_kidney_box.instr'
				self.instr_main_file=instr_main_file
			if self.sample.sample_shape=='spot_box':
				instr_main_file='MACS_sample_kidney_box_spot.instr'
				self.instr_main_file=instr_main_file
				#first make a copy of the template files and put them into a new experiment directory
			if self.sample.sample_shape=='box_inel_crystal':
				instr_main_file='MACS_sample_kidney_box_inel_crystal.instr'
				self.instr_main_file=instr_main_file
			self.instr_file_directory = cwd+'/'+self.exptName+'/Instrument_files/' 
			self.instr_main_file = self.instr_file_directory+self.instr_main_file #This now points directly to the instr file that will be modified

		return 1

	def clean_expt_directory(self):
		"""Removes old simulation files.
		"""
		cwd = self.cwd
		files_in_kidsims = glob.glob(cwd+'/'+self.exptName+'/Kidney_simulations/*')
		if len(files_in_kidsims)>0:
			input('WARNING: Old simulations have been found. Press enter to continue and delete files.')
		while len(files_in_kidsims)>=1:
			files_in_kidsims = glob.glob(cwd+'/'+self.exptName+'/Kidney_simulations/*')
			print(cwd+'/'+self.exptName+'/Kidney_simulations')
			os.system('rm -rf '+cwd+'/'+self.exptName+'/param_files_kidney')
			os.system('rm -rf '+cwd+'/'+self.exptName+'/Kidney_simulations')
			time.sleep(1)
		self.clear_ramdisk()
		return 1

	def prepare_expt_directory(self):
		"""Automatically prepares the McStas instrument files and output directories. Will require that instruments 
		be recompiled. Takes into consideration the various sample options allowed."""
		if self.useOld==True:
			self.prepare_old_expt_directory()
			return 1
		else:
			if type(self.sample.laufile) is not str:
				#Need to generate and assign lau file
				self.sample.cif2lau()
			self.clear_ramdisk()
			cwd=self.cwd
			self.instr_template_dir=os.path.dirname(__file__)+'/UNION MACS Models/UNION MACS Base/'
			self.kidney_instr_dir = os.path.dirname(__file__)+'/UNION MACS Models/UNION MACS Kidney Files/'
			if self.sample.sample_shape not in ['box','cylinder','powder','spot_box','spot_cylinder','box_inel_crystal']:
				print('WARNING: Only allowed sample shapes are [box, cylinder, powder, spot_box, box_inel_crystal]')
				print('Instr file not written. ')
			if self.sample.sample_shape=='cylinder':
				instr_main_file = 'MACS_sample_kidney_cylinder.instr'
				self.instr_main_file=instr_main_file
			if self.sample.sample_shape=='box':
				instr_main_file = 'MACS_sample_kidney_box.instr'
				self.instr_main_file=instr_main_file
			if self.sample.sample_shape=='spot_box':
				instr_main_file='MACS_sample_kidney_box_spot.instr'
				self.instr_main_file=instr_main_file
				#first make a copy of the template files and put them into a new experiment directory
			if self.sample.sample_shape=='box_inel_crystal':
				instr_main_file='MACS_sample_kidney_box_inel_crystal.instr'
				self.instr_main_file=instr_main_file
			while os.path.exists(cwd+'/'+self.exptName+'/Instrument_files'):
				print('WARNING: Old instrument directory found. Older files deleted, instrument will need to be recompiled.')
				os.system('rm -rf \"'+cwd+'/'+self.exptName+'\"')
				self.clean_expt_directory()
			self.instr_file_directory = cwd+'/'+self.exptName+'/Instrument_files/' 
			self.instr_main_file = self.instr_file_directory+self.instr_main_file #This now points directly to the instr file that will be modified
			#Copy the base files into the new instrument directory
			shutil.copytree(self.instr_template_dir,self.instr_file_directory)
			#Copy the particular instrument file into the instrument directory
			shutil.copy(self.kidney_instr_dir+instr_main_file,self.instr_file_directory)
			#Also need to move the lau file into the instrument directory
			shutil.copy(cwd+'/'+self.sample.laufile,self.instr_file_directory)
			shutil.copy(cwd+'/'+self.sample.ciffile,self.instr_file_directory)
			return 1

	def edit_instr_file(self):
		"""Updates the instrument file to match the current sample and instrument configuration. Will require 
		a recompilation of the instrument."""
		print('Generating sample parameters using file '+str(self.sample.ciffile))
		print('Writing instrument file assuming scattering u='+str(self.sample.orient_u)+', v='+str(self.sample.orient_v))
		#Generate the labframe for the sample 
		self.sample.project_sample_realspace()
		sampmat = np.copy(self.sample.labframe_mat)
		#This is what is in the instr file by default and must be replaced by the relevant sample params. 
		if self.sample.sample_shape=='cylinder':
			blockstr='*/ \n'+\
			  '   samp_ax = '+str(sampmat[0,0])+'; //can be calculated from lattice params and u v matrix \n'+\
			  '   samp_ay = '+str(sampmat[0,1])+'; \n'+\
			  '   samp_az = '+str(sampmat[0,2])+'; \n'+\
			  '   samp_bx = '+str(sampmat[1,0])+'; \n'+\
			  '   samp_by = '+str(sampmat[1,1])+'; \n'+\
			  '   samp_bz = '+str(sampmat[1,2])+'; \n'+\
			  '   samp_cx = '+str(sampmat[2,0])+'; \n'+\
			  '   samp_cy = '+str(sampmat[2,1])+'; \n'+\
			  '   samp_cz = '+str(sampmat[2,2])+'; \n'+\
			  '   samp_abs_xc = '+str(self.sample.rho_abs)+'; \n'+\
			  '   samp_mosaic = '+str(self.sample.sample_mosaic)+'; \n'+ \
			  '   samp_delta_d = '+str(self.sample.delta_d)+'; \n'+\
			  '   samp_inc_xc = '+str(self.sample.sigma_inc)+'; \n'+\
			  '   samp_cell_vol = '+str(self.sample.cell_vol)+'; \n'+\
			  '   samp_length = '+str(self.sample.sample_length)+'; \n'+\
			  '   crystal_axis_xrot = '+str(self.sample.crystal_axis_xrot)+'; \n'+\
			  '   crystal_axis_yrot = '+str(self.sample.crystal_axis_yrot)+' ; \n'+\
			  '   crystal_axis_zrot = '+str(self.sample.crystal_axis_zrot)+'; \n'+\
			  '/*'
		elif 'box' in self.sample.sample_shape:
			blockstr='*/ \n'+\
			  '   samp_ax = '+str(sampmat[0,0])+'; //can be calculated from lattice params and u v matrix \n'+\
			  '   samp_ay = '+str(sampmat[0,1])+'; \n'+\
			  '   samp_az = '+str(sampmat[0,2])+'; \n'+\
			  '   samp_bx = '+str(sampmat[1,0])+'; \n'+\
			  '   samp_by = '+str(sampmat[1,1])+'; \n'+\
			  '   samp_bz = '+str(sampmat[1,2])+'; \n'+\
			  '   samp_cx = '+str(sampmat[2,0])+'; \n'+\
			  '   samp_cy = '+str(sampmat[2,1])+'; \n'+\
			  '   samp_cz = '+str(sampmat[2,2])+'; \n'+\
			  '   samp_abs_xc = '+str(self.sample.rho_abs)+'; \n'+\
			  '   samp_mosaic = '+str(self.sample.sample_mosaic)+'; \n'+ \
			  '   samp_delta_d = '+str(self.sample.delta_d)+'; \n'+\
			  '   samp_inc_xc = '+str(self.sample.sigma_inc)+'; \n'+\
			  '   samp_cell_vol = '+str(self.sample.cell_vol)+'; \n'+\
			  '   samp_xwidth = '+str(self.sample.sample_widx)+'; \n'+\
			  '   samp_ywidth = '+str(self.sample.sample_widy)+'; \n'+\
			  '   samp_zwidth = '+str(self.sample.sample_widz)+'; \n'+\
			  '   crystal_axis_xrot = '+str(self.sample.crystal_axis_xrot)+'; \n'+\
			  '   crystal_axis_yrot = '+str(self.sample.crystal_axis_yrot)+' ; \n'+\
			  '   crystal_axis_zrot = '+str(self.sample.crystal_axis_zrot)+'; \n'+\
			  '/*'
		#Replace the block in the instrument file with this.
		instr_f = open(self.instr_main_file,'r')
		contents = instr_f.readlines()
		instr_f.close()
		
		for i in range(len(contents)):
			#Find the index of the string /* BEGIN INSERT BLOCK
			if 'BEGIN INSERT BLOCK' in contents[i]:
				insert_i = i+1
				
		f=open(self.instr_main_file,'w')
		contents.insert(insert_i,blockstr)
		f.writelines(contents)
		f.close()
		
		#Also need to update the following strings : REPLACETHISSTRINGWITHLAUE , replacethiswithusersamplename
		with open(self.instr_main_file) as f:
			newText = f.read().replace('REPLACETHISSTRINGWITHLAUE',self.sample.laufile)
		with open(self.instr_main_file,'w') as f:
			f.write(newText)
		with open(self.instr_main_file) as f:
			newText = f.read().replace('replacethiswithusersamplename',self.sample.laufile.split('.')[0])
		with open(self.instr_main_file,'w') as f:
			f.write(newText)
		
		with open(self.instr_main_file,'r') as f:
			filedata = f.read()
		#Insert all of the values for the single crystal process
		if self.sample.sample_shape=='cylinder':
			filedata = filedata.replace('REPLACEsamp_delta_d',str(self.sample.delta_d))
			filedata = filedata.replace('REPLACEsamp_mosaic',str(self.sample.sample_mosaic))
			filedata = filedata.replace('REPLACEsamp_ax',str(sampmat[0,0]))
			filedata = filedata.replace('REPLACEsamp_ay',str(sampmat[0,1]))
			filedata = filedata.replace('REPLACEsamp_az',str(sampmat[0,2]))
			filedata = filedata.replace('REPLACEsamp_bx',str(sampmat[1,0]))
			filedata = filedata.replace('REPLACEsamp_by',str(sampmat[1,1]))
			filedata = filedata.replace('REPLACEsamp_bz',str(sampmat[1,2]))
			filedata = filedata.replace('REPLACEsamp_cx',str(sampmat[2,0]))
			filedata = filedata.replace('REPLACEsamp_cy',str(sampmat[2,1]))
			filedata = filedata.replace('REPLACEsamp_cz',str(sampmat[2,2]))
			filedata = filedata.replace('REPLACEsamp_abs_xc',str(self.sample.rho_abs))
			filedata = filedata.replace('REPLACEsamp_inc_xc',str(self.sample.sigma_inc))
			filedata = filedata.replace('REPLACEsamp_cell_vol',str(self.sample.cell_vol))
			filedata = filedata.replace('REPLACEsample_radius',str(self.sample.sample_diameter_d/2.0))
			filedata = filedata.replace('REPLACEsamp_length',str(self.sample.sample_length))
			filedata = filedata.replace('REPLACEcrystal_axis_xrot',str(self.sample.crystal_axis_xrot))
			filedata = filedata.replace('REPLACEcrystal_axis_yrot',str(self.sample.crystal_axis_yrot))
			filedata = filedata.replace('REPLACEcrystal_axis_zrot',str(self.sample.crystal_axis_zrot))
		elif self.sample.sample_shape=='box':
			filedata = filedata.replace('REPLACEsamp_delta_d',str(self.sample.delta_d))
			filedata = filedata.replace('REPLACEsamp_mosaic',str(self.sample.sample_mosaic))
			filedata = filedata.replace('REPLACEsamp_ax',str(sampmat[0,0]))
			filedata = filedata.replace('REPLACEsamp_ay',str(sampmat[0,1]))
			filedata = filedata.replace('REPLACEsamp_az',str(sampmat[0,2]))
			filedata = filedata.replace('REPLACEsamp_bx',str(sampmat[1,0]))
			filedata = filedata.replace('REPLACEsamp_by',str(sampmat[1,1]))
			filedata = filedata.replace('REPLACEsamp_bz',str(sampmat[1,2]))
			filedata = filedata.replace('REPLACEsamp_cx',str(sampmat[2,0]))
			filedata = filedata.replace('REPLACEsamp_cy',str(sampmat[2,1]))
			filedata = filedata.replace('REPLACEsamp_cz',str(sampmat[2,2]))
			filedata = filedata.replace('REPLACEsamp_abs_xc',str(self.sample.rho_abs))
			filedata = filedata.replace('REPLACEsamp_inc_xc',str(self.sample.sigma_inc))
			filedata = filedata.replace('REPLACEsamp_cell_vol',str(self.sample.cell_vol))
			filedata = filedata.replace('REPLACEsamp_xwidth',str(self.sample.sample_widx))
			filedata = filedata.replace('REPLACEsamp_ywidth',str(self.sample.sample_widy))
			filedata = filedata.replace('REPLACEsamp_zwidth',str(self.sample.sample_widz))
			filedata = filedata.replace('REPLACEcrystal_axis_xrot',str(self.sample.crystal_axis_xrot))
			filedata = filedata.replace('REPLACEcrystal_axis_yrot',str(self.sample.crystal_axis_yrot))
			filedata = filedata.replace('REPLACEcrystal_axis_zrot',str(self.sample.crystal_axis_zrot))
		elif self.sample.sample_shape=='spot_box':
			#Prepare the sample object 
			self.prepare_spot_sample(omega=self.sample.spot_omega,spot_HKL=self.sample.spot_HKL,spot_Qmag=self.sample.spot_Qmag,\
				spot_twoTheta=self.sample.spot_twoTheta,spot_eideal=self.sample.spot_eideal)
			#Check the size of the sample. Max allowed cubic dimension is 2 cm
			if self.sample.sample_widx>=0.02:
				print('Warning: Maximium allowed sample dimension exceeded. Max dimension is 2cm, setting to 1.9 cm')
				self.sample.sample_widx=0.019
			if self.sample.sample_widy>=0.02:
				print('Warning: Maximium allowed sample dimension exceeded. Max dimension is 2cm, setting to 1 cm')
				self.sample.sample_widy=0.019
			if self.sample.sample_widz>=0.02:
				print('Warning: Maximium allowed sample dimension exceeded. Max dimension is 2cm, setting to 1 cm')
				self.sample.sample_widz=0.019			
			if self.sample.spot_omega==None:
				print('WARNING: To use spot_sample delta function energy transfer must be specified.')
				print('Check the sample.spot_omega and try again.')
				return 1
			elif (self.sample.spot_HKL==None and self.sample.spot_Qmag==None and self.sample.spot_twoTheta==None):
				print('WARNING: To use spot_sample delta function scattering angle must be specified.')
				print('Assign sample.spot_HKL, sample.spot_Qmag, or sample.spot_twoTheta and try agian.')
			filedata = filedata.replace('REPLACEsamp_delta_d',str(self.sample.delta_d))
			filedata = filedata.replace('REPLACEsamp_mosaic',str(self.sample.sample_mosaic))
			filedata = filedata.replace('REPLACEsamp_ax',str(sampmat[0,0]))
			filedata = filedata.replace('REPLACEsamp_ay',str(sampmat[0,1]))
			filedata = filedata.replace('REPLACEsamp_az',str(sampmat[0,2]))
			filedata = filedata.replace('REPLACEsamp_bx',str(sampmat[1,0]))
			filedata = filedata.replace('REPLACEsamp_by',str(sampmat[1,1]))
			filedata = filedata.replace('REPLACEsamp_bz',str(sampmat[1,2]))
			filedata = filedata.replace('REPLACEsamp_cx',str(sampmat[2,0]))
			filedata = filedata.replace('REPLACEsamp_cy',str(sampmat[2,1]))
			filedata = filedata.replace('REPLACEsamp_cz',str(sampmat[2,2]))
			filedata = filedata.replace('REPLACEsamp_abs_xc',str(self.sample.rho_abs))
			filedata = filedata.replace('REPLACEsamp_inc_xc',str(self.sample.sigma_inc))
			filedata = filedata.replace('REPLACEsamp_cell_vol',str(self.sample.cell_vol))
			filedata = filedata.replace('REPLACEsamp_xwidth',str(self.sample.sample_widx))
			filedata = filedata.replace('REPLACEsamp_ywidth',str(self.sample.sample_widy))
			filedata = filedata.replace('REPLACEsamp_zwidth',str(self.sample.sample_widz))
			filedata = filedata.replace('REPLACEcrystal_axis_xrot',str(self.sample.crystal_axis_xrot))
			filedata = filedata.replace('REPLACEcrystal_axis_yrot',str(self.sample.crystal_axis_yrot))
			filedata = filedata.replace('REPLACEcrystal_axis_zrot',str(self.sample.crystal_axis_zrot))
			filedata = filedata.replace('REPLACEspot_omega',str(self.sample.spot_omega))
			filedata = filedata.replace('REPLACEspot_twoTheta',str(self.sample.spot_twoTheta))
			filedata = filedata.replace('REPLACEspot_eideal',str(self.sample.spot_eideal))
			print('\n##############')
			print(' Spot sample successfully prepared. ')
			print('##############\n')
		elif self.sample.sample_shape=='box_inel_crystal':
			#Check if the required arrays have been specified for this calculation
			if self.sample.inel_HKL_Sq is None:
				print('Cannot prepare experiment in box_inel_crystal mode.\nSpecifiy HKL_E_Sq list using expt.sample.inel_HKL_E_Sq first.')
				return 0
			#Prepare the requisite lau file for each omega
			omega = self.sample.inel_omega
			Ei_ideal = self.kidney.Ef + omega
			launame = self.sample.gen_custom_lau(self.sample.inel_HKL_Sq,Ei_ideal,omega)
			shutil.copy(self.cwd+'/'+launame,self.instr_file_directory)


			#Check the size of the sample. Max allowed cubic dimension is 2 cm
			if self.sample.sample_widx>=0.02:
				print('Warning: Maximium allowed sample dimension exceeded. Max dimension is 2cm, setting to 1.9 cm')
				self.sample.sample_widx=0.019
			if self.sample.sample_widy>=0.02:
				print('Warning: Maximium allowed sample dimension exceeded. Max dimension is 2cm, setting to 1 cm')
				self.sample.sample_widy=0.019
			if self.sample.sample_widz>=0.02:
				print('Warning: Maximium allowed sample dimension exceeded. Max dimension is 2cm, setting to 1 cm')
				self.sample.sample_widz=0.019	
			filedata = filedata.replace('REPLACEsamp_delta_d',str(self.sample.delta_d))
			filedata = filedata.replace('REPLACEsamp_mosaic',str(self.sample.sample_mosaic))
			filedata = filedata.replace('REPLACEsamp_ax',str(sampmat[0,0]))
			filedata = filedata.replace('REPLACEsamp_ay',str(sampmat[0,1]))
			filedata = filedata.replace('REPLACEsamp_az',str(sampmat[0,2]))
			filedata = filedata.replace('REPLACEsamp_bx',str(sampmat[1,0]))
			filedata = filedata.replace('REPLACEsamp_by',str(sampmat[1,1]))
			filedata = filedata.replace('REPLACEsamp_bz',str(sampmat[1,2]))
			filedata = filedata.replace('REPLACEsamp_cx',str(sampmat[2,0]))
			filedata = filedata.replace('REPLACEsamp_cy',str(sampmat[2,1]))
			filedata = filedata.replace('REPLACEsamp_cz',str(sampmat[2,2]))
			filedata = filedata.replace('REPLACEsamp_abs_xc',str(self.sample.rho_abs))
			filedata = filedata.replace('REPLACEsamp_inc_xc',str(self.sample.sigma_inc))
			filedata = filedata.replace('REPLACEsamp_cell_vol',str(self.sample.cell_vol))
			filedata = filedata.replace('REPLACEsamp_xwidth',str(self.sample.sample_widx))
			filedata = filedata.replace('REPLACEsamp_ywidth',str(self.sample.sample_widy))
			filedata = filedata.replace('REPLACEsamp_zwidth',str(self.sample.sample_widz))
			filedata = filedata.replace('REPLACEcrystal_axis_xrot',str(self.sample.crystal_axis_xrot))
			filedata = filedata.replace('REPLACEcrystal_axis_yrot',str(self.sample.crystal_axis_yrot))
			filedata = filedata.replace('REPLACEcrystal_axis_zrot',str(self.sample.crystal_axis_zrot))
			#same as above but for the inelastic process
			inel_template = "COMPONENT REPLACEexternal_inel_sample=Single_crystal_inelastic_custom(xwidth=REPLACEsamp_xwidth,yheight=REPLACEsamp_ywidth,zdepth=REPLACEsamp_zwidth,\n  delta_d_d=REPLACE_inel_crystal_delta_d,mosaic=REPLACE_inel_crystal_mosaic,barns=1,\n  ax=REPLACE_inel_crystal_ax, ay=REPLACE_inel_crystal_ay, az = REPLACE_inel_crystal_az,\n  bx=REPLACE_inel_crystal_bx, by=REPLACE_inel_crystal_by, bz = REPLACE_inel_crystal_bz,\n  cx=REPLACE_inel_crystal_cx, cy=REPLACE_inel_crystal_cy, cz = REPLACE_inel_crystal_cz,\n  reflections=REPLACE_inel_crystal_ref_fname, omega=REPLACEsamp_omega)\nAT (0,0,0) RELATIVE target\nROTATED (0,0,0) RELATIVE crystal_axis\n\n"
			inel_sample_str = ""

			inel_sample_str = inel_template.replace('REPLACE_inel_crystal_ax',str(sampmat[0,0]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_ay',str(sampmat[0,1]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_az',str(sampmat[0,2]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_bx',str(sampmat[1,0]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_by',str(sampmat[1,1]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_bz',str(sampmat[1,2]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_cx',str(sampmat[2,0]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_cy',str(sampmat[2,1]))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_cz',str(sampmat[2,2]))
			inel_sample_str = inel_sample_str.replace('REPLACEexternal_inel_sample','external_single_crystal_sqw')			
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_ref_fname','\"'+self.sample.customlaufile+'\"')
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_mosaic',str(self.sample.sample_mosaic))
			inel_sample_str = inel_sample_str.replace('REPLACE_inel_crystal_delta_d',str(self.sample.delta_d))				
			inel_sample_str = inel_sample_str.replace('REPLACEsamp_abs_xc',str(self.sample.rho_abs))
			inel_sample_str = inel_sample_str.replace('REPLACEsamp_inc_xc',str(self.sample.sigma_inc))
			inel_sample_str = inel_sample_str.replace('REPLACEsamp_cell_vol',str(self.sample.cell_vol))
			inel_sample_str = inel_sample_str.replace('REPLACEsamp_xwidth',str(self.sample.sample_widx))
			inel_sample_str = inel_sample_str.replace('REPLACEsamp_ywidth',str(self.sample.sample_widy))
			inel_sample_str = inel_sample_str.replace('REPLACEsamp_zwidth',str(self.sample.sample_widz))
			inel_sample_str = inel_sample_str.replace('REPLACEsamp_omega',str(self.sample.inel_omega))

			filedata = filedata.replace('// INSERT EXTERNAL INEL SAMPLE STRING HERE',inel_sample_str)
			print('\n##############\n')
			print(' Inelastic Crystal sample successfully prepared. \n')
			print('##############\n')
		else:
			print('WARNING: Invalid sample shape. Allowed values are currently cylinder, box, spot_box, box_inel_crystal, and spot_cylinder.')	
		with open(self.instr_main_file,'w') as f:
			f.write(filedata)
		
		print(' ')
		print('Instrument file '+str(self.instr_main_file)+' successfully prepared.\n')
		print('Ready to compile.\n')
		print(' ')
		self.modified_kidney_flag=1
		return 1 

	def prepare_spot_sample(self,omega=None,spot_HKL=None,spot_Qmag=None,spot_twoTheta=None,spot_eideal=None):
		"""Prepares the sample for a spot calculation for spot_sample. Assigns necessary parameters to the sample before running the simulation. 
		May either specify an HKL point, Q_magnitude, or scattering angle. In the end only omega and twoTheta (degrees) matter.
		If scattering angle is specified through HKL, it is an array of form [H,K,L]

		:param omega: Energy transfer at sample in meV. 
		:type omega: float, required
		:param spot_HKL: Reflection indices HKL in reciprocal lattice units. 
		:type spot_HKL: list of shape [H,K,L], optional
		:param spot_Qmag: Magnitude of momentum transfer for spot sample in Ang^-1
		:type spot_Qmag: float, optional
		:param spot_twoTheta: Scattering angle of reflection in degrees.
		:type spot_twoTheta: float, optional
		:param spot_eideal: Incident energy expected for the spot, Ei=omega+Ef
		:type spot_eideal: float, optional
		"""
		if omega==None:
			print("Warning: To use spot_sample configuration the delta function energy transfer must be specified.")
			print('Assign sample.spot_omega=xx meV and try again.')
			return 1
		if spot_twoTheta!=None:
			self.sample.spot_twoTheta=spot_twoTheta
			return 1
		if spot_HKL!=None:
			twoTheta = self.sample.twotheta_hkl_omega(spot_HKL[0],spot_HKL[1],spot_HKL[2],Ei=self.monochromator.Ei,omega=omega)
			self.sample.spot_twoTheta=twoTheta 
			self.sample.spot_omega=omega 
			return 1
		if spot_Qmag!=None:
			twoTheta = self.sample.QE_to_twotheta(Qmag=spot_Qmag,Ei=spot_eideal,omega=omega)
			self.sample.spot_twoTheta=twoTheta
			self.sample.spot_omega=omega 
			return 1
			


	def compileInstr(self):
		"""
		Runs the instrument compiler before beginnning scan. 

		"""
		#First generate c code, need to actually go into the directories to excecute these operations
		instr_dir = self.instr_file_directory
		instr_filename = self.instr_main_file.split('/')[-1]
		c_filename = instr_filename.replace('.instr','.c')
		out_filename = instr_filename.replace('.instr','.out')
		original_directory = self.cwd
		os.chdir(instr_dir)
		shellcommand = ['mcstas','-o',c_filename,instr_filename]
		shellcommandstr ='mcstas -o '+c_filename+' '+instr_filename
		#shellcommandstr = 'mcrun -c '+instr_filename
		p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
		(output,err)=p.communicate()
		p_status=p.wait()
		#os.system(shellcommandstr)
		#Give it a moment to make sure that code is written.
		os.system('python2 generate_MACS_parts.py')
		time.sleep(0.3)
		# Something like cc -O -o MACS_sample_kidney.out MACS_sample_kidney.c -lm

		shellcommand=['cc','-O','-o',out_filename,\
			c_filename,'-lm']
		shellcommandstr='cc -O -o '+out_filename+' '+\
			c_filename+' -lm'
		#shellcommandstr='mcrun -c '+instr_filename
		print('#################')
		print('\nStarting compilation of sample kidney geometry. This will take a few minutes.\n')
		print('Passing to bash to compile sample kidney geometry:\n')
		print(shellcommandstr)
		p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
		(output,err)=p.communicate()
		p_status=p.wait()
		print('Compilation of sample kidney geometry successful.\n')
		print('#################\n')
		os.chdir(original_directory)
		self.modified_kidney_flag=0
		#Wait for this to finish. 
		return 1

	def compileMonochromator(self):
		"""Compiles monochromator McStas files.
		"""
		#First generate c code, need to actually go into the directories to excecute these operations
		instr_dir = self.instr_file_directory
		instr_filename = 'MACS_monochromator.instr'
		c_filename = instr_filename.replace('.instr','.c')
		out_filename = instr_filename.replace('.instr','.out')
		original_directory = self.cwd
		os.chdir(instr_dir)
		shellcommand = ['mcstas','-o',c_filename,instr_filename]
		shellcommandstr ='mcstas -o '+c_filename+' '+instr_filename

		os.system(shellcommandstr)
		#Give it a moment to make sure that code is written.
		time.sleep(0.5)
		# Something like cc -O -o MACS_sample_kidney.out MACS_sample_kidney.c -lm

		shellcommand=['cc','-O','-o',out_filename,\
			c_filename,'-lm']
		shellcommandstr='cc -O -o '+out_filename+' '+\
			c_filename+' -lm'
		#shellcommandstr= 'mcrun -c'+instr_filename
		print('#################')
		print('\nStarting compilation of monochromator. This will take about around 10 minutes. ')
		#shellcommandstr='mcrun -c '+instr_filename
		print('Passing the following to bash to compile monochromator:')
		print(shellcommandstr)
		p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
		(output,err)=p.communicate()
		p_status=p.wait()
		print('Compilation of monochromator geometry successful.\n')
		print('#################\n')

		os.chdir(original_directory)
		return 1


	def write_mono_paramfile_from_current_params(self):
		"""Writes the parmeter text file for monochromator simulation
		"""
		cwd=self.cwd
		try:
			if not os.path.exists(cwd+'/'+self.exptName+'/param_files_monochromator/'):
				os.mkdir(cwd+'/'+self.exptName+'/param_files_monochromator/')
		except Exception as e:
			pass
		self.mono_param_dir = self.exptdir+'/param_files_monochromator/'
		out_name = self.mono_param_dir+'mono_params_ei'+'{:.2f}'.format(self.monochromator.Ei)+'_beta1_'+'{:.3f}'.format(self.monochromator.beta_1)+'_beta2_'+'{:.3f}'.format(self.monochromator.beta_2)+'_sample_diameter_d_'+'{:.4f}'.format(self.sample.sample_diameter_d)+'.txt'

		#Correctly format the parameter file with the current parameters.

		output_str='EM='+str(self.monochromator.Ei)+'\ndEM=0.1\nEF_all='+str(self.kidney.Ef)+'\nHF=1\nVF=1\nsample_diameter_d='+str(self.sample.sample_diameter_d)+'\nbeta_1='+str(self.monochromator.beta_1)+'\nbeta_2='+str(self.monochromator.beta_2)+'\nCPF=0\nMPL=6.06\nMPD=0.775\nAPE_h=0.35\nAPE_v=0.35\nmisalign_mono_deg=0.15\nkidney_angle=0\nDIRDEV=0\nDIVSOU=3.0\nL0_delta=-1.06\nL1_delta=0.0\nmon_t=0.0\nmon_e=0.0\nmonrot_delta=0\nwrite_virtual_out=1'
		param_file = open(out_name,'w')
		param_file.write(output_str)
		param_file.close()
		return out_name


	def write_kidney_paramfile_from_current_params(self):
		"""Write the parameter text file for a kidney simulation
		"""
		orig_dir = self.cwd
		if not os.path.exists(orig_dir+'/'+self.exptName+'/param_files_kidney/'):
			os.mkdir(orig_dir+'/'+self.exptName+'/param_files_kidney/')
		self.kidney_param_dir=self.exptdir+'/param_files_kidney/'
		
		#Format the string with the most important information
		out_name_prefix = self.exptName+'_kidney_params_Ei_'+str(round(self.monochromator.Ei,2))+'_kid_angle_'+str(round(self.kidney.kidney_angle,4))+'_A3_angle_'+str(self.A3_angle)+'_Ef_'+str(round(self.kidney.Ef,2))+'.txt'
		out_name_prefix=out_name_prefix.replace('-','m')
		out_name = self.kidney_param_dir+out_name_prefix
		param_file = open(out_name,'w')
		param_file.write('A3_angle='+str(self.A3_angle)+' \n')
		param_file.write('kidney_angle='+str(self.kidney.kidney_angle)+' \n')
		param_file.write('EM='+str(self.monochromator.Ei)+' \n')
		param_file.write('EF_all='+str(self.kidney.Ef)+' \n') 
		param_file.write('HF=1 \n')
		param_file.write('VF=1 \n')
		param_file.write('sample_diameter_d='+str(self.sample.sample_diameter_d)+' \n')
		param_file.write('beta_1='+str(self.monochromator.beta_1)+' \n')
		param_file.write('beta_2='+str(self.monochromator.beta_2)+' \n')
		param_file.write('CPF=0 \n')
		param_file.write('MPL=6.06 \n')
		param_file.write('MPD=0.775 \n')
		param_file.write('APE_h=0.35 \n')
		param_file.write('APE_v=0.35 \n')
		param_file.write('misalign_mono_deg=0.15 \n')
		param_file.write('DIRDEV=0 \n')
		param_file.write('DIVSOU=3.0 \n')
		param_file.write('L0_delta=-1.06 \n')
		param_file.write('L1_delta=0.0 \n')
		param_file.write('mon_t=0.0 \n')
		param_file.write('mon_e=0.0 \n')
		param_file.write('monrot_delta=0 \n')
		param_file.write('slit_h=0.2 \n')
		param_file.write('slit_v=0.2 \n')
		param_file.write('resolution_mode=0 \n')
		param_file.write('res_radius=0.01 \n')
		param_file.write('res_height=0.03 \n')
		param_file.write('repeat_count=2 \n')
		param_file.write('E0_resolution=0 \n')
		param_file.write('dE_resolution=1 \n')
		param_file.close()
		return out_name

	def runMonoScan(self,Ei_set=False,Ef_set=False,kidney_set=False,A3_set=False,beta_1_set = False, beta_2_set =False):
		"""For a particular configuration, runs a monochromator scan. Automatically moves files to correct location afterwards.

		:param Ei_set: Ei setting for monochromator
		:type Ei_set: float, optional
		:param Ef_set: Ef setting for kidney
		:type Ef_set: float, optional 
		:param kidney_set: Kidney angle setting for kidney.
		:type kidney_set: float, optional 
		:param beta_1_set: Beta 1 angle in degrees.
		:type beta_1_set: float, optional 
		:param beta_2_set: Beta 2 angle in degrees.
		:type beta_2_set: float, optional.
		"""
		#Check if an output directory exists for monochromator scans
		cwd = self.cwd
		if not os.path.exists(self.exptdir+'/Monochromator_simulations/'):
			os.mkdir(cwd+'/'+self.exptName+'/Monochromator_simulations/')

		#Assign relevant parameters
		if Ei_set==False:
			Ei_set=self.monochromator.Ei 
		if Ef_set==False:
			Ef_set=self.kidney.Ef
		if kidney_set==False:
			kidney_set=self.kidney.kidney_angle
		if A3_set==False:
			A3_set = self.A3_angle
		if beta_1_set==False:
			beta_1_set=self.monochromator.beta_1 
		if beta_2_set==False:
			beta_2_set=self.monochromator.beta_2

		#Generate a parameter file for the current monochromator configuration
		param_fname = self.write_mono_paramfile_from_current_params()
		#Need to add the instrument directory for the imports to be recognized
		os.chdir(cwd+'/'+self.exptName+'/Instrument_files/')
		#Check if the file already exists. If it does, do not run the simulation.
		mono_file_dat_start='E'+'{:.2f}'.format(Ei_set)+'meV_HF1_VF1_Sample'+'{:.3f}'.format(self.sample.sample_diameter_d)+'_'+\
			'b1_'+'{:.2f}'.format(beta_1_set)+'_b2_'+'{:.2f}'.format(beta_2_set)+'*'
		try:
			if len(glob.glob(mono_file_dat_start))==0:
				mono_dir = 'Ei_'+str(Ei_set)+'_beta1_'+str(beta_1_set)\
				+'_beta2_'+str(beta_2_set)+'_n_'+str(self.n_mono)+'_sample_diam_'+str(self.sample.sample_diameter_d)
				#Run simulation and wait for it to end.

				shellcommandstr='mcrun -d '+mono_dir+' -n '+str(self.n_mono)+\
					' MACS_monochromator.instr EM='+str(Ei_set)+' dEM=0.1 EF_all='+str(Ef_set)+' HF=1 VF=1 sample_diameter_d='+str(self.sample.sample_diameter_d)+' beta_1='+str(beta_1_set)+\
					' beta_2='+str(beta_2_set)+' misalign_mono_deg=0.15 CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 '+\
					'kidney_angle='+str(kidney_set)+' DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 mon_e=0.0 monrot_delta=0 write_virtual_out=1'
				print('Passing the following to mcstas:')
				print(shellcommandstr)
				p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
				(output,err)=p.communicate()
				p_status=p.wait()
				#Move the output folder to the Monochromator_simulations directory
				shutil.move(mono_dir,cwd+'/'+self.exptName+'/Monochromator_simulations/')
				#Delete the old simulation.
				os.system('rm -rf '+str(mono_dir))
				time.sleep(0.1)
				os.chdir(cwd)
				#Iterate through mono_dir and add the data file outputs to the main instrument directory
				#Get the name of the monochromator data file 
				#mono_file_dat_start='E'+'{:.2f}'.format(self.monochromator.Ei)+'meV_HF1_VF1*'
				#the location of the monochromator file
				mono_dat_dir = cwd+'/'+self.exptName+'/Monochromator_simulations/'+mono_dir+'/'
				mono_file_dat_name = glob.glob(mono_dat_dir+mono_file_dat_start)[0]
				#Move the file to the instrument directory
				if not os.path.exists(self.instr_file_directory+mono_file_dat_name):
					shutil.move(mono_file_dat_name,self.instr_file_directory)
					time.sleep(1)
			else:
				#print('Using previously run monochromator simulation that is already in the directory: ')
				#print(glob.glob(mono_file_dat_start)[0])
				os.chdir(cwd)
		except Exception as e:
			print('Warning: Execution error in monochromator scan. ')
			print(e)
		return 1


	def runKidneyScan(self,append_data_matrix=True,Ei_set=False,Ef_set=False,kidney_set=False,A3_set=False,beta_1_set=False,beta_2_set=False,\
		scan_suffix=False):
		"""For current parameters, runs a kidney scan. 

		:param Ei_set: Ei setting for monochromator
		:type Ei_set: float, optional
		:param Ef_set: Ef setting for kidney
		:type Ef_set: float, optional 
		:param kidney_set: Kidney angle setting for kidney.
		:type kidney_set: float, optional 
		:param beta_1_set: Beta 1 angle in degrees.
		:type beta_1_set: float, optional 
		:param beta_2_set: Beta 2 angle in degrees.
		:type beta_2_set: float, optional.
		:param scan_suffix: Short descriptor of the current scan. Will be in output filenames.
		:type scan_suffix: string, optional
		"""
		if Ei_set==False:
			Ei_set=self.monochromator.Ei 
		if Ef_set==False:
			Ef_set=self.kidney.Ef
		if kidney_set==False:
			kidney_set=self.kidney.kidney_angle
		if A3_set==False:
			A3_set = self.A3_angle
		if beta_1_set==False:
			beta_1_set=self.monochromator.beta_1 
		if beta_2_set==False:
			beta_2_set=self.monochromator.beta_2
		self.monochromator.Ei=Ei_set
		self.kidney.Ef=Ef_set
		self.A3_angle=A3_set
		self.monochromator.beta_1=beta_1_set
		self.monochromator.beta_2=beta_2_set
		param_fname = self.write_kidney_paramfile_from_current_params()

		orig_dir = self.cwd
		#Make an output directory for the results
		if not os.path.exists(self.exptdir+'/Kidney_simulations/'):
			os.mkdir(orig_dir+'/'+self.exptName+'/Kidney_simulations/')
			self.kidsim_dir = orig_dir+'/'+self.exptName+'/Kidney_simulations/'
		param_fname = self.write_kidney_paramfile_from_current_params()
		#Change to the instrument directory 
		os.chdir(orig_dir+'/'+self.exptName+'/Instrument_files/')

		#If the scan was based off of an ng0 file need to add a string
		if self.base_ng0==False:
			ng0_string = ''
		else:
			ng0_string = '_'+self.base_ng0
		#Put this in a ramdisk to solve disk access problems large numbers of files for large simulations.
		kidney_output_dir = self.exptName+ng0_string+'_kidney_angle_'+'{:.4f}'.format(kidney_set)+'_Ei_'+\
			'{:.4f}'.format(Ei_set)+'_Ef_'+'{:.4f}'.format(Ef_set)+'_A3_angle_'+'{:.4f}'.format(A3_set)+\
			'_sample_diameter_d_'+'{:.4f}'.format(self.sample.sample_diameter_d)+'_n_'+str(self.n_sample)
		#Mcstas does not like minus signs or . in directory names
		kidney_output_dir=kidney_output_dir.replace('-','m')
		kidney_output_dir=kidney_output_dir.replace('.','p')
		#Mount the ramdisk if it has not been mounted yet. 
		if not os.path.ismount(self.ramdisk_dir):
			self.mount_ramdisk()
		kidney_output_dir=self.ramdisk_dir+'/'+kidney_output_dir
		#Check if the current simulation already exists in the data matrix.
		if type(self.data.data_matrix)==bool:
			#Not instantiated, scan definitely does not exist.
			scan_exists = False
		else:
			#Check if a row exits with the same Ei, Ef, A3, kidney_angle. That should cover the case of running the same scan.
			A3 = self.data.data_matrix['A3'].tolist()
			Ei = self.data.data_matrix['Ei'].tolist()
			Ef = self.data.data_matrix['Ef'].tolist()
			kidney = self.data.data_matrix['Kidney'].tolist()
			#Add a rounding error tolerance to each of these
			A3 = np.around(A3,3)
			Ei=np.around(Ei,3)
			Ef = np.around(Ef,3)
			kidney = np.around(kidney,3)
			#Turn these into a single numpy array where each row is a configuration
			config_mat = np.concatenate((A3[:,None],Ei[:,None],Ef[:,None],kidney[:,None]),axis=1)
			this_config = [np.around(A3_set,3),np.around(Ei_set,3),np.around(Ef_set,3),np.around(kidney_set,3)]
			if this_config in config_mat.tolist():
				scan_exists=True
			else:
				scan_exists=False

		if not scan_exists:
			#Folder does not exist, run the simulation
			#Run simulation and wait for it to end.
			shellcommandstr='mcrun -d '+kidney_output_dir+' -n '+str(self.n_sample)+' '+self.instr_main_file.split('/')[-1]+' A3_angle='+str(A3_set)+' kidney_angle='+str(kidney_set)+' EM='+str(Ei_set)+' EF_all='+str(Ef_set)+\
				' HF=1 VF=1 sample_diameter_d='+str(self.sample.sample_diameter_d)+' beta_1='+str(beta_1_set)+' beta_2='+str(beta_2_set)+' CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 '+\
				'mon_e=0.0 monrot_delta=0.0 slit_h=0.2 slit_v=0.2 resolution_mode=0 res_radius=0.01 res_height=0.03 repeat_count=1 E0_resolution=0 dE_resolution=1'
			#print('Running the following command: ')
			#print(shellcommandstr)
			p=subprocess.Popen(shellcommandstr,stdout=subprocess.PIPE,shell=True)
			(output,err)=p.communicate()
			p_status=p.wait()
			#Scan is run at this point and output files are in the kidney_output_dir
			#Append the result to the data matrix if this is a single scan. Else wait to do this until later.
			#Either way write the csv file
			if scan_suffix==False:
				suffix=''
			else:
				suffix=scan_suffix
			self.data.scan_to_csv(kidney_output_dir,file_suffix=suffix)
			time.sleep(0.01)
			#Delete the directory after this
			if self.preserve_kidney_scan_files==False:
				while os.path.exists(kidney_output_dir):
					try:
						#os.system('rm -rf \"'+str(kidney_output_dir)+'\"')
						shutil.rmtree(kidney_output_dir)
					except Exception as e:
						print('Warning: \n'+str(e))
						time.sleep(0.01)
			if self.preserve_kidney_param_files==False:
				while os.path.exists(param_fname):
					try:
						#os.system('rm \"'+param_fname+'\"')
						os.remove(param_fname)
					except Exception as e:
						print('Warning when trying to remove paramter file:')
						print(e)
			os.chdir(orig_dir)

		else:
			if self.preserve_kidney_param_files==False:
				while os.path.exists(param_fname):
					try:
						#os.system('rm '+param_fname)
						os.remove(param_fname)
					except Exception as e:
						print('Warning when trying to remove paramter file:')
						print(e)
			print('Found previous identical kidney simulation. If this is a mistake, ')
			print('delete the scan from the data matrix and try again. ')
			print(kidney_output_dir)
			os.chdir(orig_dir)
		#Delete the parameter file unless otherwise specified. 
		return 1

	def runKidneyScan_scripting(self,A3,kidney_angle,Ei,Ef,beta1,beta2,append_data_matrix=True,scan_suffix=False):
		#Run the simulation at this point 
		self.runKidneyScan(append_data_matrix=append_data_matrix,Ei_set=Ei,Ef_set=Ef,kidney_set=kidney_angle,A3_set=A3,beta_1_set = beta1, beta_2_set = beta2,scan_suffix=scan_suffix)
		return 1
	def runMonoScan_scripting(self,Ei,Ef,beta1,beta2):
		#Run the simulation at this point 
		self.runMonoScan(Ei_set=Ei,Ef_set=Ef,kidney_set=self.kidney.kidney_angle,A3_set=self.A3_angle,beta_1_set = beta1, beta_2_set = beta2)
		return 1

	def script_scan(self,A3_list,Ei_list=False,num_threads=1,scan_title=False):
		"""
		Provided with a list of A3 angles, a kidney angle resolution, optionally a list
			of incident energies, simulates a MACS scan over the full range.

		:param A3_list: List of desired A3 angles for the scan. 
		:type A3_list: list
		:param Ei_list: List of desired incident energies. Final energy is specified using virtualMACS.kidney.Ef_all = Ef.
		:type Ei_list: list
		:param num_threads: If parallelization is being used, specifies number of threads.
		:type num_threads: int
		:param scan_title: If desired, can attach a particular name to the scan. Useful when emulating ng0 files. 
		:type scan_title: str


		"""
		if scan_title==False:
			suffix=''
		else:
			suffix=scan_title
		if type(Ei_list)==bool:
			Ei_list=[self.monochromator.Ei]
		elif type(Ei_list)==float or type(Ei_list)==int:
			Ei_list=np.array([Ei_list])
		elif type(Ei_list)==list or type(Ei_list)==np.ndarray:
			#This is good they did it right
			Ei_list = np.array(Ei_list)
		else:
			print('Warning- Ei input in a strange format. Using '+str(self.monochromator.Ei)+' meV')
			Ei_list = np.array([self.monochromator.Ei])
		#Mount the ramdisk
		self.unmount_ramdisk()
		self.mount_ramdisk()
		#Run the relevant monochromator scans.
		if num_threads>1:
			print('Running these Ei values:'+str(Ei_list))
			Parallel(n_jobs=num_threads)(delayed(self.runMonoScan_scripting)(Ei,self.kidney.Ef,self.monochromator.beta_1,self.monochromator.beta_2) for Ei in Ei_list)
		else:
			for Ei in Ei_list:
				self.monochromator.Ei = Ei 
				self.runMonoScan()
		#Get total number of configurations:
		tot_configs=0
		for energy in Ei_list:
			kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution,energy)
			num_angles_E = len(kid_angle_list)*len(A3_list)
			tot_configs+=num_angles_E
		#Generate kidney angles
		if num_threads==1:
			for e_index in tnrange(len(Ei_list),desc='Total Scans'):
				energy = Ei_list[e_index]
				kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution,energy)
				#Simple case first, num_threads=1
				for k_index in tnrange(len(kid_angle_list),desc='Kidney Loop'):
					kid_angle = kid_angle_list[k_index]
					for a3_angle in A3_list:
						self.runKidneyScan_scripting(a3_angle,kid_angle,energy,self.kidney.Ef,True,suffix)

		fname_list = []
		if num_threads>1:
			#Now do the case of parallelized
			for e_index in tnrange(len(Ei_list),desc='Total Scans'):
				energy = Ei_list[e_index]
				kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution,energy)
				num_operations = len(kid_angle_list)*len(Ei_list)
				for k_index in tnrange(len(kid_angle_list),desc='Ei='+str(energy)+' meV'):
					kid_angle = kid_angle_list[k_index]
					kidsuffix = suffix+'_kidney_'+str(round(kid_angle,3))+'_Ei_'+str(round(energy,2))+'_Ef_'+str(round(self.kidney.Ef,2))
					#Parallelization happens here
					#A3,kidney_angle,Ei,Ef,beta1,beta2,append_data_matrix=True
					Parallel(n_jobs=num_threads)(delayed(self.runKidneyScan_scripting)\
							(A3_list[i],kid_angle,energy,self.kidney.Ef,self.monochromator.beta_1,self.monochromator.beta_2,True,kidsuffix) \
							for i in range(len(A3_list)))
					#After each kidney angle combine the csv like in real MACS
					filename = self.data.combine_csv_scans(preserve_old=False,flagstr=kidsuffix)
					fname_list.append(filename)
			#After all of the scans are done, write them all to MACS style ng0 files.
			for fname in fname_list:
				#Load the combination into the data matrix
				self.data.load_data_matrix_from_csv(csv_file=fname)
				#Write this to an ng0 file
				Ei = np.mean(self.data.data_matrix['Ei'].tolist())
				Ef = np.mean(self.data.data_matrix['Ef'].tolist())
				numA3 = np.size(self.data.data_matrix['A3'].tolist())
				kid = np.mean(self.data.data_matrix['Kidney'].tolist())
				fstr = 'Ei_{:.2f}_Ef{:.2f}_numA3_{:4d}_kid_{:.2f}'.format(Ei,Ef,numA3,kid)
				self.data.write_data_to_ng0(filename='McStas_'+self.exptName+'_'+fstr+'.ng0')
			#Now create a combined version of all of the csv files.
			totfname=self.data.combine_csv_scans(preserve_old=True,flagstr=suffix)
			#Load this file.
			self.data.load_data_matrix_from_csv(totfname)
		#Unmount the ramdisk safely.
		if self.preserve_kidney_scan_files==False:
				self.unmount_ramdisk()
		#Return to main directory.
		os.chdir(self.cwd)
		return 1

	def script_powder_scan(self,Ei_list=False,num_threads=1,scan_title=False):
		"""
		Provided with a list of A3 angles, a kidney angle resolution, optionally a list
			of incident energies, simulates a MACS scan over the full range.
			Num-threads parameter is for parallelization.
			Simply just calls script_scan but fixes A3 to 0

		:param Ei_list: List of incident energies to run.
		:type Ei_list: list
		:param num_threads: If parallelization is being used, number of threads to use. 
		:type num_threds: int
		:param scan_title: Name assosciated with this particular scan. 
		:type scan_title: str
		"""
		A3_list = np.array([0.0])
		self.script_scan(A3_list,Ei_list=False,num_threads=num_threads,scan_title=scan_title)
		return 1


	def simulate_ng0(self,ng0_file,in_scan=False,n_threads=1):
		"""
		Provided an ng0 file or the path to an ng0 file, emulates a scan identically with the following parameters:\n
			A3, Ei, Ef, beta1, beta1, kidney_angle, PTAI\n
			Saves the result to its own ng0 file if not part of a larger scan. The result should match the input ng0 file 
			point by point when viewed using MSlice or the built in tools.

		:param ng0_file: Input file or path to file. Must be a MACS ng0 file. 
		:type ng0_file: str
		:param num_threads: If parallelization is being used, number of threads to use. 
		:type num_threds: int
		"""

		#Mount the ramdisk
		self.mount_ramdisk()
		#Directly simulates an input ng0 file from start to finish.
		data, column_names, file_params = import_ng0(ng0_file)
		print('Emulating scan from '+str(ng0_file.split('/')[-1]))
		A3_list = np.array(data[:,file_params['Columns'].index('A3')]).astype(float)
		Ei_list = np.array(data[:,file_params['Columns'].index('Ei')]).astype(float)
		Ef_list = np.array(data[:,file_params['Columns'].index('Ef')]).astype(float)
		beta_1_list = np.array(data[:,file_params['Columns'].index('Beta1')]).astype(float)
		beta_2_list = np.array(data[:,file_params['Columns'].index('Beta2')]).astype(float)
		kid_list = np.array(data[:,file_params['Columns'].index('Kidney')]).astype(float)
		ptai_det = np.array(data[:,file_params['Columns'].index('PTAI')]).astype(int)
		self.data.PTAI_det=ptai_det[0]
		self.beta_1=beta_1_list[0]
		self.beta_2=beta_2_list[0]
		#Check if the file is in a directory 
		ng0_file = ng0_file.split('/')[-1]
		self.base_ng0=ng0_file
		#First run the monochromator jobs
		if n_threads==1 or in_scan==True:
			for i in range(len(A3_list)):
				self.runMonoScan_scripting(Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i])
			#The run the kidney / A3 jobs
			for i in range(len(A3_list)):
				self.runKidneyScan_scripting(A3_list[i],kid_list[i],Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i],append_data_matrix=True,\
					scan_suffix='_'+ng0_file.split('/')[-1])
		if n_threads>1 and in_scan==False:
			#Parallelize this process, not necessary for monochromator
			for i in range(len(A3_list)):
				self.runMonoScan_scripting(Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i])
			Parallel(n_jobs=n_threads)(delayed(self.runKidneyScan_scripting)\
							(A3_list[i],kid_list[i],Ei_list[i],Ef_list[i],beta_1_list[i],beta_2_list[i],True,\
								'_'+ng0_file.split('/')[-1]) for i in range(len(A3_list)))
		#Safely unmount ramdisk.
		if in_scan==False and self.preserve_kidney_scan_files==False:
			self.unmount_ramdisk()
		else:
			#Instead just delete the files in the ramdisk so as to not interrupt other scans.
			x=1
		#Combine the relevant data matrices into a single file
		self.data.combine_csv_scans(preserve_old=False,flagstr='_'+ng0_file.split('/')[-1])
		if in_scan==False:
			#Not parellelized, may write this data matrix to a matching ng0 file.
			csv_file = '_'+ng0_file.split('/')[-1]+\
					self.data.csv_name
			self.data.load_data_matrix_from_csv(csv_file)
			self.data.write_data_to_ng0(filename=ng0_file.split('/')[-1].replace('.ng0','_mcStas.ng0'))
		return 1

	def simulate_ng0dir(self,ng0_dir,n_threads=1):
		"""
		Provided a director of only ng0 files, emulates all scans identically with the following parameters:\n
			A3, Ei, Ef, beta1, beta1, kidney_angle, PTAI\n
			Saves the result to its own ng0 file if not part of a larger scan. The result should match the input ng0 file 
			point by point when viewed using MSlice or the built in tools.

		:param ng0_dir: List of input files or path to files. Must be MACS ng0 files. 
		:type ng0_file: list of strs
		:param num_threads: If parallelization is being used, number of threads to use. 
		:type num_threds: int
		"""
		#First mount ramdisk
		self.mount_ramdisk()

		#They may also be in folders, but nothing else should be in this folder.
		file_list = []
		cwd=os.getcwd()
		for (dirpath,dirnames,filenames) in os.walk(ng0_dir):
			for file in filenames:
				if '.ng0' in file:
					file_list.append(file)
		if n_threads==1:
			for file in file_list:
				self.simulate_ng0(file,in_scan=False)
		else:
			#Need to do monochromator jobs FIRST, then kidney
			ei_ef_b1_b2_list = []
			for f_index in tnrange(len(file_list),desc='Ng0 Files'):
				ng0_file = file_list[f_index]
				#Need to do monochromator jobs FIRST, then kidney
				#Accumulate all Ei, beta1, beta2 combinations and run.
				data, column_names, file_params = import_ng0(ng0_dir+ng0_file)
				A3_list = np.array(data[:,file_params['Columns'].index('A3')]).astype(float)
				Ei_list = np.array(data[:,file_params['Columns'].index('Ei')]).astype(float)
				Ef_list = np.array(data[:,file_params['Columns'].index('Ef')]).astype(float)
				beta_1_list = np.array(data[:,file_params['Columns'].index('Beta1')]).astype(float)
				beta_2_list = np.array(data[:,file_params['Columns'].index('Beta2')]).astype(float)
				kid_list = np.array(data[:,file_params['Columns'].index('Kidney')]).astype(float)
				ptai_det = np.array(data[:,file_params['Columns'].index('PTAI')]).astype(int)
				for i in range(len(Ei_list)):
					Ei = Ei_list[i]
					Ef = Ef_list[i]
					b1 = beta_1_list[i]
					b2 = beta_2_list[i]
					setting = [Ei,Ef,b1,b2]
					if setting not in ei_ef_b1_b2_list:
						ei_ef_b1_b2_list.append(setting)
			print('Monochromator List to simulate:')
			print('Ei, beta1, beta2 ='+str(ei_ef_b1_b2_list))
			#Run all of the relevant monochromator jobs
			Parallel(n_jobs=n_threads)(delayed(self.runMonoScan_scripting)(ei_ef_b1_b2_list[i][0],ei_ef_b1_b2_list[i][1],ei_ef_b1_b2_list[i][2],\
				ei_ef_b1_b2_list[i][3]) for i in range(len(ei_ef_b1_b2_list)))
			Parallel(n_jobs=n_threads)(delayed(self.simulate_ng0)(cwd+'/'+ng0_dir+file_list[i],in_scan=True) for i in range(len(file_list)))
			#After parellel jobs are done, iterate through the files and create matching ng0s as the measurements, but McStas

			for ng0_file in file_list:
				csv_file = '_'+ng0_file.split('/')[-1]+\
						self.data.csv_name
				self.data.load_data_matrix_from_csv(csv_file)
				self.data.write_data_to_ng0(filename=ng0_file.split('/')[-1].replace('.ng0','_mcStas.ng0'))
		#At this point generate the data matrix. all files should be in the ramdisk. Information cannot be allowed to sit in the ramdisk.
		return 1

	def calc_resfunc(self,hkl_sq_list,omega,A3_step=0.5,num_Ei=9,n_threads=1,use_res_sample=False,scan_title='',Ei_settings=False,A3_settings=False):
		"""
		Calculaetes full Q/E resolution ellipsoids around 
		specified poidfnts in Q/E space given the frame of reference of the sample. Supports 
		only a single energy transfer. It is up to the user to determine if they are far enough apart to be well seperated. 
		The same HKL points will be used for all energy transfers. 

		May also use the provided resolution_sample to calculate arbitrary resolution ellipsoids.
		Warning: There is a bug in the McStas component that powers the inelastic_cystal sample type where allowing the full 360 degree rotation 
		creates a 'ghost' reflection. This can be avoided by restricting the A3 range to be no larger than 180 degrees. 

		:param hkl_sq_list: Numpy matrix where each row represents a reflection. Each column represents the following:
			H,K,L, Multiplicity (usually 1) and Structure factor squared. 
		:type hkl_sq_list: Nx5 np.ndarray
		:param A3_step : step size of virtual A3 angle in degrees. 
		:type A3_step: float, default 0.5 deg
		:param omega_list: List of energy transfers for resolution ellipsoids in meV. Take care to make sure that they are well separated. 
		:type omega_list: np.ndarray of length N
		:param Energy_step: Step size for energy transfer calculation. Default 0.1 meV, but all energy transfer points will be calculated by default
			from the elastic line to the maximum resolution ellipsoid + 1 meV. Max Ei allowed for MACS is 17 meV.
		:type Energy_step: float, default 0.1 meV
		:param n_threads: Number of threads to parallelize A3 scan with. Default 1.
		:type n_threads: int
		:param use_res_sample: Specifies if the special resolution_sample should be used or not. Not currently operational.
		:type use_res_sample: bool, default False
		:param Ei_settings: Allows user to manually specify the Ei settings if desired. Ef is fixed.  
		:type Ei_settings: List, np.ndarray or bool, default False
		:param A3_settings: Allows user to manually specify A3 rotations of virtual sample. Default is -90 to 90 with step size of 0.5 deg. 
			Max allowed A3 range is 180 degrees- any input with a larger range will throw an error. 
		:type A3_settings: List/np.ndarray or bool, default is False.
		"""
		if use_res_sample==True:
			#change the cif file to the false one
			cifName = 'resolution_crystal.cif'
			self.sample=sample.Sample(ciffile=cifName)
			self.sample.sample_shape='box_inel_crystal'
			self.sample.orient_u = np.array([1,0,0])
			self.sample.orient_v = np.array([0,0,1])
		else:
			self.sample.sample_shape='box_inel_crystal'
		self.sample.inel_HKL_Sq = hkl_sq_list
		self.sample.inel_omega = omega
		self.sample.sample_widx=5e-3
		self.sample.sample_widz=5e-3
		self.sample.sample_widy=5e-3

		#Regardless, do all of the below.
		self.sample.project_sample_realspace()
		#Prepare the requisite lau file 
		self.sample.cif2lau()
		Ei_ideal = self.kidney.Ef+omega
		launame = self.sample.customlaufile

		#Now prepare calculation over all A3 angles. 
		if type(A3_settings) is bool:
			A3_list = np.arange(-90,90,A3_step)
		else:
			if np.abs(np.min(A3_list)-np.max(A3_list))>180.0:
				print('WARNING: This function does not support A3 ranges larger than 180 degrees due to a bug. Please change the A3 specification.')
				return 0 
			A3_list=A3_settings

		#Need to recompile the instrument
		if self.useOld==False:
			self.data.data_matrix=False
		self.prepare_expt_directory()
		self.edit_instr_file()
		self.compileInstr()
		self.compileMonochromator()
		#Sample + instrument are prepared. Predict FWHM from MACS website observations:
		excitation_Ei = self.kidney.Ef + omega
		if type(Ei_settings) is not bool:
			Ei_list = Ei_settings
		else:
			fwhm_approx = 0.1*excitation_Ei-0.16 #See https://www.ncnr.nist.gov/instruments/macs/EivsFWHM_res.jpg
			if fwhm_approx<0.01:
				fwhm_approx=0.05 #User has set the Ef to be too low, throw a warning:
				print('WARNING: Ef setting of '+str(self.kidney.Ef)+' meV is too low to be reasonable. Check your \n \
					parameters. Results probably not meaningful')
			omega_max = omega+2.0*fwhm_approx
			omega_min = omega-2.0*fwhm_approx
			omega_step = np.abs(omega_max-omega_min)/num_Ei 

			omega_list = [omega_min+i*omega_step for i in range(num_Ei)]
			if omega not in omega_list:
				omega_list.append(omega)
			omega_list=np.array(omega_list)
			omega_list=np.sort(omega_list)
			Ei_list = omega_list + self.kidney.Ef

		#Now simply call the script_scan method. 
		self.script_scan(A3_list=A3_list,Ei_list=Ei_list,scan_title=scan_title,num_threads=n_threads)
		return 1

	def calc_resfunc_multiomega(self,hkl_sq_list,omega_list,A3_step=0.5,Energy_step=0.1,n_threads=1,use_res_sample=False,Ei_settings=False,A3_settings=False):
		"""
		Calculaetes full Q/E resolution ellipsoids around 
		specified poidfnts in Q/E space given the frame of reference of the sample. Unlike calc_resfunc, supports 
		multiple energy transfers. It is up to the user to determine if they are far enough apart to be well seperated. 
		The same HKL points will be used for all energy transfers. 

		May also use the provided resolution_sample to calculate arbitrary resolution ellipsoids

		:param hkl_sq_list: Numpy matrix where each row represents a reflection. Each column represents the following:
			H,K,L, Multiplicity (usually 1) and Structure factor squared. 
		:type hkl_sq_list: Nx5 np.ndarray
		:param A3_step : step size of virtual A3 angle in degrees. 
		:type A3_step: float, default 0.5 deg
		:param omega_list: List of energy transfers for resolution ellipsoids in meV. Take care to make sure that they are well separated. 
		:type omega_list: np.ndarray of length N
		:param Energy_step: Step size for energy transfer calculation. Default 0.1 meV, but all energy transfer points will be calculated by default
			from the elastic line to the maximum resolution ellipsoid + 1 meV. Max Ei allowed for MACS is 17 meV.
		:type Energy_step: float, default 0.1 meV
		:param n_threads: Number of threads to parallelize A3 scan with. Default 1.
		:type n_threads: int
		:param use_res_sample: Specifies if the special resolution_sample should be used or not. Not currently operational.
		:type use_res_sample: bool, default False
		:param Ei_settings: Allows user to manually specify the Ei settings if desired. Ef is fixed.  
		:type Ei_settings: List, np.ndarray or bool, default False
		:param A3_settings: Allows user to manually specify A3 rotations of virtual sample. Default is -180 to 180 with step size of 0.5 deg. 
		:type A3_settings: List/np.ndarray or bool, default is False.
		"""
		#First need to determine Ei's that will be run.
		if (type(Ei_settings) is list) or (type(Ei_settings) is np.ndarray):
			#Ei's have been specified, easy case. 
			Ei_list = Ei_settings
		else:
			#Run from Ef to max omega 
			min_fwhm_approx = 0.1*self.kidney.Ef-0.16
			min_Ei = self.kidney.Ef-2.0*min_fwhm_approx
			max_fwhm_approx = 0.1*np.max(omega_list)-0.16
			max_Ei = np.max(omega_list)+2.0*max_fwhm_approx+self.kidney.Ef
			Ei_list = np.arange(min_Ei,max_Ei,Energy_step)
			#Check if the omega values are in the list, if not add them. 
			for omega in omega_list:
				if omega+self.kidney.Ef not in Ei_list:
					Ei_list=np.append(Ei_list,omega+self.kidney.Ef)
		#Handle the default A3 arguments. 
		#Sort the Ei list 
		Ei_list = np.sort(Ei_list)
		omega_i = 0 #Counter for which omega we are nearest. 
		omega_list=np.sort(omega_list)
		idealEi_list = omega_list+self.kidney.Ef 
		self.useOld=False
		for i in range(len(omega_list)):
			runOmega = omega_list[i]
			print('###############')
			print(f'\n Current energy transfer: Omega = {runOmega:.2f} meV.\n')
			print(f'On energy transfer {i}/{len(i)}')
			print(f'Instrument will be recompiled at this point.')
			print('###############')
			if i>0:
				self.useOld=True
			#Determine the Ei's for which this omega is the closest.
			runEi_list = []
			for Ei_setting in Ei_list:
				closest_i = np.argmin(np.abs(idealEi_list-Ei_setting))
				closest_ideal_Ei = idealEi_list[closest_i]
				if closest_ideal_Ei-self.kidney.Ef == runOmega:
					runEi_list.append(Ei_setting)
			#We have our incident energies, now we can simply run the scan. 
			self.calc_resfunc(hkl_sq_list,omega=runOmega,A3_step=A3_step,num_Ei=9,n_threads=n_threads,use_res_sample=use_res_sample,Ei_settings=runEi_list,A3_settings=A3_settings)
		#The instrument will need to recompile at each energy tranfer but it should result in a 4-dimensional grid with all of the desired resolution ellipsoids. 
		return 1


	def calc_resfunc_slice(self,q_list,e_range):
		"""
		Calculates full Q/E resolution ellipsoids along a given path in Q-space.
		Automatically determines spacing between the ellipsoids such that they should not
		overlap. Also evenly spaces ellipsoids in energy. Result can be interpolated to use in 
		SPINW or other calculations of S(Q,omega)

		:param q_list: List of q-points that determine the scan direction in format of a Nx3 matrix where columns are H,K,L
		:type q_list: Nx3 np.ndarray
		:param e_range: Min and max energy transfers of the scans of format [minE,maxE]
		:type e_range: list
		"""

		return 1
