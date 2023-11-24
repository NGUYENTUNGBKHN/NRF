TARGETS=systick_os
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs


DEBUG=0

ifeq ($(DEBUG),1)
ECHO=
else
ECHO=@
endif

# toolchain
PREFIX=arm-none-eabi

CC='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc' -x assembler-with-cpp
SZ='$(TOOLCHAIN_TUNG)/$(PREFIX)-size'
CP='$(TOOLCHAIN_TUNG)/$(PREFIX)-objcopy'

HEX=$(CP) -O ihex 
BIN=$(CP) -O binary -S


LINKER_SCRIPT=systick_os.ld

# C option
CPU=-mcpu=cortex-m4
FPU=-mfpu=fpv4-sp-d16
FLOAT_ABI=-mfloat-abi=hard
OPT=-O3 -g3
MCU=$(CPU) $(FPU) $(FLOAT_ABI) $(OPT)

CCFLAGS+=$(MCU)
CCFLAGS+=-Wall -Werror -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAGS+=-fno-builtin -fshort-enums
CCFLAGS+=-MMD -MP -MF"$(@:%.o=%.d)"

# ASM option
ASMFLAGS=$(MCU)


# Linker option
LDFLAGS+=$(MCU)
LDFLAGS+=-T$(LINKER_SCRIPT) --specs=nano.specs
LDFLAGS+=-Wl,--gc-sections,-Map=$(OUTPUT_PROJ_DIR)/$(TARGETS).map

# Library
LIBS=-lc -lm -lnosys

SRC_FILES=main.c\
	startup.c\

ASM_FILES=

INC_FOLDERS=


OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.s, $(OUTPUT_OBJS_DIR)/%.s.o, $(ASM_FILES))

.PHONY: default all clean


default: all

all: $(OUTPUT_PROJ_DIR)/$(TARGETS).out $(OUTPUT_PROJ_DIR)/$(TARGETS).hex $(OUTPUT_PROJ_DIR)/$(TARGETS).bin
	$(ECHO)echo "Done Build."


$(OUTPUT_OBJS_DIR)/%.o: %.c
	$(ECHO)echo "Compiling $<"
	$(ECHO)mkdir -p $(shell dirname $@)
	$(ECHO)$(CC) $(CCFLAGS) $(INC_FOLDERS) -c $< -o $@

$(OUTPUT_OBJS_DIR)/%.s.o: %.s
	$(ECHO)echo "Compiling $<"
	$(ECHO)mkdir -p $(shell dirname $@)
	$(ECHO)$(AS) $(ASMFLAGS) $(INC_FOLDERS) -c $< -o $@

$(OUTPUT_PROJ_DIR)/$(TARGETS).out: $(OBJECTS)
	$(ECHO)echo "Linking target $@"
	$(ECHO)$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	$(ECHO)$(SZ) $@

$(OUTPUT_PROJ_DIR)/$(TARGETS).hex: $(OUTPUT_PROJ_DIR)/$(TARGETS).out
	$(ECHO)$(HEX) $< $@


$(OUTPUT_PROJ_DIR)/$(TARGETS).bin: $(OUTPUT_PROJ_DIR)/$(TARGETS).out
	$(ECHO)$(BIN) $< $@


flash: default
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

softdevice:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/sd_windows.jlink

clean: 
	rm -r $(OUTPUT_PROJ_DIR)


