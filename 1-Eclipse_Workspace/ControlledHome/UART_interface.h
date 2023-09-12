/**************************************************************/
/**************** Name    : MoaaZ Abd-elrhman *****************/ 
/**************** Date    : 21/10/2022        *****************/
/**************** SWC     : UART              *****************/
/**************** Version : 1.2               *****************/
/**************************************************************/
#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_VoidInit             (void);
                           
void VoidSendDataByte          (u8 Copy_u8SendData);
  
u8 UART_VoidRecieveDataByte    (u8 *Copy_u8RecieveData);  

#endif