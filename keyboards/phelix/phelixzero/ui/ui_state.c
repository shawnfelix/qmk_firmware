// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "globals.h"
#include "lvgl.h"

static wui_gbl_state_t wui_gbl_state[NumberOfWuiTypes];
static gbl_ui_state_t gbl_ui_state;
static lv_obj_t *scr_home;

lv_obj_t *get_home_scr(void) {
    return scr_home;
}

// add global UI state functions here
void init_global_ui_state(void) {
    gbl_ui_state = (gbl_ui_state_t) {
        .active_layer_text="Default",
        NULL,
        false,
        false,
        NULL,
        NULL,
        false,
        false,
        NULL,
        NULL
    };
}

lv_obj_t *init_screen_home(void) {
    scr_home = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr_home, THEME_PRIMARY_BG, LV_PART_MAIN);

    init_clock(scr_home, 3500);
    init_ui_action_button_bar(scr_home);
    init_ui_layer_state(scr_home);
    init_native_ui_elements();
    init_all_wuis();

    lv_scr_load_anim(scr_home, LV_SCR_LOAD_ANIM_FADE_ON, 500, 3000, false);
    return scr_home;
}

void register_observer(void) {

}

void unregister_observer(void) {

}

void notify_observers(void) {

}

void maximize_wui(wui_t wui) {

}

void get_active_component(void) {

}
