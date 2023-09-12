/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 11/2/2023         *****************/
/**************** SWC     : Stepper Motor     *****************/
/**************** Version : 1.0               *****************/
/**************************************************************/
#ifndef STEPPERMOTOR_INTERFACE_H_
#define STEPPERMOTOR_INTERFACE_H_
 
#define StepperMotor_u8_ClockWise			     	0
#define StepperMotor_u8_AntiClockWise				1
		   
void Step_VoidSetAngle(u8 Copy_u8Direction ,u16 Copy_u16Angle);

#endif