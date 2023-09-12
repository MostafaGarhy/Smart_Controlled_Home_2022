/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 3/9/2022          *****************/
/**************** SWC     : DIO               *****************/
/**************** Version : 3.3                 *****************/
/**************************************************************/

/* Lib Layer */
#include "STD_TYPES.h"
#include "bit_math.h"
/* MCAL */
#include "DIO_Private.h"
#include "DIO_Interface.h"
#include "DIO_Config.h"

void DIO_VoidInit(void)
{
	/* DDR */

	DDRA_REG = Init_Problem(DIO_U8_PA7_INTIAL_DIRECTION,DIO_U8_PA6_INTIAL_DIRECTION,DIO_U8_PA5_INTIAL_DIRECTION,
			   DIO_U8_PA4_INTIAL_DIRECTION,DIO_U8_PA3_INTIAL_DIRECTION,DIO_U8_PA2_INTIAL_DIRECTION,
			   DIO_U8_PA1_INTIAL_DIRECTION,DIO_U8_PA0_INTIAL_DIRECTION);

	DDRB_REG = Init_Problem(DIO_U8_PB7_INTIAL_DIRECTION,DIO_U8_PB6_INTIAL_DIRECTION,DIO_U8_PB5_INTIAL_DIRECTION,
			   DIO_U8_PB4_INTIAL_DIRECTION,DIO_U8_PB3_INTIAL_DIRECTION,DIO_U8_PB2_INTIAL_DIRECTION,
			   DIO_U8_PB1_INTIAL_DIRECTION,DIO_U8_PB0_INTIAL_DIRECTION);

	DDRC_REG = Init_Problem(DIO_U8_PC7_INTIAL_DIRECTION,DIO_U8_PC6_INTIAL_DIRECTION,DIO_U8_PC5_INTIAL_DIRECTION,
			   DIO_U8_PC4_INTIAL_DIRECTION,DIO_U8_PC3_INTIAL_DIRECTION,DIO_U8_PC2_INTIAL_DIRECTION,
			   DIO_U8_PC1_INTIAL_DIRECTION,DIO_U8_PC0_INTIAL_DIRECTION);

	DDRD_REG = Init_Problem(DIO_U8_PD7_INTIAL_DIRECTION,DIO_U8_PD6_INTIAL_DIRECTION,DIO_U8_PD5_INTIAL_DIRECTION,
			   DIO_U8_PD4_INTIAL_DIRECTION,DIO_U8_PD3_INTIAL_DIRECTION,DIO_U8_PD2_INTIAL_DIRECTION,
			   DIO_U8_PD1_INTIAL_DIRECTION,DIO_U8_PD0_INTIAL_DIRECTION);

	/* PORTS */

	PORTA_REG = Init_Problem(DIO_U8_PA7_INTIAL_VALUE,DIO_U8_PA6_INTIAL_VALUE,DIO_U8_PA5_INTIAL_VALUE,
			    DIO_U8_PA4_INTIAL_VALUE,DIO_U8_PA3_INTIAL_VALUE,DIO_U8_PA2_INTIAL_VALUE,
			    DIO_U8_PA1_INTIAL_VALUE,DIO_U8_PA0_INTIAL_VALUE);

	PORTB_REG = Init_Problem(DIO_U8_PB7_INTIAL_VALUE,DIO_U8_PB6_INTIAL_VALUE,DIO_U8_PB5_INTIAL_VALUE,
			    DIO_U8_PB4_INTIAL_VALUE,DIO_U8_PB3_INTIAL_VALUE,DIO_U8_PB5_INTIAL_VALUE,
			    DIO_U8_PB1_INTIAL_VALUE,DIO_U8_PB0_INTIAL_VALUE);

	PORTC_REG = Init_Problem(DIO_U8_PC7_INTIAL_VALUE,DIO_U8_PC6_INTIAL_VALUE,DIO_U8_PC5_INTIAL_VALUE,
			    DIO_U8_PC4_INTIAL_VALUE,DIO_U8_PC3_INTIAL_VALUE,DIO_U8_PC2_INTIAL_VALUE,
			    DIO_U8_PC1_INTIAL_VALUE,DIO_U8_PC0_INTIAL_VALUE);

	PORTD_REG = Init_Problem(DIO_U8_PD7_INTIAL_VALUE,DIO_U8_PD6_INTIAL_VALUE,DIO_U8_PD5_INTIAL_VALUE,
			    DIO_U8_PD4_INTIAL_VALUE,DIO_U8_PD3_INTIAL_VALUE,DIO_U8_PD2_INTIAL_VALUE,
			    DIO_U8_PD1_INTIAL_VALUE,DIO_U8_PD0_INTIAL_VALUE);


}

u8 DIO_U8SetPinDirection(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Direction)
{
	u8 Local_U8ErrorState = STATE_OK;
	if (Copy_U8Port<=DIO_U8_PORTD && Copy_U8Pin<=DIO_U8_PIN7)
	{
		switch	(Copy_U8Port)
		{

		    case DIO_U8_PORTA :
		    {
		    	if(Copy_U8Direction == DIO_U8_LOW)
		    		CLR_BIT(DDRA_REG,Copy_U8Pin);
		    	else if(Copy_U8Direction ==DIO_U8_HIGH)
		    		SET_BIT(DDRA_REG,Copy_U8Pin);
		    	else
				{
		    		/* Do Nothing */
				}	
		    		break;
		    }		
		    case DIO_U8_PORTB :
			{
		    	if(Copy_U8Direction == DIO_U8_LOW)
		    		CLR_BIT(DDRB_REG,Copy_U8Pin);
		    	else if (Copy_U8Direction == DIO_U8_HIGH)
		    		SET_BIT(DDRB_REG,Copy_U8Pin);
		    	else
				{
		    		/* Do Nothing */
				}	
		    		break;
			}
		    case DIO_U8_PORTC :
			{
		    	if(Copy_U8Direction == DIO_U8_LOW)
		    		CLR_BIT(DDRC_REG,Copy_U8Pin);
		    	else if (Copy_U8Direction == DIO_U8_HIGH)
		    		SET_BIT(DDRC_REG,Copy_U8Pin);
		    	else
				{
		    		/* Do Nothing */
				}	
		    		break;
			}
		    case DIO_U8_PORTD :
			{
		    	if(Copy_U8Direction == DIO_U8_LOW)
		    		CLR_BIT(DDRD_REG,Copy_U8Pin);
		    	else if (Copy_U8Direction == DIO_U8_HIGH)
		    		SET_BIT(DDRD_REG,Copy_U8Pin);
		    	else
				{
		    		/* Do Nothing */
				}	
		    		break;
			}
            
	    }
	}
	else
		Local_U8ErrorState = STATE_NOK;
	return(Local_U8ErrorState);
}
u8 DIO_U8SetPortDirection(u8 Copy_U8Port ,u8 Copy_U8Direction)
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_U8Port<=DIO_U8_PORTD )
	{
		switch(Copy_U8Port)
		{
		case DIO_U8_PORTA :DDRA_REG = Copy_U8Direction ; break;
		case DIO_U8_PORTB :DDRB_REG = Copy_U8Direction ; break;
		case DIO_U8_PORTC :DDRC_REG = Copy_U8Direction ; break;
		case DIO_U8_PORTD :DDRD_REG = Copy_U8Direction ; break;
		}
	}
	else
	{
		Local_U8ErrorState = STATE_NOK;
	}
	return(Local_U8ErrorState);
}
u8 DIO_U8SetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value)
{
	u8 Local_U8ErrorState = STATE_OK;
	if (Copy_U8Port<=DIO_U8_PORTD && Copy_U8Pin<=DIO_U8_PIN7)
	{
		switch(Copy_U8Port)
		{

		    case DIO_U8_PORTA :
		    {
		    	if(DIO_U8_HIGH == Copy_U8Value)
		    	{
		    		SET_BIT(PORTA_REG,Copy_U8Pin);
		    	}
		    	else if (DIO_U8_LOW == Copy_U8Value)
		    	{
		    		CLR_BIT(PORTA_REG,Copy_U8Pin);
		    	}
		    	else
				{
		    		/* Do Nothing */
				}	
		    	break;
		    }
            
		    case DIO_U8_PORTB :
			{
		    	if(DIO_U8_HIGH == Copy_U8Value)
		    	{
		    		SET_BIT(PORTB_REG,Copy_U8Pin);
		    	}
		    	else if (DIO_U8_LOW == Copy_U8Value)
		    	{
		    		CLR_BIT(PORTB_REG,Copy_U8Pin);
		    	}
		    	else
				{
		    		/* Do Nothing */
				}	
		    	break;
			}
            
		    case DIO_U8_PORTC :
			{
		    	if(DIO_U8_HIGH == Copy_U8Value)
		    	{
		    		SET_BIT(PORTC_REG,Copy_U8Pin);
		    	}
		    	else if (DIO_U8_LOW == Copy_U8Value)
		    	{
		    		CLR_BIT(PORTC_REG,Copy_U8Pin);
		    	}
		    	else
				{
		    		/* Do Nothing */
				}	
		    	break;
			}
		    case DIO_U8_PORTD :
			{
		    	if(DIO_U8_HIGH == Copy_U8Value)
		    	{
		    		SET_BIT(PORTD_REG,Copy_U8Pin);
		    	}
		    	else if (DIO_U8_LOW == Copy_U8Value)
		    	{
		    		CLR_BIT(PORTD_REG,Copy_U8Pin);
		    	}
		    	else
				{
		    		/* Do Nothing */
				}	
		    	break;
			}
		}

	}
	else
	{
		Local_U8ErrorState = STATE_NOK;
	}
	return(Local_U8ErrorState);
}
u8 DIO_U8SetPortValue(u8 Copy_U8Port ,u8 Copy_U8Value)
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_U8Port<=DIO_U8_PORTD )
	{
		switch(Copy_U8Port)
		{
		case DIO_U8_PORTA : PORTA_REG = Copy_U8Value;break;
		case DIO_U8_PORTB : PORTB_REG = Copy_U8Value;break;
		case DIO_U8_PORTC : PORTC_REG = Copy_U8Value;break;
		case DIO_U8_PORTD : PORTD_REG = Copy_U8Value;break;
		}
	}
	else 
		Local_U8ErrorState = STATE_NOK;
	return(Local_U8ErrorState);
}
u8 DIO_U8TogglePinValue(u8 Copy_U8Port ,u8 Copy_U8Pin)
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_U8Port<=DIO_U8_PORTD && Copy_U8Pin<=DIO_U8_PIN7)
	{
		switch(Copy_U8Port)
		{
		case DIO_U8_PORTA : TOG_BIT(PORTA_REG,Copy_U8Pin);break;
		case DIO_U8_PORTB : TOG_BIT(PORTB_REG,Copy_U8Pin);break;
		case DIO_U8_PORTC : TOG_BIT(PORTC_REG,Copy_U8Pin);break;
		case DIO_U8_PORTD : TOG_BIT(PORTD_REG,Copy_U8Pin);break;
		}

	}
	else 
		Local_U8ErrorState = STATE_NOK;
	return(Local_U8ErrorState);
}

u8 DIO_u8GetPinValue(u8 Copy_U8Port ,u8 Copy_U8Pin,u8 * Copy_pu8ReturnedPinValue)
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_U8Port<=DIO_U8_PORTD && Copy_U8Pin<=DIO_U8_PIN7)
	{
		switch(Copy_U8Port)
		{
		;
		case DIO_U8_PORTA : * Copy_pu8ReturnedPinValue = GET_BIT(PINA_REG,Copy_U8Pin);break;
		case DIO_U8_PORTB : * Copy_pu8ReturnedPinValue = GET_BIT(PINB_REG,Copy_U8Pin);break;
		case DIO_U8_PORTC : * Copy_pu8ReturnedPinValue = GET_BIT(PINC_REG,Copy_U8Pin);break;
		case DIO_U8_PORTD : * Copy_pu8ReturnedPinValue = GET_BIT(PIND_REG,Copy_U8Pin);break;

		}
	}
	else 
		Local_U8ErrorState = STATE_NOK;
	return(Local_U8ErrorState);
}
