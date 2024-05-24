// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "globals.h"
#include "controls.h"
#include "ui_state.h"

/* routes ui input to the active feature */
void route_btn_event(wui_btn_t btn) {
    if (btn == B4 || btn == B5) {
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
