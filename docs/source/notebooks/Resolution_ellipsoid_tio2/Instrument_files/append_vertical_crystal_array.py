import numpy as np 
import mcstasscript as ms

def append_vertical_crystal_array(instrument, name, crystal_width, crystal_height, crystal_depth, number_of_crystals, total_height, radius_of_curvature, arm_name, material_name, priority_start, priority_end,x_position_string="0",y_position_string="0",z_position_string="0",x_rotation_string="0",y_rotation_string="0",z_rotation_string="0",number_of_crystals_value=0):

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
        number_of_crystals_value=number_of_crystals
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
    delta_priority = (priority_end - priority_start)/number_of_crystals_value;
    
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
    

    for i in range(0,number_of_crystals_value):
    
        full_x_position_string = x_position_string + " + " + name + "_effective_radius_of_curvature * (1-cos(" + name + "_theta[" + str(i) + "]))"
        full_y_position_string = y_position_string + " + " + name + "_effective_radius_of_curvature * sin(" + name + "_theta[" + str(i) + "])"
        full_z_position_string = z_position_string
        
        full_x_rotation_string = x_rotation_string
        full_y_rotation_string = y_rotation_string
        full_z_rotation_string = z_rotation_string + "-RAD2DEG*" + name + "_theta[" + str(i) + "]"
    
        crystal_array = instrument.add_component(name + "_crystal_array_" + str(i),"Union_box")
        crystal_array.zdepth =crystal_width_name
        crystal_array.yheight =crystal_height_name
        crystal_array.xwidth = crystal_depth_name
        crystal_array.priority = i*delta_priority + priority_start
        crystal_array.material_string = '\"'+material_name + '\"'
        #instrument.append_trace("AT (" + name + "_effective_radius_of_curvature * (1-cos(" + name + "_theta[" + str(i) + "]))," + name + "_effective_radius_of_curvature * sin(" + name + "_theta[" + str(i) + "]),0) RELATIVE " + arm_name)
        crystal_array.set_AT([full_x_position_string,full_y_position_string , full_z_position_string],
            RELATIVE=arm_name)
        #instrument.append_trace("ROTATED (0,0,-RAD2DEG*" + name + "_theta[" + str(i) + "]) RELATIVE " + arm_name + "\n")
        crystal_array.set_ROTATED([full_x_rotation_string , full_y_rotation_string , full_z_rotation_string],
            RELATIVE=arm_name)
    return instrument

