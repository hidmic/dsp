################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP_Source/CommonTables/arm_common_tables.c 

OBJS += \
./DSP_Source/CommonTables/arm_common_tables.o 

C_DEPS += \
./DSP_Source/CommonTables/arm_common_tables.d 


# Each subdirectory must supply rules for building sources it contributes
DSP_Source/CommonTables/arm_common_tables.o: ../DSP_Source/CommonTables/arm_common_tables.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/CommonTables/arm_common_tables.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

