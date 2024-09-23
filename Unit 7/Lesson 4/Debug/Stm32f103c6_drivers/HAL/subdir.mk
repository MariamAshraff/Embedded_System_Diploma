################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Stm32f103c6_drivers/HAL/KPD.c \
../Stm32f103c6_drivers/HAL/LCD.c \
../Stm32f103c6_drivers/HAL/SevenSeg.c 

OBJS += \
./Stm32f103c6_drivers/HAL/KPD.o \
./Stm32f103c6_drivers/HAL/LCD.o \
./Stm32f103c6_drivers/HAL/SevenSeg.o 

C_DEPS += \
./Stm32f103c6_drivers/HAL/KPD.d \
./Stm32f103c6_drivers/HAL/LCD.d \
./Stm32f103c6_drivers/HAL/SevenSeg.d 


# Each subdirectory must supply rules for building sources it contributes
Stm32f103c6_drivers/HAL/KPD.o: ../Stm32f103c6_drivers/HAL/KPD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_drivers/HAL/KPD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_drivers/HAL/LCD.o: ../Stm32f103c6_drivers/HAL/LCD.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_drivers/HAL/LCD.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
Stm32f103c6_drivers/HAL/SevenSeg.o: ../Stm32f103c6_drivers/HAL/SevenSeg.c
	arm-none-eabi-gcc -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -I"C:/Users/VTE/Desktop/embededd MZ/kerlous/Sectionnnnnnnnn3/Stm32f103c6_drivers/Include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Stm32f103c6_drivers/HAL/SevenSeg.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

