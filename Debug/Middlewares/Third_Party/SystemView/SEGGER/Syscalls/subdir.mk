################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.c \
../Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.c \
../Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.c \
../Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.c 

OBJS += \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.o \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.o \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.o 

C_DEPS += \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.d \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.d \
./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/SystemView/SEGGER/Syscalls/%.o Middlewares/Third_Party/SystemView/SEGGER/Syscalls/%.su Middlewares/Third_Party/SystemView/SEGGER/Syscalls/%.cyclo: ../Middlewares/Third_Party/SystemView/SEGGER/Syscalls/%.c Middlewares/Third_Party/SystemView/SEGGER/Syscalls/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/SystemView/Config -I../Middlewares/Third_Party/SystemView/FreeRTOSV11 -I../Middlewares/Third_Party/SystemView/SEGGER -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-SystemView-2f-SEGGER-2f-Syscalls

clean-Middlewares-2f-Third_Party-2f-SystemView-2f-SEGGER-2f-Syscalls:
	-$(RM) ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.cyclo ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.d ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.o ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_GCC.su ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.cyclo ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.d ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.o ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_IAR.su ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.cyclo ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.d ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.o ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_KEIL.su ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.cyclo ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.d ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.o ./Middlewares/Third_Party/SystemView/SEGGER/Syscalls/SEGGER_RTT_Syscalls_SES.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-SystemView-2f-SEGGER-2f-Syscalls

