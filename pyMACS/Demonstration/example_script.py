# Simple example script to show some uses of pyMACS

import sys
import os
import numpy as np
cwd = os.getcwd()
#Add the directory of the module to the path.
sys.path.append('/'.join(cwd.split('/')[0:-1]))
from virtualMACS import virtualMACS
import mcstasscript as ms

testobj = virtualMACS('ncrystal_experiment',cifName='TiO2.cif',useOld=False)
testobj.sample.formula_weight=79.87
numthreads=8

testobj.sample.sample_shape='box'
testobj.sample.sample_widx=4.3e-3 
testobj.sample.sample_widy=1.3e-3
testobj.sample.sample_widz=3.3e-3 
#Going to make our sample artifically big to increase count rate. 
testobj.sample.sample_widx=5e-3 
testobj.sample.sample_widy=5e-3
testobj.sample.sample_widz=5e-3 

testobj.sample.sample_tilt=-30
'''
testobj.sample.sample_shape='cylinder'
testobj.sample.sample_length=0.02
'''
testobj.sample.sample_diameter_d=0.01

testobj.monochromator.Ei = 5.0
testobj.monochromator.Ef = 5.0

#First need to convert CIF to lau style file. 
testobj.sample.cif2lau()
Qmod_110 = testobj.sample.Qmag_HKL(1,1,0)
print('Momentum transfer of (110) = '+'{:.2f}'.format(Qmod_110)+' Ang^-1')

#Tilt the sample
testobj.sample.crystal_axis_xrot=0.0
testobj.sample.crystal_axis_zrot=0.0
testobj.sample.crystal_axis_zrot=0.0

print('Sample Lattice vectors')
print('')
print('a='+str(testobj.sample.a))
print('alpha='+str(testobj.sample.alpha))
print('b='+str(testobj.sample.b))
print('beta='+str(testobj.sample.beta))
print('c='+str(testobj.sample.c))
print('gamma='+str(testobj.sample.gamma))
print('')
print('Sample orientation U')
print(testobj.sample.orient_u)
testobj.sample.orient_u=[1,1,0]
testobj.sample.orient_v=[0,0,1]
print('Sample orientation v')
print(testobj.sample.orient_v)
print('')
testobj.sample.project_sample_realspace()
print('Real Space projection of lattice vectors [ax,ay,az; bx,by,bz;cx,cy,cz]')
print(testobj.sample.labframe_mat)
print('')
print('Structure factors:')
print('|F(110)|^2 = '+str(round(testobj.sample.fetch_F_HKL(1,1,0)[3],4))+' barn')
print('|F(100)|^2 = '+str(round(testobj.sample.fetch_F_HKL(1,0,0)[3],4))+' barn')
print('|F(1-10)|^2 = '+str(round(testobj.sample.fetch_F_HKL(1,-1,0)[3],4))+' barn')
print('|F(001)|^2 = '+str(round(testobj.sample.fetch_F_HKL(0,0,1)[3],4))+' barn')

print('sigma_abs ='+str(testobj.sample.rho_abs)+' barn/unit cell')
print('sigma_inc ='+str(testobj.sample.sigma_inc)+' barn/unit cell')

scattering_def = ms.McStas_instr("scattering_definition",checks=False)
inc_scatter = scattering_def.add_component("inc_scatter","Incoherent_process")
inc_scatter.sigma=testobj.sample.sigma_inc
inc_scatter.unit_cell_volume = testobj.sample.cell_vol
inc_scatter.packing_factor = 1
inc_scatter.set_AT([0,0,0])

#Single crystal process. 
crystal_scatter = scattering_def.add_component("crystal_scatter","Single_crystal_process")
crystal_scatter.delta_d_d=0.005
crystal_scatter.mosaic = 30.0
#Projections of lattice vectors onto lab frame is handled by the previous helper process.
labproj = testobj.sample.labframe_mat
crystal_scatter.ax = labproj[0,0]
crystal_scatter.ay = labproj[0,1]
crystal_scatter.az = labproj[0,2]
crystal_scatter.bx = labproj[1,0]
crystal_scatter.by = labproj[1,1]
crystal_scatter.bz = labproj[1,2]
crystal_scatter.cx = labproj[2,0]
crystal_scatter.cy = labproj[2,1]
crystal_scatter.cz = labproj[2,2]
crystal_scatter.reflections='\"'+"TiO2.lau"+'\"'
crystal_scatter.barns=1
crystal_scatter.packing_factor=1
crystal_scatter.powder=0
crystal_scatter.PG=0
crystal_scatter.interact_fraction=0.8
crystal_scatter.set_AT([0,0,0])
crystal_scatter.set_ROTATED([0,0,0])

scattering = scattering_def.add_component("TiO2","Union_make_material")
scattering.process_string='"crystal_scatter,inc_scatter"'
scattering.my_absorption=testobj.sample.rho_abs
scattering.set_AT([0,0,0])

#Now, this pseudo-instrument will be saved as the scattering definition of the sample. 
testobj.sample.scattering_def = scattering_def

#Make a second object for the geometry. This particular case replicates the validation experiment for this package.
geo_def = ms.McStas_instr("geometry_definition",checks=False)

sample_cube=geo_def.add_component("sample_cube","Union_box")
sample_cube.xwidth=1.0*testobj.sample.sample_widx
sample_cube.yheight=1.0*testobj.sample.sample_widy
sample_cube.zdepth=1.0*testobj.sample.sample_widz
sample_cube.priority=100
sample_cube.material_string='\"TiO2\"'
sample_cube.number_of_activations="number_of_activations_sample" #Do not change. 
sample_cube.set_AT([0,0,0],RELATIVE='crystal_assembly')
sample_cube.set_ROTATED([0,0,0],RELATIVE='crystal_assembly')
'''
sample_cube_mask1 = geo_def.add_component("sample_cube_mask1","Union_box") #It's easier to rotate a mask rather than the sample itself.
sample_cube_mask1.xwidth=testobj.sample.sample_widx
sample_cube_mask1.yheight=testobj.sample.sample_widy
sample_cube_mask1.zdepth=testobj.sample.sample_widz
sample_cube_mask1.priority=0
sample_cube_mask1.material_string='"Mask"'
sample_cube_mask1.number_of_activations="number_of_activations_sample"
sample_cube_mask1.mask_string='"sample_cube"'
sample_cube_mask1.mask_setting='"All"'
sample_cube_mask1.visualize=0
sample_cube_mask1.set_AT([0,0,0],RELATIVE="crystal_assembly")
sample_cube_mask1.set_ROTATED([0,0,0], RELATIVE="crystal_assembly")
'''
sample_plate = geo_def.add_component("sample_plate","Union_cylinder")
sample_plate.radius=0.006
sample_plate.yheight=0.002
sample_plate.priority=40
sample_plate.material_string='"Al"'
plate_distance = testobj.sample.sample_widy+0.002
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

testobj.sample.geometry_def = geo_def


useOld=False
if useOld==True:
    testobj.prepare_old_expt_directory()
    #testobj.clean_expt_directory()
else:
    testobj.data.data_matrix=False
    #testobj.clean_expt_directory()
    testobj.prepare_expt_directory()
    testobj.edit_instr_file()
    testobj.compileMonochromator()

    testobj.compileInstr()


testobj.n_mono=1e7
testobj.n_sample=1e6

#First example is a simple A3 scan 
testobj.kidney.Ef=5.0

testobj.kidney_angle_resolution=0.8
testobj.preserve_kidney_scan_files=False
testobj.script_scan(A3_list=np.arange(-70,-20,0.25),Ei_list=[5.0],\
                    num_threads=12,scan_title='_tio2_a3scan_cube')

testobj.data.load_data_matrix_from_csv('_tio2_a3scan_cube_dataMatrix.csv')
testobj.data.write_data_to_ng0('tio2_a3scan_cube.ng0')


import matplotlib.pyplot as plt
testobj.data.project_data_QE()
U,V,I = testobj.data.bin_constE_slice(120,120,[-2,2],[-2,2],[-1,1])

plt.figure()
plt.pcolormesh(U,V,I.T,vmin=0,vmax=20)
plt.xlabel('[HH0]')
plt.ylabel('[00L]')
plt.title("TiO2 A3 Scan, Elastic")
plt.savefig("TiO2_A3scan_test.pdf",bbox_inches="tight")

'''
#Second is emulating a single ng0 file. 

testobj.data.data_matrix=False 
#object looks for previous scans in the data matrix, set the data matrix to False to disable this behavior and run 
# all scans regardless of if they have been run before.
sample_ng0 = 'Example_ng0_files/fpx78891.ng0'
testobj.n_sample=1e6
testobj.simulate_ng0(sample_ng0,n_threads=numthreads)

ngo_dir = 'Example_ng0_files/'
testobj.simulate_ng0dir(ngo_dir,n_threads=numthreads) #Uncomment this line to run the example directory.

#Here we combine any scans that exist individually and append them to the data holder class
testobj.data.combine_csv_scans(preserve_old=True,flagstr='_combined_')
testobj.data.load_data_matrix_from_csv(csv_name='_combined_dataMatrix.csv')

#The data is now written to a MACS style file for comparison in MSlice.
testobj.data.write_data_to_ng0(filename='_cube_TiO2_demonstration_scan.ng0',beta_1=testobj.monochromator.beta_1,\
                               beta_2=testobj.monochromator.beta_2)
'''