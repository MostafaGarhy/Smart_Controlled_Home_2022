/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 28/9/2022         *****************/
/**************** SWC     : TIMERS            *****************/
/**************** Version : 1.3               *****************/
/**************************************************************/
#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

/* Define Of Registers For Timer0 */
#define TIMERS_u8_TCCR0_REG           *((volatile u8  *)0x53)
#define TIMERS_u8_TCNT0_REG           *((volatile u8  *)0x52)
#define TIMERS_u8_OCR0_REG            *((volatile u8  *)0x5C)
#define TIMERS_u8_TIMSK_REG           *((volatile u8  *)0x59)
#define TIMERS_u8_TIFR_REG            *((volatile u8  *)0x58)

/* Define Of Registers For Timer1 */
#define TIMERS_u8_TCCR1A_REG          *((volatile u8  *)0x4F)
#define TIMERS_u8_TCCR1B_REG          *((volatile u8  *)0x4E)
                                      
#define TIMERS_u8_TCNT1H_REG          *((volatile u8  *)0x4D)
#define TIMERS_u8_TCNT1L_REG          *((volatile u8  *)0x4C)
#define TIMERS_u16_TCNT1_REG          *((volatile u16 *)0x4C)

#define TIMERS_u8_OCR1AH_REG          *((volatile u8  *)0x4B)
#define TIMERS_u8_OCR1AL_REG          *((volatile u8  *)0x4A)
#define TIMERS_u16_OCR1A_REG          *((volatile u16 *)0x4A)

#define TIMERS_u8_OCR1BH_REG          *((volatile u8  *)0x49)
#define TIMERS_u8_OCR1BL_REG          *((volatile u8  *)0x48)
#define TIMERS_u16_OCR1B_REG          *((volatile u16 *)0x48)

#define TIMERS_u8_ICR1H_REG           *((volatile u8  *)0x47)
#define TIMERS_u8_ICR1L_REG           *((volatile u8  *)0x46)
#define TIMERS_u16_ICR1_REG           *((volatile u16 *)0x46)

/* Macros For Timer0 Mode */
#define TIMER0_NORMAL_MODE                         0
#define TIMER0_CTC_MODE                            1
#define TIMER0_FAST_PWM_MODE                       2
#define TIMER0_PWM_PHASE_CORRECT_MODE              3

#endif