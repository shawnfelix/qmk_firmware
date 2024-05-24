// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include "native_defs.h"
#include "controls.h"

typedef struct {
    bool placeholder; // TODO
} scroll_selector_t;

void init_ui_widget_selector(lv_obj_t * screen, uint32_t number_of_init_wuis);

void show_widget_selector(void);
void hide_widget_selector(void);

native_cb_action_t ui_btn_event_scroll_selector(wui_btn_t btn);
