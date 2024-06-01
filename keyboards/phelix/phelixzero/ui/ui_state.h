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


wui_gbl_state_t *get_wui(wui_t wui);
wui_gbl_state_t *get_active_wui(void);
gbl_ui_state_t *get_gbl_state(void);
wui_t get_active_wui_type(void);

void register_observer(void);
void unregister_observer(void);
void notify_observers(void);
void maximize_wui(wui_t wui);
void minimize_wui(wui_t wui);
void minimize_active_wui(void);
void show_menu(void);




