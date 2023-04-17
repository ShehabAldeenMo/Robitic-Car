################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP_DRIVER/MultipleTasksCar_Prg.c 

OBJS += \
./APP_DRIVER/MultipleTasksCar_Prg.o 

C_DEPS += \
./APP_DRIVER/MultipleTasksCar_Prg.d 


# Each subdirectory must supply rules for building sources it contributes
APP_DRIVER/%.o: ../APP_DRIVER/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


