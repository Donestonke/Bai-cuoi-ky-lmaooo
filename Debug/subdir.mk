################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BinaryGate.cpp \
../Connector.cpp \
../GateException.cpp \
../LogicGate.cpp \
../ParityChecker4Bit.cpp \
../PrintMenu.cpp \
../UnaryGate.cpp \
../Utility.cpp \
../XorGate.cpp \
../eXorGate.cpp \
../main.cpp 

OBJS += \
./BinaryGate.o \
./Connector.o \
./GateException.o \
./LogicGate.o \
./ParityChecker4Bit.o \
./PrintMenu.o \
./UnaryGate.o \
./Utility.o \
./XorGate.o \
./eXorGate.o \
./main.o 

CPP_DEPS += \
./BinaryGate.d \
./Connector.d \
./GateException.d \
./LogicGate.d \
./ParityChecker4Bit.d \
./PrintMenu.d \
./UnaryGate.d \
./Utility.d \
./XorGate.d \
./eXorGate.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


