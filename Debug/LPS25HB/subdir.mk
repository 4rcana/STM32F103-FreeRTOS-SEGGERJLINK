################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LPS25HB/LPS25HB.c 

OBJS += \
./LPS25HB/LPS25HB.o 

C_DEPS += \
./LPS25HB/LPS25HB.d 


# Each subdirectory must supply rules for building sources it contributes
LPS25HB/%.o LPS25HB/%.su LPS25HB/%.cyclo: ../LPS25HB/%.c LPS25HB/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/SystemView/Config -I../Middlewares/Third_Party/SystemView/FreeRTOSV11 -I../Middlewares/Third_Party/SystemView/SEGGER -I../LPS25HB -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-LPS25HB

clean-LPS25HB:
	-$(RM) ./LPS25HB/LPS25HB.cyclo ./LPS25HB/LPS25HB.d ./LPS25HB/LPS25HB.o ./LPS25HB/LPS25HB.su

.PHONY: clean-LPS25HB

