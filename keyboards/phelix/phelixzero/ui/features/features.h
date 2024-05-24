// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "pomodoro.h"
#include "pk_wpm.h"
#include "controls.h"
#include "common_types.h"

// wrapper common type for the state of a WUI widget,
typedef struct {
    wui_init_state_t wui_init_state;
    window_state_t window_state;
    void (*fun_btn_event) (wui_btn_t btn); // event router sends button events using this func
    void (*fun_window_event) (wui_init_state_t wui_init_state); // send window events min/max/hide etc
    union {
        // add other widgets here
        pomo_wui_state_t pomo_wui_state;
        wpm_wui_state_t wpm_wui_state;
    };
} wui_gbl_state_t;
