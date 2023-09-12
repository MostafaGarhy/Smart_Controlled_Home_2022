/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 28/9/2022         *****************/
/**************** SWC     : ADC               *****************/
/**************** Version : 1.0               *****************/
/**************************************************************/
#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_u8_Channel_0                 0
#define ADC_u8_Channel_1                 1
#define ADC_u8_Channel_2                 2
#define ADC_u8_Channel_3                 3
#define ADC_u8_Channel_4                 4
#define ADC_u8_Channel_5                 5
#define ADC_u8_Channel_6                 6
#define ADC_u8_Channel_7                 7



void ADC_VoidInit           (void);

u8 ADC_u8GetDigitalValue    (u8 Copy_ChannalNum,u16 *Copy_Pu16ReturnDigitalValue);

u8 ADC_u8GetDigitalValueINT (u8 Copy_ChannalNum,void(*Copy_Pf)(u16));

u8 ADC_u8GetRegValue        (u16 *Copy_u16RegValue);



#endif