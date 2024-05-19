// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "globals.h"
#include "ui_state.h"
#include "print.h"
#include "features/pomodoro.h"
#include "features/pk_wpm.h"
#include "controls.h"
#include "native/native.h"

wui_gbl_state_t wui_gbl_state[NumberOfWuiTypes];
gbl_ui_state_t gbl_ui_state;
lv_obj_t *scr_home;

const char* enumToString(wui_t wui_enum) {
    switch (wui_enum) {
        case WUI_POMODORO:    return "Pomodoro";
        case WUI_WPM:         return "WPM";
        default:              return "Invalid"; // Handle invalid enum value
    }
}
void register_wuis(void) {
    //todo come up with a better solution for adding new wuis
    // doing this manually sucks
    wui_gbl_state[WUI_POMODORO].fun_btn_event = &do_btn_action_pomodoro;
    wui_gbl_state[WUI_WPM].fun_btn_event = &do_btn_action_pomodoro;

}

void init_all_wuis(void) {
    wui_gbl_state[WUI_POMODORO].wui_init_state = NOT_INIT;
    init_widget_pomodoro();
    register_wuis();
}

void init_global_ui_state(void) {
    gbl_ui_state = (gbl_ui_state_t) { .active_layer_text="Default", NULL, false, ""};
}



// TODO observer pattern
void set_wui_window_state(wui_t wui_enum, window_state_t state) {
    wui_gbl_state[wui_enum].window_state = state;
    if (wui_enum == WUI_POMODORO) {
        switch(state) {
            case MAX:
                println("MAX ---");
                ui_show_pomodoro();
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
void set_gbl_wui(wui_t wui_enum, window_state_t init_state, window_state_t ui_state) {
    set_wui_window_state(wui_enum, ui_state);
}
void minimize_wui(wui_t wui_enum) {

}

/* routes ui input to the active feature */
//TODO probably move this to its own module
void btn_event_router(wui_btn_t btn) {
    if (btn == B5) {
        toggle_native_elements_visibility();
        return;
    }

    // TODO replace this check with a global UI mode (native vs wui/child)
    if (gbl_ui_state.widget_selector_mode_active == true) {
        // if the widget selector is open
        println("global router with widget selector mode");
        native_btn_event_router(btn);
    } else {
        // TODO wui btn event router
        wui_gbl_state[gbl_ui_state.curr_active_wui].fun_btn_event(btn);
    }
}
