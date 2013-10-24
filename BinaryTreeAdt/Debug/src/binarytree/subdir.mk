################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/binarytree/BinaryTree.cpp \
../src/binarytree/binarySearchTree.cpp 

OBJS += \
./src/binarytree/BinaryTree.o \
./src/binarytree/binarySearchTree.o 

CPP_DEPS += \
./src/binarytree/BinaryTree.d \
./src/binarytree/binarySearchTree.d 


# Each subdirectory must supply rules for building sources it contributes
src/binarytree/%.o: ../src/binarytree/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


