// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include_next <halconf.h>

#undef HAL_USE_SPI
#define HAL_USE_SPI TRUE

#undef SPI_USE_WAIT
#define SPI_USE_WAIT TRUE

#undef SPI_SELECT_MODE
#define SPI_SELECT_MODE SPI_SELECT_MODE_PAD
