################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

C_SRCS += \
../src/DS1302.c \
../src/GicAndTimer.c \
../src/KEYS.c \
../src/LED.c \
../src/main.c 

OBJS += \
./src/DS1302.o \
./src/GicAndTimer.o \
./src/KEYS.o \
./src/LED.o \
./src/main.o 

C_DEPS += \
./src/DS1302.d \
./src/GicAndTimer.d \
./src/KEYS.d \
./src/LED.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 gcc compiler'
	arm-none-eabi-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../CPU0_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


