#More complex example of pyMACS usage

import sys
import os
import numpy as np
cwd = os.getcwd()
#Add the directory of the module to the path.
sys.path.append('/'.join(cwd.split('/')[0:-1]))
from virtualMACS import virtualMACS
import mcstasscript as ms

macs_instr = virtualMACS('cri3_experiment',cifName='CrI3.cif',useOld=False)
macs_instr.sample.formula_weight=432.7
numthreads=8

'''

This is a more complex example of the usage of the pyMACS interface, which 
simulates a real experiment from start to finish. The system of choice is 
CrI3, which has a well defined spin hamiltonian. The system was simulated using
SpinW, with the spin interactions defined by the following work 

https://journals.aps.org/prx/abstract/10.1103/PhysRevX.8.041028

The sample is assumed to be larger than is realistic, to give appreciable intensity
from spin waves. 

'''
#Going to make our sample artifically big to increase count rate. 
macs_instr.sample.sample_widx=0.01
macs_instr.sample.sample_widy=0.01
macs_instr.sample.sample_widz=0.01

macs_instr.monochromator.Ei = 5.0
macs_instr.monochromator.Ef = 5.0
macs_instr.sample.cif2lau()

#Sample is aligned in the HK0 plane
macs_instr.sample.orient_u=[1,0,0]
macs_instr.sample.orient_v=[-1,2,0]
macs_instr.sample.project_sample_realspace()
print('Real Space projection of lattice vectors [ax,ay,az; bx,by,bz;cx,cy,cz]')
print(macs_instr.sample.labframe_mat)
print('')
print('Structure factors:')
print('|F(110)|^2 = '+str(round(macs_instr.sample.fetch_F_HKL(1,1,0)[3],4))+' barn')
print('|F(100)|^2 = '+str(round(macs_instr.sample.fetch_F_HKL(1,0,0)[3],4))+' barn')
print('|F(1-10)|^2 = '+str(round(macs_instr.sample.fetch_F_HKL(1,-1,0)[3],4))+' barn')
print('|F(001)|^2 = '+str(round(macs_instr.sample.fetch_F_HKL(0,0,1)[3],4))+' barn')

print('sigma_abs ='+str(macs_instr.sample.rho_abs)+' barn/unit cell')
print('sigma_inc ='+str(macs_instr.sample.sigma_inc)+' barn/unit cell')

#MACS can't actually access the full spinwave spectrum of this system, we will only 
# look at energy transfers below 12 meV. Ei_max = 17 meV

# In this example, the sample has three different scattering processes. 
# Bragg diffraction, incoherent scattering, and spin waves. 

scattering_def = ms.McStas_instr("scattering_definition",checks=False)
inc_scatter = scattering_def.add_component("inc_scatter","Incoherent_process")
inc_scatter.sigma=macs_instr.sample.sigma_inc
inc_scatter.unit_cell_volume = macs_instr.sample.cell_vol
inc_scatter.packing_factor = 1
inc_scatter.interact_fraction=1
inc_scatter.set_AT([0,0,0])

#Single crystal process. 
crystal_scatter = scattering_def.add_component("crystal_scatter","Single_crystal_process")
crystal_scatter.delta_d_d=0.005
crystal_scatter.mosaic = 30.0
#Projections of lattice vectors onto lab frame is handled by the previous helper process.
labproj = macs_instr.sample.labframe_mat
crystal_scatter.ax = 6.867*np.sqrt(3)/2.0
crystal_scatter.ay = 0
crystal_scatter.az = -6.867*0.5
crystal_scatter.bx =0
crystal_scatter.by = 0
crystal_scatter.bz = 6.867
crystal_scatter.cx = 0
crystal_scatter.cy = 19.807
crystal_scatter.cz = 0
crystal_scatter.reflections='\"'+"CrI3.lau"+'\"'
crystal_scatter.barns=1
crystal_scatter.packing_factor=1
crystal_scatter.powder=0
crystal_scatter.PG=0
crystal_scatter.interact_fraction=1
crystal_scatter.set_AT([0,0,0])
crystal_scatter.set_ROTATED([0,0,0])

#Sample sqw4 processs
sample_sqw4 = scattering_def.add_component("sample_sqw4", "Sqw4_process")
sample_sqw4.sqw = '"spinw_CrI3_full.sqw4"'
#This file must also be added to the instrument file dependencies to be copied correctly.
macs_instr.file_dependencies="spinw_CrI3_full.sqw4"
#We are choosing to have the (100) vector along the x-axis
sample_sqw4.ax=6.867*np.sqrt(3)/2.0
sample_sqw4.ay=0
sample_sqw4.az=-6.867*0.5
sample_sqw4.bx=0
sample_sqw4.by=0
sample_sqw4.bz=6.867
sample_sqw4.cx=0
sample_sqw4.cy=19.807
sample_sqw4.cz=0
sample_sqw4.aa=90
sample_sqw4.bb=90
sample_sqw4.cc=120
sample_sqw4.barns=1
sample_sqw4.max_stored_ki=1e5
sample_sqw4.max_bad=1e5
sample_sqw4.stored_dTheta = 0.1
sample_sqw4.stored_dkmag = 1e-4
sample_sqw4.recip_cell=0
sample_sqw4.interact_fraction=1
#sample_sqw4.init="'init'"
#sample_sqw4.append_EXTEND("// Remove direct beam\nif(!SCATTERED) ABSORB;")
sample_sqw4.set_AT([0,0,0])
sample_sqw4.set_ROTATED([0,0,0])

scattering = scattering_def.add_component("CrI3","Union_make_material")
scattering.process_string='"crystal_scatter,inc_scatter,sample_sqw4"'
scattering.my_absorption=macs_instr.sample.rho_abs
scattering.set_AT([0,0,0])

#Now, this pseudo-instrument will be saved as the scattering definition of the sample. 
macs_instr.sample.scattering_def = scattering_def

#Make a second object for the geometry. This particular case replicates the validation experiment for this package.
geo_def = ms.McStas_instr("geometry_definition",checks=False)

sample_cube=geo_def.add_component("sample_cube","Union_box")
sample_cube.xwidth=1.0*macs_instr.sample.sample_widx
sample_cube.yheight=1.0*macs_instr.sample.sample_widy
sample_cube.zdepth=1.0*macs_instr.sample.sample_widz
sample_cube.priority=100
sample_cube.material_string='\"CrI3\"'
sample_cube.number_of_activations="number_of_activations_sample" #Do not change. 
sample_cube.set_AT([0,0,0],RELATIVE='crystal_assembly')
sample_cube.set_ROTATED([0,0,0],RELATIVE='crystal_assembly')

sample_plate = geo_def.add_component("sample_plate","Union_cylinder")
sample_plate.radius=0.006
sample_plate.yheight=0.002
sample_plate.priority=40
sample_plate.material_string='"Al"'
plate_distance = macs_instr.sample.sample_widy+0.002
sample_plate.set_AT([0,plate_distance,0],RELATIVE="target")
sample_plate.set_ROTATED([0,0,0],RELATIVE="target")

sample_plate_rod = geo_def.add_component("sample_plate_rod","Union_cylinder")
sample_plate_rod.radius=0.00125
sample_plate_rod.yheight=0.0633
sample_plate_rod.priority=41
sample_plate_rod.material_string='"Al"'
sample_plate_rod.set_AT([0,plate_distance+0.001+0.031,0], RELATIVE="target")
sample_plate_rod.set_ROTATED([0,0,0],RELATIVE="target")

sample_base = geo_def.add_component("sample_base","Union_cylinder")
sample_base.radius=0.0065
sample_base.yheight=0.013
sample_base.priority=42
sample_base.material_string='\"Al\"'
sample_base.set_AT([0,0.0628,0],RELATIVE="target")
sample_base.set_ROTATED([0,0,0],RELATIVE="target")

sample_base_gap = geo_def.add_component("sample_base_gap","Union_cylinder")
sample_base_gap.radius=0.004
sample_base_gap.yheight=0.009
sample_base_gap.priority=43
sample_base_gap.material_string='"Vacuum"'
sample_base_gap.set_AT([0,0.0668,0], RELATIVE="target")
sample_base_gap.set_ROTATED([0,0,0],RELATIVE="target")

macs_instr.sample.geometry_def = geo_def


useOld=True
if useOld==True:
    macs_instr.prepare_old_expt_directory()
    #macs_instr.clean_expt_directory()
else:
    macs_instr.data.data_matrix=False
    #macs_instr.clean_expt_directory()
    macs_instr.prepare_expt_directory()
    macs_instr.edit_instr_file()
    macs_instr.compileMonochromator()

    macs_instr.compileInstr()

#A note about file sizes here - a single 1e8 monochromator scan will make a 
# 350 Mb output file, so just be aware of this.
macs_instr.n_mono=1e7
macs_instr.n_sample=5e5


#The object is now set up and ready to perform simulations. 

macs_instr.kidney.Ef=5.0
macs_instr.kidney_angle_resolution=0.8
Ei_list = np.arange(5.0,17.0,1)
#On a typical desktop machine with 8 threads, this job started at 
# 1PM and ended at 
macs_instr.preserve_kidney_scan_files=False
macs_instr.script_scan(A3_list=np.arange(-120,120,0.8),Ei_list=Ei_list,\
                    num_threads=12,scan_title="cri3_a3scan_cube")

macs_instr.data.load_data_matrix_from_csv("cri3_a3scan_cube_dataMatrix.csv")
macs_instr.data.write_data_to_ng0(f"cri3_a3scan_cube.ng0")

# Plotting is in a separate file. 