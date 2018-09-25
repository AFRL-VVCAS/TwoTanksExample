pragma SPARK_Mode(On);
package Tank2
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
                         Mid_Sensor_Loc   : in Tank_Height_Float;
                         Low_Sensor_Loc   : in Tank_Height_Float)
     with
       Global => (Output => Tank_State),
       Depends => (Tank_State => 
                   (Crossection_Area,
                    Height,
                    High_Sensor_Loc,
                    Mid_Sensor_Loc,
                    Low_Sensor_Loc)),
       Pre => (Crossection_Area > 0.0 and
               Height > 0.0 and
               High_Sensor_Loc > 0.0 and
               High_Sensor_Loc <= Height and
               Mid_Sensor_Loc > 0.0 and
               Mid_Sensor_Loc < Height and
               Mid_Sensor_Loc < High_Sensor_Loc and
               Low_Sensor_Loc < Mid_Sensor_Loc and
               Low_Sensor_Loc >= 0.0 and
               Low_Sensor_Loc < Height),
        Post => Valid_Tank;
   
   
   -- This function to be deleted when system working correctly
   function Liquid_Height return Float
     with
       Global => (Input => Tank_State),
       Depends => (Liquid_Height'Result => Tank_State);
   
   -- This procedure handles the input of Liquid to the Tank
   -- Takes in a non-negative Float in cubic feet that is added
   procedure Liquid_In (Flow_In : in Tank_Volume_Float)
     with
       Global => (In_Out => Tank_State),
       Depends => (Tank_State =>+ (Flow_In)),
       Pre => (Flow_In >= 0.0 and Valid_Tank),
       Post => (Valid_Tank);
   
   -- This procedure handles that outflow of liquid from the Tank
   -- Takes in a non-negative Float in cubic feet that is subracted
   procedure Liquid_Out (Flow_Out : in Tank_Volume_Float)
   with
       Global => (In_Out => Tank_State),
       Depends => (Tank_State =>+ (Flow_Out)),
       Pre => (Flow_Out >= 0.0 and Valid_Tank),
       Post => Valid_Tank;
   
   -- This procedure gives the status of the High liquid sensor
   function High_Sensor_Status return Boolean
     with
       Global => (Input => Tank_State),
       Depends => (High_Sensor_Status'Result => Tank_State),
       Pre => Valid_Tank;
   
   -- This procedure gives the status of the Mid liquid sensor
   function Mid_Sensor_Status return Boolean
     with
       Global => (Input => Tank_State),
       Depends => (Mid_Sensor_Status'Result => Tank_State),
       Pre => Valid_Tank;
   
   -- This procedure gives the status of the Low liquid sensor
   function Low_Sensor_Status return Boolean
     with
       Global => (Input => Tank_State),
       Depends => (Low_Sensor_Status'Result => Tank_State);
    
   -- This function checks the validity of the state of the Tank
   function Valid_Tank return boolean
     with
       Global => (Input => Tank_State),
     Depends => (Valid_Tank'Result => Tank_State);
   
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

end Tank2;
