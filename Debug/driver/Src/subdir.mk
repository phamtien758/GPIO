################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../driver/Src/gpio.c 

OBJS += \
./driver/Src/gpio.o 

C_DEPS += \
./driver/Src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
driver/Src/%.o driver/Src/%.su driver/Src/%.cyclo: ../driver/Src/%.c driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DNUCLEO_F401RE -DSTM32 -DSTM32F401RETx -DSTM32F4 -c -I../Inc -I../driver/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-driver-2f-Src

clean-driver-2f-Src:
	-$(RM) ./driver/Src/gpio.cyclo ./driver/Src/gpio.d ./driver/Src/gpio.o ./driver/Src/gpio.su

.PHONY: clean-driver-2f-Src

