// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

typedef enum {
    B1, /* OK, Yes, or Continue button in the UI. Affirmative ui event */
    B2, /* Up or Alt Modifier 1 button in the UI */
    B3, /* Down or Alt M button in the UI */
    B4, /* Cancel, Back, or No button in the UI. Negative action */
    B5,
    ENC_CW, /* Encoder UP/RIGHT - clockwise */
    ENC_CCW,/* Encoder DOWN/LEFT - counter-clockwise */
    ENC_BTN, /* Encoder switch button */
    WUI_BTN_COUNT
} wui_btn_t;
