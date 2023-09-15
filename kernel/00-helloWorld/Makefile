TARGET=helloWorld
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs

# toolchain
FREFIX=arm-none-eabi
CC='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc' -x assembler-with-cpp
CP='$(TOOLCHAIN_TUNG)/$(FREFIX)-objcopy'
SZ='$(TOOLCHAIN_TUNG)/$(FREFIX)-size'
HEX=$(CP) -O ihex
BIN=$(CP) -O binary -S

LINKER_SCRIPT=hello.ld

CPU=-mcpu=cortex-m4
FPU=-mfpu=fpv4-sp-d16
FLOAT_ABI=-mfloat-abi=hard
MCU= $(CPU) $(FPU) $(FLOAT_ABI)
OPT= -O3 -g3
CCFLAGS= $(MCU) $(OPT)
CCFLAGS+= -Wall -Werror -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAGS+= -fno-builtin -fshort-enums -D__STARTUP_CONFIG
CCFLAGS+= -MMD -MP -MF"$(@:%.o=%.d)"

ASMFLAG= $(MCU)
ASMFLAG+= -g3


LDFLAGS= $(MCU)
LDFLAGS+= $(OPT) -T$(LINKER_SCRIPT) --specs=nano.specs
LDFLAGS+= -Wl,--gc-sections,-Map=$(OUTPUT_PROJ_DIR)/$(TARGET).map


LIB_FILES +=-lc -lm -lnosys 

SRC_FILES=main.c\
	startup.c\


ASM_FILES=\

INC_FOLDER=\


OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.S, $(OUTPUT_OBJS_DIR)/%.o, $(ASM_FILES))

.PHONY: all clean

all: $(OUTPUT_PROJ_DIR)/$(TARGET).out $(OUTPUT_PROJ_DIR)/$(TARGET).bin $(OUTPUT_PROJ_DIR)/$(TARGET).hex

$(OUTPUT_OBJS_DIR)/%.o: %.c | Makefile
	@echo "Compiling $(notdir $<)"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_OBJS_DIR)/%.o: %.S | Makefile
	@echo "Assembling $(notdir $<)"
	@mkdir -p $(shell dirname $@)
	@$(AS) $(ASMFLAG) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_PROJ_DIR)/$(TARGET).out: $(OBJECTS)
	@echo "Link target $(notdir $@)"
	@$(CC) $(LDFLAGS) $(LIB_FILES) $(OBJECTS) -o $@
	@$(SZ) $@

$(OUTPUT_PROJ_DIR)/$(TARGET).bin: $(OUTPUT_PROJ_DIR)/$(TARGET).out
	@echo "BIN $@"
	@$(BIN) $< $@


$(OUTPUT_PROJ_DIR)/$(TARGET).hex: $(OUTPUT_PROJ_DIR)/$(TARGET).out
	@echo "HEX $@"
	@$(HEX) $< $@

clean:
	rm -r $(OUTPUT_PROJ_DIR)

-include $(wildcard */*/*.d)
-include $(wildcard */*/*/*.d)

flash:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

softdevice:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/sd_windows.jlink

