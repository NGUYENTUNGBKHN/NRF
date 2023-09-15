TARGET:=code
OUTPUT_PROJ_DIR=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/obj

ROOT_PROJ := ./
LIB_NRF := ../

$(OUTPUT_PROJ_DIR)/$(TARGET).out:\
	LINKER_SCRIPT := uart_gcc_nrf52.ld

CPU=-mcpu=cortex-m4 -mthumb -mabi=aapcs -std=gnu99
FPU=-mfloat-abi=hard -mfpu=fpv4-sp-d16
OPT=-O3 -g3

CCFLAG +=$(CPU) $(FPU) $(OPT)
CCFLAG +=
CCFLAG += -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAG += -fno-builtin -fshort-enums
CCFLAG += -DBOARD_PCA10056
CCFLAG += -DBSP_DEFINES_ONLY
CCFLAG += -DCONFIG_GPIO_AS_PINRESET
CCFLAG += -DFLOAT_ABI_HARD
CCFLAG += -DNRF52840_XXAA
CCFLAG += -Wall -Werror


CCFLAG +=$(CPU) $(FPU) $(OPT)
CCFLAG +=
CCFLAG += -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAG += -fno-builtin -fshort-enums
CCFLAG += -DBOARD_PCA10056
CCFLAG += -DBSP_DEFINES_ONLY
CCFLAG += -DCONFIG_GPIO_AS_PINRESET
CCFLAG += -DFLOAT_ABI_HARD
CCFLAG += -DNRF52840_XXAA
CCFLAG += -Wall -Werror

ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DBOARD_PCA10056
ASMFLAGS += -DBSP_DEFINES_ONLY
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52840_XXAA


LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(LIB_NRF)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

LIB_FILES += -lc -lm

SRC_FILES += \
	$(LIB_NRF)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
	main.c\
	syscall.c\
	sysmem.c\

INC_FOLDER +=\

 
.PHONY: default help flash


default: $(TARGET)

include Makefile.common

$(foreach target, $(TARGET),$(call define_target,$(target)))

help:
	echo "help"

SDK_CONFIG_FILE := $(ROOT_PROJ)/config/sdk_config.h
CMSIS_CONFIG_TOOL := $(LIB_NRF)/external_tools/cmsisconfig/CMSIS_Configuration_Wizard.jar
sdk_config:
	java -jar $(CMSIS_CONFIG_TOOL) $(SDK_CONFIG_FILE)


flash:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

softdevice:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/sd_windows.jlink
