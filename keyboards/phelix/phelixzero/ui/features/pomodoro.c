// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later


#include <qp.h>
#include "qp_lvgl.h"
#include "pomodoro.h"
#include "ui_state.h"
#include "globals.h"


void update_pomo_state(pomo_state_t state) {
    get_wui(WUI_POMODORO)->pomo_wui_state.pomo_state = state;
}

uint32_t update_pomodoro_callback(uint32_t trig, void *cb_arg) {
    wui_gbl_state_t *gbl_state = (wui_gbl_state_t*)cb_arg;
    gbl_state->pomo_wui_state.pomo_timer += 1000;
    uint32_t seconds = gbl_state->pomo_wui_state.pomo_timer / 1000;
    uint32_t hours = seconds / 3600;
    uint32_t mins = (seconds % 3600) / 60;
    uint32_t secs = seconds % 60;
    lv_label_set_text_fmt(gbl_state->pomo_wui_state.pomo_label, "%02ld:%02ld:%02ld", hours, mins, secs);
    return 1000;
}

// starts timer
void start_pomodoro(void) {
    switch (get_wui(WUI_POMODORO)->pomo_wui_state.pomo_state) {
        case POMO_STOPPED:
        case POMO_PAUSED:
            get_wui(WUI_POMODORO)->pomo_wui_state.token = defer_exec(1000, update_pomodoro_callback, get_wui(WUI_POMODORO));
            update_pomo_state(POMO_RUNNING);
            break;
        case POMO_RUNNING:
            pause_pomodoro();
            break;
        default:
            break;
    }
}
// pauses timer callback indefinitely
void pause_pomodoro(void) {
    if (get_wui(WUI_POMODORO)->pomo_wui_state.pomo_state == POMO_RUNNING) {
        cancel_deferred_exec(get_wui(WUI_POMODORO)->pomo_wui_state.token);
        update_pomo_state(POMO_PAUSED);
    }
}
// resets timer to 0 if state is RUNNING or PAUSED
void reset_pomodoro(void) {
    switch(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_state) {
        case POMO_RUNNING:
        case POMO_PAUSED:
            get_wui(WUI_POMODORO)->pomo_wui_state.pomo_timer = 0;
            cancel_deferred_exec(get_wui(WUI_POMODORO)->pomo_wui_state.token);
            lv_label_set_text_fmt(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, "%02d:%02d:%02d", 0, 0, 0);
            update_pomo_state(POMO_STOPPED);
            break;
        default:
            break;
    }
}

void init_widget_pomodoro(lv_obj_t *screen) {
    if (get_wui(WUI_POMODORO)->wui_init_state == NOT_INIT) {
        // init pomo wui state in global context
        get_wui(WUI_POMODORO)->pomo_wui_state = (pomo_wui_state_t){
                .pomo_timer = 0,
                .pomo_state= POMO_STOPPED,
                .pomo_label = NULL
            };
        get_wui(WUI_POMODORO)->wui_init_state = INIT;
        // init ui stuff
        get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label = lv_label_create(screen);
        lv_label_set_text_fmt(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, "%02d:%02d:%02d", 0, 0, 0);
        lv_obj_set_style_text_color(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, lv_color_make(163, 169, 194), LV_PART_MAIN);
        lv_obj_set_style_text_font(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, &lv_font_montserrat_38, LV_PART_MAIN);
        lv_obj_align(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, LV_ALIGN_CENTER, 0, 0);
        lv_obj_add_flag(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, LV_OBJ_FLAG_HIDDEN);
        //TODO move the line below to the observer based on parameter (optional animation fade in for example)
        //lv_obj_fade_in(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, 400, 100);
    }
}

void do_btn_action_pomodoro(wui_btn_t btn) {
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

void ui_show_pomodoro(void) {
    lv_obj_clear_flag(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label,LV_OBJ_FLAG_HIDDEN);
    lv_obj_fade_in(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label, 400, 100);
}

void ui_hide_pomodoro(void) {
    lv_obj_add_flag(get_wui(WUI_POMODORO)->pomo_wui_state.pomo_label,LV_OBJ_FLAG_HIDDEN);
}
