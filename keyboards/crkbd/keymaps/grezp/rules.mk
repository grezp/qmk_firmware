OLED_DRIVER_ENABLE = yes # new OLED driver
EXTRAKEY_ENABLE = yes # audio controls
MOUSEKEY_ENABLE = yes # use mouse keys
BOOTLOADER = atmel-dfu

# If you want to change the display of OLED, you need to change here
SRC +=  logo_reader.c \
				layer.c
