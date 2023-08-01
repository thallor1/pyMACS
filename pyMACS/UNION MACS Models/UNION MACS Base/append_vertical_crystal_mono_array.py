import numpy as np 
import mcstasscript as ms

def append_vertical_crystal_mono_array(instrument, name, crystal_width, crystal_height, crystal_depth, 
	number_of_crystals, total_height, radius_of_curvature, arm_name, material_name, priority_start, 
	support_arch_thickness, support_arch_width, support_arch_spacing, misalignment_deg, 
	priority_end,x_position_string="0",y_position_string="0",z_position_string="0",x_rotation_string="0",
	y_rotation_string="0",z_rotation_string="0",number_of_crystals_value=0,mask_height_diviation=0):
	#First check if crystal_widht, crystal_height, crystal_depth, number_of_crystals, total_height, radius_of_curvature
	# misalignment_deg have been declared / initialized. If not, append to DECLARE and INITIALIZE.
	declare_vars = [instrument.declare_list[i].name for i in range(len(instrument.declare_list))]
	initialize_string = instrument.initialize_section
	if name+"_cystal_width" in declare_vars:
		crystal_width_name = name+"_cystal_width"
	else:
		crystal_width_name = name + "_crystal_width"
		instrument.add_declare_var("double",crystal_width_name)
		instrument.append_initialize(crystal_width_name+f"={crystal_width};")

	if name+"_crystal_height" in declare_vars: 
		crystal_height_name = name+"_crystal_height"
	else:
		crystal_height_name = name + "_crystal_height"
		instrument.add_declare_var("double",crystal_height_name)
		instrument.append_initialize(crystal_height_name+f"={crystal_height};")

	if name+"_crystal_depth" in declare_vars: 
		crystal_depth_name = name+"_crystal_depth"
	else:
		crystal_depth_name = name + "_crystal_depth"
		instrument.add_declare_var("double",crystal_depth_name)
		instrument.append_initialize(crystal_depth_name+f"={crystal_depth};")

	if name+"_number_of_crystals" in declare_vars: 
		number_of_crystals_name = name + "_number_of_crystals"
		number_of_crystals_value = number_of_crystals
	else:
		number_of_crystals_name = name + "_number_of_crystals"
		number_of_crystals_value = number_of_crystals
		instrument.add_declare_var("int",number_of_crystals_name)
		instrument.append_initialize(number_of_crystals_name+f"={number_of_crystals};")

	if name+"_total_height" in declare_vars: 
		total_height_name = name+"_total_height"
	else:
		total_height_name = name + "_total_height"
		instrument.add_declare_var("double",total_height_name)
		instrument.append_initialize(total_height_name+f"={total_height};")

	if name+"_radius_of_curvature" in declare_vars: 
		radius_of_curvature_name = name+"_radius_of_curvature"
	else:
		radius_of_curvature_name = name + "_radius_of_curvature"
		instrument.add_declare_var("double",radius_of_curvature_name)
		instrument.append_initialize(radius_of_curvature_name+f"={radius_of_curvature};")

	if "misalignment_deg" in declare_vars: 
		misalignment_deg_name = "misalignment_deg"
	else:
		misalignment_deg_name = "misalignment_deg"
		instrument.add_declare_var("double",misalignment_deg_name)
		instrument.append_initialize(misalignment_deg_name+f"={misalignment_deg};")

	delta_priority = (priority_end - priority_start)/(number_of_crystals_value+3); # 3 extra needed for support arch
	

	# the depth of each crystal is along the vector between it's center and the focal point.
	# the center of the surface of each crystal traces the circle of curvature
	instrument.add_declare_var("double",name + "_effective_radius_of_curvature")
	# the total height is between the top and bottom corner of the top and bottom crystal
	#instrument.append_initialize(name + "_effective_radius_of_curvature = " + name + "_crystal_depth + " + name + "_radius_of_curvature;")
	instrument.append_initialize(name + "_effective_radius_of_curvature = " + crystal_depth_name + "+" + radius_of_curvature_name + ";")
	
	instrument.add_declare_var("double",name + "_theta_max")
	# may need other input methods than total_height, as it is probabily not known to often.
	# calculate theta max from geometry considerations
	instrument.append_initialize(name + "_theta_max = asin(" + total_height_name + "/sqrt((2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ")*(2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ") + " + crystal_height_name + "*" + crystal_height_name + ") - atan(" + crystal_height_name + "/(2*" + radius_of_curvature_name + " + 2*" + crystal_depth_name + ")));")
	# calculate rotation for each crystal, called theta
	instrument.add_declare_var("double",name + "_delta_theta")
	instrument.append_initialize(name + "_delta_theta = (2*" + name + "_theta_max) / ((double) " + number_of_crystals_name + " - 1);")
	# the theta array describes the angle between the horizontal and the vector between the crystal center and focal point
	instrument.add_declare_var("double",name + "_theta",array=number_of_crystals)
	instrument.add_declare_var("int",name + "_iterate")
	instrument.append_initialize("for (" + name + "_iterate=0;" + name + "_iterate<" + str(number_of_crystals) + ";" + name + "_iterate++)")
	instrument.append_initialize("    " + name + "_theta[" + name + "_iterate] = " + name + "_delta_theta * (double) " + name + "_iterate - " + name + "_theta_max;")
	

	mono_crystal_array_arm = instrument.add_component(name + "_crystal_array_arm","Arm")
	mono_crystal_array_arm.set_AT([x_position_string,y_position_string,z_position_string],
		RELATIVE=arm_name)
	mono_crystal_array_arm.set_ROTATED([x_rotation_string,y_rotation_string,z_rotation_string],
		RELATIVE=arm_name)

	for i in range(0,number_of_crystals_value):
		full_x_position_string = name + "_effective_radius_of_curvature * (1-cos(" + name + "_theta[" + str(i) + "]))"
		full_y_position_string = name + "_effective_radius_of_curvature * sin(" + name + "_theta[" + str(i) + "])"
		full_z_position_string = "0"
		
		full_x_rotation_string = "0"
		full_y_rotation_string = misalignment_deg_name + "*randnorm()"
		full_z_rotation_string = "-RAD2DEG*" + name + "_theta[" + str(i) + "] + " + misalignment_deg_name + "*randnorm()"
	
		mono_box = instrument.add_component(name + "_crystal_array_" + str(i), "Union_box")
		mono_box.zdepth = crystal_width_name
		mono_box.yheight = crystal_height_name
		mono_box.xwidth = crystal_depth_name
		mono_box.p_interact=0.0
		mono_box.priority=(i+3)*delta_priority + priority_start
		mono_box.material_string = '\"'+material_name+'\"'
		mono_box.set_AT([full_x_position_string,full_y_position_string,full_z_position_string],
		 RELATIVE=name + "_crystal_array_arm")
		mono_box.set_ROTATED([full_x_rotation_string,full_y_rotation_string,full_z_rotation_string],
			RELATIVE=name + "_crystal_array_arm")

	if name+"_support_arch_thickness" in declare_vars: 
		support_arch_thickness_name = name+"_support_arch_thickness"
	else:
		support_arch_thickness_name = name + "_support_arch_thickness"
		instrument.add_declare_var("double",support_arch_thickness_name)
		instrument.append_initialize(support_arch_thickness_name+f"={support_arch_thickness};")

	if name+"_support_arch_width" in declare_vars: 
		support_arch_width_name = name+"_support_arch_width"
	else:
		support_arch_width_name = name + "_support_arch_width"
		instrument.add_declare_var("double",support_arch_width_name)
		instrument.append_initialize(support_arch_width_name+f"={support_arch_width};")

	if name+"_support_arch_spacing" in declare_vars: 
		support_arch_spacing_name = name+"_support_arch_spacing"
	else:
		support_arch_spacing_name = name + "_support_arch_spacing"
		instrument.add_declare_var("double",support_arch_spacing_name)
		instrument.append_initialize(support_arch_spacing_name+f"={support_arch_spacing};")


	instrument.add_declare_var("double",name + "_arch_outer_radius")
	instrument.add_declare_var("double",name + "_arch_inner_radius")
	instrument.append_initialize(name + "_arch_inner_radius = " + radius_of_curvature_name + "+" + crystal_depth_name + "+" + support_arch_spacing_name + ";")
	instrument.append_initialize(name + "_arch_outer_radius = " + name + "_arch_inner_radius + " + support_arch_thickness_name + ";")

	instrument.add_declare_var("double",name + "_mask_depth")
	instrument.append_initialize(name + "_mask_depth = " + radius_of_curvature_name + " * (1-cos(" + name + "_theta_max + 2*" + name + "_delta_theta));")

	mounting_arch = instrument.add_component(name + "_crystal_array_mounting_arch","Union_cylinder")
	mounting_arch.radius =name + "_arch_outer_radius"
	mounting_arch.yheight =support_arch_width_name
	mounting_arch.priority =0*delta_priority + priority_start
	mounting_arch.material_string = '"al_mono"'
	mounting_arch.set_AT([radius_of_curvature,0,0],RELATIVE=name + "_crystal_array_arm")
	mounting_arch.set_ROTATED([90,0,0],RELATIVE=name + "_crystal_array_arm")

	mounting_arch_vac = instrument.add_component(name + "_crystal_array_mounting_arch_vacuum","Union_cylinder")
	mounting_arch_vac.radius =name + "_arch_inner_radius"
	mounting_arch_vac.yheight = "0.0002+"+ crystal_width_name
	mounting_arch_vac.priority = f"1*{delta_priority + priority_start}"
	mounting_arch_vac.material_string = '"Vacuum"'
	mounting_arch_vac.set_AT([radius_of_curvature,0,0],RELATIVE=name + "_crystal_array_arm")
	mounting_arch_vac.set_ROTATED([90,0,0],RELATIVE=name + "_crystal_array_arm")

	mounting_arch_mask=instrument.add_component(name + "_crystal_array_mounting_arch_mask","Union_box")
	mounting_arch_mask.zdepth = "0.0004+"+crystal_width_name
	mounting_arch_mask.yheight = "1.2*"+name+"_total_height+"+f"{mask_height_diviation}"
	mounting_arch_mask.xwidth = 0.05
	mounting_arch_mask.priority =2*delta_priority + priority_start
	mounting_arch_mask.visualize=0
	arch_str = '\"'+name + "_crystal_array_mounting_arch," + name +  "_crystal_array_mounting_arch_vacuum"+'\"'
	mounting_arch_mask.mask_string=arch_str
	mounting_arch_mask.set_AT(["1.05*"+name+"_mask_depth-0.025",0,0],RELATIVE=name + "_crystal_array_arm")
	mounting_arch_mask.set_ROTATED([0,0,0], RELATIVE=name + "_crystal_array_arm")

	return instrument