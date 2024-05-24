// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include <qp.h>
#include "qp_lvgl.h"
#include "globals.h"
#include "features.h"
#include "ui_state.h"

void ui_cli_do_action(cli_action_t action) {
    switch (action) {
        case CLI_BSPC:
            lv_textarea_del_char(get_gbl_state()->cli_ta);
            break;
        case CLI_LEFT:
            lv_textarea_cursor_left(get_gbl_state()->cli_ta);
            break;
        case CLI_RIGHT:
            lv_textarea_cursor_right(get_gbl_state()->cli_ta);
            break;
        case CLI_OPEN:
            get_gbl_state()->cli_mode_active = true;
            lv_obj_clear_flag(get_gbl_state()->cli_ta, LV_OBJ_FLAG_HIDDEN);
            break;
        case CLI_CLOSE:
            get_gbl_state()->cli_mode_active = false;
            lv_textarea_set_text(get_gbl_state()->cli_ta, "");
            lv_obj_add_flag(get_gbl_state()->cli_ta, LV_OBJ_FLAG_HIDDEN);
            break;
        case CLI_SUBMIT:
            get_gbl_state()->cli_mode_active = false;
            lv_textarea_set_text(get_gbl_state()->cli_ta, "");
            lv_obj_add_flag(get_gbl_state()->cli_ta, LV_OBJ_FLAG_HIDDEN);
            break;
        case CLI_CLEAR:
            break;
        default:
            break;
    }
}

void init_ui_cli(lv_obj_t *lv_obj) {
    get_gbl_state()->cli_ta = lv_textarea_create(lv_obj);
    lv_obj_align(get_gbl_state()->cli_ta, LV_ALIGN_BOTTOM_MID, 0, 30);
    lv_obj_add_state(get_gbl_state()->cli_ta, LV_STATE_FOCUSED);
    lv_obj_add_flag(get_gbl_state()->cli_ta, LV_OBJ_FLAG_HIDDEN);
}
