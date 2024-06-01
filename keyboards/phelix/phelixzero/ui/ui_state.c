// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "globals.h"
#include "lvgl.h"
#include "common_types.h"

static wui_gbl_state_t wui_gbl_state[NumberOfWuiTypes];
static gbl_ui_state_t gbl_ui_state;
static lv_obj_t *scr_home;

void register_wuis(void) {
    //todo come up with a better solution for adding new wuis
    // doing this manually sucks
    wui_gbl_state[WUI_POMODORO].fun_btn_event = &do_btn_action_pomodoro;
    wui_gbl_state[WUI_WPM].fun_btn_event = &do_btn_action_pomodoro;
}
void init_all_wuis(void) {
    wui_gbl_state[WUI_POMODORO].wui_init_state = NOT_INIT;
    init_widget_pomodoro(scr_home);
    register_wuis();
}

lv_obj_t *get_home_scr(void) {
    return scr_home;
}

/*wui_gbl_state_t *get_wui_gbl_states(void) {
    return &wui_gbl_state;
}*/
wui_gbl_state_t *get_wui(wui_t wui) {
    return &wui_gbl_state[wui];
}
wui_gbl_state_t *get_active_wui(void) {
    return &wui_gbl_state[gbl_ui_state.curr_active_wui];
}
gbl_ui_state_t *get_gbl_state(void) {
    return &gbl_ui_state;
}
wui_t get_active_wui_type(void) {
    return gbl_ui_state.curr_active_wui;
}
// TODO observer pattern
void set_wui_window_state(wui_t wui_enum, window_state_t state) {
    wui_gbl_state[wui_enum].window_state = state;
    if (wui_enum == WUI_POMODORO) {
        switch(state) {
            case MAX:
                println("MAX ---");
                ui_show_pomodoro();
                gbl_ui_state.active_wui = WUI_POMODORO;
                ////lv_obj_add_flag(wui_gbl_state[wui_enum].pomo_wui_state.pomo_label,LV_OBJ_FLAG_HIDDEN);
                break;
            case HIDDEN:
                println("HIDDEN ---");
                ui_hide_pomodoro();
                //lv_obj_clear_flag(wui_gbl_state[wui_enum].pomo_wui_state.pomo_label,LV_OBJ_FLAG_HIDDEN);
                break;
            default:
                break;
        }
    }
}

// add global UI state functions here
void init_global_ui_state(void) {
    gbl_ui_state = (gbl_ui_state_t) {
        .active_layer_text="Default",
        .active_layer_obj=NULL,
    };
}

lv_obj_t *init_screen_home(void) {
    scr_home = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr_home, THEME_PRIMARY_BG, LV_PART_MAIN);

    init_native_ui_elements(scr_home);
    init_all_wuis();

    lv_scr_load_anim(scr_home, LV_SCR_LOAD_ANIM_FADE_ON, 500, 3000, false);
    return scr_home;
}

void load_home_screen(void) {
    
}

void register_observer(void) {

}

void unregister_observer(void) {

}

void notify_observers(void) {

}

void maximize_wui(wui_t wui) {

}
void minimize_wui(wui_t wui) {
    set_wui_window_state(wui, HIDDEN);
}
void minimize_active_wui(void) {
    minimize_wui(get_active_wui_type());

}

void get_active_component(void) {

}
