#pragma once


#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MOSI_PIN GP7
#define SPI_MISO_PIN GP11

#define LCD_RST_PIN GP8
#define LCD_DC_PIN GP4
#define LCD_CS_PIN GP5

#define LCD_SPI_DIVISOR 8

#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE true
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 120000

#define SPLIT_WPM_ENABLE
#define SPLIT_USB_DETECT
#define MASTER_LEFT
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USEPI01
//#define SERIAL_DEBUG

#define MATRIX_COLS 8
#define MATRIX_ROWS 12
//#define MATRIX_ROW_PINS       { GP29, GP28, GP27, GP26, GP22 }
//#define MATRIX_COL_PINS       { GP12, GP13, GP14, GP15, GP16, GP21, GP23, GP10 }
//#define MATRIX_COL_PINS_RIGHT { GP21, GP23, GP20, GP22, GP26, GP27, GP28, GP29 }
//#define MATRIX_ROW_PINS_RIGHT { GP12, GP13, GP14, GP15, GP16, GP9 }