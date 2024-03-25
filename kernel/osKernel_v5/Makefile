TARGET_NAME=kernel
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs

PROJ_DIR=./
DRIVER_DIR=./driver
CSW_DIR=./context_switch
MUL_DIR=./multitasking
OSK_DIR=./osKernel
INC_COMMON=./include


LINKER_SCRIPT=kernel.ld

PREFIX=arm-none-eabi

# TOOLCHAIN
CC='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc' -x assembler-with-cpp
CP='$(TOOLCHAIN_TUNG)/$(PREFIX)-objcopy'
SZ='$(TOOLCHAIN_TUNG)/$(PREFIX)-size'

HEX=$(CP) -O ihex
BIN=$(CP) -O binary -S

CPU=-mcpu=cortex-m4
FPU=-mfpu=fpv4-sp-d16
FLOAT_ABI=-mfloat-abi=hard
OPT=-O3 -g3
MCU=$(CPU) $(FPU) $(FLOAT_ABI)
CCFLAGS+= $(MCU) $(OPT)
CCFLAGS+= -Wall -Werror -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAGS+= -fno-builtin -fshort-enums
CCFLAGS+= -MMD -MP -MF"$(@:%.o=%.d)"

ASMFLAGS+=$(MCU) -g3

LDFLAGS+=$(MCU) $(OPT)
LDFLAGS+=-T$(LINKER_SCRIPT)  --specs=nano.specs
LDFLAGS+= -Wl,--gc-sections,-Map=$(OUTPUT_PROJ_DIR)/$(TARGET_NAME).map


SRC_FILES=\
	$(OSK_DIR)/main.c\
	$(OSK_DIR)/osKernel.c\
	$(DRIVER_DIR)/log/log.c\
	# $(MUL_DIR)/main.c\
	# $(CSW_DIR)/context_sw.c\
	

ASM_FILES=startup.s\
	$(OSK_DIR)/osKernel.s\
	# $(MUL_DIR)/mul.s\
	# $(MUL_DIR)/syscall.s\
	# $(CSW_DIR)/context_sw.s\



INC_FOLDER=-I$(INC_COMMON)\
	-I$(DRIVER_DIR)/log\
	-I$(CSW_DIR)\
	-I$(MUL_DIR)\
	-I$(OSK_DIR)\

LIBS=-lc -lm -lnosys


OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.s, $(OUTPUT_OBJS_DIR)/%.s.o, $(ASM_FILES))

.PHONY: default all clean

default: all
	@echo "DONE."

all: $(OUTPUT_PROJ_DIR)/$(TARGET_NAME).out $(OUTPUT_PROJ_DIR)/$(TARGET_NAME).hex $(OUTPUT_PROJ_DIR)/$(TARGET_NAME).bin

$(OUTPUT_OBJS_DIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@


$(OUTPUT_OBJS_DIR)/%.s.o: %.s
	@echo "Assembling $<"
	@mkdir -p $(shell dirname $@)
	@$(AS) $(ASMFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_PROJ_DIR)/$(TARGET_NAME).out: $(OBJECTS)
	@echo "LINK $@"
	@$(CC) $(LDFLAGS) $(INC_FOLDER) $(LIBS) $(OBJECTS) -o $@
	@$(SZ) $@

$(OUTPUT_PROJ_DIR)/$(TARGET_NAME).hex: $(OUTPUT_PROJ_DIR)/$(TARGET_NAME).out
	@echo "HEX $@"
	@$(HEX) $< $@

$(OUTPUT_PROJ_DIR)/$(TARGET_NAME).bin: $(OUTPUT_PROJ_DIR)/$(TARGET_NAME).out
	@echo "BIN $@"
	@$(HEX) $< $@


flash: default
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

clean:
	rm -r $(OUTPUT_PROJ_DIR)




