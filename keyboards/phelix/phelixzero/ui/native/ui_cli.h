// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include "features.h"

typedef struct {
    bool placeholder; // TODO
} ui_cli_t;

typedef enum {
    CLI_OPEN,
    CLI_CLOSE,
    CLI_SUBMIT,
    CLI_CLEAR,
    CLI_BSPC,
    CLI_LEFT,
    CLI_RIGHT
} cli_action_t;

// cli UI action handler
void ui_cli_do_action(cli_action_t action);

void init_ui_cli(lv_obj_t *lv_obj);

