// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

typedef struct {
    uint8_t last_wpm;
    lv_obj_t *wpm_label;
    deferred_token token;
} wpm_wui_state_t;

void init_widget_wpm(lv_obj_t *screen, lv_color_t text_color);

void ui_btn_action_wpm(wui_btn_t btn);
