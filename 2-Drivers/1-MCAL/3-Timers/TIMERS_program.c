/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 28/9/2022         *****************/
/**************** SWC     : TIMERS            *****************/
/**************** Version : 3.0               *****************/
/**************************************************************/
#include "STD_TYPES.h"
#include "bit_math.h"

/* MCAL */
#include"TIMERS_private.h"
#include"TIMERS_interface.h"
#include "TIMERS_config.h"
/* Global Pointer To Function Timers */
static void(*TIMERS_PfTimer0OVF)(void) = NULL;
static void(*TIMERS_PfTimer0CTC)(void) = NULL;

void TIMERS_VoidTimer1Init(void)
{
	/* Select Mode 14 Fast PMW */
	SET_BIT(TIMERS_u8_TCCR1A_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,0);
	SET_BIT(TIMERS_u8_TCCR1B_REG,4);
	SET_BIT(TIMERS_u8_TCCR1B_REG,3);
	/* Set Top Value In Register ICR1 REG */
	SET_BIT(TIMERS_u8_TCCR1A_REG,7);
	CLR_BIT(TIMERS_u8_TCCR1A_REG,6);
	TIMERS_u16_ICR1_REG  = 19999;
	/* Set Hardware Action On Pin OCR */
	TIMERS_u16_OCR1A_REG = 999;
	/* Set Prescaler CLK/8 */
	CLR_BIT(TIMERS_u8_TCCR1B_REG,2);
	SET_BIT(TIMERS_u8_TCCR1B_REG,1);
	CLR_BIT(TIMERS_u8_TCCR1B_REG,0);
}
void TIMERS_VoidTimer1SetCompareMatchValueA (u16 Copy_u16OCRValue)
{
	TIMERS_u16_OCR1A_REG = Copy_u16OCRValue;
}
void TIMERS_VoidInit(void)
{
#if      TIMER0_MODE == TIMER0_NORMAL_MODE
	/* Select Normal Mode */
	CLR_BIT(TIMERS_u8_TCCR0_REG,3);
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	/* Select Clock/8 */
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
	/* Start Counter From .. */
	TIMERS_u8_TCNT0_REG = 196;
	/* Enable Interrupt Timer0 OVF */
    SET_BIT(TIMERS_u8_TIMSK_REG,0);
#elif    TIMER0_MODE == TIMER0_CTC_MODE	
	/* Select CTC Mode */
	SET_BIT(TIMERS_u8_TCCR0_REG,3);
	CLR_BIT(TIMERS_u8_TCCR0_REG,6);
	/* Select Clock/8 */
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
	/* Enable Interrupt Timer0 CTC */
    SET_BIT(TIMERS_u8_TIMSK_REG,1);
	/* Set Compare Match For unit Reg */
	TIMERS_u8_OCR0_REG = 99;
#elif    TIMER0_MODE == TIMER0_FAST_PWM_MODE
	/* Select Fast PWM Mode */
	SET_BIT(TIMERS_u8_TCCR0_REG,3);
	SET_BIT(TIMERS_u8_TCCR0_REG,6);
	/* Select Hardware Pin Action on Compare Output Mode ,Fast PWM Mode */
	SET_BIT(TIMERS_u8_TCCR0_REG,5);
	CLR_BIT(TIMERS_u8_TCCR0_REG,4);
	/* Select Clock/8 */
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
#elif    TIMER0_MODE == TIMER0_PWM_PHASE_CORRECT_MODE
	/* Select PWM Phase Correct Mode */
	CLR_BIT(TIMERS_u8_TCCR0_REG,3);
	SET_BIT(TIMERS_u8_TCCR0_REG,6);
	/* Select Hardware Pin Action on Compare Output Mode ,PWM Phase Correct Mode */
	SET_BIT(TIMERS_u8_TCCR0_REG,5);
	CLR_BIT(TIMERS_u8_TCCR0_REG,4);
	/* Select Clock/8 */
	CLR_BIT(TIMERS_u8_TCCR0_REG,2);
	SET_BIT(TIMERS_u8_TCCR0_REG,1);
	CLR_BIT(TIMERS_u8_TCCR0_REG,0);
#else  
       #error "Error Timer0 Mode"	
#endif 
}
void TIMERS_VoidTIMER0WriteCompareMatchValue(u8 Copy_u8OCRValue)
{
	TIMERS_u8_OCR0_REG = Copy_u8OCRValue;
}  
u8 TIMERS_u8TIMER0OVFSetCallBack(void(*Copy_Pf)(void))
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_Pf != NULL)
	{
		TIMERS_PfTimer0OVF = Copy_Pf;
	}
	else
	{
		Local_U8ErrorState = STATE_NOK;
	}
	return Local_U8ErrorState;
}
u8 TIMERS_u8TIMER0CTCSetCallBack(void(*Copy_Pf)(void))
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_Pf != NULL)
	{
		TIMERS_PfTimer0CTC = Copy_Pf;
	}
	else
	{
		Local_U8ErrorState = STATE_NOK;
	}
	return Local_U8ErrorState;
}
 
 /* ProtoType Of ISR FOR Timer0 OVF */
void __vector_11(void)          __attribute__((signal));
void __vector_11(void)
{
	static u16 Local_u16CounterOVF = 0;
	/* Increment Counter Flag */
	Local_u16CounterOVF++;
	/* Flag Happen 10 Time Every 256 MacroSecond */
	if(Local_u16CounterOVF == 2560)
	{
	    TIMERS_u8_TCNT0_REG = 196;
		/* Clear OVF Counter */
		Local_u16CounterOVF = 0;
		/* Call Application Function */
		if(TIMERS_PfTimer0OVF != NULL)
		{
			TIMERS_PfTimer0OVF();
		}
	}
}

/* ProtoType Of ISR FOR Timer0 CTC */
void __vector_10(void)          __attribute__((signal));
void __vector_10(void)
{
	static u16 Local_u16CounterCTC = 0;
	/* Increment Counter Flag */
	Local_u16CounterCTC++;
	/* Flag Happen 10 Time Every 256 MacroSecond */
	if(Local_u16CounterCTC == 10000)
	{
		/* Clear OVF Counter */
		Local_u16CounterCTC = 0;
		/* Call Application Function */
		if(TIMERS_PfTimer0CTC != NULL)
		{
			TIMERS_PfTimer0CTC();
		}
	}
}
