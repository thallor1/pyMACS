import sys,os
import numpy as np
from . import sample
from . import monochromator
from . import kidney
from . import macsdata
from . import scripting
import shutil
import subprocess
import time
import glob
try:
    import mcstasscript as ms
    testinstr = ms.McStas_instr("dummy_instr",checks=False)
    inc_scatter = testinstr.add_component("inc_scatter","Incoherent_process")
except Exception as e:
    print(d)
    print("Warning: Error when initializing McStasscript, refer to mcstasscript documentation.")
    print("The configurator object must be pointing to your mcstas installation, which is system dependent.")
from .scripting import import_ng0
from .scripting import resfunc

from joblib import Parallel, delayed
from tqdm.auto import tqdm
import pickle
from importlib.resources import files

class VirtualMACS(object):
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

    def __init__(self, exptName, cifName=None, useOld=False):
        """ Constructor method
		"""
        self.exptName = exptName
        if cifName is not None:
            self.sample = sample.Sample(ciffile=cifName)
        else:
            self.sample = sample.Sample()
        self.monochromator = monochromator.Monochromator()
        self.kidney = kidney.Kidney()
        # If it does not exist, make an experiment directory.
        cwd = os.getcwd()
        if not os.path.exists(cwd + '/' + exptName):
            os.mkdir(cwd + '/' + exptName)
        self.exptdir = cwd + '/' + exptName
        self.cwd = cwd
        self.data = macsdata.Data(self.sample, self.exptName, kidney_result_dir=self.exptdir + '/Kidney_simulations/')

        # Now some elements that are usually only needed for the simulations
        self.n_sample = 1e5
        self.n_mono = 1e6
        self.A3_angle = 0.0
        self.kidney_angle_resolution = 1.0  # Should be set by user eventually
        self.repeat_count = 1
        self.output_dir = self.exptdir + '/macs_kidney_scan_1'
        self.instr_template_dir = None
        self.kidney_instr_dir = None
        self.monochromator_instr_file = 'MACS_monochromator.instr'
        self.instr_main_file = "MACS_sample_kidney.instr"
        self.mono_param_dir = None
        self.file_dependencies = None
        self.kidney_param_dir = None
        self.useOld = useOld
        self.mono_scanList = []  # Will keep track of the scans that have been run.
        self.kidney_scanList = []
        self.instr_file_directory = cwd + '/' + self.exptName + '/Instrument_files/'
        self.modified_kidney_flag = 0  # keeps track of if the instr file must be recompiled.
        self.base_ng0 = False
        self.kidsim_dir = cwd + '/' + self.exptName + '/Kidney_simulations/'
        # Name of ramdisk directory for simulation output.
        # self.ramdisk_dir = '/tmp/memory'
        self.ramdisk_dir = '/dev/shm/memory'

        self.ramdisk_size = '2G'  # This can be changed by user manually if needed but it should never get larger than this.
        self.sudo_password = 'password'  # Plaintext password for sudo access to disk, this needs to be fixed later.
        self.data.kidney_sim_dir = self.ramdisk_dir + '/Kidney_simulations/'
        self.preserve_kidney_scan_files = False  # Flag to determine if files are deleted from ramdisk after each scan.
        self.preserve_kidney_param_files = False  # Flag to determine if individual kidney parmeter files are preserved.
        i = 2
        while os.path.exists(self.output_dir):
            self.output_dir = self.exptdir + '/macs_kidney_scan_' + str(
                i)  # Prevents default directory from already existing
            i += 1

        i = 0
        # Some elements specifically used in box_inel_crystal;
        self.inel_reflect_list = None
        self.inel_reflect_omega_list = None
        self.inel_reflect_SF_list = None

    def mount_ramdisk_old(self):
        """ Mounts a disk based in memory. Disk operations are too slow, users are not intended to access
			the ramdisk."""

        if os.path.ismount(self.ramdisk_dir):
            return 1
        else:
            if not os.path.exists(self.ramdisk_dir):
                os.system('echo \'' + str(self.sudo_password) + '\' |sudo -S mkdir ' + self.ramdisk_dir)
            os.system('echo \'' + str(self.sudo_password) + '\' | sudo -S chmod 777 ' + str(self.ramdisk_dir))
            os.system('echo \'' + str(self.sudo_password) + '\' | sudo -S mount -t tmpfs -o size=' + str(
                self.ramdisk_size) + ' mcstasramdisk ' + self.ramdisk_dir)
        print('RAMDISK mounted in ' + self.ramdisk_dir)
        print('Ensure tmpfs is unmounted safely.')
        return 1

    def mount_ramdisk(self,verbose=False):
        """ Mounts a disk based in memory. Disk operations are too slow, users are not intended to access
			the ramdisk."""
        if os.path.exists(self.ramdisk_dir):
            return 1
        else:
            os.mkdir(self.ramdisk_dir)
            if verbose is True:
                print(self.ramdisk_dir + ' successfully mounted.')

    def clear_ramdisk(self):
        """ Unmounts the ramdisk. Should be done after simulation is over to free memory.
		"""
        if os.path.exists(self.ramdisk_dir):
            shutil.rmtree(self.ramdisk_dir)
        # os.system('rm -rf '+self.ramdisk_dir)
        return 1

    def unmount_ramdisk(self):
        """ Unmounts the ramdisk. Should be done after simulation is over to free memory.
		"""
        if os.path.exists(self.ramdisk_dir):
            shutil.rmtree(self.ramdisk_dir)
        return 1

    def prepare_old_expt_directory(self):
        """Prepares an experiment using previously generated and/or compiled .instr files. Used to
		resume a simulation that was interrupted or should be appended.
		"""
        cwd = self.cwd
        if self.useOld == True:
            self.clear_ramdisk()
            self.instr_template_dir = str(files("pyMACS")) + '/UNION MACS Models/UNION MACS Base/'
            self.kidney_instr_dir = str(files("pyMACS"))+ '/UNION MACS Models/UNION MACS Kidney Files/'

            instr_main_file = 'MACS_sample_kidney.instr'
            self.instr_main_file = instr_main_file
            self.instr_file_directory = cwd + '/' + self.exptName + '/Instrument_files/'
            self.instr_main_file = self.instr_file_directory + self.instr_main_file  # This now points directly to the instr file that will be modified
            # Copy the base files into the new instrument directory
            shutil.copytree(self.instr_template_dir, self.instr_file_directory)
            # Copy the particular instrument file into the instrument directory
            shutil.copy(self.kidney_instr_dir + instr_main_file, self.instr_file_directory)
            # Also need to move the lau file into the instrument directory
            shutil.copy(cwd + '/' + self.sample.laufile, self.instr_file_directory)
            shutil.copy(cwd + '/' + self.sample.ciffile, self.instr_file_directory)
            #Check if the instrument file exists.
            if not os.path.exists(self.instr_main_file):
                    shutil.copy(self.kidney_instr_dir + instr_main_file, self.instr_file_directory)

        return 1

    def clean_expt_directory(self):
        """Removes old simulation files, use with care.
		"""
        cwd = self.cwd
        files_in_kidsims = glob.glob(cwd + '/' + self.exptName + '/Kidney_simulations/*')
        if len(files_in_kidsims) > 0:
            input('WARNING: Old simulations have been found. Press enter to continue and delete files.')
        while len(files_in_kidsims) >= 1 and self.useOld is False:
            files_in_kidsims = glob.glob(cwd + '/' + self.exptName + '/Kidney_simulations/*')
            print(cwd + '/' + self.exptName + '/Kidney_simulations')
            if self.useOld is False:
                shutil.rmtree(cwd + '/' + self.exptName + '/param_files_kidney')
                shutil.rmtree(cwd + '/' + self.exptName + '/Kidney_simulations')
            time.sleep(0.1)
        self.clear_ramdisk()
        return 1

    def prepare_expt_directory(self):
        """Automatically prepares the McStas instrument files and output directories. Will require that instruments
		be recompiled. Takes into consideration the various sample options allowed."""
        if type(self.sample.laufile) is not str:
            # Need to generate and assign lau file
            self.sample.cif2lau()
        self.clear_ramdisk()
        cwd = self.cwd
        self.instr_template_dir = str(files("pyMACS")) + '/UNION MACS Models/UNION MACS Base/'
        self.kidney_instr_dir = str(files("pyMACS")) + '/UNION MACS Models/UNION MACS Kidney Files/'
        instr_main_file = 'MACS_sample_kidney.instr'
        self.instr_main_file = instr_main_file
        while os.path.exists(cwd + '/' + self.exptName + '/Instrument_files') and self.useOld is False:
            print(
                'WARNING: Old instrument directory found. Older files deleted, instrument will need to be recompiled.')
            os.system('rm -rf \"' + cwd + '/' + self.exptName + '\"')
            self.clean_expt_directory()
        self.instr_file_directory = cwd + '/' + self.exptName + '/Instrument_files/'
        self.instr_main_file = self.instr_file_directory + self.instr_main_file  # This now points directly to the instr file that will be modified
        # Copy the base files into the new instrument directory
        shutil.copytree(self.instr_template_dir, self.instr_file_directory, dirs_exist_ok=True)
        # Copy the particular instrument file into the instrument directory
        shutil.copy(self.kidney_instr_dir + instr_main_file, self.instr_file_directory)
        # Also need to move the lau+cif files into the instrument directory
        shutil.copy(cwd + '/' + self.sample.laufile, self.instr_file_directory)
        shutil.copy(cwd + '/' + self.sample.ciffile, self.instr_file_directory)
        # Finally, move any file dependencies into the instrument directory.
        if self.file_dependencies is not None:
            if isinstance(self.file_dependencies, str):
                # only one file.
                shutil.copy(cwd + '/' + self.file_dependencies, self.instr_file_directory)
            else:
                # list of strings.
                for f_dep in self.file_dependencies:
                    shutil.copy(cwd + '/' + f_dep, self.instr_file_directory)

        return 1

    def edit_instr_file(self,verbose=False):
        """Updates the instrument file to match the current sample and instrument configuration. Will require
		a recompilation of the instrument."""
        if verbose is True:
            print('Generating sample parameters using file ' + str(self.sample.ciffile))
            print('Writing instrument file assuming scattering u=' + str(self.sample.orient_u) + ', v=' + str(
                self.sample.orient_v))
        # If it exists, delete the old instr file. 
        if os.path.exists(self.instr_main_file):
            os.remove(self.instr_main_file)
            shutil.copy(self.kidney_instr_dir + "MACS_sample_kidney.instr", self.instr_file_directory)
        if self.sample.scattering_def is False:
            print("Cannot generate instrument file before defining scattering processes!")
            print(
                "Define a mcstasscript objects with proper UNION scattering components using\nself.sample.scattering_def=mcstasscriptobj")
            return 0
        if self.sample.geometry_def is False:
            print("Cannot generate instrument file before defining scattering geometries!")
            print(
                "Define a mcstasscript objects with proper UNION scattering components using\nself.sample.geometry_def=mcstasscriptobj")
            return 0
        else:
            # We can write the instrument files:
            scattering = self.sample.scattering_def
            geometries = self.sample.geometry_def
            scattering.write_full_instrument()
            geometries.write_full_instrument()
            scattering_f = scattering.name + '.instr'
            geometry_f = geometries.name + ".instr"
            # We want the lines between TRACE and FINALLY
            f = open(scattering_f)
            lines = f.readlines()
            f.close()
            outline_scattering = ''
            traceflag = 0
            finallyflag = 0
            for line in lines:
                if traceflag == 1 and finallyflag == 0 and "FINALLY" not in line:
                    # Sometimes lines don't read in correctly with strings
                    outline_scattering = outline_scattering + line
                if "TRACE" in line:
                    traceflag = 1
                elif "FINALLY" in line:
                    finallyflag = 1
            f = open(geometry_f)
            lines_geo = f.readlines()
            f.close()
            outline_geo = ''
            traceflag = 0
            finallyflag = 0
            for line in lines_geo:
                if traceflag == 1 and finallyflag == 0 and "FINALLY" not in line:
                    outline_geo = outline_geo + line
                if "TRACE" in line:
                    traceflag = 1
                elif "FINALLY" in line:
                    finallyflag = 1
        # Replace the block in the instrument file with this.
        print(os.getcwd())
        instr_f = open(self.instr_main_file, 'r')
        contents = instr_f.readlines()
        instr_f.close()
        insert_i_scattering = 0
        insert_i_geo = 0
        for i in range(len(contents)):
            # Find the index of the string /* BEGIN INSERT BLOCK
            if 'REPLACEUNIONSCATTERINGPROCESSESFLAG' in contents[i]:
                insert_i_scattering = i + 1
        f = open(self.instr_main_file, 'w')
        contents.insert(insert_i_scattering, outline_scattering)
        f.writelines(contents)
        f.close()
        # Repeat for geometries
        instr_f = open(self.instr_main_file, 'r')
        contents = instr_f.readlines()
        instr_f.close()
        for i in range(len(contents)):
            if 'REPLACEUNIONGEOMETRIESSFLAG' in contents[i]:
                insert_i_geo = i + 1
        contents.insert(insert_i_geo, outline_geo)
        f = open(self.instr_main_file, 'w')
        f.writelines(contents)
        f.close()
        if verbose is True:
            print(' ')
            print('Instrument file ' + str(self.instr_main_file) + ' successfully prepared.\n')
            print('Ready to compile.\n')
            print(' ')
        self.modified_kidney_flag = 1
        return 1

    def compileInstr(self,verbose=True):
        """
		Runs the instrument compiler before beginnning scan. 

		"""
        # First generate c code, need to actually go into the directories to excecute these operations
        instr_dir = self.instr_file_directory
        instr_filename = self.instr_main_file.split('/')[-1]
        c_filename = instr_filename.replace('.instr', '.c')
        out_filename = instr_filename.replace('.instr', '.out')
        original_directory = self.cwd
        os.chdir(instr_dir)
        # shellcommandstr = 'mcrun -c '+instr_filename
        os.system('generate_MACS_parts_mcstasscript.py'+ ' > /dev/null 2>&1')
        # Give it a second to make sure that code is written.
        time.sleep(0.3)
        # Something like cc -O -o MACS_sample_kidney.out MACS_sample_kidney.c -lm

        shellcommand = ['cc', '-O', '-o', out_filename,
                        c_filename, '-lm']
        shellcommandstr = 'mcrun -c -n 10 --param=dummy_params.txt --dir=dummy_kidney ' + instr_filename+ ' > /dev/null 2>&1'
        # shellcommandstr='mcrun -c '+instr_filename
        if verbose is True:
            print('#################')
            print('\nStarting compilation of sample kidney geometry.\n')
        p = subprocess.Popen(shellcommandstr, stdout=subprocess.PIPE, shell=True)
        (output, err) = p.communicate()
        p_status = p.wait()
        if verbose is True:
            print('Compilation of sample kidney geometry successful.\n')
            print('#################\n')
        # Delete the dummy directory
        shutil.rmtree("dummy_kidney")
        os.chdir(original_directory)
        self.modified_kidney_flag = 0
        # Wait for this to finish.
        return 1

    def compileMonochromator(self,verbose=True):
        """Compiles monochromator McStas files.
		"""
        # First generate c code, need to actually go into the directories to excecute these operations
        instr_dir = self.instr_file_directory
        instr_filename = 'MACS_monochromator.instr'
        c_filename = instr_filename.replace('.instr', '.c')
        out_filename = instr_filename.replace('.instr', '.out')
        original_directory = self.cwd
        os.chdir(instr_dir)
        shellcommandstr = 'mcrun -c -n 10 --param=dummy_params_mono.txt --dir=mono_dummy_dir ' + instr_filename+ ' > /dev/null 2>&1'

        p = subprocess.Popen(shellcommandstr, stdout=subprocess.PIPE, shell=True)
        exec(open("generate_MACS_parts_mcstasscript.py").read())

        # Give it a moment to make sure that code is written.
        time.sleep(0.5)

        # shellcommandstr= 'mcrun -c'+instr_filename
        if verbose is True:
            print('#################')
            print('\nStarting compilation of monochromator.\n')
        # shellcommandstr='mcrun -c '+instr_filename
        p = subprocess.Popen(shellcommandstr, stdout=subprocess.PIPE, shell=True)
        (output, err) = p.communicate()
        p_status = p.wait()
        if verbose is True:
            print('Compilation of monochromator geometry successful.\n')
            print('#################\n')
        # Remove the dummy directory
        shutil.rmtree("mono_dummy_dir")
        os.chdir(original_directory)
        return 1

    def write_mono_paramfile_from_current_params(self):
        """Writes the parmeter text file for monochromator simulation
		"""
        cwd = self.cwd
        try:
            if not os.path.exists(cwd + '/' + self.exptName + '/param_files_monochromator/'):
                os.mkdir(cwd + '/' + self.exptName + '/param_files_monochromator/')
        except Exception as e:
            pass
        self.mono_param_dir = self.exptdir + '/param_files_monochromator/'
        out_name = self.mono_param_dir + 'mono_params_ei' + '{:.2f}'.format(
            self.monochromator.Ei) + '_beta1_' + '{:.2f}'.format(
            self.monochromator.beta_1) + '_beta2_' + '{:.2f}'.format(
            self.monochromator.beta_2) + '_sample_diameter_d_' + '{:.4f}'.format(self.sample.sample_diameter_d) + '.txt'

        # Correctly format the parameter file with the current parameters.

        output_str = 'EM=' + str(self.monochromator.Ei) + '\nEF_all=' + str(self.kidney.Ef) + \
                     '\nHF=1\nVF=1\nsample_diameter_d=' + str(self.sample.sample_diameter_d) + \
                     '\nbeta_1=' + f"{self.monochromator.beta_1:.2f}" + '\nbeta_2=' + f"{self.monochromator.beta_2:.2f}" \
                     + '\nCPF=0\nMPL=6.06\nMPD=0.775\nAPE_h=0.35\nAPE_v=0.35\nmisalign_mono_deg=0.15\nkidney_angle=0\nDIRDEV=0\nDIVSOU=3.0\nL0_delta=-1.06\nL1_delta=0.0\nmon_t=0.0\nmon_e=0.0\nmonrot_delta=0\nwrite_virtual_out=1'
        param_file = open(out_name, 'w')
        param_file.write(output_str)
        param_file.close()
        return out_name

    def write_kidney_paramfile_from_current_params(self):
        """Write the parameter text file for a kidney simulation
		"""
        orig_dir = self.cwd
        if not os.path.exists(orig_dir + '/' + self.exptName + '/param_files_kidney/'):
            os.mkdir(orig_dir + '/' + self.exptName + '/param_files_kidney/')
        self.kidney_param_dir = self.exptdir + '/param_files_kidney/'

        # Format the string with the most important information
        out_name_prefix = self.exptName + '_kidney_params_Ei_' + str(
            round(self.monochromator.Ei, 2)) + '_kid_angle_' + str(
            round(self.kidney.kidney_angle, 4)) + '_A3_angle_' + str(self.A3_angle) + '_Ef_' + str(
            round(self.kidney.Ef, 2)) + '.txt'
        out_name_prefix = out_name_prefix.replace('-', 'm')
        out_name = self.kidney_param_dir + out_name_prefix
        param_file = open(out_name, 'w')
        param_file.write('A3_angle=' + str(self.A3_angle) + ' \n')
        param_file.write('kidney_angle=' + str(self.kidney.kidney_angle) + ' \n')
        param_file.write('EM=' + str(self.monochromator.Ei) + ' \n')
        param_file.write('EF_all=' + str(self.kidney.Ef) + ' \n')
        param_file.write('HF=1 \n')
        param_file.write('VF=1 \n')
        param_file.write('sample_diameter_d=' + str(self.sample.sample_diameter_d) + ' \n')
        param_file.write('beta_1=' + str(self.monochromator.beta_1) + ' \n')
        param_file.write('beta_2=' + str(self.monochromator.beta_2) + ' \n')
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
        # New params to handle sample multiple scattering
        param_file.write('max_sample_scatter_N=' + f"{self.sample.max_scattering_order}\n")
        param_file.write('sample_scatter_N=' + f"{self.sample.scattering_order}")

        param_file.close()
        return out_name

    def runMonoScan(self, Ei_set=False, Ef_set=False, kidney_set=False, A3_set=False, beta_1_set=False,
                    beta_2_set=False,verbose=False):
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
        # Check if an output directory exists for monochromator scans
        cwd = self.cwd
        if not os.path.exists(self.exptdir + '/Monochromator_simulations/'):
            try:
                os.mkdir(cwd + '/' + self.exptName + '/Monochromator_simulations/')
            except:
                # Sometimes two processes try to do this at the same time.
                pass
        # Assign relevant parameters
        if Ei_set is False:
            Ei_set = self.monochromator.Ei
        if Ef_set is False:
            Ef_set = self.kidney.Ef
        if kidney_set is False:
            kidney_set = self.kidney.kidney_angle
        if A3_set is False:
            A3_set = self.A3_angle
        if beta_1_set is False:
            dmbt = self.sample.sample_diameter_d
            if dmbt < 5e-3:
                dmbt = 5e-3  # Minimum allowed before interpolation gets wonky.
            beta_1_set, beta_2_set = self.monochromator.calc_betas(ei=Ei_set, dmbt=self.sample.sample_diameter_d)
            self.monochromator.beta_1 = beta_1_set
        if beta_2_set is False:
            # Calculate the beta angles.
            dmbt = self.sample.sample_diameter_d
            if dmbt < 5e-3:
                dmbt = 5e-3  # Minimum allowed before interpolation gets wonky.
            beta1_1_set, beta_2_set = self.monochromator.calc_betas(ei=Ei_set, dmbt=self.sample.sample_diameter_d)
            self.monochromator.beta_2 = beta_2_set

        # Generate a parameter file for the current monochromator configuration
        param_fname = self.write_mono_paramfile_from_current_params()
        # Need to add the instrument directory for the imports to be recognized
        os.chdir(cwd + '/' + self.exptName + '/Instrument_files/')
        # Check if the file already exists. If it does, do not run the simulation.
        mono_file_dat_start = 'E' + '{:.2f}'.format(
            Ei_set) + 'meV_HF1_VF1_Sample' + f"{self.sample.sample_diameter_d:.3f}" + '_' + \
                              'b1_' + '{:.2f}'.format(beta_1_set) + '_b2_' + '{:.2f}'.format(beta_2_set) + '*'
        try:
            # print("Checking for: "+mono_file_dat_start)
            if len(glob.glob(self.instr_file_directory + mono_file_dat_start)) == 0:
                # print(mono_file_dat_start+" is not found in \n"+str(glob.glob(mono_file_dat_start)))
                mono_dir = 'Ei_' + f"{Ei_set:.3f}" + '_beta1_' + f"{beta_1_set:.2f}" \
                           + '_beta2_' + f"{beta_2_set:.2f}" + '_n_' + f"{self.n_mono:2e}" + '_sample_diam_' + str(
                    self.sample.sample_diameter_d)
                # Run simulation and wait for it to end.

                shellcommandstr = 'mcrun -d ' + mono_dir + ' -n ' + str(self.n_mono) + \
                                  ' MACS_monochromator.instr EM=' + str(Ei_set) + ' EF_all=' + str(
                    Ef_set) + ' HF=1 VF=1 sample_diameter_d=' + str(
                    self.sample.sample_diameter_d) + ' beta_1=' + f"{beta_1_set:.2f}" + \
                                  ' beta_2=' + f"{beta_2_set:.2f}" + ' misalign_mono_deg=0.15 CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 ' + \
                                  'kidney_angle=' + str(
                    kidney_set) + ' DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 mon_e=0.0 monrot_delta=0 write_virtual_out=1' + \
                                  '> /dev/null 2>&1'
                # print('Passing the following to mcstas:')
                # print(shellcommandstr)
                p = subprocess.Popen(shellcommandstr, stdout=subprocess.PIPE, shell=True)
                (output, err) = p.communicate()
                p_status = p.wait()
                # Move the output folder to the Monochromator_simulations directory
                shutil.move(cwd + "/" + self.exptName + "/Instrument_files/" + mono_dir,
                            cwd + '/' + self.exptName + '/Monochromator_simulations/')
                # Delete the old simulation.
                os.system('rm -rf ' + str(cwd + "/" + self.exptName + mono_dir))
                time.sleep(0.1)
                os.chdir(cwd)
                # Iterate through mono_dir and add the data file outputs to the main instrument directory
                # Get the name of the monochromator data file
                # mono_file_dat_start='E'+'{:.2f}'.format(self.monochromator.Ei)+'meV_HF1_VF1*'
                # the location of the monochromator file
                mono_dat_dir = cwd + '/' + self.exptName + '/Monochromator_simulations/' + mono_dir + '/'
                mono_file_dat_name = glob.glob(mono_dat_dir + mono_file_dat_start)[0]
                # Move the file to the instrument directory
                if not os.path.exists(self.instr_file_directory + mono_file_dat_name):
                    shutil.move(mono_file_dat_name, self.instr_file_directory)
                    time.sleep(1)
            else:
                # print('Using previously run monochromator simulation that is already in the directory:\n'+str(glob.glob(mono_file_dat_start)[0]))
                os.chdir(cwd)
        except Exception as e:
            if verbose==True:
                print('Warning: Execution error in monochromator scan. ')
                print(e)
            else:
                pass
        return 1

    def runKidneyScan(self, append_data_matrix=True, Ei_set=False, Ef_set=False, kidney_set=False, A3_set=False,
                      beta_1_set=False, beta_2_set=False,
                      scan_suffix=False, PTAI_det=3):
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
        if Ei_set == False:
            Ei_set = self.monochromator.Ei
        if Ef_set == False:
            Ef_set = self.kidney.Ef
        if kidney_set == False:
            kidney_set = self.kidney.kidney_angle
        if A3_set == False:
            A3_set = self.A3_angle
        if beta_1_set is False:
            dmbt = self.sample.sample_diameter_d
            if dmbt < 5e-3:
                dmbt = 5e-3  # Minimum allowed before interpolation gets wonky.
            beta_1_set, dummy = self.monochromator.calc_betas(ei=Ei_set, dmbt=self.sample.sample_diameter_d)
            self.monochromator.beta_1 = beta_1_set
        if beta_2_set is False:
            # Calculate the beta angles.
            dmbt = self.sample.sample_diameter_d
            if dmbt < 5e-3:
                dmbt = 5e-3  # Minimum allowed before interpolation gets wonky.
            dummy, beta_2_set = self.monochromator.calc_betas(ei=Ei_set, dmbt=self.sample.sample_diameter_d)
            self.monochromator.beta_2 = beta_2_set

        self.monochromator.Ei = Ei_set
        self.kidney.Ef = Ef_set
        self.A3_angle = A3_set

        orig_dir = self.cwd
        # Make an output directory for the results
        if not os.path.exists(self.exptdir + '/Kidney_simulations/'):
            os.mkdir(orig_dir + '/' + self.exptName + '/Kidney_simulations/')
            self.kidsim_dir = orig_dir + '/' + self.exptName + '/Kidney_simulations/'
        param_fname = self.write_kidney_paramfile_from_current_params()
        # Change to the instrument directory
        os.chdir(orig_dir + '/' + self.exptName + '/Instrument_files/')

        # If the scan was based off of an ng0 file need to add a string
        if self.base_ng0 is False:
            ng0_string = ''
        else:
            # noinspection PyTypeChecker
            ng0_string = '_' + self.base_ng0
        # Put this in a ramdisk to solve disk access problems large numbers of files for large simulations.
        kidney_output_dir = self.exptName + ng0_string + "_kidney_angle_" + "{:.4f}".format(kidney_set) + '_Ei_' + \
                            '{:.4f}'.format(Ei_set) + '_Ef_' + '{:.4f}'.format(Ef_set) + '_A3_angle_' + '{:.4f}'.format(
            A3_set) + \
                            '_sample_diameter_d_' + '{:.4f}'.format(self.sample.sample_diameter_d)
        # Mcstas does not like minus signs or . in directory names
        kidney_output_dir = kidney_output_dir.replace('-', 'm')
        kidney_output_dir = kidney_output_dir.replace('.', 'p')
        # Mount the ramdisk if it has not been mounted yet.
        if not os.path.ismount(self.ramdisk_dir):
            self.mount_ramdisk()
        kidney_output_dir = self.ramdisk_dir + '/' + kidney_output_dir
        # Check if the current simulation already exists in the data matrix.
        if type(self.data.data_matrix) == bool:
            # Not instantiated, scan definitely does not exist.
            scan_exists = False
        else:
            # Check if a row exits with the same Ei, Ef, A3, kidney_angle. That should cover the case of running the same scan.
            A3 = self.data.data_matrix['A3'].tolist()
            Ei = self.data.data_matrix['Ei'].tolist()
            Ef = self.data.data_matrix['Ef'].tolist()
            kidney = self.data.data_matrix['Kidney'].tolist()
            # Add a rounding error tolerance to each of these
            A3 = np.around(A3, 3)
            Ei = np.around(Ei, 3)
            Ef = np.around(Ef, 3)
            kidney = np.around(kidney, 3)
            # Turn these into a single numpy array where each row is a configuration
            config_mat = np.concatenate((A3[:, None], Ei[:, None], Ef[:, None], kidney[:, None]), axis=1)
            this_config = [np.around(A3_set, 3), np.around(Ei_set, 3), np.around(Ef_set, 3), np.around(kidney_set, 3)]
            if this_config in config_mat.tolist():
                scan_exists = True
            else:
                scan_exists = False

        if not scan_exists:
            # Folder does not exist, run the simulation
            # Run simulation and wait for it to end.
            shellcommandstr = 'mcrun -d ' + kidney_output_dir + ' -n ' + str(self.n_sample) + ' ' + \
                              self.instr_main_file.split('/')[-1] + ' A3_angle=' + str(A3_set) + ' kidney_angle=' + str(
                kidney_set) + ' EM=' + str(Ei_set) + ' EF_all=' + str(Ef_set) + \
                              ' HF=1 VF=1 sample_diameter_d=' + \
                              str(self.sample.sample_diameter_d) + ' beta_1=' + f"{beta_1_set:.2f}" + \
                              ' beta_2=' + f"{beta_2_set:.2f}" + \
                              ' CPF=0 MPL=6.06 MPD=0.775 APE_h=0.35 APE_v=0.35 misalign_mono_deg=0.15 DIRDEV=0 DIVSOU=3.0 L0_delta=-1.06 L1_delta=0.0 mon_t=0.0 ' + \
                              'mon_e=0.0 monrot_delta=0.0 slit_h=0.2 slit_v=0.2 resolution_mode=0 res_radius=0.01 res_height=0.03 repeat_count=1 E0_resolution=0 dE_resolution=1'
            shellcommandstr += '> /dev/null 2>&1'
            # print('Running the following command: ')
            p = subprocess.Popen(shellcommandstr, stdout=subprocess.PIPE, shell=True)
            (output, err) = p.communicate()
            p_status = p.wait()
            # print("Output")
            # print(output)
            # print("Err")
            # print(err)
            # Scan is run at this point and output files are in the kidney_output_dir
            # Append the result to the data matrix if this is a single scan. Else wait to do this until later.
            # Either way write the csv file
            if scan_suffix == False:
                suffix = ''
            else:
                suffix = scan_suffix
            time.sleep(0.05)  # some file io issues if we go too fast.
            csvname = self.data.scan_to_csv(kidney_output_dir, file_suffix=suffix, PTAI_det=PTAI_det)
            # if append_data_matrix is True:
            # self.data.load_data_matrix_from_csv(csvname)
            time.sleep(0.05)
            # Delete the directory after this
            if self.preserve_kidney_scan_files == False:
                while os.path.exists(kidney_output_dir):
                    try:
                        # os.system('rm -rf \"'+str(kidney_output_dir)+'\"')
                        shutil.rmtree(kidney_output_dir)
                    except Exception as e:
                        #print('Warning: \n' + str(e))
                        time.sleep(0.01)
            if self.preserve_kidney_param_files == False:
                while os.path.exists(param_fname):
                    try:
                        # os.system('rm \"'+param_fname+'\"')
                        os.remove(param_fname)
                    except Exception as e:
                        pass
                        #print('Warning when trying to remove paramter file:')
                        #print(e)
            os.chdir(orig_dir)

        else:
            if self.preserve_kidney_param_files == False:
                while os.path.exists(param_fname):
                    try:
                        # os.system('rm '+param_fname)
                        os.remove(param_fname)
                    except Exception as e:
                        pass
                        #print('Warning when trying to remove paramter file:')
                        #print(e)
            #print('Found previous identical kidney simulation. If this is a mistake, ')
            #print('delete the scan from the data matrix and try again. ')
            #print(kidney_output_dir)
            os.chdir(orig_dir)
        # Delete the parameter file unless otherwise specified.
        return csvname

    def runKidneyScan_scripting(self, A3, kidney_angle, Ei, Ef, beta1=False, beta2=False, append_data_matrix=True,
                                scan_suffix=False, PTAI_det=3):
        # Run the simulation at this point
        try:
            self.runKidneyScan(append_data_matrix=append_data_matrix, Ei_set=Ei, Ef_set=Ef, kidney_set=kidney_angle,
                               A3_set=A3, beta_1_set=beta1, beta_2_set=beta2, scan_suffix=scan_suffix,
                               PTAI_det=PTAI_det)
        except Exception as e:
            pass
            #print(f"WARNING: {e}")
        return 1

    def runMonoScan_scripting(self, Ei, Ef, beta1, beta2):
        # Run the simulation at this point
        self.runMonoScan(Ei_set=Ei, Ef_set=Ef, kidney_set=self.kidney.kidney_angle, A3_set=self.A3_angle,
                         beta_1_set=beta1, beta_2_set=beta2)
        return 1

    def script_scan(self, A3_list, Ei_list=False, num_threads=1, scan_title=False,verbose=False):
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
        if scan_title == False:
            suffix = ''
        else:
            suffix = scan_title
        if type(Ei_list) == bool:
            Ei_list = [self.monochromator.Ei]
        elif type(Ei_list) == float or type(Ei_list) == int:
            Ei_list = np.array([Ei_list])
        elif type(Ei_list) == list or type(Ei_list) == np.ndarray:
            # This is good they did it right
            Ei_list = np.array(Ei_list)
        else:
            print('Warning- Ei input in a wrong format. Using ' + str(self.monochromator.Ei) + ' meV')
            Ei_list = np.array([self.monochromator.Ei])
        # Mount the ramdisk
        self.unmount_ramdisk()
        self.mount_ramdisk()
        # Run the relevant monochromator scans.

        if num_threads > 1:
            if verbose is True:
                print('Running these Ei values:' + str(Ei_list))
            Parallel(n_jobs=num_threads, backend="threading")(
                delayed(self.runMonoScan_scripting)(Ei, self.kidney.Ef, False, False) for Ei in Ei_list)
        else:
            for Ei in Ei_list:
                self.monochromator.Ei = Ei
                self.runMonoScan()
        # Get total number of configurations:
        tot_configs = 0
        for energy in Ei_list:
            kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution, energy)
            num_angles_E = len(kid_angle_list) * len(A3_list)
            tot_configs += num_angles_E
        # Generate kidney angles
        if num_threads == 1:
            for e_index in tqdm(range(len(Ei_list)), desc='Total Scans'):
                energy = Ei_list[e_index]
                kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution, energy)
                # Simple case first, num_threads=1
                for k_index in tqdm(range(len(kid_angle_list)), desc='Kidney Loop'):
                    kid_angle = kid_angle_list[k_index]
                    for a3_angle in A3_list:
                        self.runKidneyScan_scripting(a3_angle, kid_angle, energy, self.kidney.Ef,
                                                     self.monochromator.beta_1, self.monochromator.beta_2,
                                                     scan_suffix=suffix)

        if num_threads > 1 or num_threads == -1:
            # Now do the case of parallelized
            for e_index in tqdm(range(len(Ei_list)), desc='Total Scans'):
                energy = Ei_list[e_index]
                kid_angle_list = self.kidney.generate_kidney_positions(self.kidney_angle_resolution, energy)
                num_operations = len(kid_angle_list) * len(Ei_list)
                fname_list = []

                for k_index in tqdm(range(len(kid_angle_list)), desc='Ei=' + str(energy) + ' meV'):
                    kid_angle = kid_angle_list[k_index]
                    kidsuffix = suffix + '_kidney_' + str(round(kid_angle, 3)) + '_Ei_' + str(
                        round(energy, 2)) + '_Ef_' + str(round(self.kidney.Ef, 2))
                    # Parallelization happens here
                    # A3,kidney_angle,Ei,Ef,beta1,beta2,append_data_matrix=True

                    Parallel(n_jobs=num_threads, backend="threading")(delayed(self.runKidneyScan_scripting) \
                                                                          (A3_list[i], kid_angle, energy,
                                                                           self.kidney.Ef, False, False, True,
                                                                           kidsuffix) \
                                                                      for i in range(len(A3_list)))
                    # After each kidney angle combine the csv like in real MACS
                    filename = self.data.combine_csv_scans(preserve_old=False, flagstr=kidsuffix)
                    self.data.load_data_matrix_from_csv(csv_file=filename)
                    Ei = np.mean(self.data.data_matrix['Ei'].tolist())
                    Ef = np.mean(self.data.data_matrix['Ef'].tolist())
                    numA3 = np.size(self.data.data_matrix['A3'].tolist())
                    kid = np.mean(self.data.data_matrix['Kidney'].tolist())
                    fstr = f"Ei_{Ei:.2f}_Ef{Ef:.2f}_numA3_{numA3:3d}_kid_{kid:.2f}_".replace(' ', '0')
                    self.data.write_data_to_ng0(filename='McStas_' + self.exptName + '_' + fstr + scan_title + '.ng0')
                    fname_list.append(filename)

                fname_list = []
            # Now create a combined version of all of the csv files.
            totfname = self.data.combine_csv_scans(preserve_old=True, flagstr=suffix)
            # Load this file.
            self.data.load_data_matrix_from_csv(totfname)
        # Unmount the ramdisk safely.
        if self.preserve_kidney_scan_files == False:
            self.unmount_ramdisk()
        # Return to main directory.
        os.chdir(self.cwd)
        return 1

    def script_powder_scan(self, Ei_list=False, num_threads=1, scan_title=False):
        """
		Provided with a list of A3 angles, a kidney angle resolution, optionally a list
			of incident energies, simulates a MACS scan over the full range.
			Num-threads parameter is for parallelization.
			Simply just calls script_scan but fixes A3 to 0

		:param Ei_list: List of incident energies to run.
		:type Ei_list: list
		:param num_threads: If parallelization is being used, number of threads to use. 
		:type num_threads: int
		:param scan_title: Name assosciated with this particular scan. 
		:type scan_title: str
		"""
        A3_list = np.array([0.0])
        self.script_scan(A3_list, Ei_list=False, num_threads=num_threads, scan_title=scan_title)
        return 1

    def simulate_ng0(self, ng0_file, in_scan=False, n_threads=1):
        """
		Provided an ng0 file or the path to an ng0 file, emulates a scan identically with the following parameters:\n
			A3, Ei, Ef, beta1, beta1, kidney_angle, PTAI\n
			Saves the result to its own ng0 file if not part of a larger scan. The result should match the input ng0 file 
			point by point when viewed using MSlice or the built in tools.

		:param ng0_file: Input file or path to file. Must be a MACS ng0 file. 
		:type ng0_file: str
		"""

        # Mount the ramdisk
        self.mount_ramdisk()
        # Directly simulates an input ng0 file from start to finish.
        data, column_names, file_params = import_ng0(ng0_file)
        print('Emulating scan from ' + str(ng0_file.split('/')[-1]))
        A3_list = np.array(data[:, file_params['Columns'].index('A3')]).astype(float)
        Ei_list = np.array(data[:, file_params['Columns'].index('Ei')]).astype(float)
        Ef_list = np.array(data[:, file_params['Columns'].index('Ef')]).astype(float)
        beta_1_list = np.array(data[:, file_params['Columns'].index('Beta1')]).astype(float)
        beta_2_list = np.array(data[:, file_params['Columns'].index('Beta2')]).astype(float)
        kid_list = np.array(data[:, file_params['Columns'].index('Kidney')]).astype(float)
        ptai_det = np.array(data[:, file_params['Columns'].index('PTAI')]).astype(int)
        self.data.PTAI_det = ptai_det[0]
        self.beta_1 = beta_1_list[0]
        self.beta_2 = beta_2_list[0]
        # Check if the file is in a directory
        ng0_file = ng0_file.split('/')[-1]
        self.base_ng0 = ng0_file
        # First run the monochromator jobs
        if n_threads == 1 or in_scan == True:
            for i in range(len(A3_list)):
                self.runMonoScan_scripting(Ei_list[i], Ef_list[i], beta_1_list[i], beta_2_list[i])
            # The run the kidney / A3 jobs
            for i in range(len(A3_list)):
                self.runKidneyScan_scripting(A3_list[i], kid_list[i], Ei_list[i], Ef_list[i], beta_1_list[i],
                                             beta_2_list[i], append_data_matrix=True,
                                             scan_suffix='_' + ng0_file.split('/')[-1], PTAI_det=ptai_det[0])
        if n_threads > 1 and in_scan == False:
            # Parallelize this process, not necessary for monochromator
            for i in range(len(A3_list)):
                self.runMonoScan_scripting(Ei_list[i], Ef_list[i], beta_1_list[i], beta_2_list[i])
            Parallel(n_jobs=n_threads, backend="threading")(delayed(self.runKidneyScan_scripting) \
                                                                (A3_list[i], kid_list[i], Ei_list[i], Ef_list[i],
                                                                 beta_1_list[i], beta_2_list[i], True,
                                                                 '_' + ng0_file.split('/')[-1]) for i in
                                                            range(len(A3_list)))
        # Safely unmount ramdisk.
        if in_scan == False and self.preserve_kidney_scan_files == False:
            self.unmount_ramdisk()
        else:
            # Instead just delete the files in the ramdisk so as to not interrupt other scans.
            x = 1
        # Combine the relevant data matrices into a single file
        self.data.combine_csv_scans(preserve_old=False, flagstr='_' + ng0_file.split('/')[-1])
        if in_scan == False:
            # Not parellelized, may write this data matrix to a matching ng0 file.
            csv_file = '_' + ng0_file.split('/')[-1] + \
                       self.data.csv_name
            self.data.load_data_matrix_from_csv(csv_file)
            self.data.write_data_to_ng0(filename=ng0_file.split('/')[-1].replace('.ng0', '_mcStas.ng0'))
        return 1

    def simulate_ng0dir(self, ng0_dir, n_threads=1):
        """
		Provided a director of only ng0 files, emulates all scans identically with the following parameters:\n
			A3, Ei, Ef, beta1, beta1, kidney_angle, PTAI\n
			Saves the result to its own ng0 file if not part of a larger scan. The result should match the input ng0 file 
			point by point when viewed using MSlice or the built in tools.

		:param ng0_dir: List of input files or path to files. Must be MACS ng0 files. 
		:type ng0_dir: list of strs
		:param n_threads: If parallelization is being used, number of threads to use.
		:type n_threads: int
		"""
        # First mount ramdisk
        self.mount_ramdisk()

        # They may also be in folders, but nothing else should be in this folder.
        file_list = []
        cwd = os.getcwd()
        for (dirpath, dirnames, filenames) in os.walk(ng0_dir):
            for file in filenames:
                if '.ng0' in file:
                    file_list.append(file)
        if n_threads == 1:
            for file in file_list:
                self.simulate_ng0(file, in_scan=False)
        else:
            # Need to do monochromator jobs FIRST, then kidney
            ei_ef_b1_b2_list = []
            ptai_list = []
            for f_index in tqdm(range(len(file_list)), desc='Ng0 Files'):

                ng0_file = file_list[f_index]
                # Need to do monochromator jobs FIRST, then kidney
                # Accumulate all Ei, beta1, beta2 combinations and run.
                data, column_names, file_params = import_ng0(ng0_dir + ng0_file)
                # A3_list = np.array(data[:,file_params['Columns'].index('A3')]).astype(float)
                Ei_list = np.array(data[:, file_params['Columns'].index('Ei')]).astype(float)
                Ef_list = np.array(data[:, file_params['Columns'].index('Ef')]).astype(float)
                beta_1_list = np.array(data[:, file_params['Columns'].index('Beta1')]).astype(float)
                beta_2_list = np.array(data[:, file_params['Columns'].index('Beta2')]).astype(float)
                kid_list = np.array(data[:, file_params['Columns'].index('Kidney')]).astype(float)
                ptai_det = np.array(data[:, file_params['Columns'].index('PTAI')]).astype(int)
                for i in range(len(Ei_list)):
                    Ei = Ei_list[i]
                    Ef = Ef_list[i]
                    b1 = beta_1_list[i]
                    b2 = beta_2_list[i]
                    setting = [Ei, Ef, b1, b2]
                    if setting not in ei_ef_b1_b2_list:
                        ei_ef_b1_b2_list.append(setting)
            print('Monochromator List to simulate:')
            for config in ei_ef_b1_b2_list:
                print(f"Ei={config[0]}, Ef={config[1]}, beta1={config[2]}, beta2={config[3]}")
            # Run all of the relevant monochromator jobs
            Parallel(n_jobs=n_threads, backend="threading")(
                delayed(self.runMonoScan_scripting)(ei_ef_b1_b2_list[i][0], ei_ef_b1_b2_list[i][1],
                                                    ei_ef_b1_b2_list[i][2],
                                                    ei_ef_b1_b2_list[i][3]) for i in range(len(ei_ef_b1_b2_list)))
            Parallel(n_jobs=n_threads, backend="threading")(
                delayed(self.simulate_ng0)(cwd + '/' + ng0_dir + file_list[i], in_scan=True) for i in
                range(len(file_list)))
            # After parellel jobs are done, iterate through the files and create matching ng0s as the measurements, but McStas

            for ng0_file in file_list:
                csv_file = '_' + ng0_file.split('/')[-1] + \
                           self.data.csv_name
                self.data.load_data_matrix_from_csv(csv_file)
                self.data.write_data_to_ng0(filename=ng0_file.split('/')[-1].replace('.ng0', '_mcStas.ng0'))
        # At this point generate the data matrix. all files should be in the ramdisk. Information cannot be allowed to sit in the ramdisk.
        return 1

    def resmat(self,h,k,l,E,sampleFrame=True,gen_plot=False,verbose=False,figdir="Calculated_ellipsoid_pngs/"):
        """
        Using a previously tabulated list of resolution ellipsoid calculations, returns the closest resolution ellipsoid to the input h,k,l,E point. 
        More granular execution of this method is available in the scripting subclass, but for almost all use cases this should be enough. The only configurations that have been
        pre-calculated are the double-focusing Ef=3.7 and Ef=5.0 modes. There are some minor bugs, such as a few missing ellipsoids where one would expect one and some poorly fitted ellipsoids at low momentum transfers,
        but overall it behaves well. The ellipsoid is always returned in the (Qx, Qz, E) frame, in units of Ang^-1, Ang^-1, meV. This function also returns the same reslevant FWHM's, 
        which is what most users probably want. 

        :param h: Miller h index. Non-integer values allowed.
        :type h: float, required
        :param k: Miller k index.
        :type k: float, required
        :param l: Miller l index.
        :type l: float, required
        :param E: Energy transfer (meV)
        :type E: float, required
        :param gen_plot: Flag to trigger creation of figure summarizing the MACS resolution ellipsoid.
        :type gen_plot: bool, optional.
        :param sampleFrame: If true, the input sample coordinate system of the virtualMACS object will be used rather than the Qx, Qz frame in Ang^-1. 
        :type sampleFrame: bool, optional
        :param verbose: Flag to print resoultion ellipsoid information to terminal.
        :type verbose: bool, optional.
        :param calc_mode: There are three options, "default", "load_cov", and "Covariance". Users should only use "load_cov", or "default" if they have the correct csv files available. "Covariance" was a developer option, and returns just the covariance matrix.
        :type calc_mode: str, optional.
        :return: M, M_diag, Q_hkw. The resolution matrix, the diagonal elements / fwhm in Qx, Qz, E, and the (Qx, Qz, E) position of the closest tabulated point.
        :rtype: np.ndarray, np.ndarray, np.ndarray
        """ 
        if sampleFrame is True:
            macsobj = self
        else: 
            macsobj=False
        M,M_diag,Q_hkw = resfunc.macs_resfunc(h,k,l,E,self.kidney.Ef,macsobj=macsobj,gen_plot=gen_plot,verbose=verbose,calc_mode="load_cov",figdir=figdir)
        return M,M_diag,Q_hkw

    def load_res_fwhm_interp_objects(self):
        """
        Using a previously tabulated list of resolution ellipsoid calculations, returns the closest resolution ellipsoid to the input h,k,l,E point. 
        This variant uses a linear interpolation between the tabulated points to quickly get the FWHM in the principle axes, Qx, Qz, E, in (Ang^-1, Ang^-1, meV)
        The returned objects are scipy interpolators, which take input such as 
            - dE = interp_dE(h,k,l,E)
        The interpolation objects is a RegularGridInterpolator, and also accepts np.ndarrays of shape (N,4), where N is the number of points. 

        :return: interp_dQx, interp_dQz, interp_dE, scipy.interpolate.RegularGridInterpolator obejcts that return the macs Bragg widhths in the respective directions for arbitrary h,k,l,E, for the Ef=3.7 or Ef=5.0 settings.
        :rtype: scipy.interpolate.RegularGridInterpolator, scipy.interpolate.RegularGridInterpolator, scipy.interpolate.RegularGridInterpolator 
        """ 
        interp_dir = str(files("pyMACS")) + '/scripting/interp_fwhm/'
        if np.min(np.abs(np.array([5.0,3.7])-self.kidney.Ef))>0.1:
            #Check if the instrumental configruation is valid.
            print("Macs Ef hasn't been tabulated. Use Ef=3.7 or Ef=5.0")
            return 0,0,0
        if np.abs(5.0-self.kidney.Ef)<0.1:
            f_dE = interp_dir+"MACS_Ef_5p0_interp_dE.pck"
            f_dQx = interp_dir+"MACS_Ef_5p0_interp_dQx.pck"
            f_dQz = interp_dir+"MACS_Ef_5p0_interp_dQz.pck"
        if np.abs(3.7-self.kidney.Ef)<0.1:
            f_dE = interp_dir+"MACS_Ef_3p7_interp_dE.pck"
            f_dQx = interp_dir+"MACS_Ef_3p7_interp_dQx.pck"
            f_dQz = interp_dir+"MACS_Ef_3p7_interp_dQz.pck"
        with open(f_dQx, "rb") as input_file:
            interp_dQx = pickle.load(input_file)
        with open(f_dQz, "rb") as input_file:
            interp_dQz = pickle.load(input_file)
        with open(f_dE, "rb") as input_file:
            interp_dE = pickle.load(input_file)
        return interp_dQx,interp_dQz,interp_dE

    