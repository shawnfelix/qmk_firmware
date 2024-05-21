// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include <globals.h>
#include "scroll_selector.h"
#include "ui_cli.h"
#include "native_defs.h"

extern uint8_t current_scroll_pos;

void init_native_ui_elements(void) {
    init_ui_cli(scr_home);
    init_ui_widget_selector(scr_home, NumberOfWuiTypes);
    gbl_ui_state.widget_selector_mode_active = false;
}

void toggle_widget_selector(void) {
    if (gbl_ui_state.widget_selector_mode_active == true) {
        println("toggle");
        hide_widget_selector();
        gbl_ui_state.widget_selector_mode_active = false;
    } else {
        show_widget_selector();
        gbl_ui_state.widget_selector_mode_active = true;
    }
}

void toggle_native_elements_visibility(void) {
    println("toggling native menu");
    toggle_widget_selector();
}
void native_btn_event_router(wui_btn_t btn) {
    uprintf("native_btn_event_router(): %d\n", btn);
    if (gbl_ui_state.widget_selector_mode_active == true) {
        switch(ui_btn_event_scroll_selector(btn)) {
            case N_CLOSE: toggle_native_elements_visibility();
            break;
            case N_KEEP_OPEN:
            default:
            break;
        }
    }
}
