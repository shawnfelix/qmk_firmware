
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
