// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "ui_state.h"
#include "features/features.h"

// wui_gbl_state_t stores the state of all WUI widgets
extern wui_gbl_state_t wui_gbl_state[NumberOfWuiTypes];
extern gbl_ui_state_t gbl_ui_state;
extern lv_obj_t *scr_home;

const char* enumToString(wui_t wui_enum);

void init_global_ui_state(void);

void set_wui_window_state(wui_t wui_enum, window_state_t state);

void set_gbl_wui(wui_t wui_enum, window_state_t init_state, window_state_t ui_state);

void btn_event_router(wui_btn_t btn);

void init_all_wuis(void);
