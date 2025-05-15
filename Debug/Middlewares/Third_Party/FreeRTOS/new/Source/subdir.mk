################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/new/Source/croutine.c \
../Middlewares/Third_Party/FreeRTOS/new/Source/event_groups.c \
../Middlewares/Third_Party/FreeRTOS/new/Source/list.c \
../Middlewares/Third_Party/FreeRTOS/new/Source/queue.c \
../Middlewares/Third_Party/FreeRTOS/new/Source/stream_buffer.c \
../Middlewares/Third_Party/FreeRTOS/new/Source/tasks.c \
../Middlewares/Third_Party/FreeRTOS/new/Source/timers.c 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/new/Source/croutine.o \
./Middlewares/Third_Party/FreeRTOS/new/Source/event_groups.o \
./Middlewares/Third_Party/FreeRTOS/new/Source/list.o \
./Middlewares/Third_Party/FreeRTOS/new/Source/queue.o \
./Middlewares/Third_Party/FreeRTOS/new/Source/stream_buffer.o \
./Middlewares/Third_Party/FreeRTOS/new/Source/tasks.o \
./Middlewares/Third_Party/FreeRTOS/new/Source/timers.o 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/new/Source/croutine.d \
./Middlewares/Third_Party/FreeRTOS/new/Source/event_groups.d \
./Middlewares/Third_Party/FreeRTOS/new/Source/list.d \
./Middlewares/Third_Party/FreeRTOS/new/Source/queue.d \
./Middlewares/Third_Party/FreeRTOS/new/Source/stream_buffer.d \
./Middlewares/Third_Party/FreeRTOS/new/Source/tasks.d \
./Middlewares/Third_Party/FreeRTOS/new/Source/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/new/Source/%.o Middlewares/Third_Party/FreeRTOS/new/Source/%.su Middlewares/Third_Party/FreeRTOS/new/Source/%.cyclo: ../Middlewares/Third_Party/FreeRTOS/new/Source/%.c Middlewares/Third_Party/FreeRTOS/new/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Middlewares/Third_Party/SystemView/Config -I../Middlewares/Third_Party/SystemView/Patch -I../Middlewares/Third_Party/SystemView/SEGGER -I../Middlewares/Third_Party/SystemView/FreeRTOSV10 -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-new-2f-Source

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-new-2f-Source:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/new/Source/croutine.cyclo ./Middlewares/Third_Party/FreeRTOS/new/Source/croutine.d ./Middlewares/Third_Party/FreeRTOS/new/Source/croutine.o ./Middlewares/Third_Party/FreeRTOS/new/Source/croutine.su ./Middlewares/Third_Party/FreeRTOS/new/Source/event_groups.cyclo ./Middlewares/Third_Party/FreeRTOS/new/Source/event_groups.d ./Middlewares/Third_Party/FreeRTOS/new/Source/event_groups.o ./Middlewares/Third_Party/FreeRTOS/new/Source/event_groups.su ./Middlewares/Third_Party/FreeRTOS/new/Source/list.cyclo ./Middlewares/Third_Party/FreeRTOS/new/Source/list.d ./Middlewares/Third_Party/FreeRTOS/new/Source/list.o ./Middlewares/Third_Party/FreeRTOS/new/Source/list.su ./Middlewares/Third_Party/FreeRTOS/new/Source/queue.cyclo ./Middlewares/Third_Party/FreeRTOS/new/Source/queue.d ./Middlewares/Third_Party/FreeRTOS/new/Source/queue.o ./Middlewares/Third_Party/FreeRTOS/new/Source/queue.su ./Middlewares/Third_Party/FreeRTOS/new/Source/stream_buffer.cyclo ./Middlewares/Third_Party/FreeRTOS/new/Source/stream_buffer.d ./Middlewares/Third_Party/FreeRTOS/new/Source/stream_buffer.o ./Middlewares/Third_Party/FreeRTOS/new/Source/stream_buffer.su ./Middlewares/Third_Party/FreeRTOS/new/Source/tasks.cyclo ./Middlewares/Third_Party/FreeRTOS/new/Source/tasks.d ./Middlewares/Third_Party/FreeRTOS/new/Source/tasks.o ./Middlewares/Third_Party/FreeRTOS/new/Source/tasks.su ./Middlewares/Third_Party/FreeRTOS/new/Source/timers.cyclo ./Middlewares/Third_Party/FreeRTOS/new/Source/timers.d ./Middlewares/Third_Party/FreeRTOS/new/Source/timers.o ./Middlewares/Third_Party/FreeRTOS/new/Source/timers.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-new-2f-Source

