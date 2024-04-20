
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
    //return state->pomodoro_state == 1 ? 1000 : 0;
    return 1000;
}

void start_pomodoro(void) {
    //pomo_state.pomodoro_state = 1;
    //pomo_state.pomo_timer = 0;
    // need to store the state (aka timers/lvgl labels) pass as 3rd arg.
    // then should be able to update from there
    //defer_exec(100, test_cb, NULL);
    uprintf("starting pomo defer_exec()\n");
    wui_gbl_state[WUI_POMODORO].pomo_wui_state.token = defer_exec(1000, update_pomodoro_callback, &wui_gbl_state[WUI_POMODORO]);
}
void reset_pomodoro(void) {
    wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_timer = 0;
    cancel_deferred_exec(wui_gbl_state[WUI_POMODORO].pomo_wui_state.token);
    lv_label_set_text_fmt(wui_gbl_state[WUI_POMODORO].pomo_wui_state.pomo_label, "%02d:%02d:%02d", 0, 0, 0);
}