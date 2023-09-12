TARGET=osKernel
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs


LINKER_SCRIPT=osKernel.ld

ROOT_PROJ := ./
LIB_NRF := ../../

# toolchain

FREFIX=arm-none-eabi
CC='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc -x assembler-with-cpp'
CP='$(TOOLCHAIN_TUNG)/$(FREFIX)-objcopy'
SZ='$(TOOLCHAIN_TUNG)/$(FREFIX)-size'
HEX=$(CP) -O ihex
BIN=$(CP) -O binary -S

CPU=-mcpu=cortex-m4 
FPU=-mfpu=fpv4-sp-d16
FLOAT_ABI=-mfloat-abi=hard
MCU=$(CPU) $(FPU) $(FLOAT_ABI)
OPT=-O3 -g3

CCFLAGS+=$(MCU) $(OPT)
CCFLAGS+=-ffunction-sections -fdata-sections -fno-strict-aliasing # function
CCFLAGS+=-fno-builtin -fshort-enums
CCFLAGS+=-DBOARD_PCA10056
CCFLAGS+=-DFLOAT_ABI_HARD
CCFLAGS+=-DNRF52840_XXAA
CCFLAGS+=-Wall -Werror


ASMFLAGS+=-g3
ASMFLAGS+=-mcpu=cortex-m4
ASMFLAGS+=-mthumb -mabi=aapcs
ASMFLAGS+=-mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS+=-DBOARD_PCA10056
ASMFLAGS+=-DBSP_DEFINES_ONLY
ASMFLAGS+=-DCONFIG_GPIO_AS_PINRESET
ASMFLAGS+=-DFLOAT_ABI_HARD
ASMFLAGS+=-DNRF52840_XXAA

LIB_FILES += -lc -lm

LDFLAGS+=$(MCU)
LDFLAGS+=-Wl,--gc-sections
LDFLAGS+=--specs=nano.specs -T$(LINKER_SCRIPT) $(LIB_FILES)



# SRC_FILES=main.c\
# 		startup.c\

SRC_FILES=$(wildcard *.c)

ASM_FILES=$(wildcard *.s)

INC_FOLDER +=\

.PHONY: all clean

all: $(OUTPUT_PROJ_DIR)/$(TARGET).out $(OUTPUT_PROJ_DIR)/$(TARGET).bin $(OUTPUT_PROJ_DIR)/$(TARGET).hex


OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.S, $(OUTPUT_OBJS_DIR)/%.o, $(ASM_FILES))

$(OUTPUT_OBJS_DIR)/%.o: %.c Makefile
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_OBJS_DIR)/%.o: %.S Makefile
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@


$(OUTPUT_PROJ_DIR)/$(TARGET).out: $(OBJECTS) Makefile
	@echo "Link target $(notdir $@)"
	@$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	@$(SZ) $@

$(OUTPUT_PROJ_DIR)/$(TARGET).bin: $(OUTPUT_PROJ_DIR)/$(TARGET).out
	@echo "Binary $@"
	@$(BIN) $< $@


$(OUTPUT_PROJ_DIR)/$(TARGET).hex: $(OUTPUT_PROJ_DIR)/$(TARGET).out
	@echo "Hex $@"
	@$(HEX) $< $@

clean:
	rm -r $(OUTPUT_PROJ_DIR)


