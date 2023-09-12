/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 28/9/2022         *****************/
/**************** SWC     : ADC               *****************/
/**************** Version : 1.0               *****************/
/**************************************************************/
#include "STD_TYPES.h"
#include "bit_math.h"

#include "ADC_private.h"
#include "ADC_config.h"
#include "ADC_interface.h"

/* Global Pointer To Function */
void (*ADC_PfGlobal)(u16) = NULL;

void ADC_VoidInit(void)
{
#if VREF   == AVCC	
	/* Set Vref = VCC = 5V */
	SET_BIT(ADC_u8_ADMUX_REG,6);
	CLR_BIT(ADC_u8_ADMUX_REG,7);
#elif VREF == AREF	
	/* Set Vref = AREF */
	CLR_BIT(ADC_u8_ADMUX_REG,6);
	CLR_BIT(ADC_u8_ADMUX_REG,7);
#elif VREF == Internal_Voltage_Reference
	SET_BIT(ADC_u8_ADMUX_REG,6);
	SET_BIT(ADC_u8_ADMUX_REG,7);
#endif	
	/* Set Right Adjust */
	CLR_BIT(ADC_u8_ADMUX_REG,5);
	/* Disable Auto Trigger */
	CLR_BIT(ADC_u8_ADCSRA_REG,5);
	/* Set CLK/64 = 8MHZ/64 = 125KHZ  In Range (50KHZ : 200KHZ) */
	SET_BIT(ADC_u8_ADCSRA_REG,2);
	SET_BIT(ADC_u8_ADCSRA_REG,1);
	CLR_BIT(ADC_u8_ADCSRA_REG,0);
	/* Enable ADC */
	SET_BIT(ADC_u8_ADCSRA_REG,7);
}
u8 ADC_u8GetDigitalValue(u8 Copy_ChannalNum,u16 *Copy_Pu16ReturnDigitalValue)
{
	u8 Local_U8ErrorState = STATE_OK;
	u32 Local_u32TimeOut = 0;
	if (Copy_ChannalNum < 32 && Copy_Pu16ReturnDigitalValue!= NULL)
	{
		/* Clear MUX4 .. 0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_ChannalNum;
		/* Start Conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,6);
		/* Wait Flag */
		while(GET_BIT(ADC_u8_ADCSRA_REG,4) == 0  && Local_u32TimeOut < ADC_u32_TIME_OUT)
		{
			Local_u32TimeOut++;
		}
		if(GET_BIT(ADC_u8_ADCSRA_REG,4) != 0)
		{
			/* Clear Flag */
			SET_BIT(ADC_u8_ADCSRA_REG,4);
			*Copy_Pu16ReturnDigitalValue = ADC_u16_REG;
		}
		else
		{
			Local_U8ErrorState = STATE_NOK;
		}
	}
	else
	{
	   	Local_U8ErrorState = STATE_NOK;
	}
	return Local_U8ErrorState;
}
u8 ADC_u8GetDigitalValueINT(u8 Copy_ChannalNum,void(*Copy_Pf)(u16))
{
	u8 Local_U8ErrorState = STATE_OK;
	if (Copy_ChannalNum < 32 && Copy_Pf != NULL)
	{
		ADC_PfGlobal = Copy_Pf;
		/* Enable Intrrupt */
		SET_BIT(ADC_u8_ADCSRA_REG,3);
		/* Clear MUX4 .. 0 */
		ADC_u8_ADMUX_REG &= 0b11100000;
		/* Select Channel */
		ADC_u8_ADMUX_REG |= Copy_ChannalNum;
		/* Start Conversion */
		SET_BIT(ADC_u8_ADCSRA_REG,6);
	}
	else
	{
	   	Local_U8ErrorState = STATE_NOK;
	}
	return Local_U8ErrorState;
}
u8 ADC_u8GetRegValue(u16 *Copy_u16RegValue)
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_u16RegValue != NULL)
	{
		*Copy_u16RegValue = ADC_u16_REG;
	}
	else
	{
	   	Local_U8ErrorState = STATE_NOK;
	}
	return Local_U8ErrorState;
}

/* Prototype For ISR For ADC */
void __vector_16(void)                 __attribute__((signal));
void __vector_16(void)
{
	/* Disable INT */
	CLR_BIT(ADC_u8_ADCSRA_REG,3);
	/* Update Global Pointer */
	ADC_PfGlobal(ADC_u16_REG);
}