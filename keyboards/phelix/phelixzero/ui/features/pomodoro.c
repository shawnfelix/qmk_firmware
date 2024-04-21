// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later


#include <qp.h>
#include "qp_lvgl.h"
#include "ui_state.h"
#include "globals.h"
#include "pomodoro.h"



uint32_t update_pomodoro_callback(uint32_t trig, void *cb_arg) {
    wui_gbl_state_t *gbl_state = (wui_gbl_state_t*)cb_arg;
    gbl_state->pomo_wui_state.pomo_timer += 1000;
    //set_label_clock_time(state->pomodoro, state->pomo_timer);
    uint32_t seconds = gbl_state->pomo_wui_state.pomo_timer / 1000;
    uint32_t hours = seconds / 3600;
    uint32_t mins = (seconds %3600) / 60;
    uint32_t secs = seconds % 60;
    lv_label_set_text_fmt(gbl_state->pomo_wui_state.pomo_label, "%02ld:%02ld:%02ld", hours, mins, secs);
    //lv_label_set_text_fmt(gbl_state->pomo_wui_state.pomo_label, "cb %p", &gbl_state->pomo_wui_state.pomo_label);
    //return state->pomodoro_state == 1 ? 1000 : 0;
    return 1000;
}

void start_pomodoro(void) {
    //pomo_state.pomodoro_state = 1;
    //pomo_state.pomo_timer = 0;
    // need to store the state (aka timers/lvgl labels) pass as 3rd arg.
    // then should be able to update from there
    //defer_exec(100, test_cb, NULL);
    wui_gbl_state[WUI_POMODORO].pomo_wui_state.token = defer_exec(1000, update_pomodoro_callback, &wui_gbl_state[WUI_POMODORO]);
}
void reset_pomodoro(void) {
    wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_timer = 0;
    cancel_deferred_exec(wui_gbl_state[WUI_POMODORO].pomo_wui_state.token);
    lv_label_set_text_fmt(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, "%02d:%02d:%02d", 0, 0, 0);
    //lv_label_set_text_fmt(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, "rst %p", &wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label);
    //wui_gbl_state[WUI_POMODORO].pomo_wui_state.token = NULL;
    //wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label = NULL;
}

void init_widget_pomodoro(lv_obj_t *scr_home, lv_color_t text_color) {
    if (wui_gbl_state[WUI_POMODORO].wui_init_state == NOT_INIT) {
        wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label = lv_label_create(scr_home);
        //wui_gbl_state[WUI_POMODORO].pomo_wui_state = (pomo_wui_state_t){.pomo_timer = 0, .pomodoro_state= 0, .pomo_label = lv_label_create(scr_home)};
        lv_label_set_text_fmt(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, "%02d:%02d:%02d", 1, 0, 0);
        lv_obj_set_style_text_color(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, text_color, LV_PART_MAIN);
        lv_obj_set_style_text_font(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, &lv_font_montserrat_38, LV_PART_MAIN);
        lv_obj_align(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_fade_in(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, 400, 100);
        //lv_label_set_text_fmt(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, "init %p", &wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label);
        wui_gbl_state[WUI_POMODORO].wui_init_state = INIT;
    }
}
