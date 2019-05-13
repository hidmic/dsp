################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include DSP_Source/TransformFunctions/subdir.mk
-include DSP_Source/SupportFunctions/subdir.mk
-include DSP_Source/StatisticsFunctions/subdir.mk
-include DSP_Source/MatrixFunctions/subdir.mk
-include DSP_Source/FilteringFunctions/subdir.mk
-include DSP_Source/FastMathFunctions/subdir.mk
-include DSP_Source/ControllerFunctions/subdir.mk
-include DSP_Source/ComplexMathFunctions/subdir.mk
-include DSP_Source/CommonTables/subdir.mk
-include DSP_Source/BasicMathFunctions/subdir.mk
-include Binding/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
SerialFilter_test.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
SerialFilter_test.list \


# All Target
all: SerialFilter_test.elf secondary-outputs

# Tool invocations
SerialFilter_test.elf: $(OBJS) $(USER_OBJS) /Users/juanmanuelgeria/Documents/Facultad/2019/DSP\ en\ tiempo\ real/workspace/SerialFilter_test/STM32F401RETX_FLASH.ld
	arm-none-eabi-gcc -o "SerialFilter_test.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/STM32F401RETX_FLASH.ld" --specs=nosys.specs -Wl,-Map="SerialFilter_test.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

SerialFilter_test.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "SerialFilter_test.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
