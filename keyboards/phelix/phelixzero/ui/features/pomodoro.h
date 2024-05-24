// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include "controls.h"
#include "qp_lvgl.h"

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

void do_btn_action_pomodoro(wui_btn_t btn);
void start_pomodoro(void);
void reset_pomodoro(void);
void pause_pomodoro(void);

void init_widget_pomodoro(void);

void ui_show_pomodoro(void);
void ui_hide_pomodoro(void);
