'''
###########################################

Library of functions for mcstas resolution function analysis of MACS

Thomas Halloran 2019
Johns Hopkins University

###########################################
'''
import numpy as np
import os
import time
import shutil
from joblib import Parallel, delayed 
import multiprocessing
import glob
import tqdm
import math
from datetime import date 
import datetime



def import_ng0(fname):
	#given a MACS ng0 file, generates a dictionary of all parameters and a numpy matrix with data
	#print('Importing '+fname+'...')
	data = np.genfromtxt(fname,dtype=str)
	column_labels={}
	file_params = {}
	f=open(fname,'r')
	lines = f.readlines()
	#Write all params to a dictionary
	for line in lines:
		param = line.split('\n')[0]
		param_name = param.split()[0].strip('#')
		param_val = param.split()[1:]

		file_params[param_name]=param_val
		if param_name=='Columns':
			#after this is data - break the loop. 
			break
	column_labels=file_params['Columns']

	return data, column_labels, file_params

def get_mono_params(column_labels,data):
	#subroutine to gather naming info for monochromator simulation
	Ei_index = 0
	beta1_index=0
	beta2_index=0
	Ef_index =0
	for i in range(len(column_labels)):
		if column_labels[i]=='Ei':
			Ei_index=i 
		if column_labels[i]=='Beta1':
			beta1_index=i 
		if column_labels[i]=='Beta2':
			beta2_index=i 
		if column_labels[i]=='Ef':
			Ef_index=i
		if Ei_index !=0 and beta1_index!=0 and beta2_index!=0 and Ef_index!=0:
			break
	#Extract values for Ei, beta1, beta2 
	Ei=np.around(np.mean(data[:,Ei_index].astype(float)),4)
	Ef=np.around(np.mean(data[:,Ef_index].astype(float)),4)
	beta1 = np.around(np.mean(data[:,beta1_index].astype(float)),4)
	beta2 = np.around(np.mean(data[:,beta2_index].astype(float)),4)
	return Ei,Ef,beta1,beta2

def write_monochromator_param_file(file_params,data,column_labels,mono_dir):
	#Write a parameter file for the monochromator given a dictionary of file params into a directory
	Ei,Ef,beta1,beta2 = get_mono_params(column_labels,data)

	out_name = mono_dir+'/mono_params_ei'+str(Ei)+'.txt'
	#Check if the ourput directory exists:
	if not os.path.isdir(mono_dir):
		#make it 
		os.makedirs(mono_dir,0o777)
	output_str = 'EM='+str(Ei)+' EF_all='+str(Ef)+' HF=1 VF=1 sample_diameter_d=0.02 beta_1='+str(beta1)+' beta_2='+str(beta2)\
					+' misalign_mono_deg=0.15 slit_h=0.2 slit_v=0.2 resolution_mode=0 res_radius=0.01 res_heigh=0.03+'\
					 'dE_resolution=1 CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 kidney_angle=0'+\
					  'DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 mon_e=0.0 monrot_delta=0'
	param_file = open(out_name,'w')
	param_file.write(output_str)
	param_file.close()
	return out_name

def get_kidney_params(file_params,column_labels,data):
	#Given an input ng0 file, gets relevant params to simulate an A3 kidney scan. 
	HF = 1 
	VF = 1
	sample_diameter_d=0.02
	misalign_mono_deg=0.15 
	slit_h = 0.2 
	slit_v = 0.2
	resolution_mode=0
	for i in range(len(column_labels)):
		if column_labels[i]=='A3':
			A3_i = i 
		if column_labels[i]=='Kidney':
			kidney_i = i 
		if column_labels[i]=='Ei':
			Ei_i = i 
		if column_labels[i]=='Ef':
			Ef_i = i 
		if column_labels[i]=='Beta1':
			beta_1_i = i 
		if column_labels[i]=='Beta2':
			beta_2_i = i 
	kidney_angle = np.mean(data[:,kidney_i].astype(float))
	Ei = np.mean(data[:,Ei_i].astype(float))
	Ef_all = np.mean(data[:,Ef_i].astype(float))
	beta1 = np.mean(data[:,beta_1_i].astype(float))
	beta2 = np.mean(data[:,beta_2_i].astype(float))
	#Need to get the A3 scan array 
	A3_arr = data[:,A3_i].astype(float)
	return 1,A3_arr,kidney_angle,Ei,Ef_all,HF,VF,sample_diameter_d,beta1,beta2,misalign_mono_deg,slit_h,slit_v,resolution_mode


def write_kidney_param_file(file_params,data,column_labels,kidney_dir):
	#Write a parameter file for the kidney given a dictionary of file params into a specified directory
	'''
	MACS_sample_kidney takes the following relevant arguments:

	*  INPUT PARAMETERS:
	*    repeat_count=1:    how many times the virtual out from MACS_monochromator is used
	*    A3_angle=0:        sample rotation [deg]
	*    kidney_angle=0:    kidney rotation [deg]
	*    EM=3.4             monochromator energy setting [meV]
	*    EF_all=3.4         analyser energy setting (for all analyser pairs) [meV]
	*    HF=1               Horizontal focusing (ALWAYS 1, 0 mode broken)
	*    VF=1               Vertical focusing (ALWAYS 1, 0 mode broken)
	*    sample_diameter_d=0.02
	*    beta_1=1
	*    beta_2=1
	*    misalign_mono_deg=0.15
	*    slit_h=0.2         Slit after guide horizontal [m]
	*    slit_v=0.2         Slit after guide vertical [m]
	*    resolution_mode=0  If resolution_mode == 1, the r

	Writing these to a file are purely for record keeping purposes. They are directly fed into the command line.
	The following arguments do not come from the file and must be user-specified, but are nearly always left default:
		repeat_count, misalign_mono_deg, resolution_mode
	'''
	slit_h = 0.2 
	slit_v = 0.2
	repeat_count,A3_arr,kidney_angle,Ei,Ef_all,HF,VF,sample_diameter_d,beta1,beta2,misalign_mono_deg,slit_h,slit_v,resolution_mode = get_kidney_params(file_params,column_labels,data)
	#This file isn't used for anything so no real need to save a file for each A3- simply one for the fpx file.
	Ei_str = "%.2f" % round(Ei,2)
	Ef_str = "%.2f" % round(Ef_all,2)
	b1_str = "%.2f" % round(beta1,2)
	b2_str = "%.2f" % round(beta2,2)
	out_name=kidney_dir+'/kidney_params_A4='+str(np.around(kidney_angle,3))+'_Ei='+str(np.around(Ei,2))+'_Ef='+str(np.around(Ef_all,2))+'_b1='+str(np.around(beta1,3))+'.txt'
	if not os.path.isdir(kidney_dir):
		#make it 
		os.makedirs(kidney_dir,0o777)
	output_str = 'A3_angle='+str(A3_arr)+' EM='+Ei_str+' EF_all='+Ef_str+' HF=1 VF=1 sample_diameter_d='+str(sample_diameter_d)+' beta_1='+b1_str+' beta_2='+b2_str\
					+' misalign_mono_deg='+str(misalign_mono_deg)+' slit_h='+str(slit_h)+' slit_v='+str(slit_v)+' resolution_mode='+str(resolution_mode)+' res_radius=0.01 res_heigh=0.03+'\
					 'dE_resolution=1 CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 kidney_angle=0'+\
					  'DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 mon_e=0.0 monrot_delta=0'
	param_file = open(out_name,'w')
	param_file.write(output_str)
	param_file.close()
	return out_name


def write_newng0(new_data,new_fname,a=1.0,b=1.0,c=1.0,alpha=90.0,beta=90.0,gamma=90.0,Ei=3.7,orientstr='1 0 0 0 1 0',header=False):
	#Generates a new NG0 file
	#Data needs to be in the format of 

	out_file = open(new_fname,'w')
	marker=0
	write_str =[]
	i=0
	now=datetime.datetime.now()
	dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
	n_points = len(new_data)
	#Header string is generated below
	if header==False:
		header='#ICE           0.4.0\n#ICERepositoryInfo ice/server/releases/main\n\#Filename    '+new_fname+'\n\
#Date        '+str(dt_string)+' EDT\n\
#InstrName   NG0\n\
#Epoch       1527239977.04\n\
#ExptID      20180522\n\
#ExptName    Mcstas simulation\n\
#ExptParticipants Mcstas Simulation\n\
#ExptDetails \n\
#ExptComment \n\
#User        ncnr \n\
#Comment     McStas Simulation \n\
#Npoints     '+str(n_points)+'\n\
#TemperatureUnits Kelvin\n\
#Ncolumns    138\n\
#DetectorDims 48 \n\
#Signal      102 SPEC\n\
#Reference   8 Monitor\n\
#ScanType   Find Peak Scan\n\
#Scan        '+str(len(new_data))+' A3 \n\
#ScanRanges: '+str(len(new_data))+' A3 \n\
#DetectorEfficiencies SPEC08=1.11213 DIFF08=1.0 SPEC13=1.10034 SPEC=1.0 DIFF12=1.0 DIFF06=1.0 DIFF20=1.0 SPEC18=0.80227 DIFF13=1.0 DIFF14=1.0 DIFF15=1.0 DIFF16=1.0 DIFF17=1.0 DIFF10=1.0 DIFF11=1.0 DIFF18=1.0 DIFF19=1.0 DIFF03=1.0 DIFF02=1.0 DIFF01=1.0 DIFF07=1.0 DIFF05=1.0 DIFF04=1.0 DIFF09=1.0 SPEC19=0.92229 SPARE=1.0 SPEC20=0.94215 Time=1.0 SPEC01=1.73581 SPEC10=0.82826 SPEC11=0.76417 SPEC14=1.14946 SPEC15=1.14866 SPEC16=1.0084 SPEC17=0.89907 SPEC12=0.7291 DIFF=1.0 SPEC06=0.78582 SPEC05=1.02589 SPEC04=0.89597 SPEC03=0.83476 SPEC02=1.08345 SPEC09=1.21259 SPEC07=1.01941 Monitor=1.0 \n\
#FixedE      Ei '+str(Ei)+'\n\
#Lattice     '+str(a)+' '+str(b)+' '+str(c)+' '+str(alpha)+' '+str(beta)+' '+str(gamma)+'\n\
#Orient      '+orientstr+'\n\
#MonoSpacing 3.35416\n\
#AnaSpacing  3.35416\n\
#UBEnabled   0\n\
#Fixed       All devices are free\n\
#ScanDescr   Scan:Type=6:Fixed=0:FixedE=1:CountType=MONITOR:Counts=130000.0:Range=A3='+str(np.min(new_data[:,9].astype(float)))+' '+str(np.max(new_data[:,9].astype(float)))+'Npts='+str(n_points)+':DetectorType=spec:Filename=fpx:Title=FindPeak\n\
#Columns             QX            QY            QZ             E            A4          Time          Temp       Monitor            A2            A3            A5            A6           DFM            A1       AColMon AnalyzerTheta01 AnalyzerTheta02 AnalyzerTheta03 AnalyzerTheta04 AnalyzerTheta05 AnalyzerTheta06 AnalyzerTheta07 AnalyzerTheta08 AnalyzerTheta09 AnalyzerTheta10 AnalyzerTheta11 AnalyzerTheta12 AnalyzerTheta13 AnalyzerTheta14 AnalyzerTheta15 AnalyzerTheta16 AnalyzerTheta17 AnalyzerTheta18 AnalyzerTheta19 AnalyzerTheta20       BColMon BaseSampleTheta      BeFilMon         Beta1         Beta2        DFMDTS          DIFF        DIFF01        DIFF02        DIFF03        DIFF04        DIFF05        DIFF06        DIFF07        DIFF08        DIFF09        DIFF10        DIFF11        DIFF12        DIFF13        DIFF14        DIFF15        DIFF16        DIFF17        DIFF18        DIFF19        DIFF20          DMBT            Ef            Ei          FLIP         Focus             H           HKL             K        Kidney             L      MBTSlide          MCFX      MgFilMon    MonBlade01    MonBlade02    MonBlade03    MonBlade04    MonBlade05    MonBlade06    MonBlade07    MonBlade08    MonBlade09    MonBlade10    MonBlade11    MonBlade12    MonBlade13    MonBlade14    MonBlade15    MonBlade16    MonBlade17    MonBlade18    MonBlade19    MonBlade20    MonBlade21        MonRot      MonTrans          PTAI      PgFilMon         SPARE          SPEC        SPEC01        SPEC02        SPEC03        SPEC04        SPEC05        SPEC06        SPEC07        SPEC08        SPEC09        SPEC10        SPEC11        SPEC12        SPEC13        SPEC14        SPEC15        SPEC16        SPEC17        SPEC18        SPEC19        SPEC20     SmplLTilt     SmplUTilt         SmplX         SmplY         SmplZ          VBAH          VBAV         cfxbe       cfxhopg        cfxmgf TemperatureControlReading TemperatureSetpoint TemperatureHeaterPower TemperatureSensor1 TemperatureSensor2 TemperatureSensor3    timestamp\n'
	else:
		header = header
	out_file.write(header)
	sample_dat_line ='                     N/A           N/A           N/A           N/A      -10.1853       91.2788        9.2864        130000        89.009        0.0052       44.4951       88.9902       44.5035       44.5035           OUT         44.4931         44.4855         44.5096         44.5019         44.4997         44.4953         44.4942         44.4733          44.503         44.5019         44.4997         44.4931         44.4986         44.4942         44.4953          44.481         44.4876         44.4898          44.503         44.5019           OUT          3.4275           OUT       2.99998  -4.44089e-16       -13.303         57847          2787          9557         16189          8483        112723          5364          4723          6015          7047          7905         57847   1.32535e+06        325981         11827          6734          6057          5292          4892         10513         15670            20        3.7011           3.7             A          1864      -0.13987 [-0.140,-0.012,-0.000]      -0.01236      -14.1853            -0       -5.3335            BE           OUT             0             0             0             0             0             0             0             0             0             0             0             0             0             0             0             0             0             0             0             0             0        44.503        -0.435            11           OUT             0         13885          1613          3559          8893          3894         55651          2826          2565          2524          2913          3880         13885        669408        197105          3283          2514          2753          2888          2897          4527          6201             0             0          -1.5        -0.003        -3.003        50.006       359.817            IN           OUT           OUT 10.261 10.0 5.3 9.9446 87.98 219.136    1527240071.8901460'
	
	labels='             QX            QY            QZ             E            A4          Time          Temp       Monitor            A2            A3            A5            A6           DFM            A1       AColMon AnalyzerTheta01 AnalyzerTheta02 AnalyzerTheta03 AnalyzerTheta04 AnalyzerTheta05 AnalyzerTheta06 AnalyzerTheta07 AnalyzerTheta08 AnalyzerTheta09 AnalyzerTheta10 AnalyzerTheta11 AnalyzerTheta12 AnalyzerTheta13 AnalyzerTheta14 AnalyzerTheta15 AnalyzerTheta16 AnalyzerTheta17 AnalyzerTheta18 AnalyzerTheta19 AnalyzerTheta20       BColMon BaseSampleTheta      BeFilMon         Beta1         Beta2        DFMDTS          DIFF        DIFF01        DIFF02        DIFF03        DIFF04        DIFF05        DIFF06        DIFF07        DIFF08        DIFF09        DIFF10        DIFF11        DIFF12        DIFF13        DIFF14        DIFF15        DIFF16        DIFF17        DIFF18        DIFF19        DIFF20          DMBT            Ef            Ei          FLIP         Focus             H           HKL             K        Kidney             L      MBTSlide          MCFX      MgFilMon    MonBlade01    MonBlade02    MonBlade03    MonBlade04    MonBlade05    MonBlade06    MonBlade07    MonBlade08    MonBlade09    MonBlade10    MonBlade11    MonBlade12    MonBlade13    MonBlade14    MonBlade15    MonBlade16    MonBlade17    MonBlade18    MonBlade19    MonBlade20    MonBlade21        MonRot      MonTrans          PTAI      PgFilMon         SPARE          SPEC        SPEC01        SPEC02        SPEC03        SPEC04        SPEC05        SPEC06        SPEC07        SPEC08        SPEC09        SPEC10        SPEC11        SPEC12        SPEC13        SPEC14        SPEC15        SPEC16        SPEC17        SPEC18        SPEC19        SPEC20     SmplLTilt     SmplUTilt         SmplX         SmplY         SmplZ          VBAH          VBAV         cfxbe       cfxhopg        cfxmgf TemperatureControlReading TemperatureSetpoint TemperatureHeaterPower TemperatureSensor1 TemperatureSensor2 TemperatureSensor3    timestamp'
	column_labels=labels.split()
	#Iterate through all of the new data and put it into a new line
	sample_line_split = sample_dat_line.split()
	for line in new_data:
		out_str = ''
		for element in line:
			out_str=out_str+' '+element
		out_file.write(out_str+'\n')

	end_str='#NG0:END	TYPE= FP	FIT_P1= 10819.996908	FIT_P2= 0.000000	FIT_P3= 0	FIT_P4= 1509136.059510	FIT_P5= 1.602602	FIT_P6= 2.182143'
	out_file.write(end_str)
	out_file.close()

	#Should be done- never should actually get to this point.
	return 1



def simulate_ng0(fname,mono_dir,kidney_dir,sim_mono=True,sim_kidney=True,n_mono = 1e5,n_kidney=1e6,sudoPassword=False,a=1,b=1,c=1,alpha=90,beta=90,gamma=90,orientstr='1 0 0 0 1 0'):
	#given a ng0 MACS data file, directly simulates the scan and writes a corresponding file which is identical apart from intensities. 
	if sudoPassword==False:
		sudoPassword=raw_input('Input sudo password: ')
	#First check if the monochromator has been simulated
	data,labels,params = import_ng0(fname)
	Ei,Ef,beta1,beta2 = get_mono_params(labels,data)
	kidney_dir=kidney_dir
	#Naming convention is as follows: E(Ei 2 decimal)meV_HF1_VF1 ...  .dat'
	Ei_str = "%.2f" % round(Ei,2)
	Ef_str = "%.2f" % round(Ef,2)
	b1_str = "%.2f" % round(beta1,2)
	b2_str = "%.2f" % round(beta2,2)


	filename='E'+Ei_str+'meV_HF1_VF1_Sample0.020_b1_'+b1_str+'_b2_'+b2_str+'_mono_mis0.15_CPF0.00_MPL6.06_MPD0.78_dL0_-1.060_dL1_0.000_APE_h0.350_APE_v0.350.dat'
	if os.path.exists(filename) == False:
		#file doesn't exist yet- need to run or extract from mono dir
		#First write a parameter file
		param_fname=write_monochromator_param_file(params,data,labels,mono_dir)
		#Check if the monochromator file is compiled 
		if not os.path.exists('MACS_monochromator.c'):
			if os.path.exists('compile_'+mono_dir):
				shutil.rmtree('compile_'+mono_dir)
			#not compiled- compile before going forward
			print('Compiling MACS_monochromator.instr (~10 min)')
			os.system('mcrun MACS_monochromator.instr -c -p '+param_fname+' -d compile_'+mono_dir+' >/dev/null 2>&1')
		check=0
		while check==0:
			if os.path.exists('MACS_monochromator.c'):
				check=1 
			else:
				check=0
				time.sleep(0.3)
		#remove compilation directory if it exists
		if os.path.exists('compile_'+mono_dir):
			command = 'rm -r compile_'+mono_dir
			os.system('echo %s|sudo -S %s' % (sudoPassword,command))	
		#monochromator has compiled, check to see if the data file exists
		#doesn't exist- create it. also check for the newest folder for this point
		curr_dir = os.getcwd()
		
		directory = mono_dir
		mono_file_folder = 'MONO_TEMP_Ei='+Ei_str+'_Ef_'+Ef_str+'_B1_'+b1_str+'_B2_'+b2_str
		#Need to check if the folder exists- if it does it's currently being calculated. Need to wait until it's done.
		if not os.path.exists(mono_file_folder):
			print('Running monochromator simulation for Ei='+str(Ei))
			print('Filename: '+str(filename))
			#print('Outputting parameter files to directory: '+directory)
			#print('Outputting simulation file to '+mono_file_folder)
			command1 = 'mcrun MACS_monochromator.instr -d '+mono_file_folder+' -n '+str(n_mono)+\
				' EM='+Ei_str+' EF_all='+Ef_str+' HF=1 VF=1 sample_diameter_d=0.02 beta_1='+b1_str+' beta_2='+b2_str\
					+' misalign_mono_deg=0.15 CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 kidney_angle=0 '+\
					  'DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 mon_e=0.0 monrot_delta=0 >/dev/null 2>&1'
			os.system('echo %s|sudo -S %s' % (sudoPassword,command1))

		#Check to make sure that the file hasn't finished - specifying directory causes bugs related to MCstas parsing
		# So, check for new Mcstas folder then rename once it's found. 
		check = 0
		while check == 0:
			#Wait a second
			time.sleep(1)
			#check for new folder 
			if not os.path.exists(mono_file_folder+'/'+filename) and (not os.path.exists(filename)):
				check=0
			else:
				print('File '+filename+' found=='+str(os.path.exists(filename)))
				check=1
				#now move on, extract file from the directory
		if os.path.exists(mono_file_folder):
			src = mono_file_folder+'/'+filename
			dst = curr_dir+'/'+filename
			#print('Copying .dat file to working directory.')
			#Once this is done move the output file to the working directory and delete the folder
			shutil.move(src,dst)
			#remove the source folder, no need for it. 
			command = 'rm -r '+mono_file_folder
			os.system('echo %s|sudo -S %s' % (sudoPassword,command))
			print('Monochromator simulation successfully completed for Ei='+str(np.around(Ei,2)))
	else:
		#print('Monochromator .dat file found for Ei='+str(np.around(Ei,2))+'meV. Using for kidney scan.')
		x=0
	#We can now do the kidney scan. Need to do one for each A3 angle provided.
	# First check if it's been compiled. 
	kidney_param_fname=write_kidney_param_file(params,data,labels,kidney_dir)
	if not os.path.exists('MACS_sample_kidney.c'):
		#not compiled- compile before going forward
		print('Compiling MACS_sample_kidney.c, ~10 minutes compile time. 32GB Memory required.')
		os.system('mcrun MACS_sample_kidney.instr -c -p '+kidney_param_fname+' -d compile_'+kidney_dir+' >/dev/null 2>&1')
	check=0
	if os.path.exists('MACS_sample_kidney.c'):
		check=1
	while check==0:
		
		if os.path.exists('MACS_sample_kidney.c'):
			check=1 
		else:
			check=0
	#Remove the compilation directory if it exists
	if os.path.exists('compile_'+kidney_dir):
		command = 'rm -r compile_'+kidney_dir
		os.system('echo %s|sudo -S %s' % (sudoPassword,command))
	#Check if this particular simulation has been run :
	if os.path.exists(fname.split('.')[0]+'_mcstasSim.ng0'):
		return 0
	else:
		#Definitely compiled now: for every A3 angle, run.
		repeat_count,A3_arr,kidney_angle,Ei,Ef_all,HF,VF,sample_diameter_d,beta1,beta2,misalign_mono_deg,slit_h,slit_v,resolution_mode = get_kidney_params(params,labels,data)
		sim_data = data.copy()
		dir_i = 0
		dir_folder = fname
		spec_1_i = labels.index('SPEC01')
		diff_1_i = labels.index('DIFF01')
		monitor_i = labels.index('Monitor')

		#Mount a temporary folder for RAM usage, outputting all of these files to disk is slow and tough on the storage
		mount_directory = '/mnt/ramdisk'
		if not os.path.exists('/mnt/ramdisk'):
			#Make the ram directory
			command1 = 'mkdir /mnt/ramdisk'
			command2 = 'mount -t tmpfs -o size=2048m tmpfs /mnt/ramdisk'
			os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
			os.system('echo %s|sudo -S %s' % (sudoPassword,command2))

		for i in range(len(A3_arr)):
			#Pass the simulation command 

			A3_angle=A3_arr[i]
			dir_folder = '/mnt/ramdisk/'+fname+str(A3_angle)
			dir_folder = dir_folder.replace('-','m').replace('.','p')
			param_str = 'A3_angle='+str(A3_arr[i])+' kidney_angle='+str(kidney_angle)+' EM='+Ei_str+'\
			 EF_all='+Ef_str+' HF=1 VF=1 sample_diameter_d='+str(sample_diameter_d)+' beta_1='+b1_str+\
			 ' beta_2='+b2_str+' repeat_count=1 ' #rest are default
			if i==0 and i==1:
				command = 'mcrun MACS_sample_kidney.instr -n '+str(n_kidney)+' -d '+str(dir_folder)+' '+param_str#+'  >/dev/null 2>&1'
				print(command)
			else:
				command = 'mcrun MACS_sample_kidney.instr -n '+str(n_kidney)+' -d '+str(dir_folder)+' '+param_str+'  >/dev/null 2>&1'
			os.system('echo %s|sudo -S %s' % (sudoPassword,command))
			#print('Running Kidney Angle='+str(np.around(kidney_angle,3))+' A3='+str(np.around(A3_angle,3)))
			#Now that the angle is done, extract the intensities for each SPEC, DIFF detector
			#Scan through all files in the directory
			sub_files = os.listdir(str(dir_folder))
			#print('Reducing mcstas files to ng0 file:')
			for j in range(len(sub_files)):
				if sub_files[j].split('_')[0]=='diff':
					det_index = int(sub_files[j].split('_')[2].split('.')[0])
					data_in = np.genfromtxt(str(dir_folder)+'/'+sub_files[j])
					I=np.sum(data_in[0:4])
					err = np.sqrt(np.sum(data_in[4:9]**2))
					sim_data[i,diff_1_i+det_index]=0
					sim_data[i,diff_1_i+det_index]=I
				if sub_files[j].split('_')[0]=='spec' and len(sub_files[j].split('_'))==3:
					det_index= int(sub_files[j].split('_')[2].split('.')[0])
					data_in = np.genfromtxt(str(dir_folder)+'/'+sub_files[j])
					I = np.sum(data_in[0:4])
					sim_data[i,spec_1_i+det_index]=0
					sim_data[i,spec_1_i+det_index]=I
			sim_data[i,monitor_i]=100
			#delete this directory
			command = 'rm -r '+dir_folder
			os.system('echo %s|sudo -S %s' % (sudoPassword,command))

			dir_i+=1
		new_fname=fname.split('.')[0]+'_mcstasSim.ng0'
		#Pull the previous header with better formatting
		file = open(fname)
		lines = file.readlines()
		header_str = ''
		file.close()
		for line in lines:
			if line.split()[0]!='#Columns':
				header_str=header_str+line
			else:
				header_str=header_str+line
				break
		test = write_newng0(sim_data,new_fname,a=a,b=b,c=c,alpha=alpha,beta=beta,gamma=gamma,Ei=Ei,orientstr='1 0 0 0 1 0',header=header_str)

		#now delete the old folders:

	return 1


def sim_ng0_dir(mono_dir,kidney_dir,n_mono=1e7,n_kidney=1e6,n_threads=12,expt_directory='',sudoPassword=False,a=1,b=1,c=1,alpha=90,beta=90,gamma=90,orientstr='1 0 0 0 1 0'):
	#Given a directory of ng0 files, simulates each one and creates a simulated version for direct 
	# comparison.
	# Importantly, input ng0 files should ONLY be the experiment.
	if sudoPassword==False:
		sudoPassword=raw_input('Input sudo password: ')
	ng0_files = glob.glob('*.ng0')
	expt_files = []
	#Check if the monochromator file is compiled 
	if not os.path.exists('MACS_monochromator.c'):
		if os.path.exists('compile_'+mono_dir):
			shutil.rmtree('compile_'+mono_dir)
		#not compiled- compile before going forward
		print('Compiling MACS_monochromator.instr (~10 min)')
		os.system('mcrun MACS_monochromator.instr -c -p '+param_fname+' -d compile_'+mono_dir+' >/dev/null 2>&1')
	check=0
	while check==0:
		if os.path.exists('MACS_monochromator.c'):
			check=1 
		else:
			check=0
			time.sleep(0.3)
	#remove compilation directory if it exists
	if os.path.exists('compile_'+mono_dir):
		command = 'rm -r compile_'+mono_dir
		os.system('echo %s|sudo -S %s' % (sudoPassword,command))
	#Check if the kidney is compiled 
	if not os.path.exists('MACS_sample_kidney.c'):
		#not compiled- compile before going forward
		print('Compiling MACS_sample_kidney.c, ~10 minutes compile time.')
		os.system('mcrun MACS_sample_kidney.instr -c -p '+kidney_param_fname+' -d compile_'+kidney_dir+' >/dev/null 2>&1')
	check=0
	while check==0:
		
		if os.path.exists('MACS_sample_kidney.c'):
			check=1 
		else:
			check=0
			time.sleep(0.3)
	#Remove the compilation directory if it exists
	if os.path.exists('compile_'+kidney_dir):
		command = 'rm -r compile_'+kidney_dir
		os.system('echo %s|sudo -S %s' % (sudoPassword,command))

	#check for simulated files
	for i in range(len(ng0_files)):
		filename=ng0_files[i].split('_')
		if len(filename)==1:
			expt_files.append(filename[0])
	#Set up joblib
	num_cores = multiprocessing.cpu_count()
	if n_threads>num_cores:
		print('Too many threads defined: max available are '+str(num_cores))
		n_threads=num_cores-1
	results = Parallel(n_jobs=n_threads)(delayed(simulate_ng0)(expt_files[i],mono_dir,kidney_dir,True,True,n_mono,n_kidney,sudoPassword,a,b,c,alpha,beta,gamma,orientstr) for i in tqdm.tqdm(range(len(expt_files))))
	print('Simulation complete.')
	#Make sure any ramdisk no longer exists.
	if os.path.exists('/mnt/ramdisk'):
		command1 = 'umount /mnt/ramdisk'
		command2 = 'rm -r /mnt/ramdisk'
		os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
		os.system('echo %s|sudo -S %s' % (sudoPassword,command2))	
	return 0 

def pass_kid_scan(kidney_angle,Ei_str,Ef_str,b1_str,b2_str,sample_ng0_fname,A3_arr,n,sudoPassword,a=1.0,b=1.0,c=1.0,alpha=90.0,beta=90.0,gamma=90.0,Ei=3.7,orientstr='1 0 0 0 1 0'):
	#Helperfunction to parallelize the kindey scan script
	fname='Macs_kid_'+str(round(kidney_angle,3)).replace('-','m').replace('.','p')+'_deg'
	#Check if this dir exists
	if not os.path.exists('/mnt/ramdisk'):
		#Make the ram directory
		command1 = 'mkdir /mnt/ramdisk'
		command2 = 'mount -t tmpfs -o size=2048m tmpfs /mnt/ramdisk'
		os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
		os.system('echo %s|sudo -S %s' % (sudoPassword,command2))
	if not os.path.exists('/mnt/ramdisk/'+fname):
		command1 = 'mkdir /mnt/ramdisk/'+fname
		os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
	data = np.genfromtxt(sample_ng0_fname,dtype=str)
	dat_row = data[0]
	#Expand this into the correct shape to be simulated data (same number of rows as A3 positions)
	sim_data=np.tile(dat_row,(len(A3_arr),1))
	fakedat,labels,fileparams = import_ng0(sample_ng0_fname)

	spec_1_i = labels.index('SPEC01')
	diff_1_i = labels.index('DIFF01')
	Ei_i = labels.index('Ei')
	Ef_i = labels.index('Ef')
	a4_i = labels.index('A4')
	kidney_i = labels.index('Kidney')
	a3_i = labels.index('A3')
	sample_diameter_d=0.02
	dir_i=0
	for i in range(len(A3_arr)):
	#Pass the simulation command 
		A3_angle=A3_arr[i]
		dir_folder = '/mnt/ramdisk/'+fname+'/'+str(A3_angle).replace('-','m').replace('.','p')

		param_str = 'A3_angle='+str(A3_arr[i])+' kidney_angle='+str(kidney_angle)+' EM='+Ei_str+\
		 ' EF_all='+Ef_str+' HF=1 VF=1 sample_diameter_d='+str(sample_diameter_d)+' beta_1='+b1_str+\
		 ' beta_2='+b2_str+' repeat_count=1 ' #rest are default
		#os.system('mcrun MACS_sample_kidney.instr -n '+str(n_kidney)+' -d '+str(dir_folder)+' '+param_str+' >/dev/null 2>&1')
		command1 = 'mcrun MACS_sample_kidney.instr -n '+str(n)+' -d '+str(dir_folder)+' '+param_str+' >/dev/null 2>&1'
		os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
		#print('Running Kidney Angle='+str(np.around(kidney_angle,3))+' A3='+str(np.around(A3_angle,3)))
		#Now that the angle is done, extract the intensities for each SPEC, DIFF detector
		#Scan through all files in the directory
		sub_files = os.listdir(str(dir_folder))
		#print('Reducing mcstas files to ng0 file:')
		#Need to import a sample MACS file to imitate

		for j in range(len(sub_files)):
			if sub_files[j].split('_')[0]=='diff':
				det_index = int(sub_files[j].split('_')[2].split('.')[0])
				data_in = np.genfromtxt(str(dir_folder)+'/'+sub_files[j])
				I=np.sum(data_in[0:4])
				err = np.sqrt(np.sum(data_in[4:9]**2))
				sim_data[i,diff_1_i+det_index]=I
			if sub_files[j].split('_')[0]=='spec' and len(sub_files[j].split('_'))==3:
				det_index= int(sub_files[j].split('_')[2].split('.')[0])
				data_in = np.genfromtxt(str(dir_folder)+'/'+sub_files[j])
				I = np.sum(data_in[0:4])
				sim_data[i,spec_1_i+det_index]=I
		#delete this directory
		sim_data[i,a4_i]=str(kidney_angle+4.0)
		sim_data[i,kidney_i]=str(kidney_angle)
		sim_data[i,a3_i]=str(A3_angle)
		sim_data[i,Ei_i]=Ei_str
		sim_data[i,Ef_i]=Ef_str
	dir_i+=1
	test = write_newng0(sim_data,fname+'_mcstasSim.ng0',a,b,c,alpha,beta,gamma,Ei,orientstr)


def script_kidney_scan(Ei=5.0,Ef=5.0,da4=0.5,A3min=-90,A3max=90,numA3=91,n=1e6,beta_1=3.0,beta_2=3.02,num_cores=2,baseName='mcstas_test',\
	sample_ng0_fname='sample.ng0',n_threads=4,sudoPassword=False,a=1.0,b=1.0,c=1.0,alpha=90.0,beta=90.0,gamma=90.0,orientstr='1 0 0 0 1 0'):
	#Quick script to automate McStas kidney_angle scripts
	#First determine the list of angles
	#Angles now in array kpositions
	# Also assumes that the sample_kidney.instr file has been compiled
	# assumes that the monochromator has been simulated already- betas, Ei, Ef must match the file for anything to happen!1

	angle_file = '/home/thomas/mcstas/Mcstas_2019/mcstas_python/macs_kidneylimit_new.txt'
	dict= {}
	angle_mat = np.genfromtxt(angle_file)
	for row in angle_mat:
		dict[row[0]]=[row[1],row[2]]
	#Find closest Ei in the dictionary
	list_Ei= angle_mat[:,0]
	def find_nearest(array,value):
	    idx = (np.abs(array-value)).argmin()
	    return array[idx]
	A3_arr=np.linspace(A3min,A3max,numA3)
	Ei = find_nearest(list_Ei,Ei)

	#Now have Init, Final kidney angles

	Ki = dict[Ei][0]
	Kf = dict[Ei][1]
	#print(Ki)
	#print(Kf)

	#Calculate kidney step size

	kidney_range = Kf - Ki 
	a4_range = kidney_range+8.0*19.0
	Ntot = a4_range/da4 
	stepin = kidney_range / (Ntot / 20.0)

	#Now calculate optimum angles to avoid overlap

	N = max(round(Kf-Ki)/8 , 1)
	m = int(round(8*N/stepin))
	i=m 
	for i in range(m,m+100):
		if((i/8)*8 != i):
			if((i/N)*N != i):
				break
		i=m 
	steps = 8.0*N/i 

	total_steps = int(math.floor((Kf - Ki)/steps)+1)
	rangeT = (total_steps-1)*(steps)+0.001
	nnkcen=(Kf+Ki)/2 
	kpositions = nnkcen-rangeT/2.0+np.arange(total_steps)*steps

	#Now take in the input energy, output energy, N, MPI, A3 Range

	Steps = numA3

	MPI = 1

	#Write param file for each kidney angle

	def writeParams(param_file, kidney_angle, Ei, Ef):
		param_file.write('A3_angle=0 \n')
		param_file.write('kidney_angle='+str(kidney_angle)+' \n')
		param_file.write('EM='+str(Ei)+' \n')
		param_file.write('EF_all='+str(Ef)+' \n')
		param_file.write('HF=1 \n')
		param_file.write('VF=1 \n')
		param_file.write('sample_diameter_d=0.02 \n')
		param_file.write('beta_1=1 \n')
		param_file.write('beta_2=1 \n')
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
		param_file.write( 'monrot_delta=0 \n')
		param_file.write( 'slit_h=0.2 \n')
		param_file.write('slit_v=0.2 \n')
		param_file.write('resolution_mode=0 \n')
		param_file.write('res_radius=0.01 \n')
		param_file.write('res_height=0.03 \n')
		param_file.write('repeat_count=2 \n')
		param_file.write('E0_resolution=0 \n')
		param_file.write('dE_resolution=1 \n')
		param_file.close()


	for angle in kpositions:
		param_file_name = baseName+'_param_'+str(round(angle,3))
		param_file = open(param_file_name, 'w')
		writeParams(param_file, angle, Ei, Ef)
	#Flush the ramdisk
	if os.path.exists('/mnt/ramdisk'):
		#Make the ram directory
		command1 = 'umount /mnt/ramdisk'
		command2 = 'rm -r /mnt/ramdisk'
		os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
		os.system('echo %s|sudo -S %s' % (sudoPassword,command2))

	#Rather than write to a script, interate shell input through python for every position
	#To mimic MACS have each Ei be its own ng0 file
	mount_directory = '/mnt/ramdisk'
	if not os.path.exists('/mnt/ramdisk'):
		#Make the ram directory
		command1 = 'mkdir /mnt/ramdisk'
		command2 = 'mount -t tmpfs -o size=2048m tmpfs /mnt/ramdisk'
		os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
		os.system('echo %s|sudo -S %s' % (sudoPassword,command2))
	dir_folder = '/mnt/ramdisk/'

	#For each kidney angle run a simulation and write an ng0 file
	Ei_str = "%.2f" % round(Ei,2)
	Ef_str = "%.2f" % round(Ef,2)
	b1_str = "%.2f" % round(beta_1,2)
	b2_str = "%.2f" % round(beta_2,2)
	sample_diameter_d=0.02

	n_kidney=int(len(kpositions))
	dir_i=0

	num_cores = multiprocessing.cpu_count()
	if n_threads>num_cores:
		print('Too many threads defined: max available are '+str(num_cores))
		print('Using '+str(num_cores-1)+' threads instead')
		n_threads=num_cores-1

	results = Parallel(n_jobs=n_threads)(delayed(pass_kid_scan)(kpositions[i],Ei_str,Ef_str,b1_str,b2_str,sample_ng0_fname,A3_arr,n,sudoPassword,a,b,c,alpha,beta,gamma,Ei,orientstr) for i in tqdm.tqdm(range(len(kpositions))))

	if os.path.exists('/mnt/ramdisk'):
		#Make the ram directory
		command1 = 'umount /mnt/ramdisk'
		command2 = 'rm -r /mnt/ramdisk'
		os.system('echo %s|sudo -S %s' % (sudoPassword,command1))
		os.system('echo %s|sudo -S %s' % (sudoPassword,command2))	
	
	return 1
