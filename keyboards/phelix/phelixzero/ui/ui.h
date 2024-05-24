// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "controls.h"
#include "ui_state.h"


bool init_display(void);

void ui_btn_event(wui_btn_t btn);

void update_ui_layer_state(char layer_name_text[]);

void execute_cli_command(char input[]);
