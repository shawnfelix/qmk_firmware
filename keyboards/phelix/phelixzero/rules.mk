QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

MCU = RP2040
SERIAL_DRIVER = vendor

#for debug mode
CONSOLE_ENABLE = yes
DEBUG_ENABLE = yes

DEFERRED_EXEC_ENABLE = yes
WPM_ENABLE = yes

EXTRAKEY_ENABLE = yes #enable media controls

VPATH += keyboards/phelix/phelixzero/ui \
		 keyboards/phelix/phelixzero/ui/features

SRC += ui.c \
	   globals.c \
	   pomodoro.c \
	   pk_wpm.c \
	   ui_cli.c \
       ui/fonts/hooskai_font_36.c


# Fix LVGL opcode compile issue on RP2040
# https://github.com/qmk/qmk_firmware/issues/21203
OPT_DEFS = -O2



DYNAMIC_KEYMAP_ENABLE = no # try this later for reconfigurable keyboard without flashing firmware
