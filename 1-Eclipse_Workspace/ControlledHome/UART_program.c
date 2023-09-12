/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 21/10/2022        *****************/
/**************** SWC     : UART              *****************/
/**************** Version : 1.4               *****************/
/**************************************************************/
/* Lib Layer */
#include "STD_TYPES.h"
#include "bit_math.h"

/* MCAL */
#include "UART_private.h"
#include "UART_interface.h"

void UART_VoidInit(void)
{
	u8 Local_u8UCSRC_Reg = 0b10000000;
	/* Select Normal Speed Transmission */
	CLR_BIT(UART_u8_UCSRA_REG,1);
	/* Disable Multi-processor Communication Mode */
	CLR_BIT(UART_u8_UCSRA_REG,0);
	/* Disable Asynchronous Operation */
	CLR_BIT(Local_u8UCSRC_Reg,6);
	/* Disable Parity Mode */
	CLR_BIT(Local_u8UCSRC_Reg,5);
	CLR_BIT(Local_u8UCSRC_Reg,4);
	/* Enable Tx , Rx */
	SET_BIT(UART_u8_UCSRB_REG,3);
	SET_BIT(UART_u8_UCSRB_REG,4);
	/* Enable 1 - Stop Bit */
	SET_BIT(Local_u8UCSRC_Reg,3);
	/* Set Character Size 8 - Bit */
	SET_BIT(Local_u8UCSRC_Reg,2);
	SET_BIT(Local_u8UCSRC_Reg,1);
	SET_BIT(UART_u8_UCSRB_REG,2);
	/* Update UCSRC Register */
	UART_u8_UCSRC_REG = Local_u8UCSRC_Reg;
	/* Baud Rate = 9600 */ 
	UART_u8_UBRRL_REG = 51;
	UART_u8_UBRRH_REG = 0x00;
}                    
void UART_VoidSendDataByte(u8 Copy_u8SendData)
{
	/* Wait For Transmit Buffer Set */
	while((GET_BIT(UART_u8_UCSRA_REG,5))==0);
	/* Send Data 8 - Bit */
	UART_u8_UDR_REG = Copy_u8SendData;
}
u8 UART_VoidRecieveDataByte(u8 *Copy_u8RecieveData)
{
	u8 Local_U8ErrorState = STATE_OK;
	if(Copy_u8RecieveData !=NULL)
	{
	    /* Wait For Receive Buffer Is Cleared */
	    while((GET_BIT(UART_u8_UCSRA_REG,7))==0);
	    /* Recieve Data */
	    *Copy_u8RecieveData = UART_u8_UDR_REG;
	}
	else
	{
		u8 Local_U8ErrorState = STATE_NOK;
	}
	return Local_U8ErrorState;
}