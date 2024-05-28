// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include "qp_lvgl.h"
#include <globals.h>
#include "native_defs.h"

static lv_obj_t * cont;
static uint8_t current_scroll_pos;
static lv_obj_t *exit_wui_btn;

/**
 * Translate the object as they scroll
 */
static void widget_selector_scroll_event_cb(lv_event_t * e)
{
    lv_obj_t * cont_tmp = lv_event_get_target(e);

    lv_area_t cont_a;
    lv_obj_get_coords(cont_tmp, &cont_a);
    lv_coord_t cont_y_center = cont_a.y1 + lv_area_get_height(&cont_a) / 2;

    lv_coord_t r = lv_obj_get_height(cont_tmp) * 7 / 4;
    uint32_t i;
    uint32_t child_cnt = lv_obj_get_child_cnt(cont_tmp);
    for(i = 0; i < child_cnt; i++) {
        lv_obj_t * child = lv_obj_get_child(cont_tmp, i);
        lv_area_t child_a;
        lv_obj_get_coords(child, &child_a);

        lv_coord_t child_y_center = child_a.y1 + lv_area_get_height(&child_a) / 2;

        lv_coord_t diff_y = child_y_center - cont_y_center;
        diff_y = LV_ABS(diff_y);

        /*Get the x of diff_y on a circle.*/
        lv_coord_t x;
        /*If diff_y is out of the circle use the last point of the circle (the radius)*/
        if(diff_y >= r) {
            x = r;
        } else {
            /*Use Pythagoras theorem to get x from radius and y*/
            uint32_t x_sqr = r * r - diff_y * diff_y;
            lv_sqrt_res_t res;
            lv_sqrt(x_sqr, &res, 0x8000);   /*Use lvgl's built in sqrt root function*/
            x = res.i - r;
        }

        /*Translate the item by the calculated X coordinate*/
        lv_obj_set_style_translate_x(child, x, 0);

        /*Use some opacity with larger translations*/
        //lv_opa_t opa = lv_map(x, 0, r, LV_OPA_TRANSP, LV_OPA_COVER);
        //lv_obj_set_style_opa(child, LV_OPA_COVER - opa, 0);
    }
}
void init_ui_widget_selector(lv_obj_t * screen, uint32_t number_of_init_wuis) {
    cont = lv_obj_create(screen);
    lv_obj_set_size(cont, 172, 150);
    lv_obj_set_style_bg_opa(cont, 0, 0);
    lv_obj_set_style_border_width(cont, 0, 0);
    lv_obj_center(cont);
    lv_obj_align(cont, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(cont, widget_selector_scroll_event_cb, LV_EVENT_SCROLL, NULL);
    //lv_obj_set_style_radius(cont, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(cont, true, 0);
    lv_obj_set_scroll_dir(cont, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

    uint32_t i;
    for(i = 0; i < number_of_init_wuis; i++) {
        lv_obj_t * btn = lv_btn_create(cont);
        lv_obj_set_width(btn, lv_pct(100));
        lv_obj_set_style_bg_color(btn, lv_color_make(112, 119, 147), 0);

        lv_obj_t * label = lv_label_create(btn);
        lv_label_set_text(label, enumToString(i));
    }

    exit_wui_btn = lv_btn_create(cont);
    lv_obj_set_width(exit_wui_btn, lv_pct(100));
    lv_obj_set_style_bg_color(exit_wui_btn, lv_color_make(50, 119, 147), 0);

    lv_obj_t * label = lv_label_create(exit_wui_btn);
    lv_label_set_text(label, "exit");

    /*Update the buttons position manually for first*/
    lv_event_send(cont, LV_EVENT_SCROLL, NULL);

    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(cont, 0), LV_ANIM_OFF);
    current_scroll_pos = 0;
    lv_obj_add_flag(cont, LV_OBJ_FLAG_HIDDEN);
}

void scroll_up(void) {
    if (current_scroll_pos > 0) {
        current_scroll_pos = current_scroll_pos -1;
        //lv_obj_scroll_to_view(lv_obj_get_child(cont, current_scroll_pos), LV_ANIM_ON);
        lv_obj_scroll_to_view(lv_obj_get_child(cont, current_scroll_pos), LV_ANIM_ON);
        //lv_event_send(lv_obj_get_child(cont, current_scroll_pos), LV_EVENT_CLICKED, NULL);

    }
}
void scroll_down(void) {
    if (current_scroll_pos < NumberOfWuiTypes) {
        current_scroll_pos = current_scroll_pos +1;
        //lv_obj_get_child(cont, current_scroll_pos)
        //lv_event_send(cont, LV_EVENT_SCROLL, current_scroll_pos+1)
        lv_obj_scroll_to_view(lv_obj_get_child(cont, current_scroll_pos), LV_ANIM_ON);
        //lv_event_send(lv_obj_get_child(cont, current_scroll_pos), LV_EVENT_CLICKED, NULL);
    }
}

void open_widget_at_pos(void) {
    if (current_scroll_pos == NumberOfWuiTypes) {
        // exit button
        minimize_active_wui();
    }
    set_wui_window_state(current_scroll_pos, MAX);
}

void show_widget_selector(void) {
    lv_obj_clear_flag(cont, LV_OBJ_FLAG_HIDDEN);
}
void hide_widget_selector(void) {
    lv_obj_add_flag(cont, LV_OBJ_FLAG_HIDDEN);
}

native_cb_action_t ui_btn_event_scroll_selector(wui_btn_t btn) {
    switch (btn) {
        case ENC_CW:
            scroll_up();
        break;
        case ENC_CCW:
            scroll_down();
        break;
        case ENC_BTN:
            open_widget_at_pos();
            return N_CLOSE;
        break;
        default:
        break;
    }
    return N_KEEP_OPEN;
}
