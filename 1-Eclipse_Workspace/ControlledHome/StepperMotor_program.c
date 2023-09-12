/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 11/2/2023         *****************/
/**************** SWC     : Stepper Motor     *****************/
/**************** Version : 1.0               *****************/
/**************************************************************/

/* Lib Layer */
#include "STD_TYPES.h"
#include "bit_math.h"
#include <util/delay.h>
/* MCAL */
#include "DIO_Interface.h"
#include "StepperMotor_interface.h"
void Step_VoidSetAngle(u8 Copy_u8Direction ,u16 Copy_u16Angle)
{
	u32 Local_u32NumberOfSteps ,Local_u32NumberOfIterations ,Local_u32Counter ;
	
	 /* Calculate Number Of Steps */
	Local_u32NumberOfSteps = (Copy_u16Angle * 2048UL)/360;
	
	/* Calculate Number Of Iterations */
	Local_u32NumberOfIterations = Local_u32NumberOfSteps/4 ;

	if(Copy_u8Direction == StepperMotor_u8_AntiClockWise )
	{
		for(Local_u32Counter = 0; Local_u32Counter < Local_u32NumberOfIterations; Local_u32Counter++)
		{
			/*                        Step1                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_HIGH);
			_delay_ms(10);
			/*                        Step2                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_HIGH);
			_delay_ms(10);
			/*                        Step3                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_HIGH);
			_delay_ms(10);
			/*                        Step4                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_LOW);
			_delay_ms(10);
		}
	}
	else if (Copy_u8Direction == StepperMotor_u8_ClockWise)
	{
		for(Local_u32Counter = 0; Local_u32Counter < Local_u32NumberOfIterations; Local_u32Counter++)
		{
			/*                        Step1                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_LOW);
			_delay_ms(10);
			/*                        Step2                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_HIGH);
			_delay_ms(10);
			/*                        Step3                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_HIGH);
			_delay_ms(10);
			/*                        Step4                               */
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN3, DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN4, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN5, DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTC, DIO_U8_PIN6, DIO_U8_HIGH);
			_delay_ms(10);
		}
	}
}
