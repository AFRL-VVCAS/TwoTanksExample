pragma SPARK_Mode(On);
package body Control 
is
   
   -- This procedure performs the basic control logic
   -- for the operation of the Pump and Tank1 Valve.
   procedure Tank1_Control (HS_Status : in Boolean;
                            LS_Status : in Boolean;
                            Pump_Signal : in out Boolean;
                            Valve_Signal : in out Boolean)
   is
   begin
      -- If liquid above the High Sensor:
      --    Turn off Pump and Open Tank1_Valve
      -- Else If liquid is below the Low Sensor:
      --    Turn on Pump and Close Tank1_Valve
      -- Otherwise leave as they were.
      if (HS_Status) then
         Pump_Signal := False;
         Valve_Signal := True;
      elsif (LS_Status = False) then
         Pump_Signal := True;
         Valve_Signal := False;
      else
         -- No change in signals
         null;
      end if;
   end Tank1_Control;
   
   -- This procedure performs the basic control logic
   -- for the operation of the Tank2 Valves.
   procedure Tank2_Control (HS_Status : in Boolean;
                            MS_Status : in Boolean;
                            LS_Status : in Boolean;
                            Tank1_Valve : in Boolean;
                            Prod_Valve_Signal : out Boolean;
                            Emer_Valve_Signal : in out Boolean)
   is
   begin
      
      if LS_Status then
         Prod_Valve_Signal := True;
      else 
         Prod_Valve_Signal := False;
      end if;
      
      if (HS_Status or else
            (MS_Status and then 
             Tank1_Valve and then 
             Emer_Valve_Signal)) then
         Emer_Valve_Signal := True;
      else
         Emer_Valve_Signal := False;
      end if;
      
   end Tank2_Control;
   
   
end Control;
