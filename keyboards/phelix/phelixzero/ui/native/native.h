// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

#include "scroll_selector.h"
#include "ui_cli.h"
#include "theme.h"
#include <controls.h>

typedef struct {
    // add common functions for native events
    union {
        scroll_selector_t scroll_selector;
        ui_cli_t ui_cli;
    };
} native_state_t;

void init_native_ui_elements(void);

void toggle_native_elements_visibility(void);
void native_btn_event_router(wui_btn_t btn);
