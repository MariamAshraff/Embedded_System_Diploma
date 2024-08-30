################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
L1U7.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
L1U7.list \

OBJCOPY_BIN += \
L1U7.bin \


# All Target
all: L1U7.elf secondary-outputs

# Tool invocations
L1U7.elf: $(OBJS) $(USER_OBJS) C:\Users\VTE\Desktop\embededd\ MZ\kerlous\GITHUB\Embedded_System_Diploma\Unit\ 7\Lesson\ 1\Lab1\Code\STM32F103C6TX_FLASH.ld
	arm-none-eabi-gcc -gdwarf-2 -o "L1U7.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\Users\VTE\Desktop\embededd MZ\kerlous\GITHUB\Embedded_System_Diploma\Unit 7\Lesson 1\Lab1\Code\STM32F103C6TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="L1U7.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

L1U7.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "L1U7.list"
	@echo 'Finished building: $@'
	@echo ' '

L1U7.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "L1U7.bin"
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
