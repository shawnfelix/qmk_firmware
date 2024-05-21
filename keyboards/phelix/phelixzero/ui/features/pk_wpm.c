
// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later


#include <qp.h>
#include "qp_lvgl.h"
#include "globals.h"
#include <wpm.h>

uint32_t update_wpm_callback(uint32_t trig, void *cb_arg) {
    wui_gbl_state_t *gbl_state = (wui_gbl_state_t*)cb_arg;
    //gbl_state->wpm_wui_state.last_wpm = get_u8_str(, '')
    uint8_t wp = get_current_wpm();
    lv_label_set_text_fmt(gbl_state->wpm_wui_state.wpm_label, "%u WPM", wp);
    return 200;
}

void init_widget_wpm(lv_obj_t *scr_home, lv_color_t text_color) {
    if (wui_gbl_state[WUI_WPM].wui_init_state == NOT_INIT) {
        // init wpm wui state in global context
        wui_gbl_state[WUI_WPM].wpm_wui_state = (wpm_wui_state_t){
                .last_wpm = 0,
                .wpm_label = NULL
            };
        wui_gbl_state[WUI_WPM].wui_init_state = INIT;
        // init ui stuff
        wui_gbl_state[WUI_WPM].wpm_wui_state.wpm_label = lv_label_create(scr_home);
        lv_label_set_text_fmt(wui_gbl_state[WUI_WPM].wpm_wui_state.wpm_label, "%02d WPM", 0);
        lv_obj_set_style_text_color(wui_gbl_state[WUI_WPM].wpm_wui_state.wpm_label, text_color, LV_PART_MAIN);
        lv_obj_set_style_text_font(wui_gbl_state[WUI_WPM].wpm_wui_state.wpm_label, &lv_font_montserrat_38, LV_PART_MAIN);
        lv_obj_align(wui_gbl_state[WUI_WPM].wpm_wui_state.wpm_label, LV_ALIGN_CENTER, -20, 0);
        lv_obj_set_width(wui_gbl_state[WUI_WPM].wpm_wui_state.wpm_label, 190);
        lv_obj_fade_in(wui_gbl_state[WUI_WPM].wpm_wui_state.wpm_label, 400, 100);


        wui_gbl_state[WUI_WPM].wpm_wui_state.token = defer_exec(500, update_wpm_callback, &wui_gbl_state[WUI_WPM]);
        //wui_gbl_state[WUI_WPM].wui_ui_state = RUNNING;
    }
}

void ui_btn_action_wpm(wui_btn_t btn) {
    switch (btn) {
        case B1:
            start_pomodoro();
        break;
        case B2:
            reset_pomodoro();
        break;
        default:
        break;
    }
}

