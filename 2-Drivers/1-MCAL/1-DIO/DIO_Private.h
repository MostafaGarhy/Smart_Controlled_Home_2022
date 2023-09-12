/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 3/9/2022          *****************/
/**************** SWC     : DIO               *****************/
/**************** Version : 1.3               *****************/
/**************************************************************/

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

#define DDRA_REG  *((u8*)0x3A)
#define DDRB_REG  *((u8*)0x37)
#define DDRC_REG  *((u8*)0x34)
#define DDRD_REG  *((u8*)0x31)

#define PORTA_REG *((u8*)0x3B)
#define PORTB_REG *((u8*)0x38)
#define PORTC_REG *((u8*)0x35)
#define PORTD_REG *((u8*)0x32)

#define PINA_REG  *((volatile u8*)0x39)
#define PINB_REG  *((volatile u8*)0x36)
#define PINC_REG  *((volatile u8*)0x33)
#define PIND_REG  *((volatile u8*)0x30)


/* Function Of Intial Pins */
#define Init_Problem(a7,a6,a5,a4,a3,a2,a1,a0)             SolInit_Problem(a7,a6,a5,a4,a3,a2,a1,a0)
#define SolInit_Problem(a7,a6,a5,a4,a3,a2,a1,a0)          0b##a7##a6##a5##a4##a3##a2##a1##a0

/* Condition Of Statement */
#define  STATE_OK                 1
#define  STATE_NOK                0

#endif