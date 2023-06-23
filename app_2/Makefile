TARGETS := app_2
OUTPUT_PROJ_DIR := _build
OUTPUT_OBJS_DIR := $(OUTPUT_PROJ_DIR)/objs/

ROOT_PROJ := ./
LIB_NRF := ../

SRC_FILES +=\
	$(ROOT_PROJ)/Application/main.c\


INC_FOLDER +=\


.PHONY: default help


default: $(TARGETS)


include Makefile.common

$(foreach target, $(TARGETS), $(call define_target, $(target)))

help:
	echo "help"





