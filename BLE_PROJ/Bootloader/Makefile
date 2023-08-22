TARGETS:=bootloader
OUTPUT_PROJ_DIR:=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/obj

ROOT_PROJ := ./
LIB_NRF := ../../
COMMON_DIR := ./../Common

$(OUTPUT_PROJ_DIR)/$(TARGETS).out: \
	LINKER_SCRIPT := secure_bootloader_gcc_nrf52.ld


# Source files common to all targets
SRC_FILES += \
  $(LIB_NRF)/modules/nrfx/mdk/gcc_startup_nrf52840.S \
  $(LIB_NRF)/components/libraries/log/src/nrf_log_frontend.c \
  $(LIB_NRF)/components/libraries/log/src/nrf_log_str_formatter.c \
  $(LIB_NRF)/components/libraries/util/app_error_weak.c \
  $(LIB_NRF)/components/libraries/scheduler/app_scheduler.c \
  $(LIB_NRF)/components/libraries/util/app_util_platform.c \
  $(LIB_NRF)/components/libraries/crc32/crc32.c \
  $(LIB_NRF)/components/libraries/mem_manager/mem_manager.c \
  $(LIB_NRF)/components/libraries/util/nrf_assert.c \
  $(LIB_NRF)/components/libraries/atomic_fifo/nrf_atfifo.c \
  $(LIB_NRF)/components/libraries/atomic/nrf_atomic.c \
  $(LIB_NRF)/components/libraries/balloc/nrf_balloc.c \
  $(LIB_NRF)/external/fprintf/nrf_fprintf.c \
  $(LIB_NRF)/external/fprintf/nrf_fprintf_format.c \
  $(LIB_NRF)/components/libraries/fstorage/nrf_fstorage.c \
  $(LIB_NRF)/components/libraries/fstorage/nrf_fstorage_nvmc.c \
  $(LIB_NRF)/components/libraries/fstorage/nrf_fstorage_sd.c \
  $(LIB_NRF)/components/libraries/memobj/nrf_memobj.c \
  $(LIB_NRF)/components/libraries/queue/nrf_queue.c \
  $(LIB_NRF)/components/libraries/ringbuf/nrf_ringbuf.c \
  $(LIB_NRF)/components/libraries/experimental_section_vars/nrf_section_iter.c \
  $(LIB_NRF)/components/libraries/strerror/nrf_strerror.c \
  $(LIB_NRF)/modules/nrfx/mdk/system_nrf52840.c \
  $(LIB_NRF)/components/libraries/crypto/backend/cc310_bl/cc310_bl_backend_ecc.c \
  $(LIB_NRF)/components/libraries/crypto/backend/cc310_bl/cc310_bl_backend_ecdsa.c \
  $(LIB_NRF)/components/libraries/crypto/backend/cc310_bl/cc310_bl_backend_hash.c \
  $(LIB_NRF)/components/libraries/crypto/backend/cc310_bl/cc310_bl_backend_init.c \
  $(LIB_NRF)/components/libraries/crypto/backend/cc310_bl/cc310_bl_backend_shared.c \
  $(LIB_NRF)/components/boards/boards.c \
  $(LIB_NRF)/components/softdevice/common/nrf_sdh.c \
  $(LIB_NRF)/components/softdevice/common/nrf_sdh_ble.c \
  $(LIB_NRF)/components/softdevice/common/nrf_sdh_soc.c \
  $(LIB_NRF)/modules/nrfx/hal/nrf_nvmc.c \
  $(LIB_NRF)/modules/nrfx/soc/nrfx_atomic.c \
  $(LIB_NRF)/components/libraries/crypto/nrf_crypto_ecc.c \
  $(LIB_NRF)/components/libraries/crypto/nrf_crypto_ecdsa.c \
  $(LIB_NRF)/components/libraries/crypto/nrf_crypto_hash.c \
  $(LIB_NRF)/components/libraries/crypto/nrf_crypto_init.c \
  $(LIB_NRF)/components/libraries/crypto/nrf_crypto_shared.c \
  $(ROOT_PROJ)/dfu_public_key.c \
  $(ROOT_PROJ)/main.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_svci.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_svci_handler.c \
  $(LIB_NRF)/components/libraries/svc/nrf_svc_handler.c \
  $(LIB_NRF)/components/ble/common/ble_srv_common.c \
  $(LIB_NRF)/components/libraries/bootloader/nrf_bootloader.c \
  $(LIB_NRF)/components/libraries/bootloader/nrf_bootloader_app_start.c \
  $(LIB_NRF)/components/libraries/bootloader/nrf_bootloader_app_start_final.c \
  $(LIB_NRF)/components/libraries/bootloader/nrf_bootloader_dfu_timers.c \
  $(LIB_NRF)/components/libraries/bootloader/nrf_bootloader_fw_activation.c \
  $(LIB_NRF)/components/libraries/bootloader/nrf_bootloader_info.c \
  $(LIB_NRF)/components/libraries/bootloader/nrf_bootloader_wdt.c \
  $(LIB_NRF)/external/nano-pb/pb_common.c \
  $(LIB_NRF)/external/nano-pb/pb_decode.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/dfu-cc.pb.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu.c \
  $(LIB_NRF)/components/libraries/bootloader/ble_dfu/nrf_dfu_ble.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_flash.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_handling_error.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_mbr.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_req_handler.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_settings.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_settings_svci.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_transport.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_utils.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_validation.c \
  $(LIB_NRF)/components/libraries/bootloader/dfu/nrf_dfu_ver_validation.c \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon/oberon_backend_chacha_poly_aead.c \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon/oberon_backend_ecc.c \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon/oberon_backend_ecdh.c \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon/oberon_backend_ecdsa.c \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon/oberon_backend_eddsa.c \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon/oberon_backend_hash.c \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon/oberon_backend_hmac.c \

# Include folders common to all targets
INC_FOLDERS += \
  $(LIB_NRF)/components/libraries/crypto/backend/micro_ecc \
  $(LIB_NRF)/components/libraries/memobj \
  $(LIB_NRF)/components/softdevice/s140/headers/nrf52 \
  $(LIB_NRF)/components/libraries/crc32 \
  $(LIB_NRF)/components/libraries/experimental_section_vars \
  $(LIB_NRF)/components/libraries/mem_manager \
  $(LIB_NRF)/components/libraries/fstorage \
  $(LIB_NRF)/components/libraries/util \
  $(LIB_NRF)/modules/nrfx \
  $(LIB_NRF)/external/nrf_oberon/include \
  $(LIB_NRF)/components/libraries/crypto/backend/oberon \
  $(LIB_NRF)/components/libraries/crypto/backend/cifra \
  $(LIB_NRF)/components/libraries/atomic \
  $(LIB_NRF)/integration/nrfx \
  $(LIB_NRF)/components/libraries/crypto/backend/cc310_bl \
  $(LIB_NRF)/external/nrf_cc310/include \
  $(LIB_NRF)/components/libraries/log/src \
  $(LIB_NRF)/components/libraries/bootloader/dfu \
  $(LIB_NRF)/components/ble/common \
  $(LIB_NRF)/components/libraries/delay \
  $(LIB_NRF)/components/libraries/svc \
  $(LIB_NRF)/components/libraries/stack_info \
  $(LIB_NRF)/components/libraries/crypto/backend/nrf_hw \
  $(LIB_NRF)/components/libraries/log \
  $(LIB_NRF)/external/nrf_oberon \
  $(LIB_NRF)/components/libraries/strerror \
  $(LIB_NRF)/components/libraries/crypto/backend/mbedtls \
  $(LIB_NRF)/components/boards \
  $(LIB_NRF)/components/libraries/crypto/backend/cc310 \
  $(LIB_NRF)/components/libraries/bootloader \
  $(LIB_NRF)/components/softdevice/s140/headers \
  $(LIB_NRF)/components/libraries/crypto \
  $(ROOT_PROJ)/config \
  $(LIB_NRF)/components/libraries/crypto/backend/optiga \
  $(LIB_NRF)/components/libraries/scheduler \
  $(LIB_NRF)/external/nrf_cc310_bl/include \
  $(LIB_NRF)/modules/nrfx/hal \
  $(LIB_NRF)/external/fprintf \
  $(LIB_NRF)/components/toolchain/cmsis/include \
  $(LIB_NRF)/components/libraries/balloc \
  $(LIB_NRF)/components/libraries/atomic_fifo \
  $(ROOT_PROJ) \
  $(LIB_NRF)/components/libraries/crypto/backend/nrf_sw \
  $(LIB_NRF)/modules/nrfx/mdk \
  $(LIB_NRF)/components/libraries/bootloader/ble_dfu \
  $(LIB_NRF)/components/softdevice/common \
  $(LIB_NRF)/external/nano-pb \
  $(LIB_NRF)/components/libraries/queue \
  $(LIB_NRF)/components/libraries/mutex \
  $(LIB_NRF)/components/libraries/ringbuf \

LIB_FILES += \
  $(LIB_NRF)/external/nrf_oberon/lib/cortex-m4/hard-float/liboberon_3.0.8.a \
  $(LIB_NRF)/external/nrf_cc310_bl/lib/cortex-m4/hard-float/libnrf_cc310_bl_0.9.13.a \


# Optimization flagsF
OPT = -Os -g3
# Uncomment the line below to enable link time optimization
#OPT += -flto

# C flags common to all targets
CCFLAGS += $(OPT)
CCFLAGS += -DBLE_STACK_SUPPORT_REQD
CCFLAGS += -DBOARD_PCA10056
CCFLAGS += -DCONFIG_GPIO_AS_PINRESET
CCFLAGS += -DFLOAT_ABI_HARD
CCFLAGS += -DNRF52840_XXAA
CCFLAGS += -DNRF_DFU_SETTINGS_VERSION=2
CCFLAGS += -DNRF_DFU_SVCI_ENABLED
CCFLAGS += -DNRF_SD_BLE_API_VERSION=7
CCFLAGS += -DS140
CCFLAGS += -DSOFTDEVICE_PRESENT
CCFLAGS += -DSVC_INTERFACE_CALL_AS_NORMAL_FUNCTION
CCFLAGS += -mcpu=cortex-m4
CCFLAGS += -mthumb -mabi=aapcs
CCFLAGS += -Wall -Werror
CCFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# keep every function in a separate section, this allows linker to discard unused ones
CCFLAGS += -ffunction-sections -fdata-sections -fno-strict-aliasing
CCFLAGS += -fno-builtin -fshort-enums

# C++ flags common to all targets
CXXFLAGS += $(OPT)
# Assembler flags common to all targets
ASMFLAGS += -g3
ASMFLAGS += -mcpu=cortex-m4
ASMFLAGS += -mthumb -mabi=aapcs
ASMFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
ASMFLAGS += -DBLE_STACK_SUPPORT_REQD
ASMFLAGS += -DBOARD_PCA10056
ASMFLAGS += -DCONFIG_GPIO_AS_PINRESET
ASMFLAGS += -DFLOAT_ABI_HARD
ASMFLAGS += -DNRF52840_XXAA
ASMFLAGS += -DNRF_DFU_SETTINGS_VERSION=2
ASMFLAGS += -DNRF_DFU_SVCI_ENABLED
ASMFLAGS += -DNRF_SD_BLE_API_VERSION=7
ASMFLAGS += -DS140
ASMFLAGS += -DSOFTDEVICE_PRESENT
ASMFLAGS += -DSVC_INTERFACE_CALL_AS_NORMAL_FUNCTION

# Linker flags
LDFLAGS += $(OPT)
LDFLAGS += -mthumb -mabi=aapcs -L$(LIB_NRF)/modules/nrfx/mdk -T$(LINKER_SCRIPT)
LDFLAGS += -mcpu=cortex-m4
LDFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16
# let linker dump unused sections
LDFLAGS += -Wl,--gc-sections
# use newlib in nano version
LDFLAGS += --specs=nano.specs

$(TARGETS): CFLAGS += -D__HEAP_SIZE=0
$(TARGETS): ASMFLAGS += -D__HEAP_SIZE=0

LIB_FILES += -lc -lnosys -lm

.PHONY:	default help


default: $(TARGETS)



help:
	@echo "help"


include $(COMMON_DIR)/Makefile.common

$(foreach target,$(TARGETS),$(call target_define,$(target)))


