tank1_sensor_hi_height_m = 5; %[m]
tank1_sensor_lo_height_m = 2; %[m]
tank1_pump_flow_rate_m3s = 0.2; % [m^3/s]
tank1_valve_flow_rate_m3s = 0.1; % [m^3/s]
tank1_cross_section_area_m2 = 1; % [m^2]
tank1_max_vol_m3 = 7; % [m^3]

tank2_sensor_hi_height_m = 3; %[m]
tank2_sensor_md_height_m = 2; %[m]
tank2_sensor_lo_height_m = 1; %[m]
tank2_p_valve_flow_rate_m3s = 0.05; % [m^3/s]
tank2_e_valve_flow_rate_m3s = 0.2; % [m^3/s]
tank2_cross_section_area_m2 = 2; % [m^2]
tank2_max_vol_m3 = 8; % [m^3]

time_increment_s = 0.1; %[s]

% time rates	
init_period_s = 20.0; %[s]
high_safety_margin_s = 3.0; %[s]
low_safety_margin_s = 3.0; %[s]

% safety heights
tank1_safety_hi_ht_m = 5.0;
tank1_safety_lo_ht_m = 2.0;    
tank2_safety_hi_ht_m = 3.0;
tank2_safety_md_ht_m = 2.0;
tank2_safety_lo_ht_m = 1.0;
