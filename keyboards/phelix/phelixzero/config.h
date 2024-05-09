// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

// ----------------------------
// qmk firmware/hardware configs
// ----------------------------

// SPI driver pin assignments for LCD screen
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP6
#define SPI_MOSI_PIN GP7
#define SPI_MISO_PIN GP11

#define QUANTUM_PAINTER_SUPPORTS_NATIVE_COLORS true
#define QUANTUM_PAINTER_SUPPORTS_256_PALETTE true
#define QUANTUM_PAINTER_DISPLAY_TIMEOUT 120000

#define SPLIT_WPM_ENABLE

#define SERIAL_USART_FULL_DUPLEX // use two wire RX/TX for comms
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_PIO_USEPI01 // use RP2040 specific PIO driver
//#define SERIAL_DEBUG

// ----------------------------
// phelix-zero configs
// ----------------------------

// LCD
#define LCD_RST_PIN GP8
#define LCD_DC_PIN GP4
#define LCD_CS_PIN GP5
#define LCD_SPI_DIVISOR 2



#define LV_LVGL_H_INCLUDE_SIMPLE
