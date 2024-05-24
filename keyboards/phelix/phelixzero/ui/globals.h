// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "ui_state.h"
#include "native/native.h"
#include "common_types.h"
#include "features.h"

extern wui_gbl_state_t wui_gbl_state[NumberOfWuiTypes];
extern native_t n_gbl_state[NumberOfNativeComponents];
extern gbl_ui_state_t gbl_ui_state;

const char* enumToString(wui_t wui_enum);

void set_wui_window_state(wui_t wui_enum, window_state_t state);

void set_gbl_wui(wui_t wui_enum, window_state_t init_state, window_state_t ui_state);


void init_all_wuis(void);
