QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

MCU = RP2040
#SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

#for debug mode
CONSOLE_ENABLE = yes
DEBUG_ENABLE = yes

DEFERRED_EXEC_ENABLE = yes

ENCODER_ENABLE = yes
#ENCODER_MAP_ENABLE = yes

EXTRAKEY_ENABLE = yes #enable media controls

VPATH += keyboards/phelix/phelixzero/ui \
		 keyboards/phelix/phelixzero/ui/features \
		 keyboards/phelix/phelixzero/fonts

SRC += ui.c \
	   pomodoro.c \
	   ui_cli.c \
	   fonts/hooskai_font_36.c


# Fix LVGL opcode compile issue on RP2040
# https://github.com/qmk/qmk_firmware/issues/21203
OPT_DEFS = -O2



DYNAMIC_KEYMAP_ENABLE = no # try this later for reconfigurable keyboard without flashing firmware
