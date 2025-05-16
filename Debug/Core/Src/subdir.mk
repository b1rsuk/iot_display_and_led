################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/font.c \
../Core/Src/http.c \
../Core/Src/http_parser.c \
../Core/Src/http_response.c \
../Core/Src/led_control.c \
../Core/Src/main.c \
../Core/Src/picohttpparser.c \
../Core/Src/ssd1306.c \
../Core/Src/stm32f1xx_hal_msp.c \
../Core/Src/stm32f1xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f1xx.c \
../Core/Src/uart_utils.c 

OBJS += \
./Core/Src/font.o \
./Core/Src/http.o \
./Core/Src/http_parser.o \
./Core/Src/http_response.o \
./Core/Src/led_control.o \
./Core/Src/main.o \
./Core/Src/picohttpparser.o \
./Core/Src/ssd1306.o \
./Core/Src/stm32f1xx_hal_msp.o \
./Core/Src/stm32f1xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f1xx.o \
./Core/Src/uart_utils.o 

C_DEPS += \
./Core/Src/font.d \
./Core/Src/http.d \
./Core/Src/http_parser.d \
./Core/Src/http_response.d \
./Core/Src/led_control.d \
./Core/Src/main.d \
./Core/Src/picohttpparser.d \
./Core/Src/ssd1306.d \
./Core/Src/stm32f1xx_hal_msp.d \
./Core/Src/stm32f1xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f1xx.d \
./Core/Src/uart_utils.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/font.cyclo ./Core/Src/font.d ./Core/Src/font.o ./Core/Src/font.su ./Core/Src/http.cyclo ./Core/Src/http.d ./Core/Src/http.o ./Core/Src/http.su ./Core/Src/http_parser.cyclo ./Core/Src/http_parser.d ./Core/Src/http_parser.o ./Core/Src/http_parser.su ./Core/Src/http_response.cyclo ./Core/Src/http_response.d ./Core/Src/http_response.o ./Core/Src/http_response.su ./Core/Src/led_control.cyclo ./Core/Src/led_control.d ./Core/Src/led_control.o ./Core/Src/led_control.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/picohttpparser.cyclo ./Core/Src/picohttpparser.d ./Core/Src/picohttpparser.o ./Core/Src/picohttpparser.su ./Core/Src/ssd1306.cyclo ./Core/Src/ssd1306.d ./Core/Src/ssd1306.o ./Core/Src/ssd1306.su ./Core/Src/stm32f1xx_hal_msp.cyclo ./Core/Src/stm32f1xx_hal_msp.d ./Core/Src/stm32f1xx_hal_msp.o ./Core/Src/stm32f1xx_hal_msp.su ./Core/Src/stm32f1xx_it.cyclo ./Core/Src/stm32f1xx_it.d ./Core/Src/stm32f1xx_it.o ./Core/Src/stm32f1xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f1xx.cyclo ./Core/Src/system_stm32f1xx.d ./Core/Src/system_stm32f1xx.o ./Core/Src/system_stm32f1xx.su ./Core/Src/uart_utils.cyclo ./Core/Src/uart_utils.d ./Core/Src/uart_utils.o ./Core/Src/uart_utils.su

.PHONY: clean-Core-2f-Src

