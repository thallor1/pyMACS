COMPONENT kidney_master_arm = Arm()
AT (0,0,0) RELATIVE target
ROTATED (0,kidney_angle,0) RELATIVE target
EXTEND %{
 channel_selected = -1;
%}

COMPONENT kidney_channel_0 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-76.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_1 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-68.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_2 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-60.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_3 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-52.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_4 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-44.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_5 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-36.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_6 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-28.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_7 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-20.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_8 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-12.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_9 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-4.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_10 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,4.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_11 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,12.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_12 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,20.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_13 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,28.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_14 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,36.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_15 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,44.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_16 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,52.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_17 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,60.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_18 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,68.0,0) RELATIVE kidney_master_arm

COMPONENT kidney_channel_19 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,76.0,0) RELATIVE kidney_master_arm

COMPONENT channel_0_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_0
ROTATED (0,0,0) RELATIVE kidney_channel_0
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 0;
%}

COMPONENT channel_1_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_1
ROTATED (0,0,0) RELATIVE kidney_channel_1
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 1;
%}

COMPONENT channel_2_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_2
ROTATED (0,0,0) RELATIVE kidney_channel_2
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 2;
%}

COMPONENT channel_3_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_3
ROTATED (0,0,0) RELATIVE kidney_channel_3
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 3;
%}

COMPONENT channel_4_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_4
ROTATED (0,0,0) RELATIVE kidney_channel_4
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 4;
%}

COMPONENT channel_5_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_5
ROTATED (0,0,0) RELATIVE kidney_channel_5
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 5;
%}

COMPONENT channel_6_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_6
ROTATED (0,0,0) RELATIVE kidney_channel_6
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 6;
%}

COMPONENT channel_7_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_7
ROTATED (0,0,0) RELATIVE kidney_channel_7
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 7;
%}

COMPONENT channel_8_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_8
ROTATED (0,0,0) RELATIVE kidney_channel_8
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 8;
%}

COMPONENT channel_9_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_9
ROTATED (0,0,0) RELATIVE kidney_channel_9
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 9;
%}

COMPONENT channel_10_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_10
ROTATED (0,0,0) RELATIVE kidney_channel_10
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 10;
%}

COMPONENT channel_11_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_11
ROTATED (0,0,0) RELATIVE kidney_channel_11
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 11;
%}

COMPONENT channel_12_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_12
ROTATED (0,0,0) RELATIVE kidney_channel_12
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 12;
%}

COMPONENT channel_13_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_13
ROTATED (0,0,0) RELATIVE kidney_channel_13
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 13;
%}

COMPONENT channel_14_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_14
ROTATED (0,0,0) RELATIVE kidney_channel_14
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 14;
%}

COMPONENT channel_15_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_15
ROTATED (0,0,0) RELATIVE kidney_channel_15
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 15;
%}

COMPONENT channel_16_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_16
ROTATED (0,0,0) RELATIVE kidney_channel_16
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 16;
%}

COMPONENT channel_17_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_17
ROTATED (0,0,0) RELATIVE kidney_channel_17
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 17;
%}

COMPONENT channel_18_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_18
ROTATED (0,0,0) RELATIVE kidney_channel_18
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 18;
%}

COMPONENT channel_19_filter = Filter_gen_no_absorb(
 filename = "Be.trm", xwidth = filter_width,
 yheight = filter_height)
AT (0,0,target_filter_dist) RELATIVE kidney_channel_19
ROTATED (0,0,0) RELATIVE kidney_channel_19
GROUP filter_group
EXTEND %{
if (SCATTERED) channel_selected = 19;
%}

COMPONENT channel_selector = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,0,0) RELATIVE kidney_master_arm
EXTEND %{
if (channel_selected == -1) ABSORB;
detector_found = 0;
%}

COMPONENT channel_0_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 0)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_0
ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_1_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 1)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_1
ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_2_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 2)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_2
ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_3_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 3)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_3
ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_4_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 4)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_4
ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_5_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 5)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_5
ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_6_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 6)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_6
ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_7_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 7)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_7
ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_8_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 8)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_8
ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_9_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 9)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_9
ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_10_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 10)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_10
ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_11_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 11)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_11
ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_12_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 12)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_12
ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_13_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 13)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_13
ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_14_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 14)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_14
ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_15_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 15)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_15
ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_16_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 16)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_16
ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_17_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 17)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_17
ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_18_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 18)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_18
ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_19_colimator = Collimator_linear(
 xwidth = channel_colimator_width, yheight = channel_colimator_height,
 length = channel_colimator_length, divergence = channel_colimator_divergence_arcmin,
 transmission = channel_colimator_transmission)
WHEN (channel_selected == 19)
AT (0,0,channel_colimator_target_dist) RELATIVE kidney_channel_19
ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT boron_incoherent = Incoherent_process(
 sigma = 1.8, packing_factor = 1,
 unit_cell_volume = 1, interact_fraction = -1)
AT (0,0,0) ABSOLUTE

COMPONENT boron_plastic = Union_make_material(
 process_string = "boron_incoherent", my_absorption = 3495)
AT (0,0,0) ABSOLUTE

COMPONENT boron_plastic_enriched_incoherent = Incoherent_process(
 sigma = 2.82, packing_factor = 1,
 unit_cell_volume = 1, interact_fraction = -1)
AT (0,0,0) ABSOLUTE

COMPONENT boron_plastic_enriched = Union_make_material(
 process_string = "boron_plastic_enriched_incoherent", my_absorption = 8071)
AT (0,0,0) ABSOLUTE

COMPONENT Collimator_gad = Union_make_material(
 process_string = "", my_absorption = 45338.6,
 absorber = 1)
AT (0,0,0) ABSOLUTE

COMPONENT Incoherent_PG_analyzer = Incoherent_process(
 sigma = 0.004, packing_factor = 1,
 unit_cell_volume = 35.29, interact_fraction = -1)
AT (0,0,0) ABSOLUTE

COMPONENT Single_crystal_PG_analyzer = Single_crystal_process(
 reflections = "C_graphite.lau", mosaic = 80,
 barns = 0, ax = 0,
 ay = 2.24, az = -1.24,
 bx = 0, by = 0,
 bz = 2.47, cx = 6.71,
 cy = 0, cz = 0,
 packing_factor = 1)
AT (0,0,0) ABSOLUTE
ROTATED (0,0,0) ABSOLUTE

COMPONENT PG_analyzer = Union_make_material(
 process_string = "Single_crystal_PG_analyzer,Incoherent_PG_analyzer", my_absorption = 0.0396713)
AT (0,0,0) ABSOLUTE

COMPONENT kidney_hull = Union_cylinder(
 material_string = "boron_plastic", priority = 100,
 radius = kidney_hull_radius, yheight = kidney_hull_height,
 p_interact = 0.3)
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,0,0) RELATIVE kidney_master_arm

COMPONENT kidney_hull_cut = Union_cylinder(
 material_string = "Vacuum", priority = 100.5,
 radius = kidney_hull_inner_radius, yheight = 1.002*kidney_hull_height)
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,0,0) RELATIVE kidney_master_arm

COMPONENT kidney_hull_box_cut_arm1 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,0.5*kidney_cylinder_angle+90,0) RELATIVE kidney_master_arm

COMPONENT kidney_hull_box_cut1 = Union_box(
 material_string = "Vacuum", priority = 101,
 xwidth = 2.1*kidney_hull_radius, yheight = 1.003*kidney_hull_height,
 zdepth = 1.2*kidney_hull_radius, visualize = 0)
AT (0,0,0.6*kidney_hull_radius) RELATIVE kidney_hull_box_cut_arm1
ROTATED (0,0,0) RELATIVE kidney_hull_box_cut_arm1

COMPONENT kidney_hull_box_cut_arm2 = Arm()
AT (0,0,0) RELATIVE kidney_master_arm
ROTATED (0,-0.5*kidney_cylinder_angle-90,0) RELATIVE kidney_master_arm

COMPONENT kidney_hull_box_cut2 = Union_box(
 material_string = "Vacuum", priority = 102,
 xwidth = 2.1*kidney_hull_radius, yheight = 1.004*kidney_hull_height,
 zdepth = 1.2*kidney_hull_radius, visualize = 0)
AT (0,0,0.6*kidney_hull_radius) RELATIVE kidney_hull_box_cut_arm2
ROTATED (0,0,0) RELATIVE kidney_hull_box_cut_arm2

COMPONENT channel_0_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 200,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_0
ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_0_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 205,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_0
ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_0_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 202,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_0
ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_0_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 203,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_0
ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT channel_0_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_0

COMPONENT channel_0_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[0]*DEG2RAD)) RELATIVE channel_0_analyzer_1_center
ROTATED (0,180-analyzer_theta[0],0) RELATIVE channel_0_analyzer_1_center

COMPONENT channel_0_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 220,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[0])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[0]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[0]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 220.1,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[1])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[1]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[1]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 220.2,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[2])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[2]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[2]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 220.3,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[3])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[3]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[3]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 220.4,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[4])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[4]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[4]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 220.5,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[5])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[5]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[5]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 220.6,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[6])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[6]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[6]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 220.7,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[7])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[7]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[7]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 220.8,
 xwidth = channel_0_analyzer_1_array_crystal_depth, yheight = channel_0_analyzer_1_array_crystal_height,
 zdepth = channel_0_analyzer_1_array_crystal_width)
AT (0 + channel_0_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_1_array_theta[8])),0 + channel_0_analyzer_1_array_effective_radius_of_curvature * sin(channel_0_analyzer_1_array_theta[8]),0) RELATIVE channel_0_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_1_array_theta[8]) RELATIVE channel_0_analyzer_1_rotated

COMPONENT channel_0_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_0_analyzer_1_center

COMPONENT channel_0_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[0]*DEG2RAD)) RELATIVE channel_0_analyzer_2_center
ROTATED (0,-analyzer_theta[0],0) RELATIVE channel_0_analyzer_2_center

COMPONENT channel_0_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 221,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[0])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[0]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[0]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 221.1,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[1])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[1]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[1]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 221.2,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[2])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[2]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[2]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 221.3,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[3])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[3]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[3]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 221.4,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[4])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[4]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[4]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 221.5,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[5])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[5]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[5]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 221.6,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[6])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[6]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[6]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 221.7,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[7])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[7]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[7]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 221.8,
 xwidth = channel_0_analyzer_2_array_crystal_depth, yheight = channel_0_analyzer_2_array_crystal_height,
 zdepth = channel_0_analyzer_2_array_crystal_width)
AT (0 + channel_0_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_0_analyzer_2_array_theta[8])),0 + channel_0_analyzer_2_array_effective_radius_of_curvature * sin(channel_0_analyzer_2_array_theta[8]),0) RELATIVE channel_0_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_0_analyzer_2_array_theta[8]) RELATIVE channel_0_analyzer_2_rotated

COMPONENT channel_0_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 207.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_0_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_0_analyzer_2_center

COMPONENT channel_0_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 201,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_0_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_0_cave2_cyl1

COMPONENT channel_0_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 206,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_0_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_0_cave2_cyl1

COMPONENT channel_0_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 207,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_0_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_0_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_0 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_0_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_0_analyzer_1_center

COMPONENT inter_analyzer_colimator_0_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 225,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 226,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 227,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 228,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT inter_analyzer_colimator_0_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 229,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_0
ROTATED (0,-analyzer_2theta[0],0) RELATIVE inter_analyzer_colimator_center_0

COMPONENT diffraction_detector_0_exit_volume = Union_box(
 material_string = "Exit", priority = 231,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_0_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_0

COMPONENT spec_detector_0_exit_volume = Union_box(
 material_string = "Exit", priority = 232,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_0_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_0_analyzer_2_center

COMPONENT channel_1_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 300,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_1
ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 305,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_1
ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 302,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_1
ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 303,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_1
ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT channel_1_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_1

COMPONENT channel_1_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[1]*DEG2RAD)) RELATIVE channel_1_analyzer_1_center
ROTATED (0,180-analyzer_theta[1],0) RELATIVE channel_1_analyzer_1_center

COMPONENT channel_1_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 320,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[0])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[0]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[0]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 320.1,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[1])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[1]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[1]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 320.2,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[2])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[2]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[2]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 320.3,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[3])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[3]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[3]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 320.4,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[4])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[4]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[4]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 320.5,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[5])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[5]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[5]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 320.6,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[6])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[6]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[6]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 320.7,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[7])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[7]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[7]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 320.8,
 xwidth = channel_1_analyzer_1_array_crystal_depth, yheight = channel_1_analyzer_1_array_crystal_height,
 zdepth = channel_1_analyzer_1_array_crystal_width)
AT (0 + channel_1_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_1_array_theta[8])),0 + channel_1_analyzer_1_array_effective_radius_of_curvature * sin(channel_1_analyzer_1_array_theta[8]),0) RELATIVE channel_1_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_1_array_theta[8]) RELATIVE channel_1_analyzer_1_rotated

COMPONENT channel_1_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_1_analyzer_1_center

COMPONENT channel_1_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[1]*DEG2RAD)) RELATIVE channel_1_analyzer_2_center
ROTATED (0,-analyzer_theta[1],0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_1_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 321,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[0])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[0]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[0]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 321.1,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[1])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[1]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[1]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 321.2,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[2])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[2]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[2]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 321.3,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[3])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[3]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[3]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 321.4,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[4])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[4]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[4]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 321.5,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[5])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[5]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[5]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 321.6,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[6])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[6]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[6]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 321.7,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[7])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[7]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[7]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 321.8,
 xwidth = channel_1_analyzer_2_array_crystal_depth, yheight = channel_1_analyzer_2_array_crystal_height,
 zdepth = channel_1_analyzer_2_array_crystal_width)
AT (0 + channel_1_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_1_analyzer_2_array_theta[8])),0 + channel_1_analyzer_2_array_effective_radius_of_curvature * sin(channel_1_analyzer_2_array_theta[8]),0) RELATIVE channel_1_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_1_analyzer_2_array_theta[8]) RELATIVE channel_1_analyzer_2_rotated

COMPONENT channel_1_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 307.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_1_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_1_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 301,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_1_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_1_cave2_cyl1

COMPONENT channel_1_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 306,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_1_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_1_cave2_cyl1

COMPONENT channel_1_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 307,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_1_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_1_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_1 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_1_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_1_analyzer_1_center

COMPONENT inter_analyzer_colimator_1_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 325,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 326,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 327,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 328,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT inter_analyzer_colimator_1_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 329,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_1
ROTATED (0,-analyzer_2theta[1],0) RELATIVE inter_analyzer_colimator_center_1

COMPONENT diffraction_detector_1_exit_volume = Union_box(
 material_string = "Exit", priority = 331,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_1_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_1

COMPONENT spec_detector_1_exit_volume = Union_box(
 material_string = "Exit", priority = 332,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_1_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_1_analyzer_2_center

COMPONENT channel_2_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 400,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_2
ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 405,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_2
ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 402,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_2
ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 403,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_2
ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT channel_2_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_2

COMPONENT channel_2_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[2]*DEG2RAD)) RELATIVE channel_2_analyzer_1_center
ROTATED (0,180-analyzer_theta[2],0) RELATIVE channel_2_analyzer_1_center

COMPONENT channel_2_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 420,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[0])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[0]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[0]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 420.1,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[1])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[1]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[1]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 420.2,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[2])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[2]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[2]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 420.3,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[3])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[3]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[3]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 420.4,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[4])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[4]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[4]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 420.5,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[5])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[5]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[5]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 420.6,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[6])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[6]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[6]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 420.7,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[7])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[7]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[7]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 420.8,
 xwidth = channel_2_analyzer_1_array_crystal_depth, yheight = channel_2_analyzer_1_array_crystal_height,
 zdepth = channel_2_analyzer_1_array_crystal_width)
AT (0 + channel_2_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_1_array_theta[8])),0 + channel_2_analyzer_1_array_effective_radius_of_curvature * sin(channel_2_analyzer_1_array_theta[8]),0) RELATIVE channel_2_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_1_array_theta[8]) RELATIVE channel_2_analyzer_1_rotated

COMPONENT channel_2_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_2_analyzer_1_center

COMPONENT channel_2_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[2]*DEG2RAD)) RELATIVE channel_2_analyzer_2_center
ROTATED (0,-analyzer_theta[2],0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_2_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 421,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[0])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[0]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[0]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 421.1,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[1])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[1]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[1]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 421.2,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[2])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[2]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[2]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 421.3,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[3])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[3]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[3]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 421.4,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[4])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[4]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[4]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 421.5,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[5])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[5]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[5]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 421.6,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[6])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[6]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[6]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 421.7,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[7])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[7]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[7]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 421.8,
 xwidth = channel_2_analyzer_2_array_crystal_depth, yheight = channel_2_analyzer_2_array_crystal_height,
 zdepth = channel_2_analyzer_2_array_crystal_width)
AT (0 + channel_2_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_2_analyzer_2_array_theta[8])),0 + channel_2_analyzer_2_array_effective_radius_of_curvature * sin(channel_2_analyzer_2_array_theta[8]),0) RELATIVE channel_2_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_2_analyzer_2_array_theta[8]) RELATIVE channel_2_analyzer_2_rotated

COMPONENT channel_2_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 407.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_2_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_2_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 401,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_2_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_2_cave2_cyl1

COMPONENT channel_2_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 406,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_2_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_2_cave2_cyl1

COMPONENT channel_2_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 407,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_2_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_2_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_2 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_2_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_2_analyzer_1_center

COMPONENT inter_analyzer_colimator_2_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 425,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 426,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 427,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 428,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT inter_analyzer_colimator_2_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 429,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_2
ROTATED (0,-analyzer_2theta[2],0) RELATIVE inter_analyzer_colimator_center_2

COMPONENT diffraction_detector_2_exit_volume = Union_box(
 material_string = "Exit", priority = 431,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_2_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_2

COMPONENT spec_detector_2_exit_volume = Union_box(
 material_string = "Exit", priority = 432,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_2_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_2_analyzer_2_center

COMPONENT channel_3_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 500,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_3
ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_3_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 505,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_3
ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_3_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 502,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_3
ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_3_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 503,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_3
ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT channel_3_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_3

COMPONENT channel_3_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[3]*DEG2RAD)) RELATIVE channel_3_analyzer_1_center
ROTATED (0,180-analyzer_theta[3],0) RELATIVE channel_3_analyzer_1_center

COMPONENT channel_3_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 520,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[0])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[0]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[0]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 520.1,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[1])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[1]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[1]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 520.2,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[2])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[2]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[2]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 520.3,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[3])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[3]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[3]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 520.4,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[4])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[4]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[4]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 520.5,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[5])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[5]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[5]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 520.6,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[6])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[6]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[6]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 520.7,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[7])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[7]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[7]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 520.8,
 xwidth = channel_3_analyzer_1_array_crystal_depth, yheight = channel_3_analyzer_1_array_crystal_height,
 zdepth = channel_3_analyzer_1_array_crystal_width)
AT (0 + channel_3_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_1_array_theta[8])),0 + channel_3_analyzer_1_array_effective_radius_of_curvature * sin(channel_3_analyzer_1_array_theta[8]),0) RELATIVE channel_3_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_1_array_theta[8]) RELATIVE channel_3_analyzer_1_rotated

COMPONENT channel_3_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_3_analyzer_1_center

COMPONENT channel_3_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[3]*DEG2RAD)) RELATIVE channel_3_analyzer_2_center
ROTATED (0,-analyzer_theta[3],0) RELATIVE channel_3_analyzer_2_center

COMPONENT channel_3_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 521,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[0])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[0]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[0]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 521.1,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[1])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[1]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[1]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 521.2,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[2])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[2]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[2]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 521.3,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[3])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[3]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[3]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 521.4,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[4])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[4]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[4]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 521.5,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[5])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[5]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[5]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 521.6,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[6])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[6]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[6]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 521.7,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[7])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[7]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[7]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 521.8,
 xwidth = channel_3_analyzer_2_array_crystal_depth, yheight = channel_3_analyzer_2_array_crystal_height,
 zdepth = channel_3_analyzer_2_array_crystal_width)
AT (0 + channel_3_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_3_analyzer_2_array_theta[8])),0 + channel_3_analyzer_2_array_effective_radius_of_curvature * sin(channel_3_analyzer_2_array_theta[8]),0) RELATIVE channel_3_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_3_analyzer_2_array_theta[8]) RELATIVE channel_3_analyzer_2_rotated

COMPONENT channel_3_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 507.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_3_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_3_analyzer_2_center

COMPONENT channel_3_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 501,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_3_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_3_cave2_cyl1

COMPONENT channel_3_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 506,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_3_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_3_cave2_cyl1

COMPONENT channel_3_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 507,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_3_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_3_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_3 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_3_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_3_analyzer_1_center

COMPONENT inter_analyzer_colimator_3_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 525,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 526,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 527,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 528,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT inter_analyzer_colimator_3_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 529,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_3
ROTATED (0,-analyzer_2theta[3],0) RELATIVE inter_analyzer_colimator_center_3

COMPONENT diffraction_detector_3_exit_volume = Union_box(
 material_string = "Exit", priority = 531,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_3_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_3

COMPONENT spec_detector_3_exit_volume = Union_box(
 material_string = "Exit", priority = 532,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_3_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_3_analyzer_2_center

COMPONENT channel_4_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 600,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_4
ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_4_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 605,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_4
ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_4_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 602,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_4
ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_4_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 603,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_4
ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT channel_4_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_4

COMPONENT channel_4_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[4]*DEG2RAD)) RELATIVE channel_4_analyzer_1_center
ROTATED (0,180-analyzer_theta[4],0) RELATIVE channel_4_analyzer_1_center

COMPONENT channel_4_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 620,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[0])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[0]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[0]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 620.1,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[1])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[1]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[1]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 620.2,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[2])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[2]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[2]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 620.3,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[3])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[3]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[3]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 620.4,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[4])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[4]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[4]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 620.5,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[5])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[5]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[5]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 620.6,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[6])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[6]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[6]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 620.7,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[7])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[7]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[7]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 620.8,
 xwidth = channel_4_analyzer_1_array_crystal_depth, yheight = channel_4_analyzer_1_array_crystal_height,
 zdepth = channel_4_analyzer_1_array_crystal_width)
AT (0 + channel_4_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_1_array_theta[8])),0 + channel_4_analyzer_1_array_effective_radius_of_curvature * sin(channel_4_analyzer_1_array_theta[8]),0) RELATIVE channel_4_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_1_array_theta[8]) RELATIVE channel_4_analyzer_1_rotated

COMPONENT channel_4_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_4_analyzer_1_center

COMPONENT channel_4_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[4]*DEG2RAD)) RELATIVE channel_4_analyzer_2_center
ROTATED (0,-analyzer_theta[4],0) RELATIVE channel_4_analyzer_2_center

COMPONENT channel_4_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 621,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[0])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[0]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[0]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 621.1,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[1])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[1]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[1]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 621.2,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[2])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[2]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[2]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 621.3,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[3])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[3]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[3]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 621.4,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[4])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[4]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[4]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 621.5,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[5])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[5]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[5]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 621.6,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[6])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[6]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[6]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 621.7,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[7])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[7]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[7]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 621.8,
 xwidth = channel_4_analyzer_2_array_crystal_depth, yheight = channel_4_analyzer_2_array_crystal_height,
 zdepth = channel_4_analyzer_2_array_crystal_width)
AT (0 + channel_4_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_4_analyzer_2_array_theta[8])),0 + channel_4_analyzer_2_array_effective_radius_of_curvature * sin(channel_4_analyzer_2_array_theta[8]),0) RELATIVE channel_4_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_4_analyzer_2_array_theta[8]) RELATIVE channel_4_analyzer_2_rotated

COMPONENT channel_4_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 607.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_4_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_4_analyzer_2_center

COMPONENT channel_4_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 601,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_4_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_4_cave2_cyl1

COMPONENT channel_4_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 606,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_4_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_4_cave2_cyl1

COMPONENT channel_4_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 607,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_4_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_4_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_4 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_4_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_4_analyzer_1_center

COMPONENT inter_analyzer_colimator_4_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 625,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 626,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 627,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 628,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT inter_analyzer_colimator_4_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 629,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_4
ROTATED (0,-analyzer_2theta[4],0) RELATIVE inter_analyzer_colimator_center_4

COMPONENT diffraction_detector_4_exit_volume = Union_box(
 material_string = "Exit", priority = 631,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_4_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_4

COMPONENT spec_detector_4_exit_volume = Union_box(
 material_string = "Exit", priority = 632,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_4_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_4_analyzer_2_center

COMPONENT channel_5_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 700,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_5
ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_5_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 705,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_5
ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_5_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 702,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_5
ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_5_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 703,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_5
ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT channel_5_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_5

COMPONENT channel_5_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[5]*DEG2RAD)) RELATIVE channel_5_analyzer_1_center
ROTATED (0,180-analyzer_theta[5],0) RELATIVE channel_5_analyzer_1_center

COMPONENT channel_5_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 720,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[0])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[0]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[0]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 720.1,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[1])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[1]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[1]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 720.2,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[2])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[2]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[2]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 720.3,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[3])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[3]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[3]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 720.4,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[4])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[4]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[4]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 720.5,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[5])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[5]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[5]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 720.6,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[6])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[6]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[6]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 720.7,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[7])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[7]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[7]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 720.8,
 xwidth = channel_5_analyzer_1_array_crystal_depth, yheight = channel_5_analyzer_1_array_crystal_height,
 zdepth = channel_5_analyzer_1_array_crystal_width)
AT (0 + channel_5_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_1_array_theta[8])),0 + channel_5_analyzer_1_array_effective_radius_of_curvature * sin(channel_5_analyzer_1_array_theta[8]),0) RELATIVE channel_5_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_1_array_theta[8]) RELATIVE channel_5_analyzer_1_rotated

COMPONENT channel_5_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_5_analyzer_1_center

COMPONENT channel_5_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[5]*DEG2RAD)) RELATIVE channel_5_analyzer_2_center
ROTATED (0,-analyzer_theta[5],0) RELATIVE channel_5_analyzer_2_center

COMPONENT channel_5_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 721,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[0])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[0]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[0]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 721.1,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[1])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[1]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[1]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 721.2,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[2])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[2]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[2]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 721.3,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[3])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[3]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[3]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 721.4,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[4])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[4]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[4]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 721.5,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[5])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[5]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[5]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 721.6,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[6])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[6]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[6]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 721.7,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[7])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[7]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[7]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 721.8,
 xwidth = channel_5_analyzer_2_array_crystal_depth, yheight = channel_5_analyzer_2_array_crystal_height,
 zdepth = channel_5_analyzer_2_array_crystal_width)
AT (0 + channel_5_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_5_analyzer_2_array_theta[8])),0 + channel_5_analyzer_2_array_effective_radius_of_curvature * sin(channel_5_analyzer_2_array_theta[8]),0) RELATIVE channel_5_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_5_analyzer_2_array_theta[8]) RELATIVE channel_5_analyzer_2_rotated

COMPONENT channel_5_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 707.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_5_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_5_analyzer_2_center

COMPONENT channel_5_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 701,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_5_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_5_cave2_cyl1

COMPONENT channel_5_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 706,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_5_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_5_cave2_cyl1

COMPONENT channel_5_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 707,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_5_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_5_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_5 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_5_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_5_analyzer_1_center

COMPONENT inter_analyzer_colimator_5_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 725,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 726,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 727,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 728,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT inter_analyzer_colimator_5_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 729,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_5
ROTATED (0,-analyzer_2theta[5],0) RELATIVE inter_analyzer_colimator_center_5

COMPONENT diffraction_detector_5_exit_volume = Union_box(
 material_string = "Exit", priority = 731,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_5_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_5

COMPONENT spec_detector_5_exit_volume = Union_box(
 material_string = "Exit", priority = 732,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_5_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_5_analyzer_2_center

COMPONENT channel_6_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 800,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_6
ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_6_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 805,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_6
ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_6_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 802,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_6
ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_6_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 803,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_6
ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT channel_6_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_6

COMPONENT channel_6_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[6]*DEG2RAD)) RELATIVE channel_6_analyzer_1_center
ROTATED (0,180-analyzer_theta[6],0) RELATIVE channel_6_analyzer_1_center

COMPONENT channel_6_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 820,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[0])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[0]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[0]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 820.1,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[1])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[1]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[1]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 820.2,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[2])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[2]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[2]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 820.3,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[3])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[3]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[3]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 820.4,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[4])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[4]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[4]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 820.5,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[5])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[5]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[5]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 820.6,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[6])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[6]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[6]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 820.7,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[7])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[7]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[7]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 820.8,
 xwidth = channel_6_analyzer_1_array_crystal_depth, yheight = channel_6_analyzer_1_array_crystal_height,
 zdepth = channel_6_analyzer_1_array_crystal_width)
AT (0 + channel_6_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_1_array_theta[8])),0 + channel_6_analyzer_1_array_effective_radius_of_curvature * sin(channel_6_analyzer_1_array_theta[8]),0) RELATIVE channel_6_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_1_array_theta[8]) RELATIVE channel_6_analyzer_1_rotated

COMPONENT channel_6_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_6_analyzer_1_center

COMPONENT channel_6_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[6]*DEG2RAD)) RELATIVE channel_6_analyzer_2_center
ROTATED (0,-analyzer_theta[6],0) RELATIVE channel_6_analyzer_2_center

COMPONENT channel_6_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 821,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[0])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[0]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[0]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 821.1,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[1])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[1]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[1]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 821.2,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[2])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[2]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[2]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 821.3,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[3])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[3]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[3]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 821.4,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[4])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[4]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[4]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 821.5,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[5])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[5]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[5]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 821.6,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[6])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[6]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[6]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 821.7,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[7])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[7]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[7]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 821.8,
 xwidth = channel_6_analyzer_2_array_crystal_depth, yheight = channel_6_analyzer_2_array_crystal_height,
 zdepth = channel_6_analyzer_2_array_crystal_width)
AT (0 + channel_6_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_6_analyzer_2_array_theta[8])),0 + channel_6_analyzer_2_array_effective_radius_of_curvature * sin(channel_6_analyzer_2_array_theta[8]),0) RELATIVE channel_6_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_6_analyzer_2_array_theta[8]) RELATIVE channel_6_analyzer_2_rotated

COMPONENT channel_6_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 807.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_6_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_6_analyzer_2_center

COMPONENT channel_6_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 801,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_6_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_6_cave2_cyl1

COMPONENT channel_6_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 806,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_6_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_6_cave2_cyl1

COMPONENT channel_6_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 807,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_6_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_6_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_6 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_6_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_6_analyzer_1_center

COMPONENT inter_analyzer_colimator_6_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 825,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 826,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 827,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 828,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT inter_analyzer_colimator_6_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 829,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_6
ROTATED (0,-analyzer_2theta[6],0) RELATIVE inter_analyzer_colimator_center_6

COMPONENT diffraction_detector_6_exit_volume = Union_box(
 material_string = "Exit", priority = 831,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_6_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_6

COMPONENT spec_detector_6_exit_volume = Union_box(
 material_string = "Exit", priority = 832,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_6_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_6_analyzer_2_center

COMPONENT channel_7_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 900,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_7
ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_7_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 905,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_7
ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_7_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 902,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_7
ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_7_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 903,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_7
ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT channel_7_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_7

COMPONENT channel_7_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[7]*DEG2RAD)) RELATIVE channel_7_analyzer_1_center
ROTATED (0,180-analyzer_theta[7],0) RELATIVE channel_7_analyzer_1_center

COMPONENT channel_7_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 920,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[0])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[0]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[0]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 920.1,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[1])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[1]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[1]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 920.2,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[2])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[2]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[2]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 920.3,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[3])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[3]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[3]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 920.4,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[4])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[4]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[4]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 920.5,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[5])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[5]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[5]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 920.6,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[6])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[6]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[6]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 920.7,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[7])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[7]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[7]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 920.8,
 xwidth = channel_7_analyzer_1_array_crystal_depth, yheight = channel_7_analyzer_1_array_crystal_height,
 zdepth = channel_7_analyzer_1_array_crystal_width)
AT (0 + channel_7_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_1_array_theta[8])),0 + channel_7_analyzer_1_array_effective_radius_of_curvature * sin(channel_7_analyzer_1_array_theta[8]),0) RELATIVE channel_7_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_1_array_theta[8]) RELATIVE channel_7_analyzer_1_rotated

COMPONENT channel_7_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_7_analyzer_1_center

COMPONENT channel_7_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[7]*DEG2RAD)) RELATIVE channel_7_analyzer_2_center
ROTATED (0,-analyzer_theta[7],0) RELATIVE channel_7_analyzer_2_center

COMPONENT channel_7_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 921,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[0])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[0]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[0]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 921.1,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[1])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[1]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[1]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 921.2,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[2])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[2]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[2]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 921.3,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[3])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[3]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[3]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 921.4,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[4])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[4]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[4]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 921.5,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[5])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[5]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[5]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 921.6,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[6])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[6]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[6]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 921.7,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[7])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[7]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[7]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 921.8,
 xwidth = channel_7_analyzer_2_array_crystal_depth, yheight = channel_7_analyzer_2_array_crystal_height,
 zdepth = channel_7_analyzer_2_array_crystal_width)
AT (0 + channel_7_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_7_analyzer_2_array_theta[8])),0 + channel_7_analyzer_2_array_effective_radius_of_curvature * sin(channel_7_analyzer_2_array_theta[8]),0) RELATIVE channel_7_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_7_analyzer_2_array_theta[8]) RELATIVE channel_7_analyzer_2_rotated

COMPONENT channel_7_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 907.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_7_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_7_analyzer_2_center

COMPONENT channel_7_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 901,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_7_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_7_cave2_cyl1

COMPONENT channel_7_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 906,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_7_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_7_cave2_cyl1

COMPONENT channel_7_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 907,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_7_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_7_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_7 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_7_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_7_analyzer_1_center

COMPONENT inter_analyzer_colimator_7_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 925,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 926,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 927,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 928,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT inter_analyzer_colimator_7_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 929,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_7
ROTATED (0,-analyzer_2theta[7],0) RELATIVE inter_analyzer_colimator_center_7

COMPONENT diffraction_detector_7_exit_volume = Union_box(
 material_string = "Exit", priority = 931,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_7_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_7

COMPONENT spec_detector_7_exit_volume = Union_box(
 material_string = "Exit", priority = 932,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_7_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_7_analyzer_2_center

COMPONENT channel_8_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1000,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_8
ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_8_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1005,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_8
ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_8_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1002,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_8
ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_8_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1003,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_8
ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT channel_8_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_8

COMPONENT channel_8_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[8]*DEG2RAD)) RELATIVE channel_8_analyzer_1_center
ROTATED (0,180-analyzer_theta[8],0) RELATIVE channel_8_analyzer_1_center

COMPONENT channel_8_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1020,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[0])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[0]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[0]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1020.1,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[1])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[1]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[1]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1020.2,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[2])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[2]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[2]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1020.3,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[3])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[3]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[3]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1020.4,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[4])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[4]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[4]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1020.5,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[5])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[5]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[5]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1020.6,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[6])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[6]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[6]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1020.7,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[7])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[7]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[7]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1020.8,
 xwidth = channel_8_analyzer_1_array_crystal_depth, yheight = channel_8_analyzer_1_array_crystal_height,
 zdepth = channel_8_analyzer_1_array_crystal_width)
AT (0 + channel_8_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_1_array_theta[8])),0 + channel_8_analyzer_1_array_effective_radius_of_curvature * sin(channel_8_analyzer_1_array_theta[8]),0) RELATIVE channel_8_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_1_array_theta[8]) RELATIVE channel_8_analyzer_1_rotated

COMPONENT channel_8_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_8_analyzer_1_center

COMPONENT channel_8_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[8]*DEG2RAD)) RELATIVE channel_8_analyzer_2_center
ROTATED (0,-analyzer_theta[8],0) RELATIVE channel_8_analyzer_2_center

COMPONENT channel_8_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1021,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[0])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[0]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[0]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1021.1,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[1])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[1]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[1]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1021.2,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[2])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[2]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[2]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1021.3,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[3])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[3]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[3]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1021.4,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[4])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[4]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[4]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1021.5,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[5])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[5]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[5]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1021.6,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[6])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[6]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[6]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1021.7,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[7])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[7]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[7]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1021.8,
 xwidth = channel_8_analyzer_2_array_crystal_depth, yheight = channel_8_analyzer_2_array_crystal_height,
 zdepth = channel_8_analyzer_2_array_crystal_width)
AT (0 + channel_8_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_8_analyzer_2_array_theta[8])),0 + channel_8_analyzer_2_array_effective_radius_of_curvature * sin(channel_8_analyzer_2_array_theta[8]),0) RELATIVE channel_8_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_8_analyzer_2_array_theta[8]) RELATIVE channel_8_analyzer_2_rotated

COMPONENT channel_8_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1007.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_8_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_8_analyzer_2_center

COMPONENT channel_8_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1001,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_8_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_8_cave2_cyl1

COMPONENT channel_8_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1006,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_8_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_8_cave2_cyl1

COMPONENT channel_8_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1007,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_8_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_8_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_8 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_8_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_8_analyzer_1_center

COMPONENT inter_analyzer_colimator_8_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1025,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1026,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1027,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1028,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT inter_analyzer_colimator_8_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1029,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_8
ROTATED (0,-analyzer_2theta[8],0) RELATIVE inter_analyzer_colimator_center_8

COMPONENT diffraction_detector_8_exit_volume = Union_box(
 material_string = "Exit", priority = 1031,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_8_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_8

COMPONENT spec_detector_8_exit_volume = Union_box(
 material_string = "Exit", priority = 1032,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_8_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_8_analyzer_2_center

COMPONENT channel_9_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1100,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_9
ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_9_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1105,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_9
ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_9_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1102,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_9
ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_9_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1103,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_9
ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT channel_9_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_9

COMPONENT channel_9_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[9]*DEG2RAD)) RELATIVE channel_9_analyzer_1_center
ROTATED (0,180-analyzer_theta[9],0) RELATIVE channel_9_analyzer_1_center

COMPONENT channel_9_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1120,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[0])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[0]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[0]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1120.1,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[1])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[1]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[1]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1120.2,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[2])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[2]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[2]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1120.3,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[3])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[3]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[3]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1120.4,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[4])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[4]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[4]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1120.5,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[5])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[5]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[5]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1120.6,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[6])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[6]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[6]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1120.7,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[7])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[7]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[7]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1120.8,
 xwidth = channel_9_analyzer_1_array_crystal_depth, yheight = channel_9_analyzer_1_array_crystal_height,
 zdepth = channel_9_analyzer_1_array_crystal_width)
AT (0 + channel_9_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_1_array_theta[8])),0 + channel_9_analyzer_1_array_effective_radius_of_curvature * sin(channel_9_analyzer_1_array_theta[8]),0) RELATIVE channel_9_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_1_array_theta[8]) RELATIVE channel_9_analyzer_1_rotated

COMPONENT channel_9_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_9_analyzer_1_center

COMPONENT channel_9_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[9]*DEG2RAD)) RELATIVE channel_9_analyzer_2_center
ROTATED (0,-analyzer_theta[9],0) RELATIVE channel_9_analyzer_2_center

COMPONENT channel_9_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1121,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[0])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[0]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[0]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1121.1,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[1])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[1]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[1]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1121.2,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[2])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[2]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[2]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1121.3,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[3])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[3]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[3]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1121.4,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[4])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[4]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[4]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1121.5,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[5])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[5]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[5]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1121.6,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[6])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[6]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[6]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1121.7,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[7])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[7]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[7]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1121.8,
 xwidth = channel_9_analyzer_2_array_crystal_depth, yheight = channel_9_analyzer_2_array_crystal_height,
 zdepth = channel_9_analyzer_2_array_crystal_width)
AT (0 + channel_9_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_9_analyzer_2_array_theta[8])),0 + channel_9_analyzer_2_array_effective_radius_of_curvature * sin(channel_9_analyzer_2_array_theta[8]),0) RELATIVE channel_9_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_9_analyzer_2_array_theta[8]) RELATIVE channel_9_analyzer_2_rotated

COMPONENT channel_9_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1107.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_9_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_9_analyzer_2_center

COMPONENT channel_9_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1101,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_9_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_9_cave2_cyl1

COMPONENT channel_9_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1106,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_9_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_9_cave2_cyl1

COMPONENT channel_9_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1107,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_9_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_9_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_9 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_9_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_9_analyzer_1_center

COMPONENT inter_analyzer_colimator_9_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1125,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1126,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1127,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1128,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT inter_analyzer_colimator_9_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1129,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_9
ROTATED (0,-analyzer_2theta[9],0) RELATIVE inter_analyzer_colimator_center_9

COMPONENT diffraction_detector_9_exit_volume = Union_box(
 material_string = "Exit", priority = 1131,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_9_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_9

COMPONENT spec_detector_9_exit_volume = Union_box(
 material_string = "Exit", priority = 1132,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_9_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_9_analyzer_2_center

COMPONENT channel_10_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1200,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_10
ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_10_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1205,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_10
ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_10_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1202,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_10
ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_10_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1203,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_10
ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT channel_10_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_10

COMPONENT channel_10_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[10]*DEG2RAD)) RELATIVE channel_10_analyzer_1_center
ROTATED (0,180-analyzer_theta[10],0) RELATIVE channel_10_analyzer_1_center

COMPONENT channel_10_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1220,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[0])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[0]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[0]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1220.1,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[1])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[1]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[1]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1220.2,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[2])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[2]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[2]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1220.3,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[3])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[3]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[3]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1220.4,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[4])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[4]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[4]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1220.5,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[5])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[5]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[5]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1220.6,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[6])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[6]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[6]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1220.7,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[7])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[7]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[7]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1220.8,
 xwidth = channel_10_analyzer_1_array_crystal_depth, yheight = channel_10_analyzer_1_array_crystal_height,
 zdepth = channel_10_analyzer_1_array_crystal_width)
AT (0 + channel_10_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_1_array_theta[8])),0 + channel_10_analyzer_1_array_effective_radius_of_curvature * sin(channel_10_analyzer_1_array_theta[8]),0) RELATIVE channel_10_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_1_array_theta[8]) RELATIVE channel_10_analyzer_1_rotated

COMPONENT channel_10_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_10_analyzer_1_center

COMPONENT channel_10_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[10]*DEG2RAD)) RELATIVE channel_10_analyzer_2_center
ROTATED (0,-analyzer_theta[10],0) RELATIVE channel_10_analyzer_2_center

COMPONENT channel_10_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1221,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[0])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[0]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[0]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1221.1,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[1])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[1]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[1]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1221.2,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[2])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[2]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[2]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1221.3,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[3])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[3]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[3]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1221.4,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[4])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[4]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[4]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1221.5,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[5])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[5]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[5]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1221.6,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[6])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[6]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[6]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1221.7,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[7])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[7]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[7]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1221.8,
 xwidth = channel_10_analyzer_2_array_crystal_depth, yheight = channel_10_analyzer_2_array_crystal_height,
 zdepth = channel_10_analyzer_2_array_crystal_width)
AT (0 + channel_10_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_10_analyzer_2_array_theta[8])),0 + channel_10_analyzer_2_array_effective_radius_of_curvature * sin(channel_10_analyzer_2_array_theta[8]),0) RELATIVE channel_10_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_10_analyzer_2_array_theta[8]) RELATIVE channel_10_analyzer_2_rotated

COMPONENT channel_10_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1207.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_10_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_10_analyzer_2_center

COMPONENT channel_10_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1201,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_10_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_10_cave2_cyl1

COMPONENT channel_10_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1206,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_10_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_10_cave2_cyl1

COMPONENT channel_10_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1207,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_10_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_10_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_10 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_10_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_10_analyzer_1_center

COMPONENT inter_analyzer_colimator_10_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1225,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1226,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1227,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1228,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT inter_analyzer_colimator_10_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1229,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_10
ROTATED (0,-analyzer_2theta[10],0) RELATIVE inter_analyzer_colimator_center_10

COMPONENT diffraction_detector_10_exit_volume = Union_box(
 material_string = "Exit", priority = 1231,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_10_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_10

COMPONENT spec_detector_10_exit_volume = Union_box(
 material_string = "Exit", priority = 1232,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_10_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_10_analyzer_2_center

COMPONENT channel_11_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1300,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_11
ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_11_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1305,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_11
ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_11_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1302,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_11
ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_11_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1303,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_11
ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT channel_11_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_11

COMPONENT channel_11_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[11]*DEG2RAD)) RELATIVE channel_11_analyzer_1_center
ROTATED (0,180-analyzer_theta[11],0) RELATIVE channel_11_analyzer_1_center

COMPONENT channel_11_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1320,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[0])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[0]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[0]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1320.1,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[1])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[1]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[1]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1320.2,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[2])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[2]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[2]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1320.3,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[3])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[3]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[3]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1320.4,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[4])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[4]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[4]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1320.5,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[5])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[5]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[5]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1320.6,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[6])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[6]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[6]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1320.7,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[7])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[7]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[7]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1320.8,
 xwidth = channel_11_analyzer_1_array_crystal_depth, yheight = channel_11_analyzer_1_array_crystal_height,
 zdepth = channel_11_analyzer_1_array_crystal_width)
AT (0 + channel_11_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_1_array_theta[8])),0 + channel_11_analyzer_1_array_effective_radius_of_curvature * sin(channel_11_analyzer_1_array_theta[8]),0) RELATIVE channel_11_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_1_array_theta[8]) RELATIVE channel_11_analyzer_1_rotated

COMPONENT channel_11_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_11_analyzer_1_center

COMPONENT channel_11_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[11]*DEG2RAD)) RELATIVE channel_11_analyzer_2_center
ROTATED (0,-analyzer_theta[11],0) RELATIVE channel_11_analyzer_2_center

COMPONENT channel_11_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1321,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[0])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[0]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[0]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1321.1,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[1])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[1]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[1]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1321.2,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[2])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[2]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[2]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1321.3,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[3])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[3]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[3]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1321.4,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[4])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[4]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[4]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1321.5,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[5])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[5]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[5]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1321.6,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[6])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[6]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[6]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1321.7,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[7])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[7]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[7]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1321.8,
 xwidth = channel_11_analyzer_2_array_crystal_depth, yheight = channel_11_analyzer_2_array_crystal_height,
 zdepth = channel_11_analyzer_2_array_crystal_width)
AT (0 + channel_11_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_11_analyzer_2_array_theta[8])),0 + channel_11_analyzer_2_array_effective_radius_of_curvature * sin(channel_11_analyzer_2_array_theta[8]),0) RELATIVE channel_11_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_11_analyzer_2_array_theta[8]) RELATIVE channel_11_analyzer_2_rotated

COMPONENT channel_11_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1307.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_11_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_11_analyzer_2_center

COMPONENT channel_11_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1301,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_11_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_11_cave2_cyl1

COMPONENT channel_11_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1306,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_11_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_11_cave2_cyl1

COMPONENT channel_11_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1307,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_11_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_11_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_11 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_11_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_11_analyzer_1_center

COMPONENT inter_analyzer_colimator_11_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1325,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1326,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1327,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1328,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT inter_analyzer_colimator_11_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1329,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_11
ROTATED (0,-analyzer_2theta[11],0) RELATIVE inter_analyzer_colimator_center_11

COMPONENT diffraction_detector_11_exit_volume = Union_box(
 material_string = "Exit", priority = 1331,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_11_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_11

COMPONENT spec_detector_11_exit_volume = Union_box(
 material_string = "Exit", priority = 1332,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_11_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_11_analyzer_2_center

COMPONENT channel_12_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1400,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_12
ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_12_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1405,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_12
ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_12_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1402,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_12
ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_12_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1403,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_12
ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT channel_12_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_12

COMPONENT channel_12_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[12]*DEG2RAD)) RELATIVE channel_12_analyzer_1_center
ROTATED (0,180-analyzer_theta[12],0) RELATIVE channel_12_analyzer_1_center

COMPONENT channel_12_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1420,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[0])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[0]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[0]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1420.1,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[1])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[1]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[1]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1420.2,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[2])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[2]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[2]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1420.3,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[3])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[3]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[3]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1420.4,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[4])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[4]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[4]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1420.5,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[5])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[5]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[5]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1420.6,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[6])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[6]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[6]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1420.7,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[7])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[7]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[7]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1420.8,
 xwidth = channel_12_analyzer_1_array_crystal_depth, yheight = channel_12_analyzer_1_array_crystal_height,
 zdepth = channel_12_analyzer_1_array_crystal_width)
AT (0 + channel_12_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_1_array_theta[8])),0 + channel_12_analyzer_1_array_effective_radius_of_curvature * sin(channel_12_analyzer_1_array_theta[8]),0) RELATIVE channel_12_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_1_array_theta[8]) RELATIVE channel_12_analyzer_1_rotated

COMPONENT channel_12_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_12_analyzer_1_center

COMPONENT channel_12_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[12]*DEG2RAD)) RELATIVE channel_12_analyzer_2_center
ROTATED (0,-analyzer_theta[12],0) RELATIVE channel_12_analyzer_2_center

COMPONENT channel_12_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1421,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[0])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[0]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[0]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1421.1,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[1])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[1]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[1]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1421.2,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[2])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[2]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[2]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1421.3,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[3])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[3]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[3]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1421.4,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[4])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[4]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[4]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1421.5,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[5])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[5]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[5]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1421.6,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[6])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[6]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[6]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1421.7,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[7])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[7]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[7]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1421.8,
 xwidth = channel_12_analyzer_2_array_crystal_depth, yheight = channel_12_analyzer_2_array_crystal_height,
 zdepth = channel_12_analyzer_2_array_crystal_width)
AT (0 + channel_12_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_12_analyzer_2_array_theta[8])),0 + channel_12_analyzer_2_array_effective_radius_of_curvature * sin(channel_12_analyzer_2_array_theta[8]),0) RELATIVE channel_12_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_12_analyzer_2_array_theta[8]) RELATIVE channel_12_analyzer_2_rotated

COMPONENT channel_12_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1407.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_12_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_12_analyzer_2_center

COMPONENT channel_12_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1401,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_12_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_12_cave2_cyl1

COMPONENT channel_12_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1406,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_12_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_12_cave2_cyl1

COMPONENT channel_12_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1407,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_12_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_12_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_12 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_12_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_12_analyzer_1_center

COMPONENT inter_analyzer_colimator_12_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1425,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1426,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1427,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1428,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT inter_analyzer_colimator_12_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1429,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_12
ROTATED (0,-analyzer_2theta[12],0) RELATIVE inter_analyzer_colimator_center_12

COMPONENT diffraction_detector_12_exit_volume = Union_box(
 material_string = "Exit", priority = 1431,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_12_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_12

COMPONENT spec_detector_12_exit_volume = Union_box(
 material_string = "Exit", priority = 1432,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_12_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_12_analyzer_2_center

COMPONENT channel_13_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1500,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_13
ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_13_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1505,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_13
ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_13_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1502,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_13
ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_13_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1503,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_13
ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT channel_13_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_13

COMPONENT channel_13_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[13]*DEG2RAD)) RELATIVE channel_13_analyzer_1_center
ROTATED (0,180-analyzer_theta[13],0) RELATIVE channel_13_analyzer_1_center

COMPONENT channel_13_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1520,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[0])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[0]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[0]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1520.1,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[1])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[1]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[1]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1520.2,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[2])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[2]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[2]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1520.3,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[3])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[3]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[3]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1520.4,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[4])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[4]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[4]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1520.5,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[5])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[5]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[5]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1520.6,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[6])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[6]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[6]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1520.7,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[7])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[7]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[7]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1520.8,
 xwidth = channel_13_analyzer_1_array_crystal_depth, yheight = channel_13_analyzer_1_array_crystal_height,
 zdepth = channel_13_analyzer_1_array_crystal_width)
AT (0 + channel_13_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_1_array_theta[8])),0 + channel_13_analyzer_1_array_effective_radius_of_curvature * sin(channel_13_analyzer_1_array_theta[8]),0) RELATIVE channel_13_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_1_array_theta[8]) RELATIVE channel_13_analyzer_1_rotated

COMPONENT channel_13_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_13_analyzer_1_center

COMPONENT channel_13_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[13]*DEG2RAD)) RELATIVE channel_13_analyzer_2_center
ROTATED (0,-analyzer_theta[13],0) RELATIVE channel_13_analyzer_2_center

COMPONENT channel_13_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1521,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[0])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[0]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[0]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1521.1,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[1])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[1]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[1]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1521.2,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[2])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[2]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[2]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1521.3,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[3])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[3]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[3]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1521.4,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[4])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[4]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[4]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1521.5,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[5])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[5]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[5]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1521.6,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[6])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[6]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[6]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1521.7,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[7])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[7]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[7]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1521.8,
 xwidth = channel_13_analyzer_2_array_crystal_depth, yheight = channel_13_analyzer_2_array_crystal_height,
 zdepth = channel_13_analyzer_2_array_crystal_width)
AT (0 + channel_13_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_13_analyzer_2_array_theta[8])),0 + channel_13_analyzer_2_array_effective_radius_of_curvature * sin(channel_13_analyzer_2_array_theta[8]),0) RELATIVE channel_13_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_13_analyzer_2_array_theta[8]) RELATIVE channel_13_analyzer_2_rotated

COMPONENT channel_13_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1507.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_13_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_13_analyzer_2_center

COMPONENT channel_13_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1501,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_13_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_13_cave2_cyl1

COMPONENT channel_13_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1506,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_13_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_13_cave2_cyl1

COMPONENT channel_13_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1507,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_13_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_13_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_13 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_13_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_13_analyzer_1_center

COMPONENT inter_analyzer_colimator_13_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1525,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1526,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1527,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1528,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT inter_analyzer_colimator_13_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1529,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_13
ROTATED (0,-analyzer_2theta[13],0) RELATIVE inter_analyzer_colimator_center_13

COMPONENT diffraction_detector_13_exit_volume = Union_box(
 material_string = "Exit", priority = 1531,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_13_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_13

COMPONENT spec_detector_13_exit_volume = Union_box(
 material_string = "Exit", priority = 1532,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_13_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_13_analyzer_2_center

COMPONENT channel_14_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1600,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_14
ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_14_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1605,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_14
ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_14_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1602,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_14
ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_14_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1603,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_14
ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT channel_14_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_14

COMPONENT channel_14_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[14]*DEG2RAD)) RELATIVE channel_14_analyzer_1_center
ROTATED (0,180-analyzer_theta[14],0) RELATIVE channel_14_analyzer_1_center

COMPONENT channel_14_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1620,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[0])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[0]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[0]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1620.1,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[1])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[1]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[1]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1620.2,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[2])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[2]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[2]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1620.3,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[3])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[3]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[3]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1620.4,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[4])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[4]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[4]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1620.5,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[5])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[5]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[5]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1620.6,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[6])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[6]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[6]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1620.7,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[7])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[7]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[7]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1620.8,
 xwidth = channel_14_analyzer_1_array_crystal_depth, yheight = channel_14_analyzer_1_array_crystal_height,
 zdepth = channel_14_analyzer_1_array_crystal_width)
AT (0 + channel_14_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_1_array_theta[8])),0 + channel_14_analyzer_1_array_effective_radius_of_curvature * sin(channel_14_analyzer_1_array_theta[8]),0) RELATIVE channel_14_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_1_array_theta[8]) RELATIVE channel_14_analyzer_1_rotated

COMPONENT channel_14_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_14_analyzer_1_center

COMPONENT channel_14_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[14]*DEG2RAD)) RELATIVE channel_14_analyzer_2_center
ROTATED (0,-analyzer_theta[14],0) RELATIVE channel_14_analyzer_2_center

COMPONENT channel_14_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1621,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[0])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[0]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[0]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1621.1,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[1])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[1]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[1]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1621.2,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[2])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[2]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[2]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1621.3,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[3])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[3]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[3]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1621.4,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[4])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[4]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[4]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1621.5,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[5])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[5]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[5]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1621.6,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[6])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[6]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[6]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1621.7,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[7])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[7]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[7]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1621.8,
 xwidth = channel_14_analyzer_2_array_crystal_depth, yheight = channel_14_analyzer_2_array_crystal_height,
 zdepth = channel_14_analyzer_2_array_crystal_width)
AT (0 + channel_14_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_14_analyzer_2_array_theta[8])),0 + channel_14_analyzer_2_array_effective_radius_of_curvature * sin(channel_14_analyzer_2_array_theta[8]),0) RELATIVE channel_14_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_14_analyzer_2_array_theta[8]) RELATIVE channel_14_analyzer_2_rotated

COMPONENT channel_14_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1607.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_14_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_14_analyzer_2_center

COMPONENT channel_14_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1601,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_14_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_14_cave2_cyl1

COMPONENT channel_14_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1606,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_14_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_14_cave2_cyl1

COMPONENT channel_14_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1607,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_14_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_14_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_14 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_14_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_14_analyzer_1_center

COMPONENT inter_analyzer_colimator_14_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1625,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1626,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1627,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1628,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT inter_analyzer_colimator_14_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1629,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_14
ROTATED (0,-analyzer_2theta[14],0) RELATIVE inter_analyzer_colimator_center_14

COMPONENT diffraction_detector_14_exit_volume = Union_box(
 material_string = "Exit", priority = 1631,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_14_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_14

COMPONENT spec_detector_14_exit_volume = Union_box(
 material_string = "Exit", priority = 1632,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_14_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_14_analyzer_2_center

COMPONENT channel_15_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1700,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_15
ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_15_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1705,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_15
ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_15_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1702,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_15
ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_15_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1703,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_15
ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT channel_15_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_15

COMPONENT channel_15_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[15]*DEG2RAD)) RELATIVE channel_15_analyzer_1_center
ROTATED (0,180-analyzer_theta[15],0) RELATIVE channel_15_analyzer_1_center

COMPONENT channel_15_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1720,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[0])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[0]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[0]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1720.1,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[1])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[1]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[1]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1720.2,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[2])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[2]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[2]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1720.3,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[3])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[3]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[3]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1720.4,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[4])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[4]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[4]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1720.5,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[5])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[5]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[5]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1720.6,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[6])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[6]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[6]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1720.7,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[7])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[7]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[7]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1720.8,
 xwidth = channel_15_analyzer_1_array_crystal_depth, yheight = channel_15_analyzer_1_array_crystal_height,
 zdepth = channel_15_analyzer_1_array_crystal_width)
AT (0 + channel_15_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_1_array_theta[8])),0 + channel_15_analyzer_1_array_effective_radius_of_curvature * sin(channel_15_analyzer_1_array_theta[8]),0) RELATIVE channel_15_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_1_array_theta[8]) RELATIVE channel_15_analyzer_1_rotated

COMPONENT channel_15_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_15_analyzer_1_center

COMPONENT channel_15_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[15]*DEG2RAD)) RELATIVE channel_15_analyzer_2_center
ROTATED (0,-analyzer_theta[15],0) RELATIVE channel_15_analyzer_2_center

COMPONENT channel_15_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1721,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[0])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[0]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[0]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1721.1,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[1])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[1]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[1]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1721.2,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[2])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[2]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[2]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1721.3,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[3])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[3]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[3]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1721.4,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[4])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[4]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[4]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1721.5,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[5])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[5]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[5]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1721.6,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[6])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[6]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[6]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1721.7,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[7])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[7]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[7]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1721.8,
 xwidth = channel_15_analyzer_2_array_crystal_depth, yheight = channel_15_analyzer_2_array_crystal_height,
 zdepth = channel_15_analyzer_2_array_crystal_width)
AT (0 + channel_15_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_15_analyzer_2_array_theta[8])),0 + channel_15_analyzer_2_array_effective_radius_of_curvature * sin(channel_15_analyzer_2_array_theta[8]),0) RELATIVE channel_15_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_15_analyzer_2_array_theta[8]) RELATIVE channel_15_analyzer_2_rotated

COMPONENT channel_15_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1707.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_15_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_15_analyzer_2_center

COMPONENT channel_15_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1701,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_15_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_15_cave2_cyl1

COMPONENT channel_15_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1706,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_15_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_15_cave2_cyl1

COMPONENT channel_15_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1707,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_15_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_15_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_15 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_15_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_15_analyzer_1_center

COMPONENT inter_analyzer_colimator_15_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1725,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1726,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1727,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1728,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT inter_analyzer_colimator_15_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1729,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_15
ROTATED (0,-analyzer_2theta[15],0) RELATIVE inter_analyzer_colimator_center_15

COMPONENT diffraction_detector_15_exit_volume = Union_box(
 material_string = "Exit", priority = 1731,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_15_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_15

COMPONENT spec_detector_15_exit_volume = Union_box(
 material_string = "Exit", priority = 1732,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_15_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_15_analyzer_2_center

COMPONENT channel_16_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1800,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_16
ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_16_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1805,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_16
ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_16_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1802,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_16
ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_16_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1803,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_16
ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT channel_16_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_16

COMPONENT channel_16_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[16]*DEG2RAD)) RELATIVE channel_16_analyzer_1_center
ROTATED (0,180-analyzer_theta[16],0) RELATIVE channel_16_analyzer_1_center

COMPONENT channel_16_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1820,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[0])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[0]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[0]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1820.1,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[1])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[1]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[1]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1820.2,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[2])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[2]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[2]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1820.3,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[3])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[3]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[3]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1820.4,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[4])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[4]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[4]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1820.5,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[5])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[5]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[5]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1820.6,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[6])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[6]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[6]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1820.7,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[7])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[7]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[7]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1820.8,
 xwidth = channel_16_analyzer_1_array_crystal_depth, yheight = channel_16_analyzer_1_array_crystal_height,
 zdepth = channel_16_analyzer_1_array_crystal_width)
AT (0 + channel_16_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_1_array_theta[8])),0 + channel_16_analyzer_1_array_effective_radius_of_curvature * sin(channel_16_analyzer_1_array_theta[8]),0) RELATIVE channel_16_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_1_array_theta[8]) RELATIVE channel_16_analyzer_1_rotated

COMPONENT channel_16_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_16_analyzer_1_center

COMPONENT channel_16_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[16]*DEG2RAD)) RELATIVE channel_16_analyzer_2_center
ROTATED (0,-analyzer_theta[16],0) RELATIVE channel_16_analyzer_2_center

COMPONENT channel_16_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1821,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[0])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[0]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[0]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1821.1,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[1])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[1]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[1]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1821.2,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[2])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[2]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[2]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1821.3,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[3])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[3]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[3]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1821.4,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[4])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[4]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[4]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1821.5,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[5])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[5]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[5]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1821.6,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[6])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[6]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[6]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1821.7,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[7])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[7]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[7]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1821.8,
 xwidth = channel_16_analyzer_2_array_crystal_depth, yheight = channel_16_analyzer_2_array_crystal_height,
 zdepth = channel_16_analyzer_2_array_crystal_width)
AT (0 + channel_16_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_16_analyzer_2_array_theta[8])),0 + channel_16_analyzer_2_array_effective_radius_of_curvature * sin(channel_16_analyzer_2_array_theta[8]),0) RELATIVE channel_16_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_16_analyzer_2_array_theta[8]) RELATIVE channel_16_analyzer_2_rotated

COMPONENT channel_16_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1807.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_16_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_16_analyzer_2_center

COMPONENT channel_16_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1801,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_16_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_16_cave2_cyl1

COMPONENT channel_16_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1806,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_16_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_16_cave2_cyl1

COMPONENT channel_16_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1807,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_16_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_16_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_16 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_16_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_16_analyzer_1_center

COMPONENT inter_analyzer_colimator_16_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1825,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1826,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1827,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1828,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT inter_analyzer_colimator_16_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1829,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_16
ROTATED (0,-analyzer_2theta[16],0) RELATIVE inter_analyzer_colimator_center_16

COMPONENT diffraction_detector_16_exit_volume = Union_box(
 material_string = "Exit", priority = 1831,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_16_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_16

COMPONENT spec_detector_16_exit_volume = Union_box(
 material_string = "Exit", priority = 1832,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_16_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_16_analyzer_2_center

COMPONENT channel_17_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 1900,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_17
ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_17_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 1905,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_17
ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_17_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 1902,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_17
ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_17_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1903,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_17
ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT channel_17_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_17

COMPONENT channel_17_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[17]*DEG2RAD)) RELATIVE channel_17_analyzer_1_center
ROTATED (0,180-analyzer_theta[17],0) RELATIVE channel_17_analyzer_1_center

COMPONENT channel_17_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1920,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[0])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[0]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[0]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1920.1,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[1])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[1]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[1]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1920.2,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[2])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[2]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[2]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1920.3,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[3])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[3]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[3]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1920.4,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[4])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[4]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[4]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1920.5,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[5])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[5]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[5]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1920.6,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[6])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[6]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[6]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1920.7,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[7])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[7]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[7]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1920.8,
 xwidth = channel_17_analyzer_1_array_crystal_depth, yheight = channel_17_analyzer_1_array_crystal_height,
 zdepth = channel_17_analyzer_1_array_crystal_width)
AT (0 + channel_17_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_1_array_theta[8])),0 + channel_17_analyzer_1_array_effective_radius_of_curvature * sin(channel_17_analyzer_1_array_theta[8]),0) RELATIVE channel_17_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_1_array_theta[8]) RELATIVE channel_17_analyzer_1_rotated

COMPONENT channel_17_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_17_analyzer_1_center

COMPONENT channel_17_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[17]*DEG2RAD)) RELATIVE channel_17_analyzer_2_center
ROTATED (0,-analyzer_theta[17],0) RELATIVE channel_17_analyzer_2_center

COMPONENT channel_17_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 1921,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[0])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[0]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[0]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 1921.1,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[1])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[1]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[1]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 1921.2,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[2])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[2]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[2]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 1921.3,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[3])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[3]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[3]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 1921.4,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[4])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[4]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[4]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 1921.5,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[5])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[5]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[5]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 1921.6,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[6])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[6]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[6]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 1921.7,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[7])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[7]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[7]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 1921.8,
 xwidth = channel_17_analyzer_2_array_crystal_depth, yheight = channel_17_analyzer_2_array_crystal_height,
 zdepth = channel_17_analyzer_2_array_crystal_width)
AT (0 + channel_17_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_17_analyzer_2_array_theta[8])),0 + channel_17_analyzer_2_array_effective_radius_of_curvature * sin(channel_17_analyzer_2_array_theta[8]),0) RELATIVE channel_17_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_17_analyzer_2_array_theta[8]) RELATIVE channel_17_analyzer_2_rotated

COMPONENT channel_17_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 1907.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_17_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_17_analyzer_2_center

COMPONENT channel_17_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 1901,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_17_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_17_cave2_cyl1

COMPONENT channel_17_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 1906,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_17_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_17_cave2_cyl1

COMPONENT channel_17_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 1907,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_17_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_17_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_17 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_17_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_17_analyzer_1_center

COMPONENT inter_analyzer_colimator_17_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 1925,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 1926,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 1927,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 1928,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT inter_analyzer_colimator_17_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 1929,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_17
ROTATED (0,-analyzer_2theta[17],0) RELATIVE inter_analyzer_colimator_center_17

COMPONENT diffraction_detector_17_exit_volume = Union_box(
 material_string = "Exit", priority = 1931,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_17_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_17

COMPONENT spec_detector_17_exit_volume = Union_box(
 material_string = "Exit", priority = 1932,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_17_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_17_analyzer_2_center

COMPONENT channel_18_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 2000,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_18
ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_18_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 2005,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_18
ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_18_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 2002,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_18
ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_18_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 2003,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_18
ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT channel_18_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_18

COMPONENT channel_18_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[18]*DEG2RAD)) RELATIVE channel_18_analyzer_1_center
ROTATED (0,180-analyzer_theta[18],0) RELATIVE channel_18_analyzer_1_center

COMPONENT channel_18_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 2020,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[0])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[0]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[0]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 2020.1,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[1])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[1]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[1]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 2020.2,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[2])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[2]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[2]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 2020.3,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[3])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[3]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[3]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 2020.4,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[4])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[4]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[4]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 2020.5,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[5])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[5]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[5]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 2020.6,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[6])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[6]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[6]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 2020.7,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[7])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[7]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[7]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 2020.8,
 xwidth = channel_18_analyzer_1_array_crystal_depth, yheight = channel_18_analyzer_1_array_crystal_height,
 zdepth = channel_18_analyzer_1_array_crystal_width)
AT (0 + channel_18_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_1_array_theta[8])),0 + channel_18_analyzer_1_array_effective_radius_of_curvature * sin(channel_18_analyzer_1_array_theta[8]),0) RELATIVE channel_18_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_1_array_theta[8]) RELATIVE channel_18_analyzer_1_rotated

COMPONENT channel_18_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_18_analyzer_1_center

COMPONENT channel_18_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[18]*DEG2RAD)) RELATIVE channel_18_analyzer_2_center
ROTATED (0,-analyzer_theta[18],0) RELATIVE channel_18_analyzer_2_center

COMPONENT channel_18_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 2021,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[0])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[0]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[0]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 2021.1,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[1])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[1]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[1]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 2021.2,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[2])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[2]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[2]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 2021.3,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[3])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[3]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[3]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 2021.4,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[4])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[4]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[4]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 2021.5,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[5])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[5]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[5]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 2021.6,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[6])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[6]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[6]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 2021.7,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[7])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[7]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[7]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 2021.8,
 xwidth = channel_18_analyzer_2_array_crystal_depth, yheight = channel_18_analyzer_2_array_crystal_height,
 zdepth = channel_18_analyzer_2_array_crystal_width)
AT (0 + channel_18_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_18_analyzer_2_array_theta[8])),0 + channel_18_analyzer_2_array_effective_radius_of_curvature * sin(channel_18_analyzer_2_array_theta[8]),0) RELATIVE channel_18_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_18_analyzer_2_array_theta[8]) RELATIVE channel_18_analyzer_2_rotated

COMPONENT channel_18_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 2007.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_18_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_18_analyzer_2_center

COMPONENT channel_18_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 2001,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_18_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_18_cave2_cyl1

COMPONENT channel_18_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 2006,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_18_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_18_cave2_cyl1

COMPONENT channel_18_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 2007,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_18_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_18_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_18 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_18_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_18_analyzer_1_center

COMPONENT inter_analyzer_colimator_18_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 2025,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 2026,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 2027,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 2028,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT inter_analyzer_colimator_18_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 2029,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_18
ROTATED (0,-analyzer_2theta[18],0) RELATIVE inter_analyzer_colimator_center_18

COMPONENT diffraction_detector_18_exit_volume = Union_box(
 material_string = "Exit", priority = 2031,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_18_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_18

COMPONENT spec_detector_18_exit_volume = Union_box(
 material_string = "Exit", priority = 2032,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_18_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_18_analyzer_2_center

COMPONENT channel_19_cave1_box1 = Union_box(
 material_string = "Vacuum", priority = 2100,
 xwidth = kidney_cave1_box1_width1, yheight = kidney_cave1_box1_height1,
 zdepth = kidney_cave1_box1_depth, xwidth2 = kidney_cave1_box1_width2,
 yheight2 = kidney_cave1_box1_height2)
AT (0,0,kidney_cave1_box1_center_to_target) RELATIVE kidney_channel_19
ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT channel_19_cave1_box2 = Union_box(
 material_string = "Vacuum", priority = 2105,
 xwidth = kidney_cave1_box2_width1, yheight = kidney_cave1_box2_height1,
 zdepth = kidney_cave1_box2_depth, xwidth2 = kidney_cave1_box2_width2,
 yheight2 = kidney_cave1_box2_height2)
AT (0,0,kidney_cave1_box2_center_to_target) RELATIVE kidney_channel_19
ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT channel_19_cave1_box3 = Union_box(
 material_string = "Vacuum", priority = 2102,
 xwidth = kidney_cave1_box3_width1, yheight = kidney_cave1_box3_height1,
 zdepth = kidney_cave1_box3_depth, xwidth2 = kidney_cave1_box3_width2,
 yheight2 = kidney_cave1_box3_height2)
AT (0,0,kidney_cave1_box3_center_to_target) RELATIVE kidney_channel_19
ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT channel_19_cave1_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 2103,
 radius = kidney_cave1_cyl1_radius, yheight = kidney_cave1_cyl1_height)
AT (0,0,kidney_cave1_cyl1_center_to_target) RELATIVE kidney_channel_19
ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT channel_19_analyzer_1_center = Arm()
AT (0,0,analyzer_1_center_to_sample) RELATIVE kidney_channel_19

COMPONENT channel_19_analyzer_1_rotated = Arm()
AT (0,0,-0.5*analyzer_seperation/tan(analyzer_2theta[19]*DEG2RAD)) RELATIVE channel_19_analyzer_1_center
ROTATED (0,180-analyzer_theta[19],0) RELATIVE channel_19_analyzer_1_center

COMPONENT channel_19_analyzer_1_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 2120,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[0])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[0]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[0]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 2120.1,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[1])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[1]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[1]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 2120.2,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[2])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[2]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[2]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 2120.3,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[3])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[3]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[3]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 2120.4,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[4])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[4]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[4]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 2120.5,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[5])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[5]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[5]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 2120.6,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[6])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[6]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[6]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 2120.7,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[7])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[7]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[7]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_1_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 2120.8,
 xwidth = channel_19_analyzer_1_array_crystal_depth, yheight = channel_19_analyzer_1_array_crystal_height,
 zdepth = channel_19_analyzer_1_array_crystal_width)
AT (0 + channel_19_analyzer_1_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_1_array_theta[8])),0 + channel_19_analyzer_1_array_effective_radius_of_curvature * sin(channel_19_analyzer_1_array_theta[8]),0) RELATIVE channel_19_analyzer_1_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_1_array_theta[8]) RELATIVE channel_19_analyzer_1_rotated

COMPONENT channel_19_analyzer_2_center = Arm()
AT (-analyzer_seperation,0,0) RELATIVE channel_19_analyzer_1_center

COMPONENT channel_19_analyzer_2_rotated = Arm()
AT (0,0,0.5*analyzer_seperation/tan(analyzer_2theta[19]*DEG2RAD)) RELATIVE channel_19_analyzer_2_center
ROTATED (0,-analyzer_theta[19],0) RELATIVE channel_19_analyzer_2_center

COMPONENT channel_19_analyzer_2_array_crystal_array_0 = Union_box(
 material_string = "PG_analyzer", priority = 2121,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[0])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[0]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[0]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_1 = Union_box(
 material_string = "PG_analyzer", priority = 2121.1,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[1])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[1]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[1]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_2 = Union_box(
 material_string = "PG_analyzer", priority = 2121.2,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[2])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[2]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[2]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_3 = Union_box(
 material_string = "PG_analyzer", priority = 2121.3,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[3])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[3]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[3]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_4 = Union_box(
 material_string = "PG_analyzer", priority = 2121.4,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[4])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[4]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[4]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_5 = Union_box(
 material_string = "PG_analyzer", priority = 2121.5,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[5])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[5]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[5]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_6 = Union_box(
 material_string = "PG_analyzer", priority = 2121.6,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[6])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[6]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[6]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_7 = Union_box(
 material_string = "PG_analyzer", priority = 2121.7,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[7])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[7]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[7]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_analyzer_2_array_crystal_array_8 = Union_box(
 material_string = "PG_analyzer", priority = 2121.8,
 xwidth = channel_19_analyzer_2_array_crystal_depth, yheight = channel_19_analyzer_2_array_crystal_height,
 zdepth = channel_19_analyzer_2_array_crystal_width)
AT (0 + channel_19_analyzer_2_array_effective_radius_of_curvature * (1-cos(channel_19_analyzer_2_array_theta[8])),0 + channel_19_analyzer_2_array_effective_radius_of_curvature * sin(channel_19_analyzer_2_array_theta[8]),0) RELATIVE channel_19_analyzer_2_rotated
ROTATED (0,0,0-RAD2DEG*channel_19_analyzer_2_array_theta[8]) RELATIVE channel_19_analyzer_2_rotated

COMPONENT channel_19_cave2_cyl1 = Union_cylinder(
 material_string = "Vacuum", priority = 2107.5,
 radius = kidney_cave2_cyl1_radius, yheight = kidney_cave2_cyl1_height)
AT (0,0,spec_detector_to_analyzer_2_center) RELATIVE channel_19_analyzer_2_center
ROTATED (0,0,0) RELATIVE channel_19_analyzer_2_center

COMPONENT channel_19_cave2_box1 = Union_box(
 material_string = "Vacuum", priority = 2101,
 xwidth = kidney_cave2_box1_width1, yheight = kidney_cave2_box1_height1,
 zdepth = kidney_cave2_box1_depth, xwidth2 = kidney_cave2_box1_width2,
 yheight2 = kidney_cave2_box1_height2)
AT (kidney_cave2_box1_center_to_spec_detector_x,0,kidney_cave2_box1_center_to_spec_detector_z) RELATIVE channel_19_cave2_cyl1
ROTATED (0,kidney_cave2_box1_y_rotation,0) RELATIVE channel_19_cave2_cyl1

COMPONENT channel_19_cave2_box2 = Union_box(
 material_string = "Vacuum", priority = 2106,
 xwidth = kidney_cave2_box2_width1, yheight = kidney_cave2_box2_height1,
 zdepth = kidney_cave2_box2_depth, xwidth2 = kidney_cave2_box2_width2,
 yheight2 = kidney_cave2_box2_height2)
AT (0,0,kidney_cave2_box2_center_to_detector) RELATIVE channel_19_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_19_cave2_cyl1

COMPONENT channel_19_cave2_box3 = Union_box(
 material_string = "Vacuum", priority = 2107,
 xwidth = kidney_cave2_box3_width1, yheight = kidney_cave2_box3_height1,
 zdepth = kidney_cave2_box3_depth, xwidth2 = kidney_cave2_box3_width2,
 yheight2 = kidney_cave2_box3_height2)
AT (0,0,kidney_cave2_box3_center_to_detector) RELATIVE channel_19_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_19_cave2_cyl1

COMPONENT inter_analyzer_colimator_center_19 = Arm()
AT (-0.5*analyzer_seperation,0,0) RELATIVE channel_19_analyzer_1_center
ROTATED (0,0,0) RELATIVE channel_19_analyzer_1_center

COMPONENT inter_analyzer_colimator_19_blade_0 = Union_box(
 material_string = "Collimator_gad", priority = 2125,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 0*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_1 = Union_box(
 material_string = "Collimator_gad", priority = 2126,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 1*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_2 = Union_box(
 material_string = "Collimator_gad", priority = 2127,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 2*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_3 = Union_box(
 material_string = "Collimator_gad", priority = 2128,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 3*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT inter_analyzer_colimator_19_blade_4 = Union_box(
 material_string = "Collimator_gad", priority = 2129,
 xwidth = inter_analyzer_colimator_width, yheight = inter_analyzer_colimator_height,
 zdepth = inter_analyzer_colimator_depth)
AT (0,0,inter_analyzer_colimator_start_pos - 4*inter_analyzer_colimator_seperation) RELATIVE inter_analyzer_colimator_center_19
ROTATED (0,-analyzer_2theta[19],0) RELATIVE inter_analyzer_colimator_center_19

COMPONENT diffraction_detector_19_exit_volume = Union_box(
 material_string = "Exit", priority = 2131,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0) RELATIVE channel_19_cave1_cyl1
ROTATED (0,0,0) RELATIVE kidney_channel_19

COMPONENT spec_detector_19_exit_volume = Union_box(
 material_string = "Exit", priority = 2132,
 xwidth = 2.01*detector_radius, yheight = 1.01*detector_height,
 zdepth = 0.001)
AT (0,0,0.0) RELATIVE channel_19_cave2_cyl1
ROTATED (0,0,0) RELATIVE channel_19_analyzer_2_center

COMPONENT kidney_master = Union_master(
 allow_inside_start = 0, inherit_number_of_scattering_events = 1)
AT (0,0,0) ABSOLUTE

COMPONENT diffraction_detector_0 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_0", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_0_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_0_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =0;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_0 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_0", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_0_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_0_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =0;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_1 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_1", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_1_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_1_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =1;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_1 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_1", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_1_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_1_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =1;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_2 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_2", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_2_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_2_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =2;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_2 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_2", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_2_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_2_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =2;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_3 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_3", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_3_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_3_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =3;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_3 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_3", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_3_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_3_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =3;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_4 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_4", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_4_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_4_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =4;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_4 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_4", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_4_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_4_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =4;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_5 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_5", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_5_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_5_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =5;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_5 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_5", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_5_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_5_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =5;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_6 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_6", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_6_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_6_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =6;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_6 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_6", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_6_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_6_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =6;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_7 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_7", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_7_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_7_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =7;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_7 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_7", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_7_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_7_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =7;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_8 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_8", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_8_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_8_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =8;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_8 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_8", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_8_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_8_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =8;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_9 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_9", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_9_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_9_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =9;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_9 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_9", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_9_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_9_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =9;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_10 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_10", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_10_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_10_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =10;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_10 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_10", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_10_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_10_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =10;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_11 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_11", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_11_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_11_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =11;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_11 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_11", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_11_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_11_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =11;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_12 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_12", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_12_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_12_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =12;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_12 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_12", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_12_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_12_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =12;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_13 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_13", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_13_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_13_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =13;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_13 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_13", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_13_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_13_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =13;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_14 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_14", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_14_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_14_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =14;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_14 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_14", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_14_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_14_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =14;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_15 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_15", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_15_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_15_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =15;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_15 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_15", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_15_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_15_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =15;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_16 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_16", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_16_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_16_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =16;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_16 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_16", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_16_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_16_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =16;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_17 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_17", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_17_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_17_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =17;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_17 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_17", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_17_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_17_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =17;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_18 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_18", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_18_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_18_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =18;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_18 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_18", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_18_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_18_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =18;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

COMPONENT diffraction_detector_19 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "diff_detector_19", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0) RELATIVE diffraction_detector_19_exit_volume
ROTATED (0,0,0) RELATIVE diffraction_detector_19_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_diff =19;
      detector_channel_spec =-1;
      detector_found = 1;
    }
%}

COMPONENT spec_detector_19 = PSD_monitor(
 nx = 5, ny = 5,
 filename = "spec_detector_19", xwidth = 2.0*detector_radius,
 yheight = 1.0*detector_height, restore_neutron = 1)
AT (0,0,0.01) RELATIVE spec_detector_19_exit_volume
ROTATED (0,0,0.0) RELATIVE spec_detector_19_exit_volume
GROUP detector_group
EXTEND %{
    if (SCATTERED) {
      detector_channel_spec =19;
      detector_channel_diff =-1;
      detector_found = 1;
    }
%}

