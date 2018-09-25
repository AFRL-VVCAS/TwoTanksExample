pragma SPARK_Mode(On);
package body Pump 
is
   
   -- This function returns the flow of liquid through
   -- the pump based upon the input Pump and whether it
   -- is turned On. 
   function Pump_Operate (Pump : in Pump_Type;
                       Enable : in Boolean) return Float
   is
   begin
      -- If On, output the capacity of the Pump
      if Enable then
         return Float(Pump);
      else
         return 0.0;
      end if;
   end Pump_Operate;

   
end Pump;
