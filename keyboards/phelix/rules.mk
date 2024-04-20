QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes

MCU = RP2040
#SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
CONSOLE_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

VPATH += keyboards/phelix/phelixzero/ui \
		 keyboards/phelix/phelixzero/ui/features

SRC += ui.c \
	   pomodoro.c


# Fix LVGL opcode compile issue on RP2040
# https://github.com/qmk/qmk_firmware/issues/21203
OPT_DEFS = -O2



DYNAMIC_KEYMAP_ENABLE = no # try this later for reconfigurable keyboard without flashing firmware
