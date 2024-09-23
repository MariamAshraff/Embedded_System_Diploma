################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32f103c6_drivers/MCAL/EXTI.c \
../Stm32f103c6_drivers/MCAL/GPIO.c 

OBJS += \
./Stm32f103c6_drivers/MCAL/EXTI.o \
./Stm32f103c6_drivers/MCAL/GPIO.o 

C_DEPS += \
./Stm32f103c6_drivers/MCAL/EXTI.d \
./Stm32f103c6_drivers/MCAL/GPIO.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32f103c6_drivers/MCAL/EXTI.o: ../Stm32f103c6_drivers/MCAL/EXTI.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_drivers/MCAL/EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_drivers/MCAL/GPIO.o: ../Stm32f103c6_drivers/MCAL/GPIO.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_drivers/MCAL/GPIO.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

