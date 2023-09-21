TARGET=helloWorld
OUTPUT_PORJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PORJ_DIR)/objs


LINKER_SCRIPT=helloWorld.ld

# toolchain
FREFIX=arm-none-eabi
CC='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc -x assembler-with-cpp'
CP='$(TOOLCHAIN_TUNG)/$(FREFIX)-objcopy'
SZ='$(TOOLCHAIN_TUNG)/$(FREFIX)-size'

HEX=$(CP) -O ihex

BIN=$(CP) -O binary -S


CCFLAGS=


ASMFLAGS=


LDFLAGS=

LIBS=


SRC_FILES=

ASM_FILES=

INC_FOLDER=

OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.S, $(OUTPUT_OBJS_DIR)/%.S.o, $(ASM_FILES))


.PHONY: default all

default: all

all: $(OUTPUT_PORJ_DIR)/$(TARGET).out $(OUTPUT_PORJ_DIR)/$(TARGET).hex $(OUTPUT_PORJ_DIR)/$(TARGET).bin

$(OUTPUT_OBJS_DIR)/%.o: %.c
	@echo "Compiling $<"
	@mkdir -p $(shell dirname $@)
	@$(CC) $(CCFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_OBJS_DIR)/%.S.o: %.S
	@echo "Assembling $<"
	@mkdir -p $(shell dirname $@)
	@$(AS) $(ASMFLAGS) $(INC_FOLDER) -c $< -o $@

$(OUTPUT_PORJ_DIR)/$(TARGET).out: $(OBJECTS)
	@echo "Linking target $@"
	@$(CC) $(LDFLAGS) $(OBJECTS) $@
	@$(SZ) $@



