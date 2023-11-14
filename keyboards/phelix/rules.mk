QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi
QUANTUM_PAINTER_LVGL_INTEGRATION = yes
SRC += fonts/helvetica-default.qff.c

MCU = RP2040
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor
CONSOLE_ENABLE = yes
DEFERRED_EXEC_ENABLE = yes

# Fix LVGL opcode compile issue on RP2040 
# https://github.com/qmk/qmk_firmware/issues/21203
OPT_DEFS = -O2