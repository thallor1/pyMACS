COMPONENT inc_pg_mono = Incoherent_process(
 sigma = 0.004, packing_factor = 1,
 unit_cell_volume = 35.29, interact_fraction = -1)
AT (0,0,0) ABSOLUTE

COMPONENT crystal_pg_mono = Single_crystal_process(
 reflections = "C_graphite.lau", mosaic = 90,
 barns = 0, ax = 0,
 ay = 2.14, az = -1.24,
 bx = 0, by = 0,
 bz = 2.47, cx = 6.71,
 cy = 0, cz = 0,
 packing_factor = 1)
AT (0,0,0) ABSOLUTE
ROTATED (0,0,0) ABSOLUTE

COMPONENT Pg_mono = Union_make_material(
 process_string = "inc_pg_mono,crystal_pg_mono", my_absorption = 0.0396713)
AT (0,0,0) ABSOLUTE

COMPONENT inc_al_mono = Incoherent_process(
 sigma = 0.0328, packing_factor = 1,
 unit_cell_volume = 66.4)
AT (0,0,0) ABSOLUTE

COMPONENT pow_al_mono = Powder_process(
 reflections = "Al.laz")
AT (0,0,0) ABSOLUTE

COMPONENT al_mono = Union_make_material(
 process_string = "inc_al_mono,pow_al_mono", my_absorption = 1.39157)
AT (0,0,0) ABSOLUTE

COMPONENT mono_pil1 = Union_cylinder(
 material_string = "al_mono", priority = 5,
 radius = 0.01255, yheight = 1.2*mono_total_height,
 p_interact = 0.2)
AT (0.1976,0,0) RELATIVE mono
ROTATED (0,0,0) RELATIVE mono

COMPONENT mono_vacpil1 = Union_cylinder(
 material_string = "Vacuum", priority = 6,
 radius = 0.0109, yheight = 1.18*mono_total_height)
AT (0.1976,0,0) RELATIVE mono
ROTATED (0,0,0) RELATIVE mono

COMPONENT mono_pil2 = Union_cylinder(
 material_string = "al_mono", priority = 7,
 radius = 0.01255, yheight = 1.2*mono_total_height,
 p_interact = 0.2)
AT (-0.0988,0,-0.1711) RELATIVE mono
ROTATED (0,0,0) RELATIVE mono

COMPONENT mono_vacpil2 = Union_cylinder(
 material_string = "Vacuum", priority = 8,
 radius = 0.0109, yheight = 1.18*mono_total_height)
AT (-0.0988,0,-0.1711) RELATIVE mono
ROTATED (0,0,0) RELATIVE mono

COMPONENT mono_pil3 = Union_cylinder(
 material_string = "al_mono", priority = 9,
 radius = 0.01255, yheight = 1.2*mono_total_height,
 p_interact = 0.2)
AT (-0.0988,0,0.1711) RELATIVE mono
ROTATED (0,0,0) RELATIVE mono

COMPONENT mono_vacpil3 = Union_cylinder(
 material_string = "Vacuum", priority = 10,
 radius = 0.0109, yheight = 1.18*mono_total_height)
AT (-0.0988,0,0.1711) RELATIVE mono
ROTATED (0,0,0) RELATIVE mono

COMPONENT mono_array0_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[0]) RELATIVE mono
ROTATED (0,mono_psi[0],0) RELATIVE mono

COMPONENT mono_array0_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 30.1275,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[0])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[0]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 30.17,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[1])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[1]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 30.2125,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[2])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[2]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 30.255,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[3])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[3]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 30.2975,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[4])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[4]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 30.34,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[5])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[5]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 30.3825,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[6])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[6]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 30.425,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[7])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[7]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 30.4675,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[8])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[8]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 30.51,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[9])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[9]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 30.5525,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[10])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[10]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 30.595,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[11])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[11]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 30.6375,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[12])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[12]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 30.68,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[13])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[13]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 30.7225,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[14])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[14]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 30.765,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[15])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[15]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 30.8075,
 xwidth = mono_array0_crystal_depth, yheight = mono_array0_crystal_height,
 zdepth = mono_array0_crystal_width, p_interact = 0)
AT (mono_array0_effective_radius_of_curvature * (1-cos(mono_array0_theta[16])),mono_array0_effective_radius_of_curvature * sin(mono_array0_theta[16]),0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array0_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 30,
 radius = mono_array0_arch_outer_radius, yheight = mono_array0_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array0_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*30.0425,
 radius = mono_array0_arch_inner_radius, yheight = 0.0002+mono_array0_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array0_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array0_crystal_array_mounting_arch_mask = Union_box(
 priority = 30.085, xwidth = 0.05,
 yheight = 1.2*mono_array0_total_height+0.0, zdepth = 0.0004+mono_array0_crystal_width,
 visualize = 0, mask_string = "mono_array0_crystal_array_mounting_arch,mono_array0_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array0_mask_depth-0.025,0,0) RELATIVE mono_array0_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array0_crystal_array_arm

COMPONENT mono_array1_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[1]) RELATIVE mono
ROTATED (0,mono_psi[1],0) RELATIVE mono

COMPONENT mono_array1_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 31.1275,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[0])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[0]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 31.17,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[1])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[1]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 31.2125,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[2])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[2]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 31.255,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[3])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[3]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 31.2975,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[4])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[4]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 31.34,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[5])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[5]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 31.3825,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[6])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[6]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 31.425,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[7])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[7]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 31.4675,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[8])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[8]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 31.51,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[9])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[9]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 31.5525,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[10])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[10]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 31.595,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[11])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[11]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 31.6375,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[12])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[12]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 31.68,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[13])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[13]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 31.7225,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[14])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[14]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 31.765,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[15])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[15]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 31.8075,
 xwidth = mono_array1_crystal_depth, yheight = mono_array1_crystal_height,
 zdepth = mono_array1_crystal_width, p_interact = 0)
AT (mono_array1_effective_radius_of_curvature * (1-cos(mono_array1_theta[16])),mono_array1_effective_radius_of_curvature * sin(mono_array1_theta[16]),0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array1_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 31,
 radius = mono_array1_arch_outer_radius, yheight = mono_array1_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array1_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*31.0425,
 radius = mono_array1_arch_inner_radius, yheight = 0.0002+mono_array1_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array1_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array1_crystal_array_mounting_arch_mask = Union_box(
 priority = 31.085, xwidth = 0.05,
 yheight = 1.2*mono_array1_total_height+0.0002, zdepth = 0.0004+mono_array1_crystal_width,
 visualize = 0, mask_string = "mono_array1_crystal_array_mounting_arch,mono_array1_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array1_mask_depth-0.025,0,0) RELATIVE mono_array1_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array1_crystal_array_arm

COMPONENT mono_array2_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[2]) RELATIVE mono
ROTATED (0,mono_psi[2],0) RELATIVE mono

COMPONENT mono_array2_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 32.1275,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[0])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[0]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 32.17,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[1])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[1]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 32.2125,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[2])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[2]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 32.255,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[3])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[3]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 32.2975,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[4])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[4]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 32.34,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[5])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[5]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 32.3825,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[6])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[6]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 32.425,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[7])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[7]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 32.4675,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[8])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[8]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 32.51,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[9])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[9]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 32.5525,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[10])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[10]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 32.595,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[11])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[11]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 32.6375,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[12])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[12]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 32.68,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[13])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[13]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 32.7225,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[14])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[14]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 32.765,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[15])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[15]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 32.8075,
 xwidth = mono_array2_crystal_depth, yheight = mono_array2_crystal_height,
 zdepth = mono_array2_crystal_width, p_interact = 0)
AT (mono_array2_effective_radius_of_curvature * (1-cos(mono_array2_theta[16])),mono_array2_effective_radius_of_curvature * sin(mono_array2_theta[16]),0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array2_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 32,
 radius = mono_array2_arch_outer_radius, yheight = mono_array2_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array2_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*32.0425,
 radius = mono_array2_arch_inner_radius, yheight = 0.0002+mono_array2_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array2_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array2_crystal_array_mounting_arch_mask = Union_box(
 priority = 32.085, xwidth = 0.05,
 yheight = 1.2*mono_array2_total_height+0.0004, zdepth = 0.0004+mono_array2_crystal_width,
 visualize = 0, mask_string = "mono_array2_crystal_array_mounting_arch,mono_array2_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array2_mask_depth-0.025,0,0) RELATIVE mono_array2_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array2_crystal_array_arm

COMPONENT mono_array3_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[3]) RELATIVE mono
ROTATED (0,mono_psi[3],0) RELATIVE mono

COMPONENT mono_array3_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 33.1275,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[0])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[0]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 33.17,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[1])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[1]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 33.2125,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[2])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[2]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 33.255,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[3])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[3]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 33.2975,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[4])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[4]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 33.34,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[5])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[5]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 33.3825,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[6])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[6]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 33.425,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[7])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[7]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 33.4675,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[8])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[8]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 33.51,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[9])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[9]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 33.5525,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[10])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[10]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 33.595,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[11])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[11]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 33.6375,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[12])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[12]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 33.68,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[13])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[13]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 33.7225,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[14])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[14]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 33.765,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[15])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[15]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 33.8075,
 xwidth = mono_array3_crystal_depth, yheight = mono_array3_crystal_height,
 zdepth = mono_array3_crystal_width, p_interact = 0)
AT (mono_array3_effective_radius_of_curvature * (1-cos(mono_array3_theta[16])),mono_array3_effective_radius_of_curvature * sin(mono_array3_theta[16]),0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array3_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 33,
 radius = mono_array3_arch_outer_radius, yheight = mono_array3_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array3_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*33.0425,
 radius = mono_array3_arch_inner_radius, yheight = 0.0002+mono_array3_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array3_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array3_crystal_array_mounting_arch_mask = Union_box(
 priority = 33.085, xwidth = 0.05,
 yheight = 1.2*mono_array3_total_height+0.0006000000000000001, zdepth = 0.0004+mono_array3_crystal_width,
 visualize = 0, mask_string = "mono_array3_crystal_array_mounting_arch,mono_array3_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array3_mask_depth-0.025,0,0) RELATIVE mono_array3_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array3_crystal_array_arm

COMPONENT mono_array4_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[4]) RELATIVE mono
ROTATED (0,mono_psi[4],0) RELATIVE mono

COMPONENT mono_array4_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 34.1275,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[0])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[0]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 34.17,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[1])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[1]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 34.2125,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[2])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[2]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 34.255,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[3])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[3]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 34.2975,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[4])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[4]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 34.34,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[5])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[5]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 34.3825,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[6])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[6]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 34.425,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[7])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[7]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 34.4675,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[8])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[8]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 34.51,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[9])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[9]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 34.5525,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[10])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[10]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 34.595,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[11])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[11]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 34.6375,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[12])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[12]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 34.68,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[13])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[13]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 34.7225,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[14])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[14]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 34.765,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[15])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[15]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 34.8075,
 xwidth = mono_array4_crystal_depth, yheight = mono_array4_crystal_height,
 zdepth = mono_array4_crystal_width, p_interact = 0)
AT (mono_array4_effective_radius_of_curvature * (1-cos(mono_array4_theta[16])),mono_array4_effective_radius_of_curvature * sin(mono_array4_theta[16]),0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array4_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 34,
 radius = mono_array4_arch_outer_radius, yheight = mono_array4_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array4_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*34.0425,
 radius = mono_array4_arch_inner_radius, yheight = 0.0002+mono_array4_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array4_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array4_crystal_array_mounting_arch_mask = Union_box(
 priority = 34.085, xwidth = 0.05,
 yheight = 1.2*mono_array4_total_height+0.0008, zdepth = 0.0004+mono_array4_crystal_width,
 visualize = 0, mask_string = "mono_array4_crystal_array_mounting_arch,mono_array4_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array4_mask_depth-0.025,0,0) RELATIVE mono_array4_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array4_crystal_array_arm

COMPONENT mono_array5_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[5]) RELATIVE mono
ROTATED (0,mono_psi[5],0) RELATIVE mono

COMPONENT mono_array5_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 35.1275,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[0])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[0]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 35.17,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[1])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[1]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 35.2125,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[2])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[2]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 35.255,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[3])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[3]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 35.2975,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[4])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[4]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 35.34,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[5])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[5]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 35.3825,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[6])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[6]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 35.425,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[7])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[7]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 35.4675,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[8])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[8]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 35.51,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[9])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[9]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 35.5525,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[10])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[10]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 35.595,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[11])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[11]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 35.6375,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[12])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[12]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 35.68,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[13])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[13]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 35.7225,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[14])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[14]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 35.765,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[15])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[15]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 35.8075,
 xwidth = mono_array5_crystal_depth, yheight = mono_array5_crystal_height,
 zdepth = mono_array5_crystal_width, p_interact = 0)
AT (mono_array5_effective_radius_of_curvature * (1-cos(mono_array5_theta[16])),mono_array5_effective_radius_of_curvature * sin(mono_array5_theta[16]),0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array5_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 35,
 radius = mono_array5_arch_outer_radius, yheight = mono_array5_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array5_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*35.0425,
 radius = mono_array5_arch_inner_radius, yheight = 0.0002+mono_array5_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array5_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array5_crystal_array_mounting_arch_mask = Union_box(
 priority = 35.085, xwidth = 0.05,
 yheight = 1.2*mono_array5_total_height+0.001, zdepth = 0.0004+mono_array5_crystal_width,
 visualize = 0, mask_string = "mono_array5_crystal_array_mounting_arch,mono_array5_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array5_mask_depth-0.025,0,0) RELATIVE mono_array5_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array5_crystal_array_arm

COMPONENT mono_array6_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[6]) RELATIVE mono
ROTATED (0,mono_psi[6],0) RELATIVE mono

COMPONENT mono_array6_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 36.1275,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[0])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[0]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 36.17,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[1])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[1]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 36.2125,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[2])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[2]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 36.255,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[3])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[3]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 36.2975,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[4])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[4]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 36.34,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[5])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[5]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 36.3825,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[6])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[6]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 36.425,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[7])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[7]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 36.4675,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[8])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[8]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 36.51,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[9])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[9]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 36.5525,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[10])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[10]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 36.595,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[11])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[11]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 36.6375,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[12])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[12]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 36.68,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[13])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[13]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 36.7225,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[14])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[14]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 36.765,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[15])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[15]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 36.8075,
 xwidth = mono_array6_crystal_depth, yheight = mono_array6_crystal_height,
 zdepth = mono_array6_crystal_width, p_interact = 0)
AT (mono_array6_effective_radius_of_curvature * (1-cos(mono_array6_theta[16])),mono_array6_effective_radius_of_curvature * sin(mono_array6_theta[16]),0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array6_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 36,
 radius = mono_array6_arch_outer_radius, yheight = mono_array6_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array6_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*36.0425,
 radius = mono_array6_arch_inner_radius, yheight = 0.0002+mono_array6_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array6_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array6_crystal_array_mounting_arch_mask = Union_box(
 priority = 36.085, xwidth = 0.05,
 yheight = 1.2*mono_array6_total_height+0.0012000000000000001, zdepth = 0.0004+mono_array6_crystal_width,
 visualize = 0, mask_string = "mono_array6_crystal_array_mounting_arch,mono_array6_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array6_mask_depth-0.025,0,0) RELATIVE mono_array6_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array6_crystal_array_arm

COMPONENT mono_array7_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[7]) RELATIVE mono
ROTATED (0,mono_psi[7],0) RELATIVE mono

COMPONENT mono_array7_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 37.1275,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[0])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[0]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 37.17,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[1])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[1]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 37.2125,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[2])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[2]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 37.255,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[3])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[3]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 37.2975,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[4])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[4]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 37.34,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[5])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[5]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 37.3825,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[6])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[6]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 37.425,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[7])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[7]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 37.4675,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[8])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[8]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 37.51,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[9])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[9]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 37.5525,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[10])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[10]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 37.595,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[11])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[11]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 37.6375,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[12])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[12]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 37.68,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[13])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[13]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 37.7225,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[14])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[14]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 37.765,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[15])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[15]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 37.8075,
 xwidth = mono_array7_crystal_depth, yheight = mono_array7_crystal_height,
 zdepth = mono_array7_crystal_width, p_interact = 0)
AT (mono_array7_effective_radius_of_curvature * (1-cos(mono_array7_theta[16])),mono_array7_effective_radius_of_curvature * sin(mono_array7_theta[16]),0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array7_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 37,
 radius = mono_array7_arch_outer_radius, yheight = mono_array7_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array7_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*37.0425,
 radius = mono_array7_arch_inner_radius, yheight = 0.0002+mono_array7_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array7_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array7_crystal_array_mounting_arch_mask = Union_box(
 priority = 37.085, xwidth = 0.05,
 yheight = 1.2*mono_array7_total_height+0.0014, zdepth = 0.0004+mono_array7_crystal_width,
 visualize = 0, mask_string = "mono_array7_crystal_array_mounting_arch,mono_array7_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array7_mask_depth-0.025,0,0) RELATIVE mono_array7_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array7_crystal_array_arm

COMPONENT mono_array8_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[8]) RELATIVE mono
ROTATED (0,mono_psi[8],0) RELATIVE mono

COMPONENT mono_array8_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 38.1275,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[0])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[0]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 38.17,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[1])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[1]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 38.2125,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[2])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[2]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 38.255,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[3])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[3]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 38.2975,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[4])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[4]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 38.34,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[5])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[5]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 38.3825,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[6])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[6]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 38.425,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[7])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[7]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 38.4675,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[8])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[8]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 38.51,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[9])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[9]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 38.5525,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[10])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[10]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 38.595,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[11])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[11]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 38.6375,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[12])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[12]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 38.68,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[13])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[13]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 38.7225,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[14])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[14]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 38.765,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[15])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[15]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 38.8075,
 xwidth = mono_array8_crystal_depth, yheight = mono_array8_crystal_height,
 zdepth = mono_array8_crystal_width, p_interact = 0)
AT (mono_array8_effective_radius_of_curvature * (1-cos(mono_array8_theta[16])),mono_array8_effective_radius_of_curvature * sin(mono_array8_theta[16]),0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array8_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 38,
 radius = mono_array8_arch_outer_radius, yheight = mono_array8_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array8_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*38.0425,
 radius = mono_array8_arch_inner_radius, yheight = 0.0002+mono_array8_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array8_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array8_crystal_array_mounting_arch_mask = Union_box(
 priority = 38.085, xwidth = 0.05,
 yheight = 1.2*mono_array8_total_height+0.0016, zdepth = 0.0004+mono_array8_crystal_width,
 visualize = 0, mask_string = "mono_array8_crystal_array_mounting_arch,mono_array8_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array8_mask_depth-0.025,0,0) RELATIVE mono_array8_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array8_crystal_array_arm

COMPONENT mono_array9_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[9]) RELATIVE mono
ROTATED (0,mono_psi[9],0) RELATIVE mono

COMPONENT mono_array9_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 39.1275,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[0])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[0]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 39.17,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[1])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[1]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 39.2125,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[2])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[2]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 39.255,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[3])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[3]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 39.2975,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[4])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[4]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 39.34,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[5])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[5]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 39.3825,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[6])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[6]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 39.425,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[7])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[7]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 39.4675,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[8])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[8]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 39.51,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[9])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[9]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 39.5525,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[10])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[10]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 39.595,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[11])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[11]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 39.6375,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[12])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[12]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 39.68,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[13])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[13]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 39.7225,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[14])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[14]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 39.765,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[15])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[15]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 39.8075,
 xwidth = mono_array9_crystal_depth, yheight = mono_array9_crystal_height,
 zdepth = mono_array9_crystal_width, p_interact = 0)
AT (mono_array9_effective_radius_of_curvature * (1-cos(mono_array9_theta[16])),mono_array9_effective_radius_of_curvature * sin(mono_array9_theta[16]),0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array9_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 39,
 radius = mono_array9_arch_outer_radius, yheight = mono_array9_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array9_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*39.0425,
 radius = mono_array9_arch_inner_radius, yheight = 0.0002+mono_array9_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array9_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array9_crystal_array_mounting_arch_mask = Union_box(
 priority = 39.085, xwidth = 0.05,
 yheight = 1.2*mono_array9_total_height+0.0018000000000000002, zdepth = 0.0004+mono_array9_crystal_width,
 visualize = 0, mask_string = "mono_array9_crystal_array_mounting_arch,mono_array9_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array9_mask_depth-0.025,0,0) RELATIVE mono_array9_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array9_crystal_array_arm

COMPONENT mono_array10_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[10]) RELATIVE mono
ROTATED (0,mono_psi[10],0) RELATIVE mono

COMPONENT mono_array10_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 40.1275,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[0])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[0]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 40.17,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[1])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[1]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 40.2125,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[2])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[2]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 40.255,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[3])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[3]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 40.2975,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[4])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[4]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 40.34,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[5])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[5]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 40.3825,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[6])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[6]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 40.425,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[7])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[7]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 40.4675,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[8])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[8]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 40.51,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[9])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[9]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 40.5525,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[10])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[10]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 40.595,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[11])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[11]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 40.6375,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[12])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[12]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 40.68,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[13])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[13]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 40.7225,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[14])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[14]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 40.765,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[15])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[15]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 40.8075,
 xwidth = mono_array10_crystal_depth, yheight = mono_array10_crystal_height,
 zdepth = mono_array10_crystal_width, p_interact = 0)
AT (mono_array10_effective_radius_of_curvature * (1-cos(mono_array10_theta[16])),mono_array10_effective_radius_of_curvature * sin(mono_array10_theta[16]),0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array10_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 40,
 radius = mono_array10_arch_outer_radius, yheight = mono_array10_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array10_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*40.0425,
 radius = mono_array10_arch_inner_radius, yheight = 0.0002+mono_array10_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array10_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array10_crystal_array_mounting_arch_mask = Union_box(
 priority = 40.085, xwidth = 0.05,
 yheight = 1.2*mono_array10_total_height+0.002, zdepth = 0.0004+mono_array10_crystal_width,
 visualize = 0, mask_string = "mono_array10_crystal_array_mounting_arch,mono_array10_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array10_mask_depth-0.025,0,0) RELATIVE mono_array10_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array10_crystal_array_arm

COMPONENT mono_array11_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[11]) RELATIVE mono
ROTATED (0,mono_psi[11],0) RELATIVE mono

COMPONENT mono_array11_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 41.1275,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[0])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[0]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 41.17,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[1])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[1]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 41.2125,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[2])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[2]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 41.255,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[3])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[3]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 41.2975,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[4])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[4]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 41.34,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[5])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[5]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 41.3825,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[6])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[6]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 41.425,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[7])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[7]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 41.4675,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[8])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[8]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 41.51,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[9])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[9]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 41.5525,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[10])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[10]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 41.595,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[11])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[11]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 41.6375,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[12])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[12]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 41.68,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[13])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[13]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 41.7225,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[14])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[14]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 41.765,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[15])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[15]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 41.8075,
 xwidth = mono_array11_crystal_depth, yheight = mono_array11_crystal_height,
 zdepth = mono_array11_crystal_width, p_interact = 0)
AT (mono_array11_effective_radius_of_curvature * (1-cos(mono_array11_theta[16])),mono_array11_effective_radius_of_curvature * sin(mono_array11_theta[16]),0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array11_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 41,
 radius = mono_array11_arch_outer_radius, yheight = mono_array11_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array11_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*41.0425,
 radius = mono_array11_arch_inner_radius, yheight = 0.0002+mono_array11_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array11_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array11_crystal_array_mounting_arch_mask = Union_box(
 priority = 41.085, xwidth = 0.05,
 yheight = 1.2*mono_array11_total_height+0.0022, zdepth = 0.0004+mono_array11_crystal_width,
 visualize = 0, mask_string = "mono_array11_crystal_array_mounting_arch,mono_array11_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array11_mask_depth-0.025,0,0) RELATIVE mono_array11_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array11_crystal_array_arm

COMPONENT mono_array12_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[12]) RELATIVE mono
ROTATED (0,mono_psi[12],0) RELATIVE mono

COMPONENT mono_array12_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 42.1275,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[0])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[0]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 42.17,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[1])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[1]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 42.2125,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[2])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[2]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 42.255,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[3])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[3]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 42.2975,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[4])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[4]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 42.34,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[5])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[5]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 42.3825,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[6])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[6]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 42.425,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[7])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[7]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 42.4675,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[8])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[8]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 42.51,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[9])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[9]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 42.5525,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[10])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[10]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 42.595,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[11])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[11]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 42.6375,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[12])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[12]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 42.68,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[13])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[13]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 42.7225,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[14])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[14]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 42.765,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[15])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[15]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 42.8075,
 xwidth = mono_array12_crystal_depth, yheight = mono_array12_crystal_height,
 zdepth = mono_array12_crystal_width, p_interact = 0)
AT (mono_array12_effective_radius_of_curvature * (1-cos(mono_array12_theta[16])),mono_array12_effective_radius_of_curvature * sin(mono_array12_theta[16]),0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array12_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 42,
 radius = mono_array12_arch_outer_radius, yheight = mono_array12_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array12_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*42.0425,
 radius = mono_array12_arch_inner_radius, yheight = 0.0002+mono_array12_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array12_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array12_crystal_array_mounting_arch_mask = Union_box(
 priority = 42.085, xwidth = 0.05,
 yheight = 1.2*mono_array12_total_height+0.0024000000000000002, zdepth = 0.0004+mono_array12_crystal_width,
 visualize = 0, mask_string = "mono_array12_crystal_array_mounting_arch,mono_array12_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array12_mask_depth-0.025,0,0) RELATIVE mono_array12_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array12_crystal_array_arm

COMPONENT mono_array13_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[13]) RELATIVE mono
ROTATED (0,mono_psi[13],0) RELATIVE mono

COMPONENT mono_array13_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 43.1275,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[0])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[0]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 43.17,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[1])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[1]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 43.2125,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[2])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[2]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 43.255,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[3])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[3]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 43.2975,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[4])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[4]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 43.34,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[5])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[5]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 43.3825,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[6])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[6]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 43.425,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[7])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[7]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 43.4675,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[8])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[8]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 43.51,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[9])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[9]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 43.5525,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[10])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[10]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 43.595,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[11])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[11]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 43.6375,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[12])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[12]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 43.68,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[13])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[13]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 43.7225,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[14])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[14]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 43.765,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[15])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[15]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 43.8075,
 xwidth = mono_array13_crystal_depth, yheight = mono_array13_crystal_height,
 zdepth = mono_array13_crystal_width, p_interact = 0)
AT (mono_array13_effective_radius_of_curvature * (1-cos(mono_array13_theta[16])),mono_array13_effective_radius_of_curvature * sin(mono_array13_theta[16]),0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array13_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 43,
 radius = mono_array13_arch_outer_radius, yheight = mono_array13_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array13_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*43.0425,
 radius = mono_array13_arch_inner_radius, yheight = 0.0002+mono_array13_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array13_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array13_crystal_array_mounting_arch_mask = Union_box(
 priority = 43.085, xwidth = 0.05,
 yheight = 1.2*mono_array13_total_height+0.0026000000000000003, zdepth = 0.0004+mono_array13_crystal_width,
 visualize = 0, mask_string = "mono_array13_crystal_array_mounting_arch,mono_array13_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array13_mask_depth-0.025,0,0) RELATIVE mono_array13_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array13_crystal_array_arm

COMPONENT mono_array14_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[14]) RELATIVE mono
ROTATED (0,mono_psi[14],0) RELATIVE mono

COMPONENT mono_array14_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 44.1275,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[0])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[0]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 44.17,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[1])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[1]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 44.2125,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[2])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[2]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 44.255,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[3])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[3]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 44.2975,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[4])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[4]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 44.34,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[5])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[5]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 44.3825,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[6])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[6]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 44.425,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[7])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[7]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 44.4675,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[8])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[8]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 44.51,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[9])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[9]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 44.5525,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[10])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[10]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 44.595,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[11])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[11]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 44.6375,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[12])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[12]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 44.68,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[13])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[13]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 44.7225,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[14])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[14]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 44.765,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[15])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[15]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 44.8075,
 xwidth = mono_array14_crystal_depth, yheight = mono_array14_crystal_height,
 zdepth = mono_array14_crystal_width, p_interact = 0)
AT (mono_array14_effective_radius_of_curvature * (1-cos(mono_array14_theta[16])),mono_array14_effective_radius_of_curvature * sin(mono_array14_theta[16]),0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array14_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 44,
 radius = mono_array14_arch_outer_radius, yheight = mono_array14_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array14_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*44.0425,
 radius = mono_array14_arch_inner_radius, yheight = 0.0002+mono_array14_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array14_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array14_crystal_array_mounting_arch_mask = Union_box(
 priority = 44.085, xwidth = 0.05,
 yheight = 1.2*mono_array14_total_height+0.0028, zdepth = 0.0004+mono_array14_crystal_width,
 visualize = 0, mask_string = "mono_array14_crystal_array_mounting_arch,mono_array14_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array14_mask_depth-0.025,0,0) RELATIVE mono_array14_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array14_crystal_array_arm

COMPONENT mono_array15_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[15]) RELATIVE mono
ROTATED (0,mono_psi[15],0) RELATIVE mono

COMPONENT mono_array15_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 45.1275,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[0])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[0]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 45.17,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[1])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[1]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 45.2125,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[2])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[2]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 45.255,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[3])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[3]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 45.2975,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[4])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[4]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 45.34,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[5])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[5]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 45.3825,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[6])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[6]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 45.425,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[7])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[7]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 45.4675,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[8])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[8]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 45.51,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[9])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[9]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 45.5525,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[10])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[10]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 45.595,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[11])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[11]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 45.6375,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[12])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[12]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 45.68,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[13])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[13]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 45.7225,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[14])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[14]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 45.765,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[15])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[15]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 45.8075,
 xwidth = mono_array15_crystal_depth, yheight = mono_array15_crystal_height,
 zdepth = mono_array15_crystal_width, p_interact = 0)
AT (mono_array15_effective_radius_of_curvature * (1-cos(mono_array15_theta[16])),mono_array15_effective_radius_of_curvature * sin(mono_array15_theta[16]),0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array15_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 45,
 radius = mono_array15_arch_outer_radius, yheight = mono_array15_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array15_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*45.0425,
 radius = mono_array15_arch_inner_radius, yheight = 0.0002+mono_array15_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array15_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array15_crystal_array_mounting_arch_mask = Union_box(
 priority = 45.085, xwidth = 0.05,
 yheight = 1.2*mono_array15_total_height+0.003, zdepth = 0.0004+mono_array15_crystal_width,
 visualize = 0, mask_string = "mono_array15_crystal_array_mounting_arch,mono_array15_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array15_mask_depth-0.025,0,0) RELATIVE mono_array15_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array15_crystal_array_arm

COMPONENT mono_array16_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[16]) RELATIVE mono
ROTATED (0,mono_psi[16],0) RELATIVE mono

COMPONENT mono_array16_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 46.1275,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[0])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[0]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 46.17,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[1])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[1]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 46.2125,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[2])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[2]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 46.255,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[3])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[3]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 46.2975,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[4])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[4]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 46.34,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[5])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[5]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 46.3825,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[6])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[6]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 46.425,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[7])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[7]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 46.4675,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[8])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[8]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 46.51,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[9])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[9]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 46.5525,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[10])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[10]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 46.595,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[11])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[11]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 46.6375,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[12])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[12]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 46.68,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[13])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[13]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 46.7225,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[14])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[14]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 46.765,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[15])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[15]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 46.8075,
 xwidth = mono_array16_crystal_depth, yheight = mono_array16_crystal_height,
 zdepth = mono_array16_crystal_width, p_interact = 0)
AT (mono_array16_effective_radius_of_curvature * (1-cos(mono_array16_theta[16])),mono_array16_effective_radius_of_curvature * sin(mono_array16_theta[16]),0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array16_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 46,
 radius = mono_array16_arch_outer_radius, yheight = mono_array16_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array16_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*46.0425,
 radius = mono_array16_arch_inner_radius, yheight = 0.0002+mono_array16_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array16_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array16_crystal_array_mounting_arch_mask = Union_box(
 priority = 46.085, xwidth = 0.05,
 yheight = 1.2*mono_array16_total_height+0.0032, zdepth = 0.0004+mono_array16_crystal_width,
 visualize = 0, mask_string = "mono_array16_crystal_array_mounting_arch,mono_array16_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array16_mask_depth-0.025,0,0) RELATIVE mono_array16_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array16_crystal_array_arm

COMPONENT mono_array17_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[17]) RELATIVE mono
ROTATED (0,mono_psi[17],0) RELATIVE mono

COMPONENT mono_array17_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 47.1275,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[0])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[0]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 47.17,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[1])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[1]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 47.2125,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[2])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[2]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 47.255,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[3])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[3]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 47.2975,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[4])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[4]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 47.34,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[5])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[5]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 47.3825,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[6])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[6]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 47.425,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[7])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[7]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 47.4675,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[8])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[8]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 47.51,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[9])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[9]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 47.5525,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[10])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[10]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 47.595,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[11])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[11]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 47.6375,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[12])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[12]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 47.68,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[13])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[13]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 47.7225,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[14])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[14]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 47.765,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[15])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[15]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 47.8075,
 xwidth = mono_array17_crystal_depth, yheight = mono_array17_crystal_height,
 zdepth = mono_array17_crystal_width, p_interact = 0)
AT (mono_array17_effective_radius_of_curvature * (1-cos(mono_array17_theta[16])),mono_array17_effective_radius_of_curvature * sin(mono_array17_theta[16]),0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array17_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 47,
 radius = mono_array17_arch_outer_radius, yheight = mono_array17_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array17_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*47.0425,
 radius = mono_array17_arch_inner_radius, yheight = 0.0002+mono_array17_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array17_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array17_crystal_array_mounting_arch_mask = Union_box(
 priority = 47.085, xwidth = 0.05,
 yheight = 1.2*mono_array17_total_height+0.0034000000000000002, zdepth = 0.0004+mono_array17_crystal_width,
 visualize = 0, mask_string = "mono_array17_crystal_array_mounting_arch,mono_array17_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array17_mask_depth-0.025,0,0) RELATIVE mono_array17_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array17_crystal_array_arm

COMPONENT mono_array18_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[18]) RELATIVE mono
ROTATED (0,mono_psi[18],0) RELATIVE mono

COMPONENT mono_array18_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 48.1275,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[0])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[0]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 48.17,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[1])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[1]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 48.2125,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[2])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[2]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 48.255,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[3])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[3]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 48.2975,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[4])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[4]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 48.34,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[5])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[5]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 48.3825,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[6])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[6]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 48.425,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[7])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[7]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 48.4675,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[8])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[8]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 48.51,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[9])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[9]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 48.5525,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[10])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[10]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 48.595,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[11])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[11]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 48.6375,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[12])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[12]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 48.68,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[13])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[13]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 48.7225,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[14])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[14]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 48.765,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[15])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[15]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 48.8075,
 xwidth = mono_array18_crystal_depth, yheight = mono_array18_crystal_height,
 zdepth = mono_array18_crystal_width, p_interact = 0)
AT (mono_array18_effective_radius_of_curvature * (1-cos(mono_array18_theta[16])),mono_array18_effective_radius_of_curvature * sin(mono_array18_theta[16]),0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array18_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 48,
 radius = mono_array18_arch_outer_radius, yheight = mono_array18_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array18_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*48.0425,
 radius = mono_array18_arch_inner_radius, yheight = 0.0002+mono_array18_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array18_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array18_crystal_array_mounting_arch_mask = Union_box(
 priority = 48.085, xwidth = 0.05,
 yheight = 1.2*mono_array18_total_height+0.0036000000000000003, zdepth = 0.0004+mono_array18_crystal_width,
 visualize = 0, mask_string = "mono_array18_crystal_array_mounting_arch,mono_array18_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array18_mask_depth-0.025,0,0) RELATIVE mono_array18_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array18_crystal_array_arm

COMPONENT mono_array19_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[19]) RELATIVE mono
ROTATED (0,mono_psi[19],0) RELATIVE mono

COMPONENT mono_array19_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 49.1275,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[0])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[0]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 49.17,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[1])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[1]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 49.2125,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[2])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[2]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 49.255,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[3])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[3]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 49.2975,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[4])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[4]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 49.34,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[5])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[5]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 49.3825,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[6])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[6]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 49.425,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[7])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[7]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 49.4675,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[8])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[8]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 49.51,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[9])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[9]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 49.5525,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[10])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[10]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 49.595,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[11])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[11]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 49.6375,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[12])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[12]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 49.68,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[13])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[13]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 49.7225,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[14])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[14]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 49.765,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[15])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[15]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 49.8075,
 xwidth = mono_array19_crystal_depth, yheight = mono_array19_crystal_height,
 zdepth = mono_array19_crystal_width, p_interact = 0)
AT (mono_array19_effective_radius_of_curvature * (1-cos(mono_array19_theta[16])),mono_array19_effective_radius_of_curvature * sin(mono_array19_theta[16]),0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array19_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 49,
 radius = mono_array19_arch_outer_radius, yheight = mono_array19_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array19_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*49.0425,
 radius = mono_array19_arch_inner_radius, yheight = 0.0002+mono_array19_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array19_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array19_crystal_array_mounting_arch_mask = Union_box(
 priority = 49.085, xwidth = 0.05,
 yheight = 1.2*mono_array19_total_height+0.0038, zdepth = 0.0004+mono_array19_crystal_width,
 visualize = 0, mask_string = "mono_array19_crystal_array_mounting_arch,mono_array19_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array19_mask_depth-0.025,0,0) RELATIVE mono_array19_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array19_crystal_array_arm

COMPONENT mono_array20_crystal_array_arm = Arm()
AT (0,0,mono_column_displacements[20]) RELATIVE mono
ROTATED (0,mono_psi[20],0) RELATIVE mono

COMPONENT mono_array20_crystal_array_0 = Union_box(
 material_string = "Pg_mono", priority = 50.1275,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[0])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[0]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[0] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_1 = Union_box(
 material_string = "Pg_mono", priority = 50.17,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[1])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[1]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[1] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_2 = Union_box(
 material_string = "Pg_mono", priority = 50.2125,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[2])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[2]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[2] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_3 = Union_box(
 material_string = "Pg_mono", priority = 50.255,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[3])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[3]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[3] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_4 = Union_box(
 material_string = "Pg_mono", priority = 50.2975,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[4])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[4]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[4] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_5 = Union_box(
 material_string = "Pg_mono", priority = 50.34,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[5])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[5]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[5] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_6 = Union_box(
 material_string = "Pg_mono", priority = 50.3825,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[6])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[6]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[6] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_7 = Union_box(
 material_string = "Pg_mono", priority = 50.425,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[7])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[7]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[7] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_8 = Union_box(
 material_string = "Pg_mono", priority = 50.4675,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[8])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[8]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[8] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_9 = Union_box(
 material_string = "Pg_mono", priority = 50.51,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[9])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[9]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[9] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_10 = Union_box(
 material_string = "Pg_mono", priority = 50.5525,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[10])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[10]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[10] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_11 = Union_box(
 material_string = "Pg_mono", priority = 50.595,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[11])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[11]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[11] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_12 = Union_box(
 material_string = "Pg_mono", priority = 50.6375,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[12])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[12]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[12] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_13 = Union_box(
 material_string = "Pg_mono", priority = 50.68,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[13])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[13]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[13] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_14 = Union_box(
 material_string = "Pg_mono", priority = 50.7225,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[14])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[14]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[14] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_15 = Union_box(
 material_string = "Pg_mono", priority = 50.765,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[15])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[15]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[15] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_16 = Union_box(
 material_string = "Pg_mono", priority = 50.8075,
 xwidth = mono_array20_crystal_depth, yheight = mono_array20_crystal_height,
 zdepth = mono_array20_crystal_width, p_interact = 0)
AT (mono_array20_effective_radius_of_curvature * (1-cos(mono_array20_theta[16])),mono_array20_effective_radius_of_curvature * sin(mono_array20_theta[16]),0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,misalignment_deg*randnorm(),-RAD2DEG*mono_array20_theta[16] + misalignment_deg*randnorm()) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_mounting_arch = Union_cylinder(
 material_string = "al_mono", priority = 50,
 radius = mono_array20_arch_outer_radius, yheight = mono_array20_support_arch_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array20_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_mounting_arch_vacuum = Union_cylinder(
 material_string = "Vacuum", priority = 1*50.0425,
 radius = mono_array20_arch_inner_radius, yheight = 0.0002+mono_array20_crystal_width)
AT (mono_Radius_of_curvature,0,0) RELATIVE mono_array20_crystal_array_arm
ROTATED (90,0,0) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_array20_crystal_array_mounting_arch_mask = Union_box(
 priority = 50.085, xwidth = 0.05,
 yheight = 1.2*mono_array20_total_height+0.004, zdepth = 0.0004+mono_array20_crystal_width,
 visualize = 0, mask_string = "mono_array20_crystal_array_mounting_arch,mono_array20_crystal_array_mounting_arch_vacuum")
AT (1.05*mono_array20_mask_depth-0.025,0,0) RELATIVE mono_array20_crystal_array_arm
ROTATED (0,0,0) RELATIVE mono_array20_crystal_array_arm

COMPONENT mono_union_master = Union_master()
AT (0,0,0) RELATIVE mono
ROTATED (0,0,0) RELATIVE mono

COMPONENT stop = Union_stop()
AT (0,0,0) ABSOLUTE
ROTATED (0,0,0) ABSOLUTE

