pragma SPARK_Mode(On);
package body Tank1 
with
Refined_State => (Tank_State => The_Tank)
is
   
   -- This sets up the parameters of the Tank
   procedure Initialize (Crossection_Area : in Tank_Area_Float;
                         Height           : in Tank_Height_Float;
                         High_Sensor_Loc  : in Tank_Height_Float;
                         Low_Sensor_Loc   : in Tank_Height_Float) 
   is  
   begin
      The_Tank := (Crossection_Area => Crossection_Area,
                   Height           => Height,
                   Max_Volume       => Crossection_Area * Height,
                   Cur_Volume       => 0.0,
                   H_Sensor_Loc     => High_Sensor_Loc,
                   L_Sensor_Loc     => Low_Sensor_Loc);
   end Initialize;
   
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
      
end Tank1;
