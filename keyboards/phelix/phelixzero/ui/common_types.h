
// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

typedef enum {
    WUI_POMODORO,
    WUI_WPM,
    NumberOfWuiTypes
} wui_t;

typedef enum {
    N_WIDGET_SELECTOR,
    N_UI_CLI,
    N_SETTINGS,
    NumberOfNativeComponents
} native_t;

// enum of the WUI widget UI states
typedef enum { MAX, MIN, HIDDEN } window_state_t;
/*
enum of all WUI widget program states
state transitions: NOT_INIT -> INIT -> IDLE <-> RUNNING
*/
typedef enum { NOT_INIT, INIT, IDLE, RUNNING } wui_init_state_t;

typedef struct {
    char active_layer_text[20];
    lv_obj_t *active_layer_obj;
    char cli_buffer[100];
    bool cli_mode_active;
    bool widget_selector_mode_active;
    wui_t curr_active_wui;
    lv_obj_t *cli_ta;

    bool native_comp_active;
    bool wui_comp_active;
    wui_t active_wui; // for btn routing
    native_t active_native; // for btn routing
} gbl_ui_state_t;