################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSP_Source/FastMathFunctions/arm_cos_f32.c \
../DSP_Source/FastMathFunctions/arm_cos_q15.c \
../DSP_Source/FastMathFunctions/arm_cos_q31.c \
../DSP_Source/FastMathFunctions/arm_sin_f32.c \
../DSP_Source/FastMathFunctions/arm_sin_q15.c \
../DSP_Source/FastMathFunctions/arm_sin_q31.c \
../DSP_Source/FastMathFunctions/arm_sqrt_q15.c \
../DSP_Source/FastMathFunctions/arm_sqrt_q31.c 

OBJS += \
./DSP_Source/FastMathFunctions/arm_cos_f32.o \
./DSP_Source/FastMathFunctions/arm_cos_q15.o \
./DSP_Source/FastMathFunctions/arm_cos_q31.o \
./DSP_Source/FastMathFunctions/arm_sin_f32.o \
./DSP_Source/FastMathFunctions/arm_sin_q15.o \
./DSP_Source/FastMathFunctions/arm_sin_q31.o \
./DSP_Source/FastMathFunctions/arm_sqrt_q15.o \
./DSP_Source/FastMathFunctions/arm_sqrt_q31.o 

C_DEPS += \
./DSP_Source/FastMathFunctions/arm_cos_f32.d \
./DSP_Source/FastMathFunctions/arm_cos_q15.d \
./DSP_Source/FastMathFunctions/arm_cos_q31.d \
./DSP_Source/FastMathFunctions/arm_sin_f32.d \
./DSP_Source/FastMathFunctions/arm_sin_q15.d \
./DSP_Source/FastMathFunctions/arm_sin_q31.d \
./DSP_Source/FastMathFunctions/arm_sqrt_q15.d \
./DSP_Source/FastMathFunctions/arm_sqrt_q31.d 


# Each subdirectory must supply rules for building sources it contributes
DSP_Source/FastMathFunctions/arm_cos_f32.o: ../DSP_Source/FastMathFunctions/arm_cos_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_cos_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP_Source/FastMathFunctions/arm_cos_q15.o: ../DSP_Source/FastMathFunctions/arm_cos_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_cos_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP_Source/FastMathFunctions/arm_cos_q31.o: ../DSP_Source/FastMathFunctions/arm_cos_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_cos_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP_Source/FastMathFunctions/arm_sin_f32.o: ../DSP_Source/FastMathFunctions/arm_sin_f32.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_sin_f32.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP_Source/FastMathFunctions/arm_sin_q15.o: ../DSP_Source/FastMathFunctions/arm_sin_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_sin_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP_Source/FastMathFunctions/arm_sin_q31.o: ../DSP_Source/FastMathFunctions/arm_sin_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_sin_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP_Source/FastMathFunctions/arm_sqrt_q15.o: ../DSP_Source/FastMathFunctions/arm_sqrt_q15.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_sqrt_q15.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
DSP_Source/FastMathFunctions/arm_sqrt_q31.o: ../DSP_Source/FastMathFunctions/arm_sqrt_q31.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F401xE -DDEBUG -DARM_MATH_CM4 '-D__FPU_PRESENT=1U' -c -I../Inc -I../Drivers/CMSIS/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I"/Users/juanmanuelgeria/Documents/Facultad/2019/DSP en tiempo real/workspace/SerialFilter_test/Binding" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSP_Source/FastMathFunctions/arm_sqrt_q31.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

