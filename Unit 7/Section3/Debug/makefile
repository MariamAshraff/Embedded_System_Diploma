################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Stm32f103c6_drivers/MCAL/subdir.mk
-include Stm32f103c6_drivers/HAL/subdir.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
Driverrrrrrrrrrrrrrrrrr.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
Driverrrrrrrrrrrrrrrrrr.list \

OBJCOPY_BIN += \
Driverrrrrrrrrrrrrrrrrr.bin \


# All Target
all: Driverrrrrrrrrrrrrrrrrr.elf secondary-outputs

# Tool invocations
Driverrrrrrrrrrrrrrrrrr.elf: $(OBJS) $(USER_OBJS) C:\Users\VTE\Desktop\embededd\ MZ\kerlous\GITHUB\Embedded_System_Diploma\Unit\ 7\Sectionnnnnnnnn3\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "Driverrrrrrrrrrrrrrrrrr.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\VTE\Desktop\embededd MZ\kerlous\GITHUB\Embedded_System_Diploma\Unit 7\Sectionnnnnnnnn3\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="Driverrrrrrrrrrrrrrrrrr.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

Driverrrrrrrrrrrrrrrrrr.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "Driverrrrrrrrrrrrrrrrrr.list"
	@echo 'Finished building: $@'
	@echo ' '

Driverrrrrrrrrrrrrrrrrr.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "Driverrrrrrrrrrrrrrrrrr.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
