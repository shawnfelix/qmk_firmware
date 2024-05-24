// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "qp_lvgl.h"
#include <features.h>
#include "globals.h"
#include <controls.h>
#include "native.h"
#include "common_types.h"

#define MAX_WUI_OBSERVERS 10
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

//typedef void (*update_func)(struct obser);
/*typedef struct {
    wui_gbl_state_t *wui_gbl_state_ptr;
} wui_observer;

typedef struct {
    wui_observer *observers[MAX_WUI_OBSERVERS];
    uint8_t num_observers;
} wui_subject;
*/

void init_global_ui_state(void);
lv_obj_t *init_screen_home(void);
void register_observer(void);
void unregister_observer(void);
void notify_observers(void);
void maximize_wui(wui_t wui);
void show_menu(void);




