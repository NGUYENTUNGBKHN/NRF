TARGETS := app_2
OUTPUT_PROJ_DIR := _build
OUTPUT_OBJS_DIR := $(OUTPUT_PROJ_DIR)/objs/

ROOT_PROJ := ./
LIB_NRF := ../

$(OUTPUT_PROJ_DIR)/$(TARGETS).out:\
	LINKER_SCRIPT := uart_gcc_nrf52.ld

CPU=-mcpu=cortex-m4 -mthumb -mabi=aapcs
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

LIB_FILES += -lc -lnosys -lm

SRC_FILES +=\
	$(LIB_NRF)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  	$(LIB_NRF)/components/libraries/log/src/nrf_log_frontend.c \
  	$(LIB_NRF)/components/libraries/log/src/nrf_log_str_formatter.c \
  	$(LIB_NRF)/components/libraries/util/app_error_handler_gcc.c \
  	$(LIB_NRF)/components/libraries/util/app_error_weak.c \
  	$(LIB_NRF)/components/libraries/util/app_util_platform.c \
  	$(LIB_NRF)/components/libraries/util/nrf_assert.c \
  	$(LIB_NRF)/components/libraries/atomic/nrf_atomic.c \
  	$(LIB_NRF)/components/libraries/balloc/nrf_balloc.c \
  	$(LIB_NRF)/external/fprintf/nrf_fprintf.c \
  	$(LIB_NRF)/external/fprintf/nrf_fprintf_format.c \
  	$(LIB_NRF)/components/libraries/memobj/nrf_memobj.c \
  	$(LIB_NRF)/components/libraries/ringbuf/nrf_ringbuf.c \
  	$(LIB_NRF)/components/libraries/strerror/nrf_strerror.c \
  	$(LIB_NRF)/components/libraries/uart/retarget.c \
  	$(LIB_NRF)/integration/nrfx/legacy/nrf_drv_uart.c \
  	$(LIB_NRF)/modules/nrfx/soc/nrfx_atomic.c \
  	$(LIB_NRF)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
  	$(LIB_NRF)/modules/nrfx/drivers/src/nrfx_uart.c \
  	$(LIB_NRF)/modules/nrfx/drivers/src/nrfx_uarte.c \
	$(LIB_NRF)/modules/nrfx/mdk/system_nrf52840.c \
  	$(ROOT_PROJ)/Application/main.c \
	$(ROOT_PROJ)/Drivers/drv_uart/drv_uart.c \
	$(ROOT_PROJ)/Drivers/drv_gpio/drv_gpio.c \
  	


INC_FOLDER +=\
	$(LIB_NRF)/components \
  	$(LIB_NRF)/modules/nrfx/mdk \
  	$(ROOT_PROJ) \
  	$(LIB_NRF)/components/libraries/fifo \
  	$(LIB_NRF)/components/libraries/strerror \
  	$(LIB_NRF)/components/toolchain/cmsis/include \
  	$(LIB_NRF)/components/libraries/util \
  	$(ROOT_PROJ)/config \
  	$(LIB_NRF)/components/libraries/balloc \
  	$(LIB_NRF)/components/libraries/ringbuf \
  	$(LIB_NRF)/modules/nrfx/hal \
  	$(LIB_NRF)/components/libraries/bsp \
  	$(LIB_NRF)/components/libraries/uart \
  	$(LIB_NRF)/components/libraries/log \
  	$(LIB_NRF)/modules/nrfx \
  	$(LIB_NRF)/components/libraries/experimental_section_vars \
  	$(LIB_NRF)/integration/nrfx/legacy \
  	$(LIB_NRF)/components/libraries/delay \
  	$(LIB_NRF)/integration/nrfx \
  	$(LIB_NRF)/components/drivers_nrf/nrf_soc_nosd \
  	$(LIB_NRF)/components/libraries/atomic \
  	$(LIB_NRF)/components/boards \
  	$(LIB_NRF)/components/libraries/memobj \
  	$(LIB_NRF)/modules/nrfx/drivers/include \
  	$(LIB_NRF)/external/fprintf \
  	$(LIB_NRF)/components/libraries/log/src \
	$(ROOT_PROJ)/Application\
	$(ROOT_PROJ)/Drivers/drv_uart\
	$(ROOT_PROJ)/Drivers/drv_gpio\


.PHONY: default help


default: $(TARGETS)


include Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

help:
	echo "help"

flash: default
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/build_windows.jlink

erase:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/erase_windows.jlink

softdevice:
	Jlink.exe -if swd -device nRF52840_xxAA -speed 4000 -CommanderScript CommanderScript/sd_windows.jlink




