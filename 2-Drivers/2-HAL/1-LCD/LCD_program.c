/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 13/9/2022         *****************/
/**************** SWC     : LCD               *****************/
/**************** Version : 4.4               *****************/
/**************************************************************/
/* Lib Layer */
#include "STD_TYPES.h"
#include "bit_math.h"
#include "util/delay.h"
/* MCAL */
#include "DIO_Interface.h"
/* Hal */
#include "LCD_private.h"
#include "LCD_interface.h"
#include "LCD_config.h"

void LCD_VoidInit(void)
{
#if LCD_MODE == LCD_MODE_8_BIT

	/* 8 Bit Init */
	_delay_ms(35);
	/* Function Set */
	LCD_VoidSendCommand(0b00111000);
	_delay_us(40);
	/* Display On/Off */
	LCD_VoidSendCommand(0b00001111);
	_delay_us(40);
	/* Display Clear */
	LCD_VoidSendCommand(0b00000001);
	_delay_ms(2);
	/* Entry Mode Set */
	LCD_VoidSendCommand(0b00000110);
	/* End Of Init */
	
#elif LCD_MODE == LCD_MODE_4_BIT

	/* LCD Power ON delay always >15ms */
	_delay_ms(35);
	LCD_VoidSendCommand(0x33);
	/* send for 4 bit initialization of LCD  */
	LCD_VoidSendCommand(0x32);
	/* Use 2 line and initialize 5*7 matrix in (4-bit mode)*/
	LCD_VoidSendCommand(0x28);
	/* Display on cursor off */
	LCD_VoidSendCommand(0x0c);
	/* Increment cursor (shift cursor to right) */
	LCD_VoidSendCommand(0x06);
	/* Clear display screen*/
	LCD_VoidSendCommand(0x01);
	_delay_ms(2);
	LCD_VoidSendCommand (0x80);
	/* End Of Init */
#endif	
}
void LCD_VoidSendChar (u8 Copy_U8Char)
{
#if LCD_MODE == LCD_MODE_8_BIT
	/* Rs = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RS_PIN,DIO_U8_HIGH);
	/* Rw = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RW_PIN,DIO_U8_LOW);
	/* Write On Command */
	DIO_U8SetPortValue(LCD_U8_PORT_DATA,Copy_U8Char);
	/* Enable = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_HIGH);
	_delay_us(1);
	/* Enable = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_LOW);
	
#elif LCD_MODE == LCD_MODE_4_BIT
	/* Rs = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RS_PIN,DIO_U8_HIGH);
	/* Rw = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RW_PIN,DIO_U8_LOW);
	/* Write On Char */
	DIO_U8SetPortValue(LCD_U8_PORT_DATA,Copy_U8Char);
	/* Enable = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_HIGH);
	_delay_us(1);
	/* Enable = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_LOW);
	_delay_us(200);
	/* Write On Char Least Signifit */
	DIO_U8SetPortValue(LCD_U8_PORT_DATA,(Copy_U8Char << 4));
	/* Enable = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_HIGH);
	_delay_us(1);
	/* Enable = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_LOW);
	_delay_ms(2);
#endif
}
void LCD_VoidSendCommand(u8 Copy_U8Command)
{
#if LCD_MODE == LCD_MODE_8_BIT
	/* Rs = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RS_PIN,DIO_U8_LOW);
	/* Rw = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RW_PIN,DIO_U8_LOW);
	/* Write On Command */
	DIO_U8SetPortValue(LCD_U8_PORT_DATA,Copy_U8Command);
	/* Enable = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_HIGH);
	_delay_us(1);
	/* Enable = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_LOW);
	
#elif LCD_MODE == LCD_MODE_4_BIT
	/* Rs = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RS_PIN,DIO_U8_LOW);
	/* Rw = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_RW_PIN,DIO_U8_LOW);
	/* Sending Upper Nibble On Command */
	DIO_U8SetPortValue(LCD_U8_PORT_DATA,Copy_U8Command);
	/* Enable = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_HIGH);
	_delay_us(1);
	/* Enable = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_LOW);
	_delay_us(200);
	/* Write On Command Least Lower Nibble */
	DIO_U8SetPortValue(LCD_U8_PORT_DATA,(Copy_U8Command << 4));
	/* Enable = 1 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_HIGH);
	_delay_us(1);
	/* Enable = 0 */
	DIO_U8SetPinValue(LCD_U8_PORT_CONTROL,LCD_U8_E_PIN,DIO_U8_LOW);
	_delay_ms(2);
#endif
}
u8 LCD_u8GoToLine(u8 Copy_LineNum,u8 Copy_Loction)
{
	/* Set DDRAM Address In Address Counter */
	u8 Local_U8ErrorState = STATE_OK;
	if (Copy_Loction <= 39)
	{
		switch(Copy_LineNum)
		{
			/* First Char In LCD */
			case LCD_u8_LINE1 : LCD_VoidSendCommand(0x80+Copy_Loction);break; /* 0b1000000 */
			/* Second Char In LCD */
			case LCD_u8_LINE2 : LCD_VoidSendCommand(0xc0+Copy_Loction);break; /* 0b1000000 */
			default : Local_U8ErrorState = STATE_NOK;
		}
	}
	else
	{
		Local_U8ErrorState = STATE_NOK;
	}
	return(Local_U8ErrorState);
}
void LCD_VoidClear(void)
{
	  /* Display Clear */
	LCD_VoidSendCommand(0x01);
	_delay_ms(2);
}
void LCD_VoidShiftPatterns(u8 Copy_TypeShift,u8 Copy_NumShift)
{
	if (Copy_NumShift == 1)
	{
	   switch(Copy_TypeShift)
	   {
	   	case LCD_SHIFT_LEFT  : LCD_VoidSendCommand(0b00011000);break;
	  	case LCD_SHIFT_RIGHT : LCD_VoidSendCommand(0b00011100);break;
	   } 
	}
	else
	{
		switch(Copy_TypeShift)
	   {
		    /* Shift Left */
	   	    case LCD_SHIFT_LEFT :
		    {
		    	for (u8 i=0; i<Copy_NumShift; i++)
		    	{
		    		LCD_VoidSendCommand(0b00011000);
		    	}
		    break;
		    }	
			/* Shift Right */	
	  	    case LCD_SHIFT_RIGHT :
		    {
		    	for (u8 i=0; i<Copy_NumShift; i++)
		    	{
		    		LCD_VoidSendCommand(0b00011100);
		    	}
		    break;
		    }
	   }
	}   
}
void LCD_VoidSentSringAndNum  (u8 *Copy_Pu8StringAndNum)
{
	while(*Copy_Pu8StringAndNum > 0)
	{
		LCD_VoidSendChar(*Copy_Pu8StringAndNum++);
	}
}  
void LCD_VoidSinsoul(u8 *Copy_Pu8StringAndNum)
{
	LCD_VoidSentSringAndNum(Copy_Pu8StringAndNum);
	_delay_ms(1000);
	LCD_VoidClear();
	LCD_u8GoToLine(2,4);
	LCD_VoidSentSringAndNum(Copy_Pu8StringAndNum);
	_delay_ms(1000);
	LCD_VoidClear();
	LCD_u8GoToLine(1,8);
	LCD_VoidSentSringAndNum(Copy_Pu8StringAndNum);
	_delay_ms(1000);
	LCD_VoidClear();
	LCD_u8GoToLine(2,12);
	LCD_VoidSentSringAndNum(Copy_Pu8StringAndNum);
	_delay_ms(1000);
	LCD_VoidClear();
	LCD_u8GoToLine(1,14);
	LCD_VoidSentSringAndNum(Copy_Pu8StringAndNum);
	_delay_ms(1000);
	LCD_VoidClear();
	LCD_u8GoToLine(2,16);
	LCD_VoidSentSringAndNum(Copy_Pu8StringAndNum);
	_delay_ms(1000);
	LCD_VoidClear();
	LCD_u8GoToLine(1,0);
}  
void LCD_voidSendNumber(u32 Copy_u8Number)
{
  u32 Local_remainder=0,Local_reverse=0,Local_TMP=0,Local_Counter,Local_TMPNum=Copy_u8Number;
  if (Copy_u8Number==0)
  {

    LCD_VoidSendChar('0');
  }
  else{
  for(Local_Counter=-1;0==Local_TMP;Local_Counter++)
  {
       Local_TMP=Local_TMPNum %10;
       Local_TMPNum=Local_TMPNum / 10;
  }
  while(Copy_u8Number!=0)
  {
    Local_remainder=Copy_u8Number %10;
    Local_reverse=Local_reverse*10+Local_remainder;
    Copy_u8Number=Copy_u8Number / 10;
  }
  Local_TMP=0;
  while (Local_reverse!=0)
  {
    Local_TMP=Local_reverse%10;
    LCD_VoidSendChar(Local_TMP+'0');
    Local_reverse=Local_reverse / 10;
  }
  while(0 != Local_Counter)
  {
    LCD_VoidSendChar('0');

    Local_Counter--;
  }
  }

}
