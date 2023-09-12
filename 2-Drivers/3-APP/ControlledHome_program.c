/*******************************************************************/
/**************** Name    : Moaaz ,Mostafa ,Bassem *****************/
/**************** Date    : 7/2/2023               *****************/
/**************** SWC     : Controlled Home        *****************/
/**************** Version : 3.0                    *****************/
/*******************************************************************/
 /* Lib Layer */
#include "STD_TYPES.h"
#include "bit_math.h"
#include "util/delay.h"
 /* MCAL Layer */
#include "DIO_Interface.h"
#include "UART_interface.h"
#include "TIMERS_interface.h"
#include "ADC_interface.h"
#include "ControlledHome_interface.h"
/* HAL Layer */
#include "LCD_interface.h"
#include "StepperMotor_interface.h"
#include "ServoMotor_interface.h"
/*                                      ROOM1                                                                 */
u8 Global_u8RecieveData;
void VoidControlledHomeRoom1(void)
{
	while(1)
	{
		/*                               Check For Receive ASCII Code From Bluetooth                                    */
		UART_VoidRecieveDataByte(&Global_u8RecieveData);
		/*                                  Check For User Turn On RED LED                                              */
		if( Global_u8RecieveData == 'a')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("Red Lamp Is On");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN0,DIO_U8_HIGH);
		}
		/*                                  Check For User Turn Off RED LED                                             */
		else if(Global_u8RecieveData == 'b')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("Red Lamp Is Off");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN0,DIO_U8_LOW);
		}
		/*                                  Check For User Turn On Yellow LED                                           */
		else if( Global_u8RecieveData == 'e')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("Yellow LED Is On");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN1,DIO_U8_HIGH);
		}
		/*                                  Check For User Turn Off Yellow LED                                          */
		else if(Global_u8RecieveData == 'f')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("Yellow LED Is OF");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN1,DIO_U8_LOW);
		}
		/*                                  Check For User Turn On Green LED                                            */
		else if( Global_u8RecieveData == 'c')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("Green LED Is On");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN2,DIO_U8_HIGH);
		}
		/*                                  Check For User Turn Off Green LED                                           */
		else if(Global_u8RecieveData == 'd')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("Green LED Is Off");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN2,DIO_U8_LOW);
		}
		/*                                  Check For User Turn On All LEDs                                             */
		if( Global_u8RecieveData == 'A')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("All LEDs Are On");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN2,DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN1,DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN0,DIO_U8_HIGH);
		}
		/*                                  Check For User Turn Off All LEDs                                            */
		else if(Global_u8RecieveData == 'B')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("All LEDs Are Off");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN2,DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN1,DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN0,DIO_U8_LOW);
		}
		/*                                  Check For User Press Button Of Return                                       */
		if(Global_u8RecieveData == '0')
		{
			LCD_VoidClear();
			break;
		}
	}
}
    /*                                         ROOM2                                                                      */
void VoidControlledHomeRoom2(void)
{
	while(1)
	{
		UART_VoidRecieveDataByte(&Global_u8RecieveData);
		if(Global_u8RecieveData == 'G')
		{
			       /* Clock Wise Motor */
			LCD_VoidClear(); LCD_VoidSentSringAndNum("Motor Is CW");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN4,DIO_U8_LOW);
		}
		else if(Global_u8RecieveData == 'H')
		{
			     /* Anti Clock Wise Motor */
			LCD_VoidClear(); LCD_VoidSentSringAndNum("Motor Is AntiCW");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN4,DIO_U8_HIGH);
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_LOW);
		}
		else if(Global_u8RecieveData == 'J')
		{
			     /* Stop Motor */
			LCD_VoidClear(); LCD_VoidSentSringAndNum("Motor Is Stop");
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN4,DIO_U8_LOW);
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_LOW);
		}
		if(Global_u8RecieveData == '0')
		{
			LCD_VoidClear();
			break;
		}
	}

}
     /*                                         ROOM3                                                                      */
void VoidControlledHomeRoom3(void)
{
	u16 Local_u16DigitalValue ,Local_u16AnalogValue ;
	u16 Local_u16TempValue;
	while(1)
	{
		/*                               Check For Receive ASCII Code From Bluetooth                                    */
		sensor:UART_VoidRecieveDataByte(&Global_u8RecieveData);
		/*                               Get Digital Value From Channel 0 ADC                                           */
		ADC_u8GetDigitalValue(ADC_u8_Channel_0,&Local_u16DigitalValue);
		/*                               Mathematical Operation For Calculate Analog Value                              */
		Local_u16AnalogValue = (u16)((Local_u16DigitalValue * 5000UL) / 1024);   /*  mV  */
		/*                                   Temperature In Voltage                                                     */
		Local_u16TempValue = Local_u16AnalogValue/10;
		/*                                  Check For User Turn On LM35 Sensor                                          */
		if(Global_u8RecieveData == 'T')
		{
			/*                 Turn on LM35 Sensor               */
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("LM35 Sensor On");
			_delay_ms(1300);
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("Temperature:  C");
			LCD_u8GoToLine(1,12);
			/* Print Temperature On LCD */
			LCD_voidSendNumber(Local_u16TempValue);
			goto sensor;
		}
		/*                                  Check For User Turn Off LM35 Sensor                                        */
		else if(Global_u8RecieveData == 'Y')
		{
			/*                 Turn Off LM35 Sensor               */
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("LM35 Sensor Off");
			goto sensor;
		}
		/*                                  Check For User Turn On LDR Sensor                                          */
		else if(Global_u8RecieveData == 'U')
		{
			/*                 Turn on LDR Sensor               */
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("LDR Sensor Is On");
			_delay_ms(1300);
			LCD_VoidClear();
			if(Local_u16AnalogValue <= 2500)
			{
				LCD_VoidSentSringAndNum("  It SunLight");
			}
			else if(Local_u16AnalogValue >= 3000)
			{
				LCD_VoidSentSringAndNum("   It DarkNess");
			}
		}
		/*                                  Check For User Turn Off LDR Sensor                                         */
		else if(Global_u8RecieveData == 'I')
		{
			/*                 Turn Off LDR Sensor               */
			LCD_VoidClear();
			LCD_VoidSentSringAndNum("LDR Sensor Off");
			goto sensor;
		}
		/*                                         Servo Motor Angles                                                  */

		/*                                  Check For User Press Button Of Angle 0 Degree                              */
		else if(Global_u8RecieveData == 'W')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 0 Deg");
			VoidServoSetAngle(0);
		}
		/*                                  Check For User Press Button Of Angle 20 Degree                             */
		else if(Global_u8RecieveData == 'w')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 20 Deg");
			VoidServoSetAngle(20);
		}
		/*                                  Check For User Press Button Of Angle 40 Degree                             */
		else if(Global_u8RecieveData == 'R')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 40 Deg");
			VoidServoSetAngle(40);
		}
		/*                                  Check For User Press Button Of Angle 60 Degree                             */
		else if(Global_u8RecieveData == 'r')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 60 Deg");
			VoidServoSetAngle(60);
		}
		/*                                  Check For User Press Button Of Angle 80 Degree                             */
		else if(Global_u8RecieveData == 'E')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 80 Deg");
			VoidServoSetAngle(80);
		}
		/*                                  Check For User Press Button Of Angle 90 Degree                             */
		else if(Global_u8RecieveData == 'e')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 90 Deg");
			VoidServoSetAngle(90);
		}
		/*                                  Check For User Press Button Of Angle 120 Degree                            */
		else if(Global_u8RecieveData == 'H')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 120 Deg");
			VoidServoSetAngle(120);
		}
		/*                                  Check For User Press Button Of Angle 150 Degree                            */
		else if(Global_u8RecieveData == 'Z')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 150 Deg");
			VoidServoSetAngle(150);
		}
		/*                                  Check For User Press Button Of Angle 180 Degree                            */
		else if(Global_u8RecieveData == 'z')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("  Servo 180 Deg");
			VoidServoSetAngle(180);
		}
		/*                                   Check For User Press Button Of Return                                     */
		if(Global_u8RecieveData == '0')
		{
			LCD_VoidClear();
			break;
		}
	}

}
      /*                                         ROOM4                                                                    */
void VoidControlledHomeRoom4(void)
{
	while(1)
	{
		/*                               Check For Receive ASCII Code From Bluetooth                                    */
		UART_VoidRecieveDataByte(&Global_u8RecieveData);
		/*                               Check For User Press Button Of StepperMotor ClockWise 45 Degree                */
		if(Global_u8RecieveData == 'v')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 45 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,45);
		}
		/*                               Check For User Press Button Of StepperMotor ClockWise 90 Degree                */
		else if(Global_u8RecieveData == 'V')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 90 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,90);
		}
		/*                               Check For User Press Button Of StepperMotor ClockWise 135 Degree               */
		else if(Global_u8RecieveData == 'b')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 135 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,135);
		}
		/*                               Check For User Press Button Of StepperMotor ClockWise 180 Degree               */
		else if(Global_u8RecieveData == 'B')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 180 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,180);
		}
		/*                               Check For User Press Button Of StepperMotor ClockWise 225 Degree               */
		else if(Global_u8RecieveData == 'n')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 225 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,225);
		}
		/*                               Check For User Press Button Of StepperMotor ClockWise 270 Degree               */
		else if(Global_u8RecieveData == 'N')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 270 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,270);
		}
		/*                               Check For User Press Button Of StepperMotor ClockWise 315 Degree               */
		else if(Global_u8RecieveData == 'k')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 315 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,315);
		}
		/*                               Check For User Press Button Of StepperMotor ClockWise 360 Degree               */
		else if(Global_u8RecieveData == 'K')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor CW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 360 Deg");
			Step_VoidSetAngle(StepperMotor_u8_ClockWise,360);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 45 Degree         */
		else if(Global_u8RecieveData == 'o')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 45 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,45);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 90 Degree         */
		else if(Global_u8RecieveData == 'O')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 90 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,90);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 135 Degree        */
		else if(Global_u8RecieveData == 'p')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 135 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,135);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 180 Degree        */
		else if(Global_u8RecieveData == 'P')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 180 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,180);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 225 Degree        */
		else if(Global_u8RecieveData == 'f')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 225 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,225);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 270 Degree        */
		else if(Global_u8RecieveData == 'F')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 270 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,270);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 315 Degree        */
		else if(Global_u8RecieveData == 'w')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 315 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,315);
		}
		/*                               Check For User Press Button Of StepperMotor Anti - ClockWise 360 Degree        */
		else if(Global_u8RecieveData == 'W')
		{
			LCD_VoidClear();LCD_VoidSentSringAndNum("StepperMotor ACW");
			LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("Rolling: 360 Deg");
			Step_VoidSetAngle(StepperMotor_u8_AntiClockWise,360);
		}
		/*                               Check For User Press Button Of Return                                          */
		if(Global_u8RecieveData == '0')
		{
			LCD_VoidClear();
			break;
		}
	}
}
   /*                                                  Login System                                                     */
void VoidControlledHomeLoginSystem(void)
{
	u8 Local_u8Iteration = 1 ;
	u8 Local_u8Counter;
	while(1)
	{
		/*                               Check For Receive ASCII Code From Bluetooth                                    */
		LOOP: UART_VoidRecieveDataByte(&Global_u8RecieveData);
		/*                               Check For User Is Enter Correct Username And Correct Password                  */
		if(Global_u8RecieveData == 'C')
		{
			/* Turn Of Red Led */
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_LOW);
			/* Turn On Green Led */
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN7,DIO_U8_HIGH);
			LCD_VoidClear();LCD_VoidSentSringAndNum("Correct Password");
			_delay_ms(1500);LCD_VoidClear();
			LCD_VoidSentSringAndNum("    Welcome ");LCD_u8GoToLine(2,0);LCD_VoidSentSringAndNum("   Smart Home");
			/* Turn Off Green Led */
			DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN7,DIO_U8_LOW);
			break;
		}
		/*                               Check For User Is Enter Wrong Username Or Wrong Password                      */
		else if(Global_u8RecieveData == 'R')
		{
			switch(Local_u8Iteration)
			{
			/*                               User Enter Wrong Username Or Password For First Enter                     */
				case 1 :LCD_VoidSentSringAndNum("Wrong  PassWord");
						LCD_u8GoToLine(2,0);
						LCD_VoidSentSringAndNum("Or     User");
						_delay_ms(1500);
						LCD_VoidClear();
						LCD_VoidSentSringAndNum("Pls Login Again");
						DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_HIGH);
						Local_u8Iteration++;
						goto LOOP;
			/*                               User Enter Wrong Username Or Password For Second Enter                    */
				case 2 :LCD_VoidClear();LCD_VoidSentSringAndNum("Wrong  PassWord");
						LCD_u8GoToLine(2,0);
						LCD_VoidSentSringAndNum("Or     User");
						_delay_ms(1500);
						LCD_VoidClear();
						LCD_VoidSentSringAndNum("Pls Login Again");
						Local_u8Iteration++;
						goto LOOP;
			/*                               User Enter Wrong Username Or Password For Third Enter                    */
				case 3 :LCD_VoidClear();LCD_VoidSentSringAndNum("Wrong  PassWord");
						LCD_u8GoToLine(2,0);
						LCD_VoidSentSringAndNum("Or     User");
						_delay_ms(1500);
						LCD_VoidClear();
						Local_u8Iteration++;
						LCD_VoidSentSringAndNum("Pls Login Again");
						goto LOOP;
			/*                               User Enter Wrong Username Or Password For Fourth Enter                   */

			/*                                                  Enter Block Mode                                      */
				case 4 :LCD_VoidClear();LCD_VoidSentSringAndNum("Block Mode");
						_delay_ms(1500);
						LCD_VoidClear();
						Local_u8Iteration++;
						LCD_VoidSentSringAndNum("Pls Wait For 10 Sec");
						_delay_ms(1000);
						LCD_VoidClear();
						/* Turn On Red Led */
						DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_HIGH);
						for(Local_u8Counter = 1;Local_u8Counter <= 10; Local_u8Counter++)
						{
							/* Print Counter On LCD */
							LCD_voidSendNumber(Local_u8Counter);
							/* Turn On Buzzer */
							DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN5,DIO_U8_HIGH);
							_delay_ms(1000);
							/* Turn Off Buzzer */
							DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN5,DIO_U8_LOW);
							LCD_VoidClear();
						}
						/* Turn Off Red Led */
						DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_LOW);
						LCD_VoidSentSringAndNum("Pls Login Again");
						goto LOOP;
						break;
			/*                               User Enter Wrong Username Or Password For Fifth Enter                   */
				case 5 : LCD_VoidClear();LCD_VoidSentSringAndNum("Block Mode");
						_delay_ms(1500);
						LCD_VoidClear();
						Local_u8Iteration++;
						LCD_VoidSentSringAndNum("Pls Wait For 30 Sec");
						_delay_ms(1000);
						LCD_VoidClear();
						/* Turn On Red Led */
						DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_HIGH);
						for(Local_u8Counter = 1;Local_u8Counter <= 30; Local_u8Counter++)
						{
							/* Turn On Buzzer */
							DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN5,DIO_U8_HIGH);
							/* Print Counter On LCD */
							LCD_voidSendNumber(Local_u8Counter);
							_delay_ms(1000);
							/* Turn Off Buzzer */
							DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN5,DIO_U8_LOW);
							LCD_VoidClear();
						}
						/* Turn Of Red Led */
						DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_LOW);
						LCD_VoidSentSringAndNum("Pls Login Again");
						goto LOOP;
						break;
			/*                               User Enter Wrong Username Or Password For Sixth Enter                    */
				case 6 :LCD_VoidClear();LCD_VoidSentSringAndNum("Ps Wait For Hour");_delay_ms(2000);LCD_VoidClear();
						DIO_U8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN6,DIO_U8_HIGH);
						break;
		}
			break;
		}
	}
}
