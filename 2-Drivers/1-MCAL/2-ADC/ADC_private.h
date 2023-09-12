/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 28/9/2022         *****************/
/**************** SWC     : ADC               *****************/
/**************** Version : 1.0               *****************/
/**************************************************************/
#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/* Macros For ADC Registers */
#define ADC_u8_ADMUX_REG            *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG           *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG             *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG             *((volatile u8 *)0x24)

#define ADC_u16_REG                 *((volatile u16 *)0x24)

#endif