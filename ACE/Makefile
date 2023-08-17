DEBUG?=0

ifeq ($(DEBUG),1)
NO_ECHO:= 
else
NO_ECHO:=@
endif

.PHONY: default app bl bl_clean flash_bl flash_app app_clean


# BUILD PROJECT

default: app bl

bl:
	$(NO_ECHO)echo "build bootloader"
	$(NO_ECHO) cd BL && make

app:
	$(NO_ECHO)echo "build application"
	$(NO_ECHO) cd APP && make

# CLEAN PROJECT

clean: bl_clean app_clean

bl_clean:
	$(NO_ECHO) cd BL && make clean

app_clean:
	$(NO_ECHO) cd APP && make clean

# FLASH CODE

flash_bl:
	$(NO_ECHO)echo "flash bootloader"
	$(NO_ECHO) cd BL && make flash

flash_app:
	$(NO_ECHO)echo "flash application"
	$(NO_ECHO) cd APP && make flash

flash:	flash_bl flash_app
