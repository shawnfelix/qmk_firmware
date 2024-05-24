// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include <globals.h>
#include "scroll_selector.h"
#include "ui_cli.h"
#include "native_defs.h"

extern uint8_t current_scroll_pos;

void update_layer_state_text(void) {
    if (gbl_ui_state.active_layer_obj != NULL) {
        lv_label_set_text_fmt(gbl_ui_state.active_layer_obj, "Layer: %s", gbl_ui_state.active_layer_text);
    }
}
void update_ui_layer_state(char layer_name_text[]) {
    strcpy(gbl_ui_state.active_layer_text, layer_name_text);
    update_layer_state_text();
}
void init_ui_layer_state(lv_obj_t *screen) {
    gbl_ui_state.active_layer_obj = lv_label_create(screen);
    lv_obj_set_style_text_color(gbl_ui_state.active_layer_obj, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(gbl_ui_state.active_layer_obj, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_align(gbl_ui_state.active_layer_obj, LV_ALIGN_TOP_LEFT, 10, 5);
    update_layer_state_text();
}

void init_native_ui_elements(lv_obj_t *screen) {
    init_ui_cli(screen);
    init_ui_widget_selector(screen, NumberOfWuiTypes);
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

void init_ui_action_button_bar(lv_obj_t *scr) {
    lv_obj_t *action_button_bar = lv_obj_create(scr);
    lv_obj_set_size(action_button_bar, 280, 30);
    lv_obj_align(action_button_bar, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_scrollbar_mode(action_button_bar , LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(action_button_bar, THEME_SECONDARY_BG, 0);
    lv_obj_set_style_border_color(action_button_bar, THEME_TEXT_LIGHT, 0);

    lv_obj_t *led_one = lv_obj_create(action_button_bar);
    lv_obj_set_scrollbar_mode(led_one , LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(led_one , 20, 20);
    lv_obj_set_style_bg_color(led_one , THEME_BUTTON_1, 0);
    lv_obj_set_style_radius(led_one , LV_RADIUS_CIRCLE, 0);
    lv_obj_t *btn_one_label = lv_label_create(action_button_bar);
    lv_obj_set_style_text_color(btn_one_label, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_one_label, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_align(led_one, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_align(btn_one_label, LV_ALIGN_LEFT_MID, 25, 0);

    lv_obj_t *led_two = lv_obj_create(action_button_bar);
    lv_obj_set_scrollbar_mode(led_two , LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(led_two , 20, 20);
    lv_obj_set_style_bg_color(led_two , THEME_BUTTON_2, 0);
    lv_obj_set_style_radius(led_two , LV_RADIUS_CIRCLE, 0);
    lv_obj_t *btn_two_label = lv_label_create(action_button_bar);
    lv_obj_set_style_text_color(btn_two_label, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_two_label, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_align(led_two, LV_ALIGN_LEFT_MID, 60, 0);
    lv_obj_align(btn_two_label, LV_ALIGN_LEFT_MID, 85, 0);

    lv_obj_t *led_three = lv_obj_create(action_button_bar);
    lv_obj_set_scrollbar_mode(led_three , LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(led_three, 20, 20);
    lv_obj_set_style_bg_color(led_three, THEME_BUTTON_3, 0);
    lv_obj_set_style_radius(led_three, LV_RADIUS_CIRCLE, 0);
    lv_obj_t *btn_three_label = lv_label_create(action_button_bar);
    lv_obj_set_style_text_color(btn_three_label, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_three_label, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_align(led_three, LV_ALIGN_LEFT_MID, 120, 0);
    lv_obj_align(btn_three_label, LV_ALIGN_LEFT_MID, 145, 0);

    lv_obj_t *led_four = lv_obj_create(action_button_bar);
    lv_obj_set_scrollbar_mode(led_three , LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_size(led_four, 20, 20);
    lv_obj_set_style_bg_color(led_four, THEME_BUTTON_4, 0);
    lv_obj_set_style_radius(led_four, LV_RADIUS_CIRCLE, 0);
    lv_obj_t *btn_four_label = lv_label_create(action_button_bar);
    lv_obj_set_style_text_color(btn_four_label, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(btn_four_label, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_align(led_four, LV_ALIGN_LEFT_MID, 180, 0);
    lv_obj_align(btn_four_label, LV_ALIGN_LEFT_MID, 205, 0);

}

void init_clock(lv_obj_t *screen, uint32_t time_offset) {
    lv_obj_t *clock = lv_label_create(screen);
    lv_label_set_text(clock, "12:48PM");
    lv_obj_set_style_text_color(clock, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(clock, &lv_font_montserrat_30, LV_PART_MAIN);
    lv_obj_align(clock, LV_ALIGN_TOP_RIGHT, -5, 5);
    lv_obj_fade_in(clock, 400, time_offset + 1000);
}
