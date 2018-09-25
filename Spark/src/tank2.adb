package body Tank2
with
Refined_State => (Tank_State => The_Tank)
is
   
   -- Cylinder Tank
   type Tank_Type is 
      record
         Crossection_Area : Float; -- in feet^2
         Height           : Float; -- in feet
         Max_Volume       : Float; -- in feet^3
         Cur_Volume       : Float; -- in feet^3
         H_Sensor_Loc     : Float; -- in feet
         M_Sensor_Loc     : Float; -- in feet
         L_Sensor_Loc     : Float; -- in feet
      end record 
   with Predicate => (Cur_Volume <= Max_Volume);
   
   -- This is the hidden data structure for package
   The_Tank : Tank_Type;
     
   -- This sets up the parameters of the Tank
   procedure Initialize (Crossection_Area : in Tank_Area_Float;
                         Height           : in Tank_Height_Float;
                         High_Sensor_Loc  : in Tank_Height_Float;
                         Mid_Sensor_Loc   : in Tank_Height_Float;
                         Low_Sensor_Loc   : in Tank_Height_Float) 
   is  
   begin
      The_Tank := (Crossection_Area => Crossection_Area,
                   Height           => Height,
                   Max_Volume       => Crossection_Area * Height,
                   Cur_Volume       => 0.0,
                   H_Sensor_Loc     => High_Sensor_Loc,
                   M_Sensor_Loc     => Mid_Sensor_Loc,
                   L_Sensor_Loc     => Low_Sensor_Loc);
   end Initialize;
   
   -- This function to be deleted when system working correctly
   function Liquid_Height return Float is (The_Tank.Cur_Volume)
   with
   Refined_Post => (Liquid_Height'Result = The_Tank.Cur_Volume);
   
   -- This procedure handles the input of Liquid to the Tank
   -- Takes in a non-negative Float in cubic feet that is added
   procedure Liquid_In(Flow_In : in Tank_Volume_Float) is
   begin
      -- Check for Overflow of the Tank
      if ((The_Tank.Cur_Volume + Flow_In) > 
        The_Tank.Max_Volume) then
            The_Tank.Cur_Volume := The_Tank.Max_Volume;
      else
        The_Tank.Cur_Volume := The_Tank.Cur_Volume +
            Flow_In;
      end if;

   end Liquid_In;
   
   -- This procedure handles that outflow of liquid from the Tank
   -- Takes in a non-negative Float in cubic feet that is subracted
   procedure Liquid_Out(Flow_Out : in Tank_Volume_Float) is
   begin
      -- Check for Underflow of the Tank
      if ((The_Tank.Cur_Volume - Flow_Out) < 0.0) then
         The_Tank.Cur_Volume := 0.0;
      else
         The_Tank.Cur_Volume := The_Tank.Cur_Volume - 
           Flow_Out;
      end if;
   end Liquid_Out;
   
   -- This procedure gives the status of the High liquid sensor
   function High_Sensor_Status return Boolean
   is
      -- Check if the liquid is at or above the Sensor
      (The_Tank.H_Sensor_Loc  <= The_Tank.Cur_Volume);
   
   -- This procedure gives the status of the Mid liquid sensor
   function Mid_Sensor_Status return Boolean
   is
      -- Check if the liquid is at or above the Sensor
      (The_Tank.M_Sensor_Loc  <= The_Tank.Cur_Volume);
   
   -- This procedure gives the status of the Low liquid sensor
   function Low_Sensor_Status return Boolean
   is
      -- Check if the liquid is at or above the Sensor
      (The_Tank.L_Sensor_Loc <= The_Tank.Cur_Volume);
   
   -- This function checks the validity of the state of the Tank
   function Valid_Tank return Boolean
   is(The_Tank.Crossection_Area > 0.0 and then
          The_Tank.Height > 0.0 and then
          The_Tank.Cur_Volume >= 0.0 and then
          The_Tank.Cur_Volume <= The_Tank.Height and then
          The_Tank.H_Sensor_Loc > The_Tank.M_Sensor_Loc and then
          The_Tank.M_Sensor_Loc > The_Tank.L_Sensor_Loc and then
          The_Tank.L_Sensor_Loc >= 0.0);
   
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
   
end Tank2;
