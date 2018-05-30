################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/imu/imu.cc 

CC_DEPS += \
./src/imu/imu.d 

OBJS += \
./src/imu/imu.o 


# Each subdirectory must supply rules for building sources it contributes
src/imu/%.o: ../src/imu/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I"C:\Users\Frien\PraticewithI2C_Inter\PraticewithI2C_Inter.sdk\SD_Card\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../SD_Card_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


