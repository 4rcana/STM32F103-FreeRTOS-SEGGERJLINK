################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.c 

OBJS += \
./Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.o 

C_DEPS += \
./Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/%.o Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/%.su Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/%.cyclo: ../Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/%.c Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Middlewares/Third_Party/SystemView/Config -I../Middlewares/Third_Party/SystemView/Patch -I../Middlewares/Third_Party/SystemView/SEGGER -I../Middlewares/Third_Party/SystemView/FreeRTOSV10 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-SystemView-2f-FreeRTOSV10-2f-Config-2f-Cortex-2d-M

clean-Middlewares-2f-Third_Party-2f-SystemView-2f-FreeRTOSV10-2f-Config-2f-Cortex-2d-M:
	-$(RM) ./Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.cyclo ./Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.d ./Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.o ./Middlewares/Third_Party/SystemView/FreeRTOSV10/Config/Cortex-M/SEGGER_SYSVIEW_Config_FreeRTOS.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-SystemView-2f-FreeRTOSV10-2f-Config-2f-Cortex-2d-M

