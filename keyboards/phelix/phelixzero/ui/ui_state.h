// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

// enum of the WUI widget UI states
typedef enum { MAX, MIN, HIDDEN } wui_ui_state_t;
/*
enum of all WUI widget program states
state transitions: NOT_INIT -> INIT -> IDLE <-> RUNNING
*/
typedef enum { NOT_INIT, INIT, IDLE, RUNNING } wui_init_state_t;

typedef struct {
    char active_layer_text[20];
    lv_obj_t *active_layer_obj;
    bool cli_mode_active;
    char cli_buffer[100];
    lv_obj_t *cli_ta;
} gbl_ui_state_t;

typedef enum {
    POMO_RUNNING,
    POMO_PAUSED,
    POMO_STOPPED
} pomo_state_t;

typedef struct {
    uint32_t pomo_timer;
    pomo_state_t pomo_state;
    lv_obj_t *pomo_label;
    deferred_token token;
} pomo_wui_state_t;

typedef struct {
    uint8_t last_wpm;
    lv_obj_t *wpm_label;
    deferred_token token;
} wpm_wui_state_t;

// wrapper common type for the state of a WUI widget,
typedef struct {
    wui_init_state_t wui_init_state;
    wui_ui_state_t wui_ui_state;
    union {
        // add other widgets here
        pomo_wui_state_t pomo_wui_state;
        wpm_wui_state_t wpm_wui_state;
    };
} wui_gbl_state_t;

// enum of all WUI widgets that are developed for phelix keyboards
typedef enum {
    WUI_POMODORO,
    WUI_WPM,
    NumberOfWuiTypes
} wui_t;
