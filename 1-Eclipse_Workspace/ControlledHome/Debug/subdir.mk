################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_program.c \
../ControlledHome_program.c \
../DIO_Prg.c \
../LCD_program.c \
../ServoMotor_program.c \
../StepperMotor_program.c \
../TIMERS_program.c \
../UART_program.c \
../main.c 

OBJS += \
./ADC_program.o \
./ControlledHome_program.o \
./DIO_Prg.o \
./LCD_program.o \
./ServoMotor_program.o \
./StepperMotor_program.o \
./TIMERS_program.o \
./UART_program.o \
./main.o 

C_DEPS += \
./ADC_program.d \
./ControlledHome_program.d \
./DIO_Prg.d \
./LCD_program.d \
./ServoMotor_program.d \
./StepperMotor_program.d \
./TIMERS_program.d \
./UART_program.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


