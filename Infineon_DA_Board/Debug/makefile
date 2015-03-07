################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Lib/subdir.mk
-include Dave/Generated/src/SPI001/subdir.mk
-include Dave/Generated/src/MATHLIBS/subdir.mk
-include Dave/Generated/src/LIBS/subdir.mk
-include Dave/Generated/src/IO004/subdir.mk
-include Dave/Generated/src/DAVESupport/subdir.mk
-include Dave/Generated/src/CLK002/subdir.mk
-include DA/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
Infineon_DA_Board.hex \

SECONDARY_LIST += \
Infineon_DA_Board.lst \

SECONDARY_SIZE += \
Infineon_DA_Board.siz \


# All Target
all: Infineon_DA_Board.elf secondary-outputs

# Tool invocations
Infineon_DA_Board.elf: $(OBJS) ../Infineon_DA_Board.ld $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: ARM-GCC C Linker'
	"D:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-gcc" -T"../Infineon_DA_Board.ld" -nostartfiles -L"D:\DAVE-3.1.10\eclipse\/../CMSIS/Infineon/Lib" -L"D:\DAVE-3.1.10\eclipse\/../Examples/Lib" -L"D:\DAVE-3.1.10\eclipse\/../emWin/Start/GUI" -Wl,-Map,"Infineon_DA_Board.map" -mcpu=cortex-m0 -mthumb -g3 -gdwarf-2 -o "Infineon_DA_Board.elf" "@makefile.rsp" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Infineon_DA_Board.hex: Infineon_DA_Board.elf
	@echo 'Invoking: ARM-GCC Create Flash Image'
	"D:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objcopy" -O ihex "Infineon_DA_Board.elf"  "Infineon_DA_Board.hex"
	@echo 'Finished building: $@'
	@echo ' '

Infineon_DA_Board.lst: Infineon_DA_Board.elf
	@echo 'Invoking: ARM-GCC Create Listing'
	"D:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-objdump" -h -S "Infineon_DA_Board.elf" > "Infineon_DA_Board.lst"
	@echo 'Finished building: $@'
	@echo ' '

Infineon_DA_Board.siz: Infineon_DA_Board.elf
	@echo 'Invoking: ARM-GCC Print Size'
	"D:\DAVE-3.1.10\ARM-GCC/bin/arm-none-eabi-size"  --format=berkeley Infineon_DA_Board.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(SECONDARY_FLASH)$(S_DEPS)$(ARM_GCC_FOR_XMC_LINKER_OUTPUT_TYPE_OUTPUTS)$(SECONDARY_LIST) Infineon_DA_Board.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
