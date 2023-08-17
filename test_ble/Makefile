TARGETS:=test_ble
OUTPUT_PROJ_DIR:=_build
OUTPUT_OBJS_DIR:=$(OUTPUT_PROJ_DIR)/obj

ROOT_PROJ := ./
LIB_NRF := ../

$(OUTPUT_PROJ_DIR)/$(TARGETS).out:\
	LINKER_SCRIPT := ble_app_uart_gcc_nrf52.ld

CPU=-mcpu=cortex-m4 -mthumb -mabi=aapcs
FPU=-mfloat-abi=hard -mfpu=fpv4-sp-d16
OPT=-O3 -g3

CCFLAG +=$(CPU) $(FPU) $(OPT)
CCFLAG += -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAG += -fno-builtin -fshort-enums
CCFLAG += -DBOARD_PCA10056
CCFLAG += -DAPP_TIMER_V2
CCFLAG += -DAPP_TIMER_V2_RTC1_ENABLED
CCFLAG += -DCONFIG_GPIO_AS_PINRESET
CCFLAG += -DFLOAT_ABI_HARD
CCFLAG += -DNRF52840_XXAA
CCFLAG += -Wall -Werror
CCFLAG += -DNRF_SD_BLE_API_VERSION=7
CCFLAG += -DS140
CCFLAG += -DSOFTDEVICE_PRESENT
CFLAGS += -fno-builtin -fshort-enums

# C++ flags common to all targets
CXXFLAGS += $(OPT)
# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DAPP_TIMER_V2
ASMFLAGS += -DAPP_TIMER_V2_RTC1_ENABLED
ASMFLAGS += -DBOARD_PCA10056
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52840_XXAA
ASMFLAGS += -DNRF_SD_BLE_API_VERSION=7
ASMFLAGS += -DS140
ASMFLAGS += -DSOFTDEVICE_PRESENT


LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(LIB_NRF)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

LIB_FILES += -lc -lm 

# Source files common to all targets
SRC_FILES += \
  $(LIB_NRF)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(LIB_NRF)/components/libraries/log/src/nrf_log_backend_rtt.c \
  $(LIB_NRF)/components/libraries/log/src/nrf_log_backend_serial.c \
  $(LIB_NRF)/components/libraries/log/src/nrf_log_default_backends.c \
  $(LIB_NRF)/components/libraries/log/src/nrf_log_frontend.c \
  $(LIB_NRF)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(LIB_NRF)/components/libraries/button/app_button.c \
  $(LIB_NRF)/components/libraries/util/app_error.c \
  $(LIB_NRF)/components/libraries/util/app_error_handler_gcc.c \
  $(LIB_NRF)/components/libraries/util/app_error_weak.c \
  $(LIB_NRF)/components/libraries/fifo/app_fifo.c \
  $(LIB_NRF)/components/libraries/scheduler/app_scheduler.c \
  $(LIB_NRF)/components/libraries/timer/app_timer2.c \
  $(LIB_NRF)/components/libraries/uart/app_uart_fifo.c \
  $(LIB_NRF)/components/libraries/util/app_util_platform.c \
  $(LIB_NRF)/components/libraries/timer/drv_rtc.c \
  $(LIB_NRF)/components/libraries/hardfault/hardfault_implementation.c \
  $(LIB_NRF)/components/libraries/util/nrf_assert.c \
  $(LIB_NRF)/components/libraries/atomic_fifo/nrf_atfifo.c \
  $(LIB_NRF)/components/libraries/atomic_flags/nrf_atflags.c \
  $(LIB_NRF)/components/libraries/atomic/nrf_atomic.c \
  $(LIB_NRF)/components/libraries/balloc/nrf_balloc.c \
  $(LIB_NRF)/external/fprintf/nrf_fprintf.c \
  $(LIB_NRF)/external/fprintf/nrf_fprintf_format.c \
  $(LIB_NRF)/components/libraries/memobj/nrf_memobj.c \
  $(LIB_NRF)/components/libraries/pwr_mgmt/nrf_pwr_mgmt.c \
  $(LIB_NRF)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(LIB_NRF)/components/libraries/experimental_section_vars/nrf_section_iter.c \
  $(LIB_NRF)/components/libraries/sortlist/nrf_sortlist.c \
  $(LIB_NRF)/components/libraries/strerror/nrf_strerror.c \
  $(LIB_NRF)/components/libraries/uart/retarget.c \
  $(LIB_NRF)/modules/nrfx/mdk/system_nrf52840.c \
  $(LIB_NRF)/components/boards/boards.c \
  $(LIB_NRF)/integration/nrfx/legacy/nrf_drv_clock.c \
  $(LIB_NRF)/integration/nrfx/legacy/nrf_drv_uart.c \
  $(LIB_NRF)/modules/nrfx/soc/nrfx_atomic.c \
  $(LIB_NRF)/modules/nrfx/drivers/src/nrfx_clock.c \
  $(LIB_NRF)/modules/nrfx/drivers/src/nrfx_gpiote.c \
  $(LIB_NRF)/modules/nrfx/drivers/src/prs/nrfx_prs.c \
  $(LIB_NRF)/modules/nrfx/drivers/src/nrfx_uart.c \
  $(LIB_NRF)/modules/nrfx/drivers/src/nrfx_uarte.c \
  $(LIB_NRF)/components/libraries/bsp/bsp.c \
  $(LIB_NRF)/components/libraries/bsp/bsp_btn_ble.c \
  $(ROOT_PROJ)/main.c \
  $(LIB_NRF)/external/segger_rtt/SEGGER_RTT.c \
  $(LIB_NRF)/external/segger_rtt/SEGGER_RTT_Syscalls_GCC.c \
  $(LIB_NRF)/external/segger_rtt/SEGGER_RTT_printf.c \
  $(LIB_NRF)/components/ble/common/ble_advdata.c \
  $(LIB_NRF)/components/ble/ble_advertising/ble_advertising.c \
  $(LIB_NRF)/components/ble/common/ble_conn_params.c \
  $(LIB_NRF)/components/ble/common/ble_conn_state.c \
  $(LIB_NRF)/components/ble/ble_link_ctx_manager/ble_link_ctx_manager.c \
  $(LIB_NRF)/components/ble/common/ble_srv_common.c \
  $(LIB_NRF)/components/ble/nrf_ble_gatt/nrf_ble_gatt.c \
  $(LIB_NRF)/components/ble/nrf_ble_qwr/nrf_ble_qwr.c \
  $(LIB_NRF)/external/utf_converter/utf.c \
  $(LIB_NRF)/components/ble/ble_services/ble_nus/ble_nus.c \
  $(LIB_NRF)/components/softdevice/common/nrf_sdh.c \
  $(LIB_NRF)/components/softdevice/common/nrf_sdh_ble.c \
  $(LIB_NRF)/components/softdevice/common/nrf_sdh_soc.c \

# Include folders common to all targets
INC_FOLDER += \
  $(LIB_NRF)/components/nfc/ndef/generic/message \
  $(LIB_NRF)/components/nfc/t2t_lib \
  $(LIB_NRF)/components/nfc/t4t_parser/hl_detection_procedure \
  $(LIB_NRF)/components/ble/ble_services/ble_ancs_c \
  $(LIB_NRF)/components/ble/ble_services/ble_ias_c \
  $(LIB_NRF)/components/libraries/pwm \
  $(LIB_NRF)/components/libraries/usbd/class/cdc/acm \
  $(LIB_NRF)/components/libraries/usbd/class/hid/generic \
  $(LIB_NRF)/components/libraries/usbd/class/msc \
  $(LIB_NRF)/components/libraries/usbd/class/hid \
  $(LIB_NRF)/modules/nrfx/hal \
  $(LIB_NRF)/components/nfc/ndef/conn_hand_parser/le_oob_rec_parser \
  $(LIB_NRF)/components/libraries/log \
  $(LIB_NRF)/components/ble/ble_services/ble_gls \
  $(LIB_NRF)/components/libraries/fstorage \
  $(LIB_NRF)/components/nfc/ndef/text \
  $(LIB_NRF)/components/libraries/mutex \
  $(LIB_NRF)/components/libraries/gfx \
  $(LIB_NRF)/components/libraries/bootloader/ble_dfu \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/common \
  $(LIB_NRF)/components/libraries/fifo \
  $(LIB_NRF)/components/boards \
  $(LIB_NRF)/components/nfc/ndef/generic/record \
  $(LIB_NRF)/components/nfc/t4t_parser/cc_file \
  $(LIB_NRF)/components/ble/ble_advertising \
  $(LIB_NRF)/external/utf_converter \
  $(LIB_NRF)/components/ble/ble_services/ble_bas_c \
  $(LIB_NRF)/modules/nrfx/drivers/include \
  $(LIB_NRF)/components/libraries/experimental_task_manager \
  $(LIB_NRF)/components/ble/ble_services/ble_hrs_c \
  $(LIB_NRF)/components/softdevice/s140/headers/nrf52 \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/le_oob_rec \
  $(LIB_NRF)/components/libraries/queue \
  $(LIB_NRF)/components/libraries/pwr_mgmt \
  $(LIB_NRF)/components/ble/ble_dtm \
  $(LIB_NRF)/components/toolchain/cmsis/include \
  $(LIB_NRF)/components/ble/ble_services/ble_rscs_c \
  $(LIB_NRF)/components/ble/common \
  $(LIB_NRF)/components/ble/ble_services/ble_lls \
  $(LIB_NRF)/components/nfc/platform \
  $(LIB_NRF)/components/libraries/bsp \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/ac_rec \
  $(LIB_NRF)/components/ble/ble_services/ble_bas \
  $(LIB_NRF)/components/libraries/mpu \
  $(LIB_NRF)/components/libraries/experimental_section_vars \
  $(LIB_NRF)/components/ble/ble_services/ble_ans_c \
  $(LIB_NRF)/components/libraries/slip \
  $(LIB_NRF)/components/libraries/delay \
  $(LIB_NRF)/components/libraries/csense_drv \
  $(LIB_NRF)/components/libraries/memobj \
  $(LIB_NRF)/components/ble/ble_services/ble_nus_c \
  $(LIB_NRF)/components/softdevice/common \
  $(LIB_NRF)/components/ble/ble_services/ble_ias \
  $(LIB_NRF)/components/libraries/usbd/class/hid/mouse \
  $(LIB_NRF)/components/libraries/low_power_pwm \
  $(LIB_NRF)/components/nfc/ndef/conn_hand_parser/ble_oob_advdata_parser \
  $(LIB_NRF)/components/ble/ble_services/ble_dfu \
  $(LIB_NRF)/external/fprintf \
  $(LIB_NRF)/components/libraries/svc \
  $(LIB_NRF)/components/libraries/atomic \
  $(LIB_NRF)/components \
  $(LIB_NRF)/components/libraries/scheduler \
  $(LIB_NRF)/components/libraries/cli \
  $(LIB_NRF)/components/ble/ble_services/ble_lbs \
  $(LIB_NRF)/components/ble/ble_services/ble_hts \
  $(LIB_NRF)/components/ble/ble_services/ble_cts_c \
  $(LIB_NRF)/components/libraries/crc16 \
  $(LIB_NRF)/components/nfc/t4t_parser/apdu \
  $(LIB_NRF)/components/libraries/util \
  $(ROOT_PROJ)/config \
  $(LIB_NRF)/components/libraries/usbd/class/cdc \
  $(LIB_NRF)/components/libraries/csense \
  $(LIB_NRF)/components/libraries/balloc \
  $(LIB_NRF)/components/libraries/ecc \
  $(LIB_NRF)/components/libraries/hardfault \
  $(LIB_NRF)/components/ble/ble_services/ble_cscs \
  $(LIB_NRF)/components/libraries/uart \
  $(LIB_NRF)/components/libraries/hci \
  $(LIB_NRF)/components/libraries/usbd/class/hid/kbd \
  $(LIB_NRF)/components/libraries/timer \
  $(LIB_NRF)/components/softdevice/s140/headers \
  $(LIB_NRF)/integration/nrfx \
  $(LIB_NRF)/components/nfc/t4t_parser/tlv \
  $(LIB_NRF)/components/libraries/sortlist \
  $(LIB_NRF)/components/libraries/spi_mngr \
  $(LIB_NRF)/components/libraries/led_softblink \
  $(LIB_NRF)/components/nfc/ndef/conn_hand_parser \
  $(LIB_NRF)/components/libraries/sdcard \
  $(LIB_NRF)/components/nfc/ndef/parser/record \
  $(LIB_NRF)/modules/nrfx/mdk \
  $(LIB_NRF)/components/ble/ble_link_ctx_manager \
  $(LIB_NRF)/components/ble/ble_services/ble_nus \
  $(LIB_NRF)/components/libraries/twi_mngr \
  $(LIB_NRF)/components/ble/ble_services/ble_hids \
  $(LIB_NRF)/components/libraries/strerror \
  $(LIB_NRF)/components/libraries/crc32 \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/ble_oob_advdata \
  $(LIB_NRF)/components/nfc/t2t_parser \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/ble_pair_msg \
  $(LIB_NRF)/components/libraries/usbd/class/audio \
  $(LIB_NRF)/components/nfc/t4t_lib \
  $(LIB_NRF)/components/ble/peer_manager \
  $(LIB_NRF)/components/libraries/mem_manager \
  $(LIB_NRF)/components/libraries/ringbuf \
  $(LIB_NRF)/components/ble/ble_services/ble_tps \
  $(LIB_NRF)/components/nfc/ndef/parser/message \
  $(LIB_NRF)/components/ble/ble_services/ble_dis \
  $(LIB_NRF)/components/nfc/ndef/uri \
  $(LIB_NRF)/components/ble/nrf_ble_gatt \
  $(LIB_NRF)/components/ble/nrf_ble_qwr \
  $(LIB_NRF)/components/libraries/gpiote \
  $(LIB_NRF)/components/libraries/button \
  $(LIB_NRF)/modules/nrfx \
  $(LIB_NRF)/components/libraries/twi_sensor \
  $(LIB_NRF)/integration/nrfx/legacy \
  $(LIB_NRF)/components/libraries/usbd \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/ep_oob_rec \
  $(LIB_NRF)/external/segger_rtt \
  $(LIB_NRF)/components/libraries/atomic_fifo \
  $(LIB_NRF)/components/ble/ble_services/ble_lbs_c \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/ble_pair_lib \
  $(LIB_NRF)/components/libraries/crypto \
  $(LIB_NRF)/components/ble/ble_racp \
  $(LIB_NRF)/components/libraries/fds \
  $(LIB_NRF)/components/nfc/ndef/launchapp \
  $(LIB_NRF)/components/libraries/atomic_flags \
  $(LIB_NRF)/components/ble/ble_services/ble_hrs \
  $(LIB_NRF)/components/ble/ble_services/ble_rscs \
  $(LIB_NRF)/components/nfc/ndef/connection_handover/hs_rec \
  $(LIB_NRF)/components/nfc/ndef/conn_hand_parser/ac_rec_parser \
  $(LIB_NRF)/components/libraries/stack_guard \
  $(LIB_NRF)/components/libraries/log/src \


.PHONY: default help

default: $(TARGETS)

help:
	echo "help"

include Makefile.common

$(foreach target, $(TARGETS), $(call define_target,$(target)))


