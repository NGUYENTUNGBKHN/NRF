TARGETS=context_sw2
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs


LINKER_SCRIPT=context.ld

PREFIX=arm-none-eabi

CC='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc' -x assembler-with-cpp
SZ='$(TOOLCHAIN_TUNG)/$(PREFIX)-size'
CP='$(TOOLCHAIN_TUNG)/$(PREFIX)-objcopy'

HEX=$(CP) -O ihex
BIN=$(CP) -O binary -S

OPT=-O3 -g3
CPU=-mcpu=cortex-m4
FPU=-mfpu=fpv4-sp-d16
FLOAT_ABI=-mfloat-abi=hard

MCU=$(CPU) $(FPU) $(OPT) $(FLOAT_ABI)

CCFLAGS+=$(MCU)
CCFLAGS+=-Wall -Werror -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAGS+=-fno-builtin -fshort-enums 
CCFLAGS+=-MMD -MP -MF"$(@:%.o=%.d)"

ASMFLAGS=$(MCU)

LDFLAGS=$(MCU)
LDFLAGS+=-T$(LINKER_SCRIPT) --specs=nano.specs
LDFLAGS+=-Wl,--gc-sections,-Map=$(OUTPUT_PROJ_DIR)/$(TARGETS).map

LIBS=-lc -lm -lnosys

SRC_FILES=main.c\
	# startup.c\

INC_FOLDER=

ASM_FILES=syscall.s\
	context_switch.s\
	startup.s\

OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.s, $(OUTPUT_OBJS_DIR)/%.s.o, $(ASM_FILES))

.PHONY: default all clean

default: all

all: $(OUTPUT_PROJ_DIR)/$(TARGETS).out $(OUTPUT_PROJ_DIR)/$(TARGETS).bin $(OUTPUT_PROJ_DIR)/$(TARGETS).hex
	@echo "Build Done."


$(OUTPUT_OBJS_DIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@


$(OUTPUT_OBJS_DIR)/%.s.o: %.s
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(AS) $(ASMFLAGS) $(INC_FOLDER) -c $< -o $@


$(OUTPUT_PROJ_DIR)/$(TARGETS).out: $(OBJECTS)
	@echo "Linking $@"
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	@$(SZ) $@

$(OUTPUT_PROJ_DIR)/$(TARGETS).bin: $(OUTPUT_PROJ_DIR)/$(TARGETS).out
	@echo "BIN $@"
	@$(BIN) $< $@

$(OUTPUT_PROJ_DIR)/$(TARGETS).hex: $(OUTPUT_PROJ_DIR)/$(TARGETS).out
	@echo "HEX $@"
	@$(HEX) $< $@


flash: default
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

softdevice:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/sd_windows.jlink

clean:
	rm -r $(OUTPUT_PROJ_DIR)

