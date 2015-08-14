Contents of TwoTanks_Basic
===============================

Last Updated: 20150109

---------------------------------------------------------------------------
Table of Contents
---------------------------------------------------------------------------
1 - Directory Contents
2 - Ctrl_Tanks_AGREE
3 - Ctrl_Tanks_SLDV
4 - Ctrl_Tanks_SpeAR
5 - QVV AGREE Primitives (20150108)
6 - Reference
7 - Additional Files

---------------------------------------------------------------------------
Directory Contents
---------------------------------------------------------------------------
+ TwoTanks_Basic
	+ Ctrl_Tanks_AGREE
		- .project
		- config.aadl
		- controller.aadl
		- CtrlTanksExample.aadl
		- Environment.aadl
		- pump.aadl
		- sensor.aadl
		- std.aadl
		- tank.aadl
		- valve.aadl
	+ Ctrl_Tanks_SLDV
		- Coupled_Tanks_Primitives_Design_Verifier_KHG_SLDV_2.slx
		- README.txt
	+ Ctrl_Tanks_SpeAR
		- .project
		- CoolingTank.spear
		- CoolingTankCtrl.spear
		- definitions.spear
		- HoldingTank.spear
		- HoldingTankCtrl.spear
		- project.xml
		- Pump.spear
		- SystemLevel.spear
		- Valve.spear
	+ QVV AGREE Primitives (20150108)
		+ Ctrl_Tanks_QVV
			- .project
			- actuator.aadl
			- binary_switch.aadl
			- config.aadl
			- constant.aadl
			- controller.aadl
			- delay.aadl
			- Environment.aadl
			- initializer.aadl
			- Initial_Conditions.aadl
			- limiter.aadl
			- not.aadl
			- relational.aadl
			- sensor.aadl
			- std.aadl
			- tank1.aadl
			- tank2.aadl
			- Tank_Constants.aadl
			- tank_system.aadl
			- two_input_and.aadl
			- two_input_diff.aadl
			- two_input_division.aadl
			- two_input_product.aadl
			- two_input_sum.aadl
			- Updater.aadl		
		- Hoffman Primitive Tank Discovery (20150108).docx
	+ Reference
		+ SpeAR Papers
			- SPEAR NFM2014_20131125.pdf
			- SPEAR SPIN2014.pdf
			- SpeAR_HCSS_2015.pdf
		- Brief to LM (20141015).pptx
		- Brief to NASA Ames_Armstrong (20141016).pptx
		- CtrlTanks_Quick_Reference.pptx
	- Coupled Tanks Requirements_20150107.docx
	- Funct_Sim_12B_qvt_00.mdl
	- README.txt

---------------------------------------------------------------------------
Ctrl_Tanks_AGREE
---------------------------------------------------------------------------
This is the original two tank model made in AGREE that is the basis of this work. Additionally the single tank model system is included in this work and can be referenced should it be necessary. Not included in this packet is the reference material that went into this creation.

---------------------------------------------------------------------------
Ctrl_Tanks_SLDV
---------------------------------------------------------------------------
This is the MatLab model work done with Simulink Design Verifier off of the AGREE representation from 2 December 2014.

---------------------------------------------------------------------------
Ctrl_Tanks_SpeAR
---------------------------------------------------------------------------
This is the SpeAR requirement analysis completed off of the original two tank concept.

---------------------------------------------------------------------------
QVV AGREE Primitives (20150108)
---------------------------------------------------------------------------
This is the AGREE work to utilize primitives on the primitive-based two tank simulink model. Included in this directory is the AGREE project that analyzes the simulink model as well as a document that describes where there were differences discovered that must be resolved.

---------------------------------------------------------------------------
Reference
---------------------------------------------------------------------------
This directory includes a number of background documents that may be useful to the reader including a number of presentations on how requirements, architecture, and models relate. There is also a document that provides a high hierarchical view of the two tank system with a quick reference layout of an AGREE and a SpeAR file.

In addition, there is a directory that includes a number of candidate SpeAR papers that may be useful if interested in additional background knowledge of that tool. 

---------------------------------------------------------------------------
Additional Files
---------------------------------------------------------------------------
Also included in this directory:
- The requirements document in the directory is the more complex mode logic version due to the lack of a basic requirement sheet being originally developed. This is a placeholder for when the basic requirement document is ready it to replace the existing.
- The simulink matlab file is the primitive-based simulink model of the two tank system. This does not include any mode logic capability at this time.