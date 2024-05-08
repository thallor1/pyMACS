import mcstasscript as ms
import numpy as np
from append_vertical_crystal_mono_array import *
from append_vertical_crystal_array import * 
from mcstasscript.tools.ncrystal_union import add_ncrystal_union_material

from contextlib import contextmanager
import os
import sys

@contextmanager
def suppress_stdout():
    with open(os.devnull, "w") as devnull:
        old_stdout = sys.stdout
        old_stderr = sys.stderr
        sys.stdout = devnull
        sys.stderr = devnull
        try:  
            yield
        finally:
            sys.stdout = old_stdout
            sys.stderr = old_stderr
with suppress_stdout():
    my_configurator = ms.Configurator()
    my_configurator.set_mcrun_path("/usr/bin/")
    my_configurator.set_mcstas_path("/usr/share/mcstas/3.3/")


    '''
    This is a translation of the original MACS model written in mcstas2 to mcstas3 using the 
    mcstasscript formalism. Work in progress. 
    '''

    macs_monochromator = ms.McStas_instr("macs_monochromator")

    monochromator_columns = 21 
    monochromator_rows = 17 

    kidney_channels = 20 

    monochromator_q = 1.87325
    use_slits_instead_of_filter = 1 
    mono_crystal_width = 0.02

    #These are for conditional logger components. 
    enable_conditional=[]
    for i in range(1,kidney_channels+1):
        enable_conditional.append(0)
    #enable_conditional[10]=1

    # Enable exit vols for diffraction detectors. 
    enable_exit_diffraction = []
    for i in range(1,kidney_channels+1):
        enable_exit_diffraction.append(1)

    # Enable exit volumes for spectroscopy detectors
    enable_exit_spectroscopy = []
    for i in range(1,kidney_channels+1):
        enable_exit_spectroscopy.append(1)
    #enable_conditional = [0]*kidney_channels
    #enable_conditional[1] = 1
    #enable_conditional[2] = 1
    #enable_conditional[3] = 1
    #enable_conditional[4] = 1
    #enable_conditional[5] = 1


    # Declare parameters in the instrument file for the monochromator
    macs_monochromator.add_declare_var("double","mono_column_displacements",array=21)
    macs_monochromator.add_declare_var("double","mono_crystal_width") #dmtas_mon_w
    macs_monochromator.add_declare_var("double","mono_number_of_rows")
    macs_monochromator.add_declare_var("double","mono_q")
    mono_col_disp_list = [-0.21, -0.189, -0.168, -0.147, -0.126, -0.105, -0.084, -0.063, 
                            -0.042, -0.021, 0, 0.021, 0.042, 0.063, 0.084, 0.105, 0.126, 
                            0.147, 0.168, 0.189, 0.21]
    for i in range(len(mono_col_disp_list)):
        macs_monochromator.append_initialize(f"mono_column_displacements[{i}]={mono_col_disp_list[i]};")

    macs_monochromator.append_initialize(f"mono_crystal_width={mono_crystal_width};")
    macs_monochromator.append_initialize(f"mono_number_of_rows={monochromator_rows};")
    macs_monochromator.append_initialize(f"mono_q={monochromator_q:.5f};")

    # Initialize / declare the relevant values for the monochromator crystals. 
    # Initialize for the monochromator
    macs_monochromator.append_initialize("")
    macs_monochromator.add_declare_var("double","mono_theta")
    macs_monochromator.append_initialize("mono_theta = asin(mono_q/2./sqrt(EM/2.0717));")

    macs_monochromator.add_declare_var("double","dist_mono_L0")     # focus distance source
    macs_monochromator.add_declare_var("double","dist_mono_L0_pos") # position of monochromator focus relative source

    macs_monochromator.append_initialize("dist_mono_L0     = MPL-MPD/tan(2.*mono_theta) + L0_delta;")
    macs_monochromator.append_initialize("dist_mono_L0_pos = MPL-MPD/tan(2.*mono_theta);")


    macs_monochromator.add_declare_var("double","dist_mono_L1")     # focus distance
    macs_monochromator.add_declare_var("double","dist_mono_L1_pos") # position of monochromator focus relative source
    macs_monochromator.append_initialize("dist_mono_L1     = 0.9+MPD/sin(2.*mono_theta) + L1_delta;")
    macs_monochromator.append_initialize("dist_mono_L1_pos = 0.9+MPD/sin(2.*mono_theta);")
    macs_monochromator.append_initialize("")


    macs_monochromator.add_declare_var("double","R_at_reference")
    macs_monochromator.append_initialize("R_at_reference =2.*dist_mono_L0*dist_mono_L1/(dist_mono_L0+dist_mono_L1);")
    macs_monochromator.add_declare_var("double","height_at_reference")
    macs_monochromator.append_initialize("height_at_reference =sin(asin((mono_crystal_width+0.001)/2./R_at_reference)*mono_number_of_rows)*R_at_reference*2.;")

    macs_monochromator.add_declare_var("double","mono_Radius_of_curvature")
    macs_monochromator.append_initialize("if (VF == 1) {")
    macs_monochromator.append_initialize("  mono_Radius_of_curvature = 2.*dist_mono_L0*dist_mono_L1*sin(mono_theta)/(dist_mono_L0+dist_mono_L1);")
    macs_monochromator.append_initialize("} else {")
    macs_monochromator.append_initialize("  mono_Radius_of_curvature = 300;")
    macs_monochromator.append_initialize("}")

    macs_monochromator.add_declare_var("double","mono_total_height")
    macs_monochromator.append_initialize("mono_total_height = sin(asin((mono_crystal_width+0.001)/2./mono_Radius_of_curvature)*mono_number_of_rows)*mono_Radius_of_curvature*2.;")

    macs_monochromator.add_declare_var("double","mono_phi")
    macs_monochromator.append_initialize("mono_phi = atan2(sin(2.*mono_theta),cos(2.*mono_theta)+dist_mono_L1/dist_mono_L0);")


    macs_monochromator.add_declare_var("double","mono_psi",array=21)
    macs_monochromator.add_declare_var("int","mono_iterate")
    macs_monochromator.append_initialize("for (mono_iterate=0;mono_iterate<" + str(monochromator_columns) + ";mono_iterate++) {")
    macs_monochromator.append_initialize("  if (HF == 1)")
    macs_monochromator.append_initialize("    mono_psi[mono_iterate] =-(atan2(sin(mono_phi),cos(mono_phi)+mono_column_displacements[mono_iterate]/dist_mono_L0)-mono_theta)*RAD2DEG;")
    macs_monochromator.append_initialize("  else {")
    macs_monochromator.append_initialize("    mono_psi[mono_iterate] = 0;")
    macs_monochromator.append_initialize("    mono_phi = mono_theta;");
    macs_monochromator.append_initialize("  }")
    macs_monochromator.append_initialize("}")


    macs_monochromator.add_declare_var("double","mono_mosaicity_eta_min") # Value in file from Jose
    macs_monochromator.add_declare_var("double","mono_mosaicity_eta_rad")
    macs_monochromator.append_initialize("mono_mosaicity_eta_min=14.1070;")
    macs_monochromator.append_initialize("mono_mosaicity_eta_rad = mono_mosaicity_eta_min/60*DEG2RAD;")
    macs_monochromator.add_declare_var("double","mono_crystal_thickness") # thickness of monochromator crystals in AA. Check scientific value works
    macs_monochromator.append_initialize("mono_crystal_thickness=0.002E10;")


    macs_monochromator.add_declare_var("double","mono_g")
    macs_monochromator.append_initialize("mono_g = 1/(2*sqrt(PI)*mono_mosaicity_eta_rad);")
    macs_monochromator.add_declare_var("double","mono_Ff")
    macs_monochromator.add_declare_var("double","mono_b_c")
    macs_monochromator.append_initialize("mono_b_c=6.646e-5;")
    macs_monochromator.append_initialize("mono_Ff=4*mono_b_c;")
    macs_monochromator.add_declare_var("double","mono_Vc")
    macs_monochromator.append_initialize("mono_Vc = sqrt(3)*2.464*2.464*6.711/2;")
    macs_monochromator.add_declare_var("double","mono_Qc")
    macs_monochromator.append_initialize("mono_Qc = lambda*lambda*lambda*mono_Ff*mono_Ff/(mono_Vc*mono_Vc*sin(2*mono_theta));")

    macs_monochromator.add_declare_var("double","mono_t") # Do not understand this value
    macs_monochromator.append_initialize("mono_t = mono_crystal_thickness/sin(mono_theta);")
    macs_monochromator.add_declare_var("double","mono_xx")
    macs_monochromator.append_initialize("mono_xx = sqrt(2)*mono_g*mono_Qc*mono_t;")
    macs_monochromator.add_declare_var("double","mono_r0")
    macs_monochromator.append_initialize("mono_r0 = mono_xx/(mono_xx+1);")

    macs_monochromator.add_declare_var("double","mono_mosaicity_rad")
    macs_monochromator.append_initialize("mono_mosaicity_rad = mono_mosaicity_eta_rad*sqrt(8*log(2+sqrt(2)*mono_g*mono_Qc*mono_crystal_thickness));")
    macs_monochromator.add_declare_var("double","mono_mosaicity_min")
    macs_monochromator.append_initialize("mono_mosaicity_min = mono_mosaicity_rad*RAD2DEG*60;")

    ## Now we have finally gotten to the trace, union components start here. 
    #init = macs_monochromator.add_component("init","Union_init")
    #init.set_AT([0,0,0])
    #init.set_ROTATED([0,0,0])

    inc_pg_mono = macs_monochromator.add_component("inc_pg_mono","Incoherent_process")
    inc_pg_mono.sigma = 4*0.001
    inc_pg_mono.unit_cell_volume = 35.29
    inc_pg_mono.packing_factor=1
    inc_pg_mono.interact_fraction=-1

    # Below is the oritinal method, where Single_crystal_process was used. 
    # NCrystal provides a slower but more realistic scattering simulation with inelastic processes included. 

    crystal_pg_mono = macs_monochromator.add_component("crystal_pg_mono","Single_crystal_process")
    crystal_pg_mono.mosaic=90
    crystal_pg_mono.reflections='"C_graphite.lau"'
    crystal_pg_mono.ax = 0
    crystal_pg_mono.ay = 2.14 
    crystal_pg_mono.az = -1.24 
    crystal_pg_mono.bx = 0
    crystal_pg_mono.by = 0 
    crystal_pg_mono.bz = 2.47
    crystal_pg_mono.cx = 6.71 
    crystal_pg_mono.cy = 0 
    crystal_pg_mono.cz = 0 
    crystal_pg_mono.barns = 0 
    crystal_pg_mono.packing_factor=1 
    crystal_pg_mono.set_AT([0,0,0])
    crystal_pg_mono.set_ROTATED([0,0,0])

    pg_mono = macs_monochromator.add_component("Pg_mono", "Union_make_material")
    pg_mono.my_absorption = 0.0035*4/35.29*100
    pg_mono.process_string = '"inc_pg_mono,crystal_pg_mono"'

    '''
    #Below is the Ncrystal version, doesn't give physically meaningful results. 
    ncrystal_pg_mono  = macs_monochromator.add_component("ncrystal_pg_mono","NCrystal_process")
    ncrystal_pg_mono.cfg = '"C_sg194_pyrolytic_graphite.ncmat;mos=3deg;dir1=@crys_hkl:0,0,1@lab:0,0,1;dir2=@crys_hkl:1,1,0@lab:0,1,0"'
    ncrystal_pg_mono.interact_fraction=1
    ncrystal_pg_mono.set_AT([0,0,0])
    ncrystal_pg_mono.set_ROTATED([0,0,0])

    pg_mono = macs_monochromator.add_component("Pg_mono", "Union_make_material")
    pg_mono.my_absorption = 0.0035*4/35.29*100
    pg_mono.process_string = '"ncrystal_pg_mono"'
    '''
    inc_al_mono = macs_monochromator.add_component("inc_al_mono","Incoherent_process")
    inc_al_mono.sigma =4*0.0082
    inc_al_mono.packing_factor=1
    inc_al_mono.unit_cell_volume=66.4

    pow_al_mono = macs_monochromator.add_component("pow_al_mono","Powder_process")
    pow_al_mono.reflections='"Al.laz"'

    al_mono = macs_monochromator.add_component("al_mono", "Union_make_material")
    al_mono.my_absorption=100*4*0.231/66.4
    al_mono.process_string ='"inc_al_mono,pow_al_mono"'

    mono_pil1 = macs_monochromator.add_component("mono_pil1",'Union_cylinder')
    mono_pil1.radius=0.01255
    mono_pil1.yheight="1.2*mono_total_height"
    mono_pil1.priority=5
    mono_pil1.material_string='"al_mono"'
    mono_pil1.p_interact=0.2
    mono_pil1.set_AT([0.1976,0,0],RELATIVE='mono')
    mono_pil1.set_ROTATED([0,0,0],RELATIVE='mono')

    mono_vacpil1 = macs_monochromator.add_component("mono_vacpil1","Union_cylinder")
    mono_vacpil1.radius = 0.0109
    mono_vacpil1.yheight = "1.18*mono_total_height"
    mono_vacpil1.priority=6
    mono_vacpil1.material_string='"Vacuum"'
    mono_vacpil1.set_AT([0.1976,0,0],RELATIVE='mono')
    mono_vacpil1.set_ROTATED([0,0,0],RELATIVE='mono')

    mono_pil2 = macs_monochromator.add_component("mono_pil2",'Union_cylinder')
    mono_pil2.radius=0.01255
    mono_pil2.yheight="1.2*mono_total_height"
    mono_pil2.priority=7
    mono_pil2.material_string='"al_mono"'
    mono_pil2.p_interact=0.2
    mono_pil2.set_AT([-0.0988,0,-0.1711],RELATIVE='mono')
    mono_pil2.set_ROTATED([0,0,0],RELATIVE='mono')

    mono_vacpil2 = macs_monochromator.add_component("mono_vacpil2","Union_cylinder")
    mono_vacpil2.radius = 0.0109
    mono_vacpil2.yheight = "1.18*mono_total_height"
    mono_vacpil2.priority=8
    mono_vacpil2.material_string='"Vacuum"'
    mono_vacpil2.set_AT([-0.0988,0,-0.1711],RELATIVE='mono')
    mono_vacpil2.set_ROTATED([0,0,0],RELATIVE='mono')

    mono_pil3 = macs_monochromator.add_component("mono_pil3",'Union_cylinder')
    mono_pil3.radius=0.01255
    mono_pil3.yheight="1.2*mono_total_height"
    mono_pil3.priority=9
    mono_pil3.material_string='"al_mono"'
    mono_pil3.p_interact=0.2
    mono_pil3.set_AT([-0.0988,0,0.1711],RELATIVE='mono')
    mono_pil3.set_ROTATED([0,0,0],RELATIVE='mono')

    mono_vacpil3 = macs_monochromator.add_component("mono_vacpil3","Union_cylinder")
    mono_vacpil3.radius = 0.0109
    mono_vacpil3.yheight = "1.18*mono_total_height"
    mono_vacpil3.priority=10
    mono_vacpil3.material_string='"Vacuum"'
    mono_vacpil3.set_AT([-0.0988,0,0.1711],RELATIVE='mono')
    mono_vacpil3.set_ROTATED([0,0,0],RELATIVE='mono')

    priority_value = 30 #start at priority 30

    # To add each individual monochromator crystal, we use the function append_vertical_crystal_mono_array
    #  as defined in the accompanyint file.
    for i in range(0,monochromator_columns):
        # Need to allow AT and rotated in the input
        macs_monochromator = append_vertical_crystal_mono_array(macs_monochromator, name = "mono_array" + str(i), 
            crystal_width = "mono_crystal_width", crystal_height = 0.02, crystal_depth = 0.002, 
            number_of_crystals = monochromator_rows, total_height = "mono_total_height", 
            radius_of_curvature = "mono_Radius_of_curvature", arm_name = "mono", priority_start = priority_value, 
            priority_end = priority_value+0.85, material_name = "Pg_mono",
            z_position_string="mono_column_displacements[" + str(i) + "]", 
            y_rotation_string="mono_psi[" + str(i) + "]", support_arch_thickness=0.00183, support_arch_width=0.0188, 
            support_arch_spacing=0.000251, mask_height_diviation=0.0002*i, misalignment_deg="misalign_mono_deg")
        # Need to set an individual priority for all 17 arrays
        priority_value = priority_value + 1;

    # Add a union master at this point. 
    mono_master = macs_monochromator.add_component("mono_union_master","Union_master")
    mono_master.set_AT([0,0,0],RELATIVE="mono")
    mono_master.set_ROTATED([0,0,0],RELATIVE="mono")

    stop = macs_monochromator.add_component("stop","Union_stop")
    stop.set_AT([0,0,0])
    stop.set_ROTATED([0,0,0])
    #stop = macs_monochromator.add_component("stop","Union_stop")
    #Finally, save the c files. 
    macs_monochromator.write_c_files()
    # Now proceed to kidney. 
    kidney = ms.McStas_instr("kidney")
    #kidney_init = kidney.add_component("init","Union_init")
    # Variable that contains the current channel number
    kidney.add_declare_var("int","channel_selected")

    # Unsure if this will work
    #kidney.add_declare_var("int","MAX_VOLUME_HISTORY_LENGTH")
    #kidney.append_initialize("MAX_VOLUME_HISTORY_LENGTH=50;")
    #kidney.add_declare_var("int","DOUBLE_MAX_VOLUME_HISTORY_LENGTH")
    #kidney.append_initialize("DOUBLE_MAX_VOLUME_HISTORY_LENGTH=100;")

    kidney_master_arm = kidney.add_component("kidney_master_arm","Arm")
    kidney_master_arm.set_AT([0,0,0],RELATIVE="target")
    kidney_master_arm.set_ROTATED([0,"kidney_angle",0],RELATIVE="target")
    kidney_master_arm.append_EXTEND(" channel_selected = -1;")

    # Works for even number of kidney channels
    kidney_channel_seperation = 8 #deg
    this_kidney_angle = -kidney_channel_seperation/2 - kidney_channels/2*kidney_channel_seperation

    for i in range(0,kidney_channels):
        this_kidney_angle = this_kidney_angle + kidney_channel_seperation
        kidney_channel = kidney.add_component("kidney_channel_" + str(i),"Arm")
        kidney_channel.set_AT([0,0,0],RELATIVE=kidney_master_arm)
        kidney_channel.set_ROTATED([0,str(this_kidney_angle),0],RELATIVE=kidney_master_arm)

    # Data input for filter
    kidney.add_declare_var("double","target_filter_dist") #This value needs to be looked up
    kidney.add_declare_var("double","filter_width") #this just needs to be small enough not to collide and large enough to cover colimator
    kidney.add_declare_var("double","filter_height") #this just needs to be small enough not to collide and large enough to cover colimator

    kidney.append_initialize("target_filter_dist=0.35;") #This value needs to be looked up
    kidney.append_initialize("filter_width=0.04;") #this just needs to be small enough not to collide and large enough to cover colimator
    kidney.append_initialize("filter_height=0.12;") #this just needs to be small enough not to collide and large enough to cover colimator

    for i in range(0,kidney_channels):
        if use_slits_instead_of_filter == 2:
            slit = kidney.add_component("channel_" + str(i) + "_filter","slit_MACS",GROUP="filter_group")
            slit.xwidth="filter_width"
            slit.yheight="filter_height"
        else:
            slit = kidney.add_component("channel_" + str(i) + "_filter","Filter_gen_no_absorb",GROUP="filter_group")
            slit.xwidth="filter_width"
            slit.yheight="filter_height"
            slit.filename='"Be.trm"'
        slit.set_AT([0,0,"target_filter_dist"],RELATIVE="kidney_channel_" + str(i))
        slit.set_ROTATED([0,0,0],RELATIVE="kidney_channel_" + str(i) )
        slit.append_EXTEND("if (SCATTERED) channel_selected = " + str(i) + ";")


    channel_selector = kidney.add_component("channel_selector","Arm")
    channel_selector.set_AT([0,0,0],RELATIVE=kidney_master_arm)
    channel_selector.set_ROTATED([0,0,0],RELATIVE=kidney_master_arm)
    channel_selector.append_EXTEND("if (channel_selected == -1) ABSORB;")
    channel_selector.append_EXTEND("detector_found = 0;")


    # Data input for colimators
    kidney.add_declare_var("double","channel_colimator_length")
    kidney.add_declare_var("double","channel_colimator_width")
    kidney.add_declare_var("double","channel_colimator_height") #this is the height at exit, entry is 220.0 mm
    kidney.add_declare_var("double","channel_colimator_divergence_arcmin")
    kidney.add_declare_var("double","channel_colimator_transmission")
    kidney.add_declare_var("double","channel_colimator_target_dist")
    # Data input for colimators
    kidney.append_initialize("channel_colimator_length=0.06;")
    kidney.append_initialize("channel_colimator_width=0.0346;")
    kidney.append_initialize("channel_colimator_height=0.1184;") #this is the height at exit, entry is 220.0 mm
    kidney.append_initialize("channel_colimator_divergence_arcmin=90;")
    kidney.append_initialize("channel_colimator_transmission=0.9;")
    kidney.append_initialize("channel_colimator_target_dist=0.4;")

    for i in range(0,kidney_channels):
        channel_coll = kidney.add_component("channel_" + str(i) + "_colimator","Collimator_linear")
        channel_coll.xwidth="channel_colimator_width"
        channel_coll.yheight="channel_colimator_height"
        channel_coll.length="channel_colimator_length"
        channel_coll.divergence = "channel_colimator_divergence_arcmin"
        channel_coll.transmission="channel_colimator_transmission"
        channel_coll.set_WHEN("channel_selected == " + str(i))
        channel_coll.set_AT([0,0,"channel_colimator_target_dist"],RELATIVE="kidney_channel_" + str(i) )
        channel_coll.set_ROTATED([0,0,0],RELATIVE="kidney_channel_" + str(i) )


    # Calculated from 40% Polyurethane and 60% B4C mass mixture and natural occurances cross sections from NIST
    boron_inc = kidney.add_component("boron_incoherent","Incoherent_process")
    boron_inc.sigma=1.80
    boron_inc.packing_factor=1
    boron_inc.unit_cell_volume=1
    boron_inc.interact_fraction=-1
    boron_inc.set_AT([0,0,0])

    boron_plastic = kidney.add_component("boron_plastic","Union_make_material")
    boron_plastic.my_absorption=3495 # 0.5*Value from MARI
    boron_plastic.process_string='"boron_incoherent"' # Done to save computational time
    boron_plastic.set_AT([0,0,0])


    # Calculated from 40% Polyurethane and 40% B4C mass mixture and natural occurances cross sections from NIST and 20% 20-B
    boron_enr_inc = kidney.add_component("boron_plastic_enriched_incoherent","Incoherent_process")
    boron_enr_inc.sigma=2.82
    boron_enr_inc.packing_factor=1
    boron_enr_inc.unit_cell_volume=1
    boron_enr_inc.interact_fraction=-1
    boron_enr_inc.set_AT([0,0,0])

    boron_enr = kidney.add_component("boron_plastic_enriched","Union_make_material")
    boron_enr.my_absorption=8071 # 0.5*Value from MARI
    boron_enr.process_string='"boron_plastic_enriched_incoherent"' # Done to save computational time
    #kidney.append_trace("  absorber=2)")
    #kidney.append_trace("  absorber=0)")
    boron_enr.set_AT([0,0,0])

    Collimator_gad = kidney.add_component("Collimator_gad","Union_make_material")
    Collimator_gad.my_absorption=2000.0*4/35.29*200
    Collimator_gad.absorber=1
    Collimator_gad.process_string='""'
    Collimator_gad.set_AT([0,0,0])

    inc_pg_ana = kidney.add_component("Incoherent_PG_analyzer","Incoherent_process")
    inc_pg_ana.sigma=4*0.001
    inc_pg_ana.packing_factor=1
    inc_pg_ana.unit_cell_volume=35.29
    inc_pg_ana.interact_fraction=-1
    inc_pg_ana.set_AT([0,0,0])

    Single_crystal_PG_analyzer= kidney.add_component("Single_crystal_PG_analyzer","Single_crystal_process")
    Single_crystal_PG_analyzer.mosaic = 80
    Single_crystal_PG_analyzer.reflections = '"C_graphite.lau"'
    Single_crystal_PG_analyzer.ax = 0
    Single_crystal_PG_analyzer.ay = 2.24
    Single_crystal_PG_analyzer.az =-1.24
    Single_crystal_PG_analyzer.bx = 0
    Single_crystal_PG_analyzer.by = 0
    Single_crystal_PG_analyzer.bz = 2.47
    Single_crystal_PG_analyzer.cx = 6.71
    Single_crystal_PG_analyzer.cy = 0
    Single_crystal_PG_analyzer.cz = 0
    Single_crystal_PG_analyzer.barns=0
    Single_crystal_PG_analyzer.packing_factor=1
    Single_crystal_PG_analyzer.set_AT([0,0,0])
    Single_crystal_PG_analyzer.set_ROTATED([0,0,0])

    PG_analyzer= kidney.add_component("PG_analyzer","Union_make_material")
    PG_analyzer.my_absorption=0.0035*4/35.29*100
    PG_analyzer.process_string='"Single_crystal_PG_analyzer,Incoherent_PG_analyzer"'
    PG_analyzer.set_AT([0,0,0])

    kidney.add_declare_var("double","kidney_hull_radius") # from CAD model
    kidney.add_declare_var("double","kidney_hull_height") # from CAD moddel (largest, there are some small steps/gaps and surface detail)
    kidney.add_declare_var("double","kidney_hull_inner_radius") # from CAD model
    kidney.add_declare_var("double","kidney_cylinder_angle") # from CAD (but the channels are not equally far from the edges)

    kidney.append_initialize("kidney_hull_radius=1.375;") # from CAD model
    kidney.append_initialize("kidney_hull_height=0.4;") # from CAD moddel (largest, there are some small steps/gaps and surface detail)
    kidney.append_initialize("kidney_hull_inner_radius=0.685;") # from CAD model
    kidney.append_initialize("kidney_cylinder_angle=160;") # from CAD (but the channels are not equally far from the edges)


    kidney_hull=kidney.add_component("kidney_hull","Union_cylinder")
    kidney_hull.radius="kidney_hull_radius"
    kidney_hull.yheight="kidney_hull_height"
    kidney_hull.priority=100
    kidney_hull.material_string='"boron_plastic"'
    kidney_hull.p_interact=0.3
    kidney_hull.set_AT([0,0,0],RELATIVE=kidney_master_arm)
    kidney_hull.set_ROTATED([0,0,0],RELATIVE=kidney_master_arm)


    kidney_hull_cut=kidney.add_component("kidney_hull_cut","Union_cylinder")
    kidney_hull_cut.radius="kidney_hull_inner_radius"
    kidney_hull_cut.yheight="1.002*kidney_hull_height"
    kidney_hull_cut.priority=100.5
    kidney_hull_cut.material_string='"Vacuum"'
    kidney_hull_cut.set_AT([0,0,0],RELATIVE=kidney_master_arm)
    kidney_hull_cut.set_ROTATED([0,0,0],RELATIVE=kidney_master_arm)

    kidney_hull_box_cut_arm1 = kidney.add_component("kidney_hull_box_cut_arm1","Arm")
    kidney_hull_box_cut_arm1.set_AT([0,0,0],RELATIVE=kidney_master_arm)
    kidney_hull_box_cut_arm1.set_ROTATED([0,"0.5*kidney_cylinder_angle+90",0],RELATIVE=kidney_master_arm)


    # When allowed starting list updated i can add a bit of height to conceal the center vacuum in mcdisplay
    kidney_hull_box_cut1=kidney.add_component("kidney_hull_box_cut1","Union_box")
    kidney_hull_box_cut1.xwidth="2.1*kidney_hull_radius"
    kidney_hull_box_cut1.yheight="1.003*kidney_hull_height"
    kidney_hull_box_cut1.zdepth="1.2*kidney_hull_radius"
    kidney_hull_box_cut1.priority=101
    kidney_hull_box_cut1.material_string='"Vacuum"'
    kidney_hull_box_cut1.visualize=0
    kidney_hull_box_cut1.set_AT([0,0,"0.6*kidney_hull_radius"],RELATIVE=kidney_hull_box_cut_arm1)
    kidney_hull_box_cut1.set_ROTATED([0,0,0],RELATIVE=kidney_hull_box_cut_arm1)

    kidney_hull_box_cut_arm2 = kidney.add_component("kidney_hull_box_cut_arm2","Arm")
    kidney_hull_box_cut_arm2.set_AT([0,0,0],RELATIVE=kidney_master_arm)
    kidney_hull_box_cut_arm2.set_ROTATED([0,"-0.5*kidney_cylinder_angle-90",0],RELATIVE=kidney_master_arm)

    kidney_hull_box_cut2 = kidney.add_component("kidney_hull_box_cut2","Union_box")
    kidney_hull_box_cut2.xwidth="2.1*kidney_hull_radius"
    kidney_hull_box_cut2.yheight="1.004*kidney_hull_height"
    kidney_hull_box_cut2.zdepth="1.2*kidney_hull_radius"
    kidney_hull_box_cut2.priority=102
    kidney_hull_box_cut2.material_string='"Vacuum"'
    kidney_hull_box_cut2.visualize=0
    kidney_hull_box_cut2.set_AT([0,0,"0.6*kidney_hull_radius"],RELATIVE=kidney_hull_box_cut_arm2)
    kidney_hull_box_cut2.set_ROTATED([0,0,0],RELATIVE=kidney_hull_box_cut_arm2)


    kidney.add_declare_var("double","zx_log_z_min")
    kidney.add_declare_var("double","zx_log_z_max")
    kidney.add_declare_var("double","zx_log_x_min")
    kidney.add_declare_var("double","zx_log_x_max")
    kidney.add_declare_var("int","zx_log_z_pixels")
    kidney.add_declare_var("int","zx_log_x_pixels")

    kidney.add_declare_var("double","zy_log_z_min")
    kidney.add_declare_var("double","zy_log_z_max")
    kidney.add_declare_var("double","zy_log_y_min")
    kidney.add_declare_var("double","zy_log_y_max")
    kidney.add_declare_var("int","zy_log_z_pixels")
    kidney.add_declare_var("int","zy_log_y_pixels")

    kidney.append_initialize("zx_log_z_min=-0.5;")
    kidney.append_initialize("zx_log_z_max=2.5;")
    kidney.append_initialize("zx_log_x_min=-2.5;")
    kidney.append_initialize("zx_log_x_max=2.5;")
    kidney.append_initialize("zx_log_z_pixels=2000;")
    kidney.append_initialize("zx_log_x_pixels=2000;")

    kidney.append_initialize("zy_log_z_min=-0.5;")
    kidney.append_initialize("zy_log_z_max=2.5;")
    kidney.append_initialize("zy_log_y_min=-0.2;")
    kidney.append_initialize("zy_log_y_max=0.2;")
    kidney.append_initialize("zy_log_z_pixels=2000;")
    kidney.append_initialize("zy_log_y_pixels=300;")


    for i in range(0,kidney_channels):
        if (enable_conditional[i] == 2):
            logger_zx = kidney.add_component("logger_zx_spatial_con_channel_" + str(i) + "_all "," Union_logger_2D_space")
            logger_zx.filename='"logger_zx_spatial_con_channel_" + str(i) + "_all.dat"'
            logger_zx.n2=zx_log_z_pixels
            logger_zx.D_direction_2='"z"'
            logger_zx.D2_min=zx_log_z_min
            logger_zx.D2_max=zx_log_z_max
            logger_zx.zx_log_x_pixels
            logger_zx.D_direction_2='"x"'
            logger_zx.D2_min=zx_log_x_min
            logger_zx.D2_max=zx_log_x_max
            logger_zx.set_AT([0,0,0],RELATIVE="target")

            logger_zy = kidney.add_component("logger_zy_spatial_con_channel_" + str(i) + "_all "," Union_logger_2D_space")
            logger_zy.filename='"logger_zy_spatial_con_channel_" + str(i) + "_all.dat"'
            logger_zy.n2=zy_log_z_pixels
            logger_zy.D_direction_2='"z"'
            logger_zy.D2_min=zy_log_z_min
            logger_zy.D2_max=zy_log_z_max
            logger_zy.zy_log_x_pixels
            logger_zy.D_direction_2='"y"'
            logger_zy.D2_min=zy_log_x_min
            logger_zy.D2_max=zy_log_x_max
            logger_zy.set_AT([0,0,0],RELATIVE="target")

            logger_zx_spatial_2 = kidney.add_component("logger_zx_spatial_con_channel_" + str(i) + "_2","Union_logger_2D_space")
            logger_zx_spatial_2.filename='"logger_zx_spatial_con_channel_' + str(i) + '_2.dat"'
            logger_zx_spatial_2.n2=zx_log_z_pixels
            logger_zx_spatial_2.D_direction_2='"z"'
            logger_zx_spatial_2.D2_min=zx_log_z_min
            logger_zx_spatial_2.D2_max=zx_log_z_max
            logger_zx_spatial_2.n2=zx_log_z_pixels
            logger_zx_spatial_2.D_direction_2='"x"'
            logger_zx_spatial_2.D2_min=zx_log_x_min
            logger_zx_spatial_2.D2_max=zx_log_x_max
            logger_zx_spatial_2.order_total=2
            logger_zx_spatial_2.set_AT([0,0,0],RELATIVE="target")

            logger_zy_spatial_2 = kidney.add_component("logger_zy_spatial_con_channel_" + str(i) + "_2","Union_logger_2D_space")
            logger_zy_spatial_2.filename='"logger_zy_spatial_con_channel_' + str(i) + '_2.dat"'
            logger_zy_spatial_2.n2=zy_log_z_pixels
            logger_zy_spatial_2.D_direction_2='"z"'
            logger_zy_spatial_2.D2_min=zy_log_z_min
            logger_zy_spatial_2.D2_may=zy_log_z_max
            logger_zy_spatial_2.n2=zy_log_z_pixels
            logger_zy_spatial_2.D_direction_2='"y"'
            logger_zy_spatial_2.D2_min=zy_log_y_min
            logger_zy_spatial_2.D2_may=zy_log_y_max
            logger_zy_spatial_2.order_total=2
            logger_zy_spatial_2.set_AT([0,0,0],RELATIVE="target")


            logger_zx_spatial_2 = kidney.add_component("logger_zx_spatial_con_channel_" + str(i) + "_2","Union_logger_2D_space")
            logger_zx_spatial_2.filename='"logger_zx_spatial_con_channel_' + str(i) + '_2.dat"'
            logger_zx_spatial_2.n2=zx_log_z_pixels
            logger_zx_spatial_2.D_direction_2='"z"'
            logger_zx_spatial_2.D2_min=zx_log_z_min
            logger_zx_spatial_2.D2_max=zx_log_z_max
            logger_zx_spatial_2.n2=zx_log_z_pixels
            logger_zx_spatial_2.D_direction_2='"x"'
            logger_zx_spatial_2.D2_min=zx_log_x_min
            logger_zx_spatial_2.D2_max=zx_log_x_max
            logger_zx_spatial_2.order_total=2
            logger_zx_spatial_2.set_AT([0,0,0],RELATIVE="target")

            logger_zy_spatial_2 = kidney.add_component("logger_zy_spatial_con_channel_" + str(i) + "_2","Union_logger_2D_space")
            logger_zy_spatial_2.filename='"logger_zy_spatial_con_channel_' + str(i) + '_2.dat"'
            logger_zy_spatial_2.n2=zy_log_z_pixels
            logger_zy_spatial_2.D_direction_2='"z"'
            logger_zy_spatial_2.D2_min=zy_log_z_min
            logger_zy_spatial_2.D2_may=zy_log_z_max
            logger_zy_spatial_2.n2=zy_log_z_pixels
            logger_zy_spatial_2.D_direction_2='"y"'
            logger_zy_spatial_2.D2_min=zy_log_y_min
            logger_zy_spatial_2.D2_may=zy_log_y_max
            logger_zy_spatial_2.order_total=2
            logger_zy_spatial_2.set_AT([0,0,0],RELATIVE="target")

            logger_zx_spatial_3 = kidney.add_component("logger_zx_spatial_con_channel_" + str(i) + "_3","Union_logger_2D_space")
            logger_zx_spatial_3.filename='"logger_zx_spatial_con_channel_' + str(i) + '_3.dat"'
            logger_zx_spatial_3.n3=zx_log_z_pixels
            logger_zx_spatial_3.D_direction_3='"z"'
            logger_zx_spatial_3.D3_min=zx_log_z_min
            logger_zx_spatial_3.D3_max=zx_log_z_max
            logger_zx_spatial_3.n2=zx_log_z_pixels
            logger_zx_spatial_3.D_direction_2='"x"'
            logger_zx_spatial_3.D2_min=zx_log_x_min
            logger_zx_spatial_3.D2_max=zx_log_x_max
            logger_zx_spatial_3.order_total=3
            logger_zx_spatial_3.set_AT([0,0,0],RELATIVE="target")

            logger_zy_spatial_3 = kidney.add_component("logger_zy_spatial_con_channel_" + str(i) + "_3","Union_logger_2D_space")
            logger_zy_spatial_3.filename='"logger_zy_spatial_con_channel_' + str(i) + '_3.dat"'
            logger_zy_spatial_3.n3=zy_log_z_pixels
            logger_zy_spatial_3.D_direction_3='"z"'
            logger_zy_spatial_3.D3_min=zy_log_z_min
            logger_zy_spatial_3.D3_may=zy_log_z_max
            logger_zy_spatial_3.n2=zy_log_z_pixels
            logger_zy_spatial_3.D_direction_2='"y"'
            logger_zy_spatial_3.D2_min=zy_log_y_min
            logger_zy_spatial_3.D2_may=zy_log_y_max
            logger_zy_spatial_3.order_total=3
            logger_zy_spatial_3.set_AT([0,0,0],RELATIVE="target")

            logger_zx_spatial_4 = kidney.add_component("logger_zx_spatial_con_channel_" + str(i) + "_4","Union_logger_2D_space")
            logger_zx_spatial_4.filename='"logger_zx_spatial_con_channel_' + str(i) + '_4.dat"'
            logger_zx_spatial_4.n4=zx_log_z_pixels
            logger_zx_spatial_4.D_direction_4='"z"'
            logger_zx_spatial_4.D4_min=zx_log_z_min
            logger_zx_spatial_4.D4_max=zx_log_z_max
            logger_zx_spatial_4.n2=zx_log_z_pixels
            logger_zx_spatial_4.D_direction_2='"x"'
            logger_zx_spatial_4.D2_min=zx_log_x_min
            logger_zx_spatial_4.D2_max=zx_log_x_max
            logger_zx_spatial_4.order_total=4
            logger_zx_spatial_4.set_AT([0,0,0],RELATIVE="target")

            logger_zy_spatial_4 = kidney.add_component("logger_zy_spatial_con_channel_" + str(i) + "_4","Union_logger_2D_space")
            logger_zy_spatial_4.filename='"logger_zy_spatial_con_channel_' + str(i) + '_4.dat"'
            logger_zy_spatial_4.n4=zy_log_z_pixels
            logger_zy_spatial_4.D_direction_4='"z"'
            logger_zy_spatial_4.D4_min=zy_log_z_min
            logger_zy_spatial_4.D4_may=zy_log_z_max
            logger_zy_spatial_4.n2=zy_log_z_pixels
            logger_zy_spatial_4.D_direction_2='"y"'
            logger_zy_spatial_4.D2_min=zy_log_y_min
            logger_zy_spatial_4.D2_may=zy_log_y_max
            logger_zy_spatial_4.order_total=4
            logger_zy_spatial_4.set_AT([0,0,0],RELATIVE="target")

    # Data input on the analyzer "caves"
    kidney.add_declare_var("double","kidney_cave1_width") #At the edge from CAD (at 917.76: 57.1148 mm)
    kidney.add_declare_var("double","kidney_cave1_height") #At the edge from CAD
    kidney.add_declare_var("double","kidney_cave1_depth")
    kidney.add_declare_var("double","kidney_cave1_start_target_dist") #less than kidney_inner_hull_radius

    kidney.append_initialize("kidney_cave1_width=0.04874;") #At the edge from CAD (at 917.76: 57.1148 mm)
    kidney.append_initialize("kidney_cave1_height=0.140;") #At the edge from CAD
    kidney.append_initialize("kidney_cave1_depth=0.55;")
    #kidney.append_initialize("kidney_cave1_start_target_dist=0.59") #less than kidney_inner_hull_radius
    kidney.append_initialize("kidney_cave1_start_target_dist = kidney_hull_inner_radius-0.001;")





    # New cave data input
    kidney.add_declare_var("double","kidney_cave1_box1_width1") # width when starting 2 cm before radius
    kidney.add_declare_var("double","kidney_cave1_box1_width2")
    kidney.add_declare_var("double","kidney_cave1_box1_center_to_target")
    kidney.add_declare_var("double","kidney_cave1_box1_depth") # made this 1mm to large to intentionally overlap box2
    kidney.add_declare_var("double","kidney_cave1_box1_height1") # updated later
    kidney.add_declare_var("double","kidney_cave1_box1_height2") # updated later

    kidney.append_initialize("kidney_cave1_box1_width1=0.04803;") # width when starting 2 cm before radius
    kidney.append_initialize("kidney_cave1_box1_width2=0.057166;")
    kidney.append_initialize("kidney_cave1_box1_center_to_target = kidney_hull_inner_radius+0.5*(0.23989-0.02);")
    kidney.append_initialize("kidney_cave1_box1_depth=0.23989+0.021;") # made this 1mm to large to intentionally overlap box2
    kidney.append_initialize("kidney_cave1_box1_height1=0.140;") # updated later
    kidney.append_initialize("kidney_cave1_box1_height2=0.173;") # updated later

    kidney.add_declare_var("double","kidney_cave1_box2_width1")
    kidney.add_declare_var("double","kidney_cave1_box2_width2")
    kidney.add_declare_var("double","kidney_cave1_box2_center_to_target")
    kidney.add_declare_var("double","kidney_cave1_box2_x_offset")
    kidney.add_declare_var("double","kidney_cave1_box2_depth")
    kidney.add_declare_var("double","kidney_cave1_box2_height1") # updated later
    kidney.add_declare_var("double","kidney_cave1_box2_height2") # updated later


    kidney.append_initialize("kidney_cave1_box2_width1=0.062634;")
    kidney.append_initialize("kidney_cave1_box2_width2=0.067257;")
    kidney.append_initialize("kidney_cave1_box2_center_to_target = kidney_hull_inner_radius+0.30609;")
    kidney.append_initialize("kidney_cave1_box2_x_offset=-0.5*0.005528;")
    kidney.append_initialize("kidney_cave1_box2_depth=0.13240;")
    kidney.append_initialize("kidney_cave1_box2_height1=0.2061;") # updated later
    kidney.append_initialize("kidney_cave1_box2_height2=0.2061;") # updated later


    kidney.add_declare_var("double","kidney_cave1_box3_width1")
    kidney.add_declare_var("double","kidney_cave1_box3_width2") # Updated to match the slope of the cylinder walls
    kidney.add_declare_var("double","kidney_cave1_box3_center_to_target")
    kidney.add_declare_var("double","kidney_cave1_box3_depth") # can make this large
    kidney.add_declare_var("double","kidney_cave1_box3_height1") # updated later
    kidney.add_declare_var("double","kidney_cave1_box3_height2") # updated later

    kidney.append_initialize("kidney_cave1_box3_width1=0.061729;")
    kidney.append_initialize("kidney_cave1_box3_width2=0.04534;") # Updated to match the slope of the cylinder walls
    kidney.append_initialize("kidney_cave1_box3_center_to_target = kidney_hull_inner_radius+0.38819-0.001-0.01163*0.125;")
    kidney.append_initialize("kidney_cave1_box3_depth=0.03380+0.0005-0.01163*0.25;") # can make this large
    kidney.append_initialize("kidney_cave1_box3_height1=0.206;") # updated later
    kidney.append_initialize("kidney_cave1_box3_height2=0.206;") # updated later

    kidney.add_declare_var("double","kidney_cave1_cyl1_radius")
    kidney.add_declare_var("double","kidney_cave1_cyl1_center_to_target")
    kidney.add_declare_var("double","kidney_cave1_cyl1_height") # updated later

    kidney.append_initialize("kidney_cave1_cyl1_radius=0.024;")
    #kidney.append_initialize("kidney_cave1_cyl1_center_to_target = kidney_hull_inner_radius+0.40609;")
    kidney.append_initialize("kidney_cave1_cyl1_center_to_target = kidney_hull_inner_radius+0.40609-0.01163;") # Correction for making the slopes match
    kidney.append_initialize("kidney_cave1_cyl1_height=0.25;") # updated later


    # Cave 2
    kidney.add_declare_var("double","kidney_cave2_box1_y_rotation")
    kidney.append_initialize("kidney_cave2_box1_y_rotation=106.4-90+1.71;")
    kidney.add_declare_var("double","kidney_cave2_box1_width1") #This value is not measured from CAD, but set close using geometry in the McStas file (approx)
    kidney.append_initialize("kidney_cave2_box1_width1=0.063;") #This value is not measured from CAD, but set close using geometry in the McStas file (approx)

    kidney.add_declare_var("double","kidney_cave2_box1_depth") #This value is not measured from CAD, but set close using geometry in the McStas file (approx)
    kidney.append_initialize("kidney_cave2_box1_depth=0.1129;") #This value is not measured from CAD, but set close using geometry in the McStas file (approx)

    kidney.add_declare_var("double","kidney_cave2_box1_width2")
    kidney.append_initialize("kidney_cave2_box1_width2 = kidney_cave2_box1_width1 + 2*kidney_cave2_box1_depth*sin((106.4-90)*DEG2RAD);") #different angle, measured in cad

    kidney.add_declare_var("double","kidney_cave2_box1_center_to_spec_detector_z")
    kidney.add_declare_var("double","kidney_cave2_box1_center_to_spec_detector_x")
    # These calculations are made from the CAD drawings and measurements therein.
    kidney.append_initialize("kidney_cave2_box1_center_to_spec_detector_z = -0.29044 - 0.5*kidney_cave2_box1_width1*sin(kidney_cave2_box1_y_rotation*DEG2RAD) + 0.5*kidney_cave2_box1_depth*cos(kidney_cave2_box1_y_rotation*DEG2RAD);")
    #kidney.append_initialize("kidney_cave2_box1_center_to_spec_detector_x = -0.029095 + 0.5*kidney_cave2_box1_width1*cos(kidney_cave2_box1_y_rotation*DEG2RAD) +  0.5*kidney_cave2_box1_depth*sin(kidney_cave2_box1_y_rotation*DEG2RAD);")
    kidney.append_initialize("kidney_cave2_box1_center_to_spec_detector_x = -0.031 + 0.5*kidney_cave2_box1_width1*cos(kidney_cave2_box1_y_rotation*DEG2RAD) +  0.5*kidney_cave2_box1_depth*sin(kidney_cave2_box1_y_rotation*DEG2RAD);")


    kidney.add_declare_var("double","kidney_cave2_box1_height1")
    kidney.add_declare_var("double","kidney_cave2_box1_height2")
    kidney.append_initialize("kidney_cave2_box1_height1=0.206;")
    kidney.append_initialize("kidney_cave2_box1_height2=0.206;")


    #box 2
    kidney.add_declare_var("double","kidney_cave2_box2_width1")
    kidney.add_declare_var("double","kidney_cave2_box2_width2")
    kidney.add_declare_var("double","kidney_cave2_box2_center_to_detector")
    kidney.add_declare_var("double","kidney_cave2_box2_depth") # can make this large
    kidney.add_declare_var("double","kidney_cave2_box2_height1")
    kidney.add_declare_var("double","kidney_cave2_box2_height2")

    #box 2
    kidney.append_initialize("kidney_cave2_box2_width1=0.06017;")
    kidney.append_initialize("kidney_cave2_box2_width2=0.05721;")
    kidney.append_initialize("kidney_cave2_box2_center_to_detector=-0.19611;")
    kidney.append_initialize("kidney_cave2_box2_depth=0.04962;") # can make this large
    kidney.append_initialize("kidney_cave2_box2_height1=0.2061;")
    kidney.append_initialize("kidney_cave2_box2_height2=0.2061;")



    #box 3
    kidney.add_declare_var("double","kidney_cave2_box3_width1")
    kidney.add_declare_var("double","kidney_cave2_box3_width2")
    kidney.add_declare_var("double","kidney_cave2_box3_center_to_detector")
    kidney.add_declare_var("double","kidney_cave2_box3_depth") # can make this large
    kidney.add_declare_var("double","kidney_cave2_box3_height1")
    kidney.add_declare_var("double","kidney_cave2_box3_height2")

    #box 3
    kidney.append_initialize("kidney_cave2_box3_width1=0.05721;")
    kidney.append_initialize("kidney_cave2_box3_width2=0.0470;")
    kidney.append_initialize("kidney_cave2_box3_center_to_detector=-0.08565;")
    kidney.append_initialize("kidney_cave2_box3_depth=0.17130+0.0005;") # can make this large
    kidney.append_initialize("kidney_cave2_box3_height1=0.185;")
    kidney.append_initialize("kidney_cave2_box3_height2=0.120;")


    # cyl1
    kidney.add_declare_var("double","kidney_cave2_cyl1_radius")
    #kidney.add_declare_var("double","kidney_cave2_cyl1_height",value=0.340)
    kidney.add_declare_var("double","kidney_cave2_cyl1_height")

    # cyl1
    kidney.append_initialize("kidney_cave2_cyl1_radius=0.0235;")
    #kidney.add_declare_var("double","kidney_cave2_cyl1_height",value=0.340)
    kidney.append_initialize("kidney_cave2_cyl1_height=0.25;")

    kidney.add_declare_var("double","kidney_cave2_start_target_dist")
    kidney.add_declare_var("double","analyzer_1_center_to_sample")
    kidney.add_declare_var("double","analyzer_seperation")

    kidney.append_initialize("kidney_cave2_start_target_dist=0.96;")
    kidney.append_initialize("analyzer_1_center_to_sample=0.99939;")
    kidney.append_initialize("analyzer_seperation=0.07;")

    # temp
    kidney.add_declare_var("double","analyzer_2theta_min")
    kidney.add_declare_var("double","analyzer_2theta_max")
    kidney.add_declare_var("double","delta_analyzer_2theta")
    kidney.add_declare_var("double","analyzer_2theta",array=kidney_channels)
    kidney.add_declare_var("double","analyzer_theta",array=kidney_channels)
    # temp
    kidney.append_initialize("analyzer_2theta_min=40;")
    kidney.append_initialize("analyzer_2theta_max=140;")



    kidney.add_declare_var("int","kidney_iterate")
    kidney.append_initialize("delta_analyzer_2theta = (analyzer_2theta_max - analyzer_2theta_min)/" + str(kidney_channels-1) + ";")
    kidney.append_initialize("for (kidney_iterate=0;kidney_iterate<" + str(kidney_channels) + ";kidney_iterate++) {")
    kidney.append_initialize("  analyzer_theta[kidney_iterate] = RAD2DEG*asin(1.87325/2./sqrt(EF_all/2.0717));")
    kidney.append_initialize("  analyzer_2theta[kidney_iterate] = 2.0*analyzer_theta[kidney_iterate];")
    kidney.append_initialize("}")


    # colimator
    kidney.add_declare_var("double","inter_analyzer_colimator_width") # 0.6 mm width from document
    kidney.add_declare_var("double","inter_analyzer_colimator_height") # from cad
    kidney.add_declare_var("double","inter_analyzer_colimator_depth") # from cadq
    kidney.add_declare_var("double","inter_analyzer_colimator_start_pos")
    kidney.add_declare_var("double","inter_analyzer_colimator_seperation")
    kidney.append_initialize("inter_analyzer_colimator_width=0.0006;") # 0.6 mm width from document
    kidney.append_initialize("inter_analyzer_colimator_height=0.202;") # from cad
    kidney.append_initialize("inter_analyzer_colimator_depth=0.0127;") # from cadq
    kidney.append_initialize("inter_analyzer_colimator_start_pos=0.016*2;")
    kidney.append_initialize("inter_analyzer_colimator_seperation=0.016;")



    # detector input
    kidney.add_declare_var("double","detector_radius")
    kidney.add_declare_var("double","detector_height")
    kidney.append_initialize("detector_radius=0.018;")
    kidney.append_initialize("detector_height=0.14;")
    kidney.add_declare_var("double","diffraction_detector_to_sample")
    kidney.append_initialize("diffraction_detector_to_sample=kidney_cave1_cyl1_center_to_target;")
    kidney.add_declare_var("double","spec_detector_to_sample")
    kidney.append_initialize("spec_detector_to_sample=1.25;")

    kidney.add_declare_var("double","spec_detector_to_analyzer_2_center")
    # I don't believe this calculation is correct, when layering simulation output and cad, this seems like ~1 cm off.
    kidney.append_initialize("spec_detector_to_analyzer_2_center = sqrt(spec_detector_to_sample*spec_detector_to_sample-analyzer_seperation*analyzer_seperation)-analyzer_1_center_to_sample;")
    # Corrected version (Second detector is 1.250 m from sample, the two analyzers are almost on a sphere
    kidney.append_initialize("spec_detector_to_analyzer_2_center = spec_detector_to_sample-analyzer_1_center_to_sample;")


    # Input of priority range of cave1
    priority_start = 200
    priority_end   = 2200
    this_priority = priority_start - (priority_end-priority_start)/kidney_channels


    for i in range(0,kidney_channels):
        this_priority = this_priority + (priority_end-priority_start)/kidney_channels
      
        channel_cave1_box1 = kidney.add_component("channel_" + str(i) + "_cave1_box1","Union_box")
        channel_cave1_box1.xwidth="kidney_cave1_box1_width1"
        channel_cave1_box1.yheight="kidney_cave1_box1_height1"
        channel_cave1_box1.zdepth="kidney_cave1_box1_depth"
        channel_cave1_box1.xwidth2="kidney_cave1_box1_width2"
        channel_cave1_box1.yheight2="kidney_cave1_box1_height2"
        channel_cave1_box1.priority=this_priority
        channel_cave1_box1.material_string='"Vacuum"'
        channel_cave1_box1.set_AT([0,0,"kidney_cave1_box1_center_to_target"],RELATIVE="kidney_channel_" + str(i) )
        channel_cave1_box1.set_ROTATED([0,0,0],RELATIVE="kidney_channel_" + str(i) )

        channel_cave1_box2 = kidney.add_component("channel_" + str(i) + "_cave1_box2","Union_box")
        channel_cave1_box2.xwidth= "kidney_cave1_box2_width1"
        channel_cave1_box2.yheight="kidney_cave1_box2_height1"
        channel_cave1_box2.zdepth="kidney_cave1_box2_depth"
        channel_cave1_box2.xwidth2= "kidney_cave1_box2_width2"
        channel_cave1_box2.yheight2="kidney_cave1_box2_height2"
        channel_cave1_box2.priority=this_priority+5
        channel_cave1_box2.material_string='"Vacuum"'
        channel_cave1_box2.set_AT([0,0,"kidney_cave1_box2_center_to_target"],RELATIVE="kidney_channel_" + str(i) )
        channel_cave1_box2.set_ROTATED([0,0,0],RELATIVE="kidney_channel_" + str(i) )

        channel_cave1_box3 = kidney.add_component("channel_" + str(i) + "_cave1_box3","Union_box")
        channel_cave1_box3.xwidth= "kidney_cave1_box3_width1"
        channel_cave1_box3.yheight="kidney_cave1_box3_height1"
        channel_cave1_box3.zdepth="kidney_cave1_box3_depth"
        channel_cave1_box3.xwidth2= "kidney_cave1_box3_width2"
        channel_cave1_box3.yheight2="kidney_cave1_box3_height2"
        channel_cave1_box3.priority=this_priority+2
        channel_cave1_box3.material_string='"Vacuum"'
        channel_cave1_box3.set_AT([0,0,"kidney_cave1_box3_center_to_target"],RELATIVE="kidney_channel_" + str(i) )
        channel_cave1_box3.set_ROTATED([0,0,0],RELATIVE="kidney_channel_" + str(i) )

        channel_cave1_cyl1 = kidney.add_component("channel_" + str(i) + "_cave1_cyl1","Union_cylinder")
        channel_cave1_cyl1.radius= "kidney_cave1_cyl1_radius"
        channel_cave1_cyl1.yheight="kidney_cave1_cyl1_height"
        channel_cave1_cyl1.priority = this_priority+3
        channel_cave1_cyl1.material_string='"Vacuum"'
        channel_cave1_cyl1.set_AT([0,0,"kidney_cave1_cyl1_center_to_target"],RELATIVE="kidney_channel_" + str(i) )
        channel_cave1_cyl1.set_ROTATED([0,0,0],RELATIVE="kidney_channel_" + str(i) )

        channel_analyzer_1_center = kidney.add_component("channel_" + str(i) + "_analyzer_1_center","Arm")
        channel_analyzer_1_center.set_AT([0,0,"analyzer_1_center_to_sample"],RELATIVE="kidney_channel_"+str(i))

        channel_analyzer_1_rotated = kidney.add_component("channel_" + str(i) + "_analyzer_1_rotated","Arm")
        channel_analyzer_1_rotated.set_AT([0,0,"-0.5*analyzer_seperation/tan(analyzer_2theta[" + str(i) + "]*DEG2RAD)"],
            RELATIVE="channel_" + str(i) + "_analyzer_1_center")
        channel_analyzer_1_rotated.set_ROTATED([0,"180-analyzer_theta[" + str(i)+"]",0],
            RELATIVE="channel_" + str(i) + "_analyzer_1_center")

        kidney = append_vertical_crystal_array(kidney, name = "channel_" + str(i) + "_analyzer_1_array", 
            crystal_width = 0.06, crystal_height = 0.02, crystal_depth = 0.002, number_of_crystals = 9, 
            total_height = 0.18, radius_of_curvature = 0.5, 
            arm_name = "channel_" + str(i) + "_analyzer_1_rotated", priority_start = this_priority+20, 
            priority_end = this_priority+20.9, material_name = "PG_analyzer")

        channel_analyzer_2_center = kidney.add_component("channel_" + str(i) + "_analyzer_2_center","Arm")
        channel_analyzer_2_center.set_AT(["-analyzer_seperation",0,0],RELATIVE="channel_" + str(i) + "_analyzer_1_center")

        channel_analyzer_2_rotated = kidney.add_component("channel_" + str(i) + "_analyzer_2_rotated","Arm")
        channel_analyzer_2_rotated.set_AT([0,0,"0.5*analyzer_seperation/tan(analyzer_2theta[" + str(i) + "]*DEG2RAD)"],
         RELATIVE="channel_" + str(i) + "_analyzer_2_center")
        channel_analyzer_2_rotated.set_ROTATED([0,"-analyzer_theta[" + str(i) + "]",0],
            RELATIVE="channel_" + str(i) + "_analyzer_2_center")

        kidney=append_vertical_crystal_array(kidney, name = "channel_" + str(i) + "_analyzer_2_array", crystal_width = 0.06, crystal_height = 0.02, crystal_depth = 0.002,
         number_of_crystals = 9, total_height = 0.18, radius_of_curvature = 0.5,
          arm_name = "channel_" + str(i) + "_analyzer_2_rotated", priority_start = this_priority+21,
           priority_end = this_priority+21.9, material_name = "PG_analyzer")

        channel_cave2_cyl1 = kidney.add_component("channel_" + str(i) + "_cave2_cyl1","Union_cylinder")
        channel_cave2_cyl1.radius="kidney_cave2_cyl1_radius"
        channel_cave2_cyl1.yheight="kidney_cave2_cyl1_height"
        channel_cave2_cyl1.priority=this_priority+7.5
        channel_cave2_cyl1.material_string='"Vacuum"'
        channel_cave2_cyl1.set_AT([0,0,"spec_detector_to_analyzer_2_center"],RELATIVE="channel_" + str(i) + "_analyzer_2_center")
        channel_cave2_cyl1.set_ROTATED([0,0,0],RELATIVE="channel_" + str(i) + "_analyzer_2_center")

        channel_cave2_box1 = kidney.add_component("channel_" + str(i) + "_cave2_box1","Union_box")
        channel_cave2_box1.xwidth="kidney_cave2_box1_width1"
        channel_cave2_box1.yheight="kidney_cave2_box1_height1"
        channel_cave2_box1.zdepth="kidney_cave2_box1_depth"
        channel_cave2_box1.xwidth2="kidney_cave2_box1_width2"
        channel_cave2_box1.yheight2="kidney_cave2_box1_height2"
        channel_cave2_box1.priority=this_priority+1
        channel_cave2_box1.material_string='"Vacuum"'
        channel_cave2_box1.set_AT(["kidney_cave2_box1_center_to_spec_detector_x",0,"kidney_cave2_box1_center_to_spec_detector_z"],
         RELATIVE="channel_" + str(i) + "_cave2_cyl1")
        channel_cave2_box1.set_ROTATED([0,"kidney_cave2_box1_y_rotation",0],RELATIVE="channel_" + str(i) + "_cave2_cyl1")

        channel_cave2_box2 = kidney.add_component("channel_" + str(i) + "_cave2_box2","Union_box")
        channel_cave2_box2.xwidth="kidney_cave2_box2_width1"
        channel_cave2_box2.yheight="kidney_cave2_box2_height1"
        channel_cave2_box2.zdepth="kidney_cave2_box2_depth"
        channel_cave2_box2.xwidth2="kidney_cave2_box2_width2"
        channel_cave2_box2.yheight2="kidney_cave2_box2_height2"
        channel_cave2_box2.priority=this_priority+6
        channel_cave2_box2.material_string='"Vacuum"'
        channel_cave2_box2.set_AT([0,0,"kidney_cave2_box2_center_to_detector"], RELATIVE="channel_" + str(i) + "_cave2_cyl1")
        channel_cave2_box2.set_ROTATED([0,0,0],RELATIVE="channel_" + str(i) + "_cave2_cyl1")

        channel_cave2_box3 = kidney.add_component("channel_" + str(i) + "_cave2_box3","Union_box")
        channel_cave2_box3.xwidth= "kidney_cave2_box3_width1"
        channel_cave2_box3.yheight="kidney_cave2_box3_height1"
        channel_cave2_box3.zdepth="kidney_cave2_box3_depth"
        channel_cave2_box3.xwidth2="kidney_cave2_box3_width2"
        channel_cave2_box3.yheight2="kidney_cave2_box3_height2"
        channel_cave2_box3.priority=this_priority+7
        channel_cave2_box3.material_string='"Vacuum"'
        channel_cave2_box3.set_AT([0,0,"kidney_cave2_box3_center_to_detector"],
            RELATIVE="channel_" + str(i) + "_cave2_cyl1")
        channel_cave2_box3.set_ROTATED([0,0,0],RELATIVE="channel_" + str(i) + "_cave2_cyl1")

        inter_analyzer_collimator_center=kidney.add_component("inter_analyzer_colimator_center_" + str(i),"Arm")
        inter_analyzer_collimator_center.set_AT(["-0.5*analyzer_seperation",0,0],RELATIVE="channel_" + str(i) + "_analyzer_1_center")
        inter_analyzer_collimator_center.set_ROTATED([0,0,0], RELATIVE="channel_" + str(i) + "_analyzer_1_center")

        for j in range(0,5):
            inter_analyzer_collimator = kidney.add_component("inter_analyzer_colimator_" + str(i) + "_blade_" + str(j),"Union_box")
            inter_analyzer_collimator.xwidth= "inter_analyzer_colimator_width"
            inter_analyzer_collimator.yheight="inter_analyzer_colimator_height"
            inter_analyzer_collimator.zdepth="inter_analyzer_colimator_depth"
            inter_analyzer_collimator.priority=this_priority+25+j
            inter_analyzer_collimator.material_string='"Collimator_gad"'
            inter_analyzer_collimator.set_AT([0,0,"inter_analyzer_colimator_start_pos - " + str(j) + "*inter_analyzer_colimator_seperation"],
                RELATIVE="inter_analyzer_colimator_center_" + str(i) )
            inter_analyzer_collimator.set_ROTATED([0,"-analyzer_2theta[" + str(i) + "]",0],
                RELATIVE="inter_analyzer_colimator_center_" + str(i) )


        diffraction_detector = kidney.add_component("diffraction_detector_" + str(i) + "_exit_volume","Union_box")
        diffraction_detector.xwidth="2.01*detector_radius"
        diffraction_detector.yheight="1.01*detector_height"
        diffraction_detector.zdepth =0.001
        if enable_exit_diffraction[i] == 1:
            diffraction_detector.priority=this_priority+31
            diffraction_detector.material_string='"Exit"'
        else:
            diffraction_detector.priority=this_priority+31
            diffraction_detector.material_string='"Vacuum"'

        diffraction_detector.set_AT([0,0,0],RELATIVE="channel_" + str(i) + "_cave1_cyl1")
        diffraction_detector.set_ROTATED([0,0,0],RELATIVE="kidney_channel_" + str(i) )
        
        
        spec_detector_exit_volume = kidney.add_component("spec_detector_" + str(i) + "_exit_volume","Union_box")
        spec_detector_exit_volume.xwidth="2.01*detector_radius"
        spec_detector_exit_volume.yheight="1.01*detector_height"
        spec_detector_exit_volume.zdepth = 0.001
        if enable_exit_spectroscopy[i] == 1:
            spec_detector_exit_volume.priority=this_priority+32
            spec_detector_exit_volume.material_string='"Exit"'
        else:
            spec_detector_exit_volume.priority=this_priority+32
            spec_detector_exit_volume.material_string='"Vacuum"'    
        #kidney.append_trace("  AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_" + str(i) + "_analyzer_2_center")
        spec_detector_exit_volume.set_AT([0,0,0.0],RELATIVE="channel_" + str(i) + "_cave2_cyl1")
        spec_detector_exit_volume.set_ROTATED([0,0,0],RELATIVE="channel_" + str(i) + "_analyzer_2_center")


        if (enable_conditional[i] == 1):
            spec_detector_conditional = kidney.add_component("spec_detector_" + str(i) + "_conditional","Union_conditional_PSD")
            spec_detector_conditional.target_loggers='\"logger_zx_spatial_con_channel_' + str(i) + '_all,logger_zy_spatial_con_channel_' + str(i) +'_all,logger_zx_spatial_con_channel_' +\
             str(i) + '_1,logger_zy_spatial_con_channel_' + str(i) +"_1,logger_zx_spatial_con_channel_" + str(i) + "_2,logger_zy_spatial_con_channel_" + \
             str(i) +"_2,logger_zx_spatial_con_channel_" + str(i) + "_3,logger_zy_spatial_con_channel_" + str(i)\
              +"_3,logger_zx_spatial_con_channel_" + str(i) + "_4,logger_zy_spatial_con_channel_" + str(i) +'_4\"'
            spec_detector_conditional.xwidth = "2.0*detector_radius"
            spec_detector_conditional.yheight = "1.0*detector_height"
            spec_detector_conditional.overwrite_logger_weight=1
            spec_detector_conditional.set_AT([0,0,0.01],RELATIVE="channel_" + str(i) + "_cave2_cyl1")
            spec_detector_conditional.set_ROTATED([0,0,0],RELATIVE="channel_" + str(i) + "_analyzer_2_center")




    kidney_master = kidney.add_component("kidney_master","Union_master")
    kidney_master.inherit_number_of_scattering_events=1
    kidney_master.allow_inside_start=0
    kidney_master.set_AT([0,0,0])
    #kidney_stop = kidney.add_component("stop","Union_stop")

    kidney.add_declare_var("int","detector_channel_diff")
    kidney.add_declare_var("int","detector_channel_spec")
    kidney.add_declare_var("int","nx_detector")
    kidney.add_declare_var("int","ny_detector")
    kidney.append_initialize("nx_detector=5;")
    kidney.append_initialize("ny_detector=5;")
    kidney.add_declare_var("int","detector_found")


    for i in range(0,kidney_channels):
        
        diffraction_detector = kidney.add_component("diffraction_detector_" + str(i) ,"PSD_monitor",GROUP="detector_group")
        diffraction_detector.xwidth="2.0*detector_radius"
        diffraction_detector.yheight="1.0*detector_height"
        diffraction_detector.restore_neutron=1
        diffraction_detector.nx=5
        diffraction_detector.ny=5
        diffraction_detector.filename='"diff_detector_'+ str(i) + "\""
        diffraction_detector.set_AT([0,0,0],RELATIVE="diffraction_detector_" + str(i) + "_exit_volume")
        diffraction_detector.set_ROTATED([0,0,0],RELATIVE="diffraction_detector_" + str(i) + "_exit_volume")
        diffraction_detector.append_EXTEND("    if (SCATTERED) {")
        diffraction_detector.append_EXTEND("      detector_channel_diff =" + str(i) + ";")
        diffraction_detector.append_EXTEND("      detector_channel_spec =-1;")
        diffraction_detector.append_EXTEND("      detector_found = 1;")
        diffraction_detector.append_EXTEND("    }")

        spec_detector = kidney.add_component("spec_detector_" + str(i) ,"PSD_monitor",GROUP="detector_group")
        spec_detector.xwidth="2.0*detector_radius"
        spec_detector.yheight="1.0*detector_height"
        spec_detector.restore_neutron=1
        spec_detector.nx=5
        spec_detector.ny=5
        spec_detector.filename='"spec_detector_'+ str(i) + "\""
        spec_detector.set_AT([0,0,0.01],RELATIVE="spec_detector_" + str(i) + "_exit_volume")
        spec_detector.set_ROTATED([0,0,0.0],RELATIVE="spec_detector_" + str(i) + "_exit_volume")
        spec_detector.append_EXTEND("    if (SCATTERED) {")
        spec_detector.append_EXTEND("      detector_channel_spec =" + str(i) + ";")
        spec_detector.append_EXTEND("      detector_channel_diff =-1;")
        spec_detector.append_EXTEND("      detector_found = 1;")
        spec_detector.append_EXTEND("    }")
        

    for i in range(0,kidney_channels):
        if i==0:
            kidney.add_declare_var("int","flag_sum");
            kidney.add_declare_var("int","flag_single");
        '''
        spec_detector_history=kidney.add_component("spec_detector_history_" + str(i),"extend_monitor")
        spec_detector_history.xwidth="2.0*detector_radius"
        spec_detector_history.yheight="1.0*detector_height"
        spec_detector_history.restore_neutron=1
        spec_detector_history.nb="DOUBLE_MAX_VOLUME_HISTORY_LENGTH"
        spec_detector_history.filename='"spec_detector_history_'+ str(i)+"\""
        spec_detector_history.set_WHEN("detector_channel_spec == " + str(i) + " && detector_found ==1")
        spec_detector_history.set_AT([0,0,0],RELATIVE="spec_detector_" + str(i) + "_exit_volume")
        spec_detector_history.set_ROTATED([0,0,0],RELATIVE="spec_detector_" + str(i) + "_exit_volume")
        spec_detector_history.append_EXTEND("    if (SCATTERED) {")
        spec_detector_history.append_EXTEND("      flag_sum=0;")
        spec_detector_history.append_EXTEND("      for (flag_index=1;flag_index<MAX_VOLUME_HISTORY_LENGTH;flag_index++) {")
        spec_detector_history.append_EXTEND("        if (scattering_history_sample_master[flag_index] > 0) {")
        spec_detector_history.append_EXTEND("          C_N[flag_index+1]++;")
        spec_detector_history.append_EXTEND("          C_p[flag_index+1] += p;")
        spec_detector_history.append_EXTEND("          C_p2[flag_index+1] += p*p;")
        spec_detector_history.append_EXTEND("          flag_sum++;")
        spec_detector_history.append_EXTEND("          flag_single = flag_index;")
        spec_detector_history.append_EXTEND("        };")
        spec_detector_history.append_EXTEND("      };")
        spec_detector_history.append_EXTEND("      if (flag_sum == 0) {")
        spec_detector_history.append_EXTEND("        C_N[1]++;")
        spec_detector_history.append_EXTEND("        C_p[1] += p;")
        spec_detector_history.append_EXTEND("        C_p2[1] += p*p;")
        spec_detector_history.append_EXTEND("      };")
        spec_detector_history.append_EXTEND("      if (flag_sum == 1) {")
        spec_detector_history.append_EXTEND("        if (scattering_history_sample_master[flag_single] == 1) {")
        spec_detector_history.append_EXTEND("          C_N[MAX_VOLUME_HISTORY_LENGTH+flag_single+1]++;")
        spec_detector_history.append_EXTEND("          C_p[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p;")
        spec_detector_history.append_EXTEND("          C_p2[MAX_VOLUME_HISTORY_LENGTH+flag_single+1] += p*p;")
        spec_detector_history.append_EXTEND("        };")
        spec_detector_history.append_EXTEND("      };")
        spec_detector_history.append_EXTEND("    };")
        '''



    kidney.write_c_files()



    '''
    analyzator_test = McStas_class.McStas_part("analysator_test")
    McStas_class.append_vertical_crystal_array(analyzator_test, name = "first_array", crystal_width = 0.03, crystal_height = 0.02, crystal_depth = 0.002, number_of_crystals = 11, total_height = 0.24, radius_of_curvature = 2, arm_name = "analysator_array_pos", priority_start = 42.1, priority_end = 42.2, material_name = "PG")

    analyzator_test.write_c_files()
    '''
