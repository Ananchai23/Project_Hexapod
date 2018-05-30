################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/hexapod_leg/imu.cc \
../src/hexapod_leg/leg.cc 

C_SRCS += \
../src/hexapod_leg/comm.c \
../src/hexapod_leg/i2c.c \
../src/hexapod_leg/interrupt.c \
../src/hexapod_leg/joint_controls.c 

CPP_SRCS += \
../src/hexapod_leg/I2Cdev.cpp \
../src/hexapod_leg/MPU6050.cpp 

CC_DEPS += \
./src/hexapod_leg/imu.d \
./src/hexapod_leg/leg.d 

OBJS += \
./src/hexapod_leg/I2Cdev.o \
./src/hexapod_leg/MPU6050.o \
./src/hexapod_leg/comm.o \
./src/hexapod_leg/i2c.o \
./src/hexapod_leg/imu.o \
./src/hexapod_leg/interrupt.o \
./src/hexapod_leg/joint_controls.o \
./src/hexapod_leg/leg.o 

C_DEPS += \
./src/hexapod_leg/comm.d \
./src/hexapod_leg/i2c.d \
./src/hexapod_leg/interrupt.d \
./src/hexapod_leg/joint_controls.d 

CPP_DEPS += \
./src/hexapod_leg/I2Cdev.d \
./src/hexapod_leg/MPU6050.d 


# Each subdirectory must supply rules for building sources it contributes
src/hexapod_leg/%.o: ../src/hexapod_leg/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I"C:\Users\Frien\PraticewithI2C_Inter\PraticewithI2C_Inter.sdk\Test_RBF_Wavegait\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../SD_Card_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hexapod_leg/%.o: ../src/hexapod_leg/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I"C:\Users\Frien\PraticewithI2C_Inter\PraticewithI2C_Inter.sdk\Test_RBF_Wavegait\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../SD_Card_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/hexapod_leg/%.o: ../src/hexapod_leg/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: ARM v7 g++ compiler'
	arm-none-eabi-g++ -Wall -O0 -g3 -I"C:\Users\Frien\PraticewithI2C_Inter\PraticewithI2C_Inter.sdk\Test_RBF_Wavegait\include" -c -fmessage-length=0 -MT"$@" -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -I../../SD_Card_bsp/ps7_cortexa9_0/include -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


