pragma SPARK_Mode(On);
package body Valve 
is
   
   -- This function allows for the operation of the valve
   -- depending on capacity and it being enabled.
   function Valve_Operate (Valve : in Valve_Type;
                       Enable : in Boolean) return Float
   is
   begin
      -- If enabled, output the capacity of the Valve
      if Enable then
         return Float(Valve);
      else
         return 0.0;
      end if;
   end Valve_Operate;
   

   
end Valve;
