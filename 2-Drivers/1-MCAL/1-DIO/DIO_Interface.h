/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 3/9/2022          *****************/
/**************** SWC     : DIO               *****************/
/**************** Version : 1.4               *****************/
/**************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Macros For PORTS */
#define  DIO_U8_PORTA             0
#define  DIO_U8_PORTB             1
#define  DIO_U8_PORTC             2
#define  DIO_U8_PORTD             3
                                 
/* Macros For PINS */            
#define  DIO_U8_PIN0              0
#define  DIO_U8_PIN1              1 
#define  DIO_U8_PIN2              2 
#define  DIO_U8_PIN3              3 
#define  DIO_U8_PIN4              4 
#define  DIO_U8_PIN5              5 
#define  DIO_U8_PIN6              6 
#define  DIO_U8_PIN7              7 

/* Macros For Direction */
#define  DIO_U8_INTIAL_INTPUT     0
#define  DIO_U8_INTIAL_OUTPUT     1

/* Macros For Value */
#define  DIO_U8_OUTPUT_HIGH       1
#define  DIO_U8_INTPUT_LOW        0
#define  DIO_U8_INPUT_FLOTING     0
#define  DIO_U8_INPUT_PULLUP      1

/* Functions Of Digital Output To Input */
void DIO_VoidInit         (void);

u8 DIO_U8SetPinDirection  (u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Direction);
       
u8 DIO_U8SetPortDirection (u8 Copy_U8Port ,u8 Copy_U8Direction);
       
u8 DIO_U8SetPinValue      (u8 Copy_U8Port ,u8 Copy_U8Pin ,u8 Copy_U8Value);
       
u8 DIO_U8SetPortValue     (u8 Copy_U8Port ,u8 Copy_U8Value);
       
u8 DIO_U8TogglePinValue   (u8 Copy_U8Port ,u8 Copy_U8Pin);

u8 DIO_u8GetPinValue      (u8 Copy_U8Port ,u8 Copy_U8Pin,u8 * Copy_pu8ReturnedPinValue);

#define DIO_U8_HIGH       1
#define DIO_U8_LOW        0

#endif
