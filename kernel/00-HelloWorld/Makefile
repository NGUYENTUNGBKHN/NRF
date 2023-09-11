TARGETS=hello
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/objs


LINKER_SCRIPT=hello.ld

FREFIX=arm-none-eabi
CC=$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc
CP=$(TOOLCHAIN_TUNG)/$(FREFIX)-objcopy
AS=$(TOOLCHAIN_TUNG)/$(FREFIX)-gcc -x assembler-with-cpp
HEX=$(CP) -O ihex
BIN=$(CP) -O binary -S


CCFLAGS=

ASMFLAGS=

LDFLAGS=

SRC_FILE=$(wildcard *.c)

ASM_FILE=$(wildcard *.s)

INC_FOLDERS=\


OBJS=$(patsubst %.c, $(OUTPUT_OBJS_DIR)/%.o, $(SRC_FILE))
OBJS+=$(patsubst %.s, $(OUTPUT_OBJS_DIR)/%.o, $(ASM_FILE))

.PHONY:	all 

all: $(OUTPUT_PROJ_DIR)/$(TARGETS).out $(OUTPUT_PROJ_DIR)/$(TARGETS).bin $(OUTPUT_PROJ_DIR)/$(TARGETS).hex

$(OUTPUT_OBJS_DIR)/%.o: %.c
	@echo "Compiling $@"
	@$(CC) $(CCFLAGS) $(INC_FOLDERS) -c $^ -o $@


$(OUTPUT_PROJ_DIR)/$(TARGETS).out: $(OBJS)
	@echo "Link target $@"
	@$(CC) $(LDFLAGS) $(OBJS) -o $@


$(OUTPUT_PROJ_DIR)/$(TARGETS).bin:
	$(BIN)  $< $@


$(OUTPUT_PROJ_DIR)/$(TARGETS).hex:
	$(HEX) $< $@

clean: 
	rm -r $(OUTPUT_PROJ_DIR)



