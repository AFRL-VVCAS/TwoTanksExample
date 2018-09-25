pragma SPARK_Mode(On);

-- This package provides a Data Type and subprograms
-- to handle Pump that moves liquid into the system.
package Pump is

   Max_Flow : constant := 20.0;

   -- This is the Pump Data Type that the subprograms use.
   -- The Float is the volume of that the Pump handles.
   type Pump_Type is new Float range 0.0 .. Max_Flow; -- in feet^3/unit time
   
   -- This function returns the flow of liquid through
   -- the pump based upon the input Pump and whether it
   -- is turned On. 
   function Pump_Operate (Pump : in Pump_Type;
                          Enable : in Boolean) return Float
     with
       Depends => (Pump_Operate'Result => (Pump, Enable)),
       Pre => Valid_Pump(Pump),
       Post => Valid_Flow(Pump_Operate'Result);
   
   -- This function checks the validity of a specified Pump
   function Valid_Pump (Pump : in Pump_Type) return Boolean
     is (Pump > 0.0)
     with
       Depends => (Valid_Pump'Result => Pump),
       Post => (Valid_Pump'Result = (Pump > 0.0)); 
   
   -- This function checks the validitiy of the output
   -- flow from the Pump_Operate function. 
   function Valid_Flow (Flow : in Float) return Boolean
     is (Flow >= 0.0)
     with
       Depends => (Valid_Flow'Result => Flow),
       Post => (Valid_Flow'Result = (Flow >= 0.0));

end Pump;
