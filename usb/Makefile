TARGET_NAME=usb
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs


# linker script
LINK_SCRIPT=usb.ld

# TOOLCHAIN
PREFIX=arm-none-eabi
CC='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc'
CX='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc'
AS='$(TOOLCHAIN_TUNG)/$(PREFIX)-gcc' -x assembler-with-cpp
CP='$(TOOLCHAIN_TUNG)/$(PREFIX)-objcopy'
SZ='$(TOOLCHAIN_TUNG)/$(PREFIX)-size'

HEX=$(CP) -O -ihex
BIN=$(CP) -O binary -S


# SETTIING
CCFLAGS=


ASMFLAGS=


LDFLAGS=


SRC_FILES=

ASM_FILES=

OBJECTS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/*.o, $(SRC_FILES))
OBJECTS+=$(patsubst %.s, $(OUTPUT_OBJS_DIR)/*.s.o, $(ASM_FILES))






