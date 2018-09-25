pragma SPARK_Mode(On);

-- This package provides a user with a Valve Type and
-- subprograms to operate a valve
package Valve is

   Max_Flow : constant := 20.0;

   -- The Valve_Type allows users to create valves
   -- with a specified capacity. 
   type Valve_Type is new Float range 0.0 .. Max_Flow; -- in feet^3/unit time
   
   -- This function allows for the operation of the valve
   -- depending on capacity and it being enabled.
   function Valve_Operate (Valve : in Valve_Type;
                       Enable : in Boolean) return Float
     with
       Depends => (Valve_Operate'Result => (Valve, Enable)),
       Pre => Valid_Valve(Valve),
       Post => Valid_Flow(Valve_Operate'Result);
   
   -- This function validates a specified Valve
   function Valid_Valve (Valve : in Valve_Type) return Boolean
     is (Valve > 0.0)
     with
       Depends => (Valid_Valve'Result => Valve);
   
   -- This function validates the flow of an operating Valve
   function Valid_Flow (Flow : in Float) return Boolean
     is (Flow >= 0.0)
     with
       Depends => (Valid_Flow'Result => Flow); 

end Valve;
