// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "globals.h"
#include "ui_state.h"
#include "features/pomodoro.h"
#include "features/pk_wpm.h"
#include "controls.h"
#include "native/native.h"
#include "common_types.h"
#include "features/features.h"


const char* enumToString(wui_t wui_enum) {
    switch (wui_enum) {
        case WUI_POMODORO:    return "Pomodoro";
        case WUI_WPM:         return "WPM";
        default:              return "Invalid"; // Handle invalid enum value
    }
}

void set_gbl_wui(wui_t wui_enum, window_state_t init_state, window_state_t ui_state) {
    set_wui_window_state(wui_enum, ui_state);
}

