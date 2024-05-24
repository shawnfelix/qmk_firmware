// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later
#include <lv_color.h>

extern lv_color_t THEME_ACCENT;
extern lv_color_t THEME_PRIMARY_BG;
extern lv_color_t THEME_SECONDARY_BG;
extern lv_color_t THEME_TEXT_DARK;
extern lv_color_t THEME_TEXT_LIGHT;
extern lv_color_t THEME_TEXT_LIGHT_GRAY;
// UI action buttons
extern lv_color_t THEME_BUTTON_1;
extern lv_color_t THEME_BUTTON_2;
extern lv_color_t THEME_BUTTON_3;
extern lv_color_t THEME_BUTTON_4;

void init_theme_colors(void) {
    THEME_ACCENT = lv_color_make(59, 186, 156); // mint green
    THEME_PRIMARY_BG = lv_color_make(46, 48, 71); // darkest blue
    THEME_SECONDARY_BG = lv_color_make(67, 69, 92); // second darkest blue
    THEME_TEXT_DARK = lv_color_make(112, 119, 147); // text darkest blue-gray
    THEME_TEXT_LIGHT = lv_color_make(163, 169, 194); // text lightest blue
    THEME_TEXT_LIGHT_GRAY = lv_color_make(180, 182, 191); // text lightest blue

    // UI action buttons
    THEME_BUTTON_1 = lv_color_make(85, 214, 79);
    THEME_BUTTON_2 = lv_color_make(49, 72, 212);
    THEME_BUTTON_3 = lv_color_make(242, 238, 7);
    THEME_BUTTON_4 = lv_color_make(209, 77, 56);

}
