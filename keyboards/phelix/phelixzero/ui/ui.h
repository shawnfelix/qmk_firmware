// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#include "features/features.h"

bool init_display(void);

bool ui_btn_event_one(void);
bool ui_btn_event_two(void);
bool ui_btn_event_three(void);
bool ui_btn_event_four(void);
void ui_encoder_switch(void);
void ui_encoder_up(void);
void ui_encoder_down(void);

void update_ui_layer_state(char layer_name_text[]);

void execute_cli_command(char input[]);
