/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 11/9/2022         *****************/
/**************** SWC     : LCD               *****************/
/**************** Version : 1.4               *****************/
/**************************************************************/
#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* Select PORT : DIO_U8_PORTA
                 DIO_U8_PORTB
                 DIO_U8_PORTC
                 DIO_U8_PORTD */
				  
#define LCD_U8_RS_PIN           DIO_U8_PIN0
#define LCD_U8_RW_PIN           DIO_U8_PIN1
#define LCD_U8_E_PIN            DIO_U8_PIN2

#define LCD_U8_PORT_CONTROL     DIO_U8_PORTC
#define LCD_U8_PORT_DATA        DIO_U8_PORTA

#define LCD_SHIFT_LEFT    1						  
#define LCD_SHIFT_RIGHT   2	
				  
/* Set Mode Of LCD : 1-LCD_MODE_8_BIT
                     2-LCD_MODE_4_BIT */
			 
#define LCD_MODE	LCD_MODE_4_BIT
 
#endif
