/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 28/9/2022         *****************/
/**************** SWC     : TIMERS            *****************/
/**************** Version : 1.0               *****************/
/**************************************************************/
#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

void TIMERS_VoidInit                        (void);
                                            
void TIMERS_VoidTimer1Init                  (void);
                                            
u8 TIMERS_u8TIMER0OVFSetCallBack            (void(*Copy_Pf)(void));
                                            
u8 TIMERS_u8TIMER0CTCSetCallBack            (void(*Copy_Pf)(void));

void TIMERS_VoidTimer1SetCompareMatchValueA (u16 Copy_u16OCRValue);

void TIMERS_VoidTIMER0WriteCompareMatchValue(u8 Copy_u8OCRValue);

#endif
