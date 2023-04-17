################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL_DRIVERS/DIO_prg.c \
../MCAL_DRIVERS/EX_INT_prg.c \
../MCAL_DRIVERS/INTERRUPT_prg.c \
../MCAL_DRIVERS/TIMER_PRG.c \
../MCAL_DRIVERS/UART_Prg.c 

OBJS += \
./MCAL_DRIVERS/DIO_prg.o \
./MCAL_DRIVERS/EX_INT_prg.o \
./MCAL_DRIVERS/INTERRUPT_prg.o \
./MCAL_DRIVERS/TIMER_PRG.o \
./MCAL_DRIVERS/UART_Prg.o 

C_DEPS += \
./MCAL_DRIVERS/DIO_prg.d \
./MCAL_DRIVERS/EX_INT_prg.d \
./MCAL_DRIVERS/INTERRUPT_prg.d \
./MCAL_DRIVERS/TIMER_PRG.d \
./MCAL_DRIVERS/UART_Prg.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL_DRIVERS/%.o: ../MCAL_DRIVERS/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


