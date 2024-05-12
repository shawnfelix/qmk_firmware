// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include <qp.h>
#include "qp_lvgl.h"
#include "globals.h"
#include "features.h"

void ui_cli_do_action(cli_action_t action) {
    switch (action) {
        case CLI_BSPC:
            lv_textarea_del_char(gbl_ui_state.cli_ta);
            break;
        case CLI_LEFT:
            lv_textarea_cursor_left(gbl_ui_state.cli_ta);
            break;
        case CLI_RIGHT:
            lv_textarea_cursor_right(gbl_ui_state.cli_ta);
            break;
        case CLI_OPEN:
            gbl_ui_state.cli_mode_active = true;
            lv_obj_clear_flag(gbl_ui_state.cli_ta, LV_OBJ_FLAG_HIDDEN);
            break;
        case CLI_CLOSE:
            gbl_ui_state.cli_mode_active = false;
            lv_textarea_set_text(gbl_ui_state.cli_ta, "");
            lv_obj_add_flag(gbl_ui_state.cli_ta, LV_OBJ_FLAG_HIDDEN);
            break;
        case CLI_SUBMIT:
            gbl_ui_state.cli_mode_active = false;
            lv_textarea_set_text(gbl_ui_state.cli_ta, "");
            lv_obj_add_flag(gbl_ui_state.cli_ta, LV_OBJ_FLAG_HIDDEN);
            break;
        case CLI_CLEAR:
            break;
        default:
            break;
    }
}

void init_ui_cli(lv_obj_t *lv_obj) {
    gbl_ui_state.cli_ta = lv_textarea_create(lv_obj);
    lv_obj_align(gbl_ui_state.cli_ta, LV_ALIGN_BOTTOM_MID, 0, 30);
    lv_obj_add_state(gbl_ui_state.cli_ta, LV_STATE_FOCUSED);
    lv_obj_add_flag(gbl_ui_state.cli_ta, LV_OBJ_FLAG_HIDDEN);
}
