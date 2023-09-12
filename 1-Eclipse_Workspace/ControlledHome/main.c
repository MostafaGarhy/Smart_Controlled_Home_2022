#include "STD_TYPES.h"
#include "bit_math.h"
#include "util/delay.h"

#include "DIO_Interface.h"
#include "LCD_interface.h"
#include "UART_interface.h"
#include "TIMERS_interface.h"
#include "ADC_interface.h"
#include "ControlledHome_interface.h"
#include "StepperMotor_interface.h"
#include "ServoMotor_interface.h"

   /*          Global Variable For Receive Data Using UART            */
u8 Global_u8RecieveData;

int main()
{
	/* Set Pins Config */
	DIO_VoidInit();
	LCD_VoidInit();
	UART_VoidInit();
	ADC_VoidInit();
	VoidServoInit();
	VoidControlledHomeLoginSystem();

	while(1)
	{
		/*                               Check For Receive ASCII Code From Bluetooth                                    */
		UART_VoidRecieveDataByte(&Global_u8RecieveData);
		/*                                   Check For User Press Button Of Login                                       */
		if(Global_u8RecieveData == 'Q')
		{
			LCD_VoidClear();
			VoidControlledHomeLoginSystem();
		}
		/*                                  Check For User Press Button Of ROOM 1                                       */
		else if(Global_u8RecieveData == '1')
		{
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("You In Room 1");
			VoidControlledHomeRoom1();
		}
		/*                                  Check For User Press Button Of ROOM 2                                       */
		else if(Global_u8RecieveData == '2')
		{
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("You In Room 2");
			VoidControlledHomeRoom2();
		}
		/*                                  Check For User Press Button Of ROOM 3                                       */
		else if(Global_u8RecieveData == '3')
		{
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("You In Room 3");
			VoidControlledHomeRoom3();
		}
		/*                                  Check For User Press Button Of ROOM 4                                       */
		else if(Global_u8RecieveData == '4')
		{
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("You In Room 4");
			VoidControlledHomeRoom4();
		}
		/*                                  Check For User Is Connected To Bluetooth                                    */
		if(Global_u8RecieveData == 'H')
		{
			LCD_VoidClear();
			VoidControlledHomeLoginSystem();
		}

	}

}
