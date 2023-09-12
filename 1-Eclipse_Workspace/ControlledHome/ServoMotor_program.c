/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 16/2/2023         *****************/
/**************** SWC     : Servo             *****************/
/**************** Version : 1.0               *****************/
/**************************************************************/
/* Lib Layer */
#include "STD_TYPES.h"
#include "bit_math.h"

#include "TIMERS_interface.h"
#include "ServoMotor_interface.h"
#include "TIMERS_private.h"

void VoidServoInit(void)
{
	TIMERS_VoidTimer1Init();
}
void VoidServoSetAngle (u8 Copy_u8Angle)
{
	TIMERS_u16_OCR1A_REG = ((Copy_u8Angle * 1000UL)/180) + 999;
}
