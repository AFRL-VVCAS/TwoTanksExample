with Ada.Text_IO; with Ada.Integer_Text_IO;
with Ada.Float_Text_IO;

with Tank1;
with Tank2;
with Control;
with Pump;
with Valve; use Valve;

procedure Tts
  with
    SPARK_Mode => On
is

   -- Create a Pump and define initial conditions
   The_Pump : constant Pump.Pump_Type := 0.4;
   Pump_Flow : Float; -- := 0.0;
   Pump_Signal : Boolean := False;

   -- Create the Tank1 Valve and define initial conditions
   T1_Valve : constant Valve.Valve_Type := 0.2;
   T1_Valve_Flow : Float; -- := 0.0;
   T1_Valve_Signal : Boolean := False;

   -- Create the Production Valve and define initial conditions
   Prod_Valve : constant Valve.Valve_Type := 0.1;
   Prod_Valve_Flow : Float; -- := 0.0;
   Prod_Valve_Signal : Boolean; -- := False;

   -- Create the Emergency Valve and define initial conditions
   Emer_Valve : constant Valve.Valve_Type := 0.7;
   Emer_Valve_Flow : Float; -- := 0.0;
   Emer_Valve_Signal : Boolean := False;

   -- Define the parameters of Tank1
   T1_Crossection : constant Float := 1.0;
   T1_Height      : constant Float := 7.0;
   T1_HS_Loc      : constant Float := 5.0;
   T1_LS_Loc      : constant Float := 3.0;

   -- Define the parameters of Tank2
   T2_Crossection : constant Float := 1.0;
   T2_Height      : constant Float := 8.0;
   T2_HS_Loc      : constant Float := 6.0;
   T2_MS_Loc      : constant Float := 4.0;
   T2_LS_Loc      : constant Float := 2.0;

   -- Set the initial conditions for the Tank1 sensors
   T1_HS_Status   : Boolean; -- := False;
   T1_LS_Status   : Boolean; -- := False;

   -- Set the initial conditions for the Tank2 sensors
   T2_HS_Status   : Boolean; -- := False;
   T2_MS_Status   : Boolean; -- := False;
   T2_LS_Status   : Boolean; -- := False;




begin

   -- Initialize Tank1
   Tank1.Initialize(T1_Crossection,
                    T1_Height,
                    T1_HS_Loc,
                    T1_LS_Loc);

   -- Initialize Tank2
   Tank2.Initialize(T2_Crossection,
                    T2_Height,
                    T2_HS_Loc,
                    T2_MS_Loc,
                    T2_LS_Loc);

   --pragma Assert(Tank1.Valid_Tank);
   --pragma Assert(Tank2.Valid_Tank);

   --pragma Assert(Valve.Valid_Valve(T1_Valve));
   --pragma Assert(T1_Valve > 0.0);
  -- pragma Assert(Valve.Valid_Valve(Prod_Valve));
  -- pragma Assert(Valve.Valid_Valve(Emer_Valve));


   -- Run for 100 time units
   for Count in 1 .. 50 loop



      -- Obtain status of Sensors
      T1_HS_Status := Tank1.High_Sensor_Status;
      T1_LS_Status := Tank1.Low_Sensor_Status;
      T2_HS_Status := Tank2.High_Sensor_Status;
      T2_MS_Status := Tank2.Mid_Sensor_Status;
      T2_LS_Status := Tank2.Low_Sensor_Status;

      --pragma Loop_Invariant(Tank1.Valid_Tank);
      --pragma Loop_Invariant(Tank2.Valid_Tank);
      --pragma Assert(T1_HS_Loc > T1_LS_Loc);
      pragma Assert(if (Tank1.Liquid_Height >= T1_LS_Loc) then Tank1.Low_Sensor_Status);
      pragma Assert(if (Tank1.Liquid_Height >= T1_HS_Loc) then Tank1.High_Sensor_Status);
      pragma Assert(if (Tank1.Valid_Tank and T1_HS_Status) then T1_LS_Status);
      pragma Assert(if T1_HS_Status then T1_LS_Status);
      pragma Loop_Invariant(if T1_Valve_Signal then not Pump_Signal);
      pragma Loop_Invariant(if Pump_Signal then not T1_Valve_Signal);

      -- Obtain conrol signals based off Sensors
      Control.Tank1_Control(HS_Status    => T1_HS_Status,
                            LS_Status    => T1_LS_Status,
                            Pump_Signal  => Pump_Signal,
                            Valve_Signal => T1_Valve_Signal);

      Control.Tank2_Control(HS_Status         => T2_HS_Status,
                            MS_Status         => T2_MS_Status,
                            LS_Status         => T2_LS_Status,
                            Tank1_Valve       => T1_Valve_Signal,
                            Prod_Valve_Signal => Prod_Valve_Signal,
                            Emer_Valve_Signal => Emer_Valve_Signal);

      -- Calculate the Pump Flow
      Pump_Flow :=
        Pump.Pump_Operate(Pump   => The_Pump,
                          Enable => Pump_Signal);

      -- Calculate the Tank1 Valve Flow
      T1_Valve_Flow :=
        Valve.Valve_Operate(Valve  => T1_Valve,
                            Enable => T1_Valve_Signal);

      -- Calculate the Production Valve Flow
      Prod_Valve_Flow :=
        Valve.Valve_Operate(Valve  => Prod_Valve,
                            Enable => Prod_Valve_Signal);

      -- Calculate the Emergency Valve Flow
      Emer_Valve_Flow :=
        Valve.Valve_Operate(Valve  => Emer_Valve,
                            Enable => Emer_Valve_Signal);

--  Ada.Text_IO.Put("At Count ");
--  Ada.Integer_Text_IO.Put(Count,1);
--  Ada.Text_IO.Put(" Pump Flow is");
--  Ada.Float_Text_IO.Put(Pump_Flow,2,1,0);
--       Ada.Text_IO.Put(" and Valve Flow is");
--       Ada.Float_Text_IO.Put(T1_Valve_Flow,2,1,0);
--       Ada.Text_IO.New_Line;

      -- Handle the Pump Flow into Tank 1
      Tank1.Liquid_In(Flow_In => Pump_Flow);

      -- Handle the Valve Flow from Tank 1
      Tank1.Liquid_Out(Flow_Out => T1_Valve_Flow);

      -- Handle the Valve Flow into Tank 2
      Tank2.Liquid_In(Flow_In => T1_Valve_Flow);

      -- Handle the Production Valve Flow from Tank 1
      Tank2.Liquid_Out(Flow_Out => Prod_Valve_Flow);

      -- Handle the Emergency Valve Flow from Tank 1
      Tank2.Liquid_Out(Flow_Out => Emer_Valve_Flow);

      -- Check for Underflow and Overflow conditions
      pragma Assert (Tank1.No_Overflow);
      --pragma Assert (Tank1.No_Underflow);
      pragma Assert (Tank2.No_Overflow);
      --pragma Assert (Tank2.No_Underflow);


--        if T1_HS_Status then
--           Ada.Text_IO.Put("At iteration ");
--           Ada.Integer_Text_IO.Put(Count,1);
--           Ada.Text_IO.Put(" Tank1 Volume is");
--           Ada.Float_Text_IO.Put(Tank1.Liquid_Height,2,1,0);
--           Ada.Text_IO.Put(" High Sensor is ON");
--           if T1_LS_Status then
--              Ada.Text_IO.Put(" and Low Sensor is ON.");
--           else
--              Ada.Text_IO.Put(" and Low Sensor is OFF.");
--           end if;
--           Ada.Text_IO.New_Line;
--        elsif not T1_LS_Status then
--           Ada.Text_IO.Put("At iteration ");
--           Ada.Integer_Text_IO.Put(Count,1);
--           Ada.Text_IO.Put(" Tank1 Volume is");
--           Ada.Float_Text_IO.Put(Tank1.Liquid_Height,2,1,0);
--           if T1_HS_Status then
--              Ada.Text_IO.Put(" High Sensor is ON");
--           else
--              Ada.Text_IO.Put(" High Sensor is OFF");
--           end if;
--           Ada.Text_IO.Put(" And Low Sensor is OFF.");
--           Ada.Text_IO.New_Line;
--        else
--           Ada.Text_IO.Put("At iteration ");
--           Ada.Integer_Text_IO.Put(Count,1);
--           Ada.Text_IO.Put(" Tank1 Volume is");
--           Ada.Float_Text_IO.Put(Tank1.Liquid_Height,2,1,0);
--           if T1_HS_Status then
--              Ada.Text_IO.Put(" High Sensor is ON");
--           else
--              Ada.Text_IO.Put(" High Sensor is OFF");
--           end if;
--           if T1_LS_Status then
--              Ada.Text_IO.Put(" and Low Sensor is ON.");
--           else
--              Ada.Text_IO.Put(" and Low Sensor is OFF.");
--           end if;
--           Ada.Text_IO.New_Line;
--        end if;
--
--        if T2_HS_Status then
--           Ada.Text_IO.Put("At iteration ");
--           Ada.Integer_Text_IO.Put(Count,1);
--           Ada.Text_IO.Put(" Tank2 Volume is");
--           Ada.Float_Text_IO.Put(Tank2.Liquid_Height,2,1,0);
--           Ada.Text_IO.Put(" High Sensor is ON");
--           if T1_LS_Status then
--              Ada.Text_IO.Put(" and Low Sensor is ON.");
--           else
--              Ada.Text_IO.Put(" and Low Sensor is OFF.");
--           end if;
--           Ada.Text_IO.New_Line;
--        elsif not T2_LS_Status then
--           Ada.Text_IO.Put("At iteration ");
--           Ada.Integer_Text_IO.Put(Count,1);
--           Ada.Text_IO.Put(" Tank2 Volume is");
--           Ada.Float_Text_IO.Put(Tank2.Liquid_Height,2,1,0);
--           if T1_HS_Status then
--              Ada.Text_IO.Put(" High Sensor is ON");
--           else
--              Ada.Text_IO.Put(" High Sensor is OFF");
--           end if;
--           Ada.Text_IO.Put(" And Low Sensor is OFF.");
--           Ada.Text_IO.New_Line;
--        else
--           Ada.Text_IO.Put("At iteration ");
--           Ada.Integer_Text_IO.Put(Count,1);
--           Ada.Text_IO.Put(" Tank2 Volume is");
--           Ada.Float_Text_IO.Put(Tank2.Liquid_Height,2,1,0);
--           if T1_HS_Status then
--              Ada.Text_IO.Put(" High Sensor is ON");
--           else
--              Ada.Text_IO.Put(" High Sensor is OFF");
--           end if;
--           if T1_LS_Status then
--              Ada.Text_IO.Put(" and Low Sensor is ON.");
--           else
--              Ada.Text_IO.Put(" and Low Sensor is OFF.");
--           end if;
--           Ada.Text_IO.New_Line;
--        end if;

   end loop;

end Tts;
