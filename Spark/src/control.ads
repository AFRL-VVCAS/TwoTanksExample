pragma SPARK_Mode(On);

-- This package provides control schemes for the 
-- pumps and valves in the system
package Control is

   -- This procedure performs the basic control logic
   -- for the operation of the Pump and Tank1 Valve.
   procedure Tank1_Control (HS_Status : in Boolean;
                            LS_Status : in Boolean;
                            Pump_Signal : in out Boolean;
                            Valve_Signal : in out Boolean)
     with
       Depends => (Pump_Signal =>+ (HS_Status, LS_Status),
                   Valve_Signal =>+ (HS_Status, LS_Status)),
       Pre => ((if HS_Status then LS_Status) and then
               (if not LS_Status then not HS_Status) and then
               (if Pump_Signal then not Valve_Signal) and then
               (if Valve_Signal then not Pump_Signal)),
       Post => (if HS_Status then (Valve_Signal and not Pump_Signal)
                  elsif not LS_Status then (Pump_Signal and not Valve_Signal)
                  else (Pump_Signal = Pump_Signal'Old and
                         Valve_Signal = Valve_Signal'Old));
   
   -- This procedure performs the basic control logic
   -- for the operation of the Tank2 Valves.
   procedure Tank2_Control (HS_Status : in Boolean;
                            MS_Status : in Boolean;
                            LS_Status : in Boolean;
                            Tank1_Valve : in Boolean;
                            Prod_Valve_Signal : out Boolean;
                            Emer_Valve_Signal : in out Boolean)
     with
       Depends => (Prod_Valve_Signal => (LS_Status),
                   Emer_Valve_Signal =>+ (HS_Status, MS_Status, Tank1_Valve)),
       Pre => ((if HS_Status then MS_Status) and then
                     (if MS_Status then LS_Status)),
       Post => ((if LS_Status then Prod_Valve_Signal else 
                      not Prod_Valve_Signal) and then
                   (if (HS_Status or else
                      (MS_Status and then 
                      Tank1_Valve and then 
                      Emer_Valve_Signal)) then
                   Emer_Valve_Signal
                      else
                   not Emer_Valve_Signal));

end Control;
