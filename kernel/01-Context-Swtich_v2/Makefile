TARGET=context_sw
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs

LINKER_SCRIPT=context.ld

# toolchain
FREFIX=arm-none-eabi
CC='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'  -x assembler-with-cpp
SZ='$(TOOLCHAIN_TUNG)/$(FREFIX)-size'
CP='$(TOOLCHAIN_TUNG)/$(FREFIX)-objcopy'

HEX=$(CP) -O ihex
BIN=$(CP) -O binary -S

CPU=-mcpu=cortex-m4
FPU=-mfpu=fpv4-sp-d16
FLOAT_ABI=-mfloat-abi=hard
MCU=$(CPU) $(FPU) $(FLOAT_ABI)
OPT=-O3 -g3

CCFLAGS=$(MCU) $(OPT)
CCFLAGS+= -Wall -Werror -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAGS+= -fno-builtin -fshort-enums -D__STARTUP_CONFIG
CCFLAGS+= -MMD -MP -MF"$(@:%.o=%.d)"

ASMFLAGS= $(MCU)
ASMFLAGS+= -g3


LDFLAGS= $(MCU)
LDFLAGS+= $(OPT) -T$(LINKER_SCRIPT) --specs=nano.specs
LDFLAGS+= -Wl,--gc-sections,-Map=$(OUTPUT_PROJ_DIR)/$(TARGET).map

LIBS=-lc -lm -lnosys 

SRC_FILES=main.c\
	startup.c\

ASM_FILES=context_switch.S\

INC_FOLDER=


OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.S, $(OUTPUT_OBJS_DIR)/%.S.o, $(ASM_FILES))


.PHONY: default all clean

default: all

all: $(OUTPUT_PROJ_DIR)/$(TARGET).out $(OUTPUT_PROJ_DIR)/$(TARGET).hex $(OUTPUT_PROJ_DIR)/$(TARGET).bin 
	@echo "Build Done."


$(OUTPUT_OBJS_DIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_OBJS_DIR)/%.S.o: %.S
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(AS) $(ASMFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_PROJ_DIR)/$(TARGET).out: $(OBJECTS)
	@echo "Linking Target $@"
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	@$(SZ) $@

$(OUTPUT_PROJ_DIR)/$(TARGET).hex: $(OUTPUT_PROJ_DIR)/$(TARGET).out
	@echo "HEX $@"
	@$(HEX) $< $@

$(OUTPUT_PROJ_DIR)/$(TARGET).bin: $(OUTPUT_PROJ_DIR)/$(TARGET).out
	@echo "BIN $@"
	@$(BIN) $< $@

flash: default
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

softdevice:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/sd_windows.jlink


clean:
	rm -r $(OUTPUT_PROJ_DIR)

