pragma SPARK_Mode(On);
package Tank1
with
Abstract_State => Tank_State
  
is

subtype Tank_Height_Float is Float range 0.0 .. 20.0;
subtype Tank_Area_Float is Float range 0.0 .. 10.0;
subtype Tank_Volume_Float is Float range 0.0 .. 200.0;

   -- Allows the user to set the parameters of the Tank
   procedure Initialize (Crossection_Area : in Tank_Area_Float;
                         Height           : in Tank_Height_Float;
                         High_Sensor_Loc  : in Tank_Height_Float;
                         Low_Sensor_Loc   : in Tank_Height_Float)
     with
       Global => (Output => Tank_State),
       Depends => (Tank_State => 
                   (Crossection_Area,
                    Height,
                    High_Sensor_Loc,
                    Low_Sensor_Loc)),
       Pre => (Crossection_Area > 0.0 and
               Height > 0.0 and
               High_Sensor_Loc > 0.0 and
               High_Sensor_Loc <= Height and
               Low_Sensor_Loc < High_Sensor_Loc and
               Low_Sensor_Loc >= 0.0 and
               Low_Sensor_Loc < Height);
   
   
   -- This function to be deleted when system working correctly
   function Liquid_Height return Float
     with
       Global => (Input => Tank_State),
       Depends => (Liquid_Height'Result => Tank_State),
       ghost;
   
   -- This procedure handles the input of Liquid to the Tank
   -- Takes in a non-negative Float in cubic feet that is added
   procedure Liquid_In (Flow_In : in Tank_Volume_Float)
     with
       Global => (In_Out => Tank_State),
       Depends => (Tank_State =>+ (Flow_In)),
       Pre => Flow_In >= 0.0;
   
   -- This procedure handles that outflow of liquid from the Tank
   -- Takes in a non-negative Float in cubic feet that is subracted
   procedure Liquid_Out (Flow_Out : in Tank_Volume_Float)
   with
       Global => (In_Out => Tank_State),
       Depends => (Tank_State =>+ (Flow_Out)),
       Pre => Flow_Out >= 0.0;
   
   -- This procedure gives the status of the High liquid sensor
   function High_Sensor_Status return Boolean
     with
       Global => (Input => Tank_State),
       Depends => (High_Sensor_Status'Result => Tank_State);
   
   -- This procedure gives the status of the Low liquid sensor
   function Low_Sensor_Status return Boolean
     with
       Global => (Input => Tank_State),
       Depends => (Low_Sensor_Status'Result => Tank_State);
    
   -- This function checks the validity of the state of the Sensors
   function Valid_Sensors return boolean
     with
       Global => (Input => Tank_State),
     Depends => (Valid_Sensors'Result => Tank_State);
   
   -- This function checks the validity of the state of the Tank
   function Valid_Tank return boolean
     with
       Global => (Input => Tank_State),
       Depends => (Valid_Tank'Result => Tank_State),
       Ghost;
   
   -- This function verifies that there is no Overflow
   function No_Overflow return Boolean
     with
       Global => (Input => Tank_State),
       Depends => (No_Overflow'Result => Tank_State);
   
   -- This function verifies that there is no Underflow
   function No_Underflow return Boolean
     with
       Global => (Input => Tank_State),
       Depends => (No_Underflow'Result => Tank_State);  

private 

   -- Cylinder Tank
   type Tank_Type is 
      record
         Crossection_Area : Tank_Area_Float; -- in feet^2
         Height           : Tank_Height_Float; -- in feet
         Max_Volume       : Tank_Volume_Float; -- in feet^3
         Cur_Volume       : Tank_Volume_Float; -- in feet^3
         H_Sensor_Loc     : Tank_Height_Float; -- in feet
         L_Sensor_Loc     : Tank_Height_Float; -- in feet
      end record
     with Predicate => 
       Cur_Volume <= Max_Volume and then 
       Crossection_Area > 0.0 and then
       Height > 0.0 and then
       Cur_Volume >= 0.0 and then
       Cur_Volume <= Height and then
       H_Sensor_Loc > L_Sensor_Loc and then
       L_Sensor_Loc >= 0.0 and then
       H_Sensor_Loc <= Height and then
       (if H_Sensor_Loc <= Cur_Volume then L_Sensor_Loc <= Cur_Volume);
   
   -- This is the hidden data structure for package
   The_Tank : Tank_Type with Part_Of => Tank_State;
     
   -- This function to be deleted when system working correctly
   function Liquid_Height  return Float is (The_Tank.Cur_Volume)
   with
       Refined_Post => (Liquid_Height'Result = The_Tank.Cur_Volume);
   
   -- This procedure gives the status of the High liquid sensor
   function High_Sensor_Status return Boolean
   is
      -- Check if the liquid is at or above the Sensor
     ((The_Tank.H_Sensor_Loc <= The_Tank.Cur_Volume) and then
          (The_Tank.L_Sensor_Loc <= The_Tank.Cur_Volume))
   with
   Refined_Post => ((High_Sensor_Status'Result = 
                      (The_Tank.H_Sensor_Loc <= The_Tank.Cur_Volume)) and then
                      (if High_Sensor_Status'Result then 
                          The_Tank.L_Sensor_Loc <= The_Tank.Cur_Volume));

   -- This procedure gives the status of the Low liquid sensor
   function Low_Sensor_Status return Boolean
   is
      -- Check if the liquid is at or above the Sensor
     (The_Tank.L_Sensor_Loc  <= The_Tank.Cur_Volume)
   with
   Refined_Post => (Low_Sensor_Status'Result = 
                      (The_Tank.L_Sensor_Loc <= The_Tank.Cur_Volume));
  
   -- This function checks the validity of the state of the Sensors
   function Valid_Sensors return boolean
   is
      (if The_Tank.H_Sensor_Loc <= The_Tank.Cur_Volume then 
                 The_Tank.L_Sensor_Loc  <= The_Tank.Cur_Volume);
   
      
   
   -- This function checks the validity of the state of the Tank
   function Valid_Tank return Boolean
   is
      (The_Tank.Crossection_Area > 0.0 and then
       The_Tank.Height > 0.0 and then
       The_Tank.Cur_Volume >= 0.0 and then
       The_Tank.Cur_Volume <= The_Tank.Height and then
       The_Tank.H_Sensor_Loc > The_Tank.L_Sensor_Loc and then
       The_Tank.L_Sensor_Loc >= 0.0 and then
       The_Tank.H_Sensor_Loc <= The_Tank.Height and then
       Valid_Sensors);
   
   -- This function verifies that there is no Overflow
   function No_Overflow return Boolean
   is
      -- Must be less than completely full
      (The_Tank.Cur_Volume < The_Tank.Max_Volume);
   
   -- This function verifies that there is no Underflow
   function No_Underflow return Boolean
   is
      -- Must not be empty
      (The_Tank.Cur_Volume > 0.0);

end Tank1;
