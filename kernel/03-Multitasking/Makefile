TARGETS=multi
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs


LINKER_SCRIPT=multitasking.ld


# Toolchain
FREFIX=arm-none-eabi

CC='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc' -x assembler-with-cpp
SZ='$(TOOLCHAIN_TUNG)/$(FREFIX)-size'
CP='$(TOOLCHAIN_TUNG)/$(FREFIX)-objcopy'

HEX= $(CP) -O ihex
BIN= $(CP) -O binary -S

# C option
CPU=-mcpu=cortex-m4
FPU=-mfpu=fpv4-sp-d16
FLOAT_ABI=-mfloat-abi=hard
OPT=-O3 -g3
MCU= $(CPU) $(FPU) $(FLOAT_EABI) $(OPT)

CCFLAGS+=$(MCU)
CCFLAGS+=-Wall -Werror -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAGS+=-fno-builtin -fshort-enums 
CCFLAGS+=-MMD -MP -MF"$(@:%.=%.d)"


# ASM option
ASMFLAGS=$(MCU)

# LD option
LDFLAGS=$(MCU)
LDFLAGS+=-T$(LINKER_SCRIPT) --specs=nano.specs
LDFLAGS+=-Wl,--gc-sections,-Map=$(OUTPUT_PROJ_DIR)/$(TARGETS).map

# Library
LIBS=-lc -lm -lnosys

# File compile
SRC_FILES=main.c\
	startup.c\

ASM_FILES=os.s\
	syscall.s\

INC_FOLDER=

# object generated
OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.s, $(OUTPUT_OBJS_DIR)/%.s.o, $(ASM_FILES))

.PHONY: default all clean

default: all

all: $(OUTPUT_PROJ_DIR)/$(TARGETS).out $(OUTPUT_PROJ_DIR)/$(TARGETS).hex $(OUTPUT_PROJ_DIR)/$(TARGETS).bin
	@echo "Build done."

$(OUTPUT_OBJS_DIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_OBJS_DIR)/%.s.o: %.s
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(AS) $(ASMFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_PROJ_DIR)/$(TARGETS).out: $(OBJECTS)
	@echo "Linking target $@"
	@$(CC) $(LDFLAGS) $(INC_FOLDER) $(OBJECTS) -o $@
	@$(SZ) $@

$(OUTPUT_PROJ_DIR)/$(TARGETS).hex: $(OUTPUT_PROJ_DIR)/$(TARGETS).out
	@$(HEX) $< $@

$(OUTPUT_PROJ_DIR)/$(TARGETS).bin: $(OUTPUT_PROJ_DIR)/$(TARGETS).out
	@$(BIN) $< $@


flash: default
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

softdevice:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/sd_windows.jlink



clean:
	rm -r $(OUTPUT_PROJ_DIR)


