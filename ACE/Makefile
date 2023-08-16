

.PHONY: default app bl bl_clean flash_bl flash_app

default: app bl

bl:
	cd BL && make

bl_clean:
	cd BL && make clean

app:
	cd APP && make

flash_bl:
	cd BL && make flash

flash_app:
	cd APP && make flash

