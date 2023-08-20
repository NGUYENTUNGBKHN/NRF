TARGETS:=bootloader
OUTPUT_PROJ_DIR:=_build
OUTPUT_OBJS_DIR=$(OUTPUT_PROJ_DIR)/obj


.PHONY:	default help


default: $(TARGETS)



help:
	@echo "help"


include Makefile.common

$(foreach target,$(TARGETS),$(call target_define,$(target)))


