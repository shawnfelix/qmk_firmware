// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include <qp.h>
#include "qp_lvgl.h"
#include "qp_st7789.h"
#include "globals.h"
#include "features/pomodoro.h"
#include "features/pk_wpm.h"
#include "features/ui_cli.h"
#include "features/features.h"

static const uint16_t D_PHYSICAL_X = 172;
static const uint16_t D_PHYSICAL_Y = 320;
static const uint16_t D_VP_OFFSET_X = 0;
static const uint16_t D_VP_OFFSET_Y = 34;

static painter_device_t display;

lv_color_t THEME_ACCENT;
lv_color_t THEME_PRIMARY_BG;
lv_color_t THEME_SECONDARY_BG;
lv_color_t THEME_TEXT_DARK;
lv_color_t THEME_TEXT_LIGHT;
lv_color_t THEME_TEXT_LIGHT_GRAY;
// UI action buttons
lv_color_t THEME_BUTTON_1;
lv_color_t THEME_BUTTON_2;
lv_color_t THEME_BUTTON_3;
lv_color_t THEME_BUTTON_4;

static lv_obj_t *scr_startup;
static lv_obj_t *scr_home;
lv_obj_t wpm_counter_widget;
LV_FONT_DECLARE(hooskai_font_36);

lv_obj_t * cont;
uint8_t current_scroll_pos;

// TODO move this to a config file optional
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

const char* enumToString(wui_t wui_enum) {
    switch (wui_enum) {
        case WUI_POMODORO:    return "Pomodoro";
        case WUI_WPM:         return "WPM";
        default:              return "Invalid"; // Handle invalid enum value
    }
}

static void scroll_event_cb(lv_event_t * e)
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

/**
 * Translate the object as they scroll
 */
void show_ui_widget_selector(void)
{
    cont = lv_obj_create(scr_home);
    lv_obj_set_size(cont, 172, 150);
    lv_obj_set_style_bg_opa(cont, 0, 0);
    lv_obj_set_style_border_width(cont, 0, 0);
    lv_obj_center(cont);
    lv_obj_align(cont, LV_ALIGN_LEFT_MID, 0, 0);
    lv_obj_set_flex_flow(cont, LV_FLEX_FLOW_COLUMN);
    lv_obj_add_event_cb(cont, scroll_event_cb, LV_EVENT_SCROLL, NULL);
    //lv_obj_set_style_radius(cont, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_clip_corner(cont, true, 0);
    lv_obj_set_scroll_dir(cont, LV_DIR_VER);
    lv_obj_set_scroll_snap_y(cont, LV_SCROLL_SNAP_CENTER);
    lv_obj_set_scrollbar_mode(cont, LV_SCROLLBAR_MODE_OFF);

    uint32_t i;
    for(i = 0; i < NumberOfWuiTypes; i++) {
        lv_obj_t * btn = lv_btn_create(cont);
        lv_obj_set_width(btn, lv_pct(100));
        lv_obj_set_style_bg_color(btn, THEME_TEXT_DARK, 0);

        lv_obj_t * label = lv_label_create(btn);
//        lv_label_set_text_fmt(label, "Button %"LV_PRIu32, i);
        lv_label_set_text(label, enumToString(i));
    }

    /*Update the buttons position manually for first*/
    lv_event_send(cont, LV_EVENT_SCROLL, NULL);

    /*Be sure the fist button is in the middle*/
    lv_obj_scroll_to_view(lv_obj_get_child(cont, 0), LV_ANIM_OFF);
    current_scroll_pos = 0;
}



void init_clock(lv_obj_t *screen, uint32_t time_offset) {
    lv_obj_t *clock = lv_label_create(scr_home);
    lv_label_set_text(clock, "12:48PM");
    lv_obj_set_style_text_color(clock, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(clock, &lv_font_montserrat_30, LV_PART_MAIN);
    lv_obj_align(clock, LV_ALIGN_TOP_RIGHT, -5, 5);
    lv_obj_fade_in(clock, 400, time_offset + 1000);
}


// wui_gbl_state_t stores the state of all WUI widgets
//wui_gbl_state_t wui_gbl_state[NumberOfWuiTypes];
//gbl_ui_state_t gbl_ui_state;
//deferred_token pomodoro_timer_start_token;

void set_wui_window_state(wui_t wui_enum, window_state_t state) {
    wui_gbl_state[wui_enum].window_state = state;
}
void set_gbl_wui(wui_t wui_enum, window_state_t init_state, window_state_t ui_state) {
    set_wui_window_state(wui_enum, ui_state);
}

/*
    Runs one time on keyboard startup to init global state
    and enable all of the widgets
*/
void init_firmware_enabled_widgets_all(void) {
    // init global state
    gbl_ui_state = (gbl_ui_state_t) { .active_layer_text="uninitialized", NULL, false, ""};
    // init the list of enabled wuis and get the count
    // create an array of wui_gbl_state_t for each enabled wui
    // create map where:
    //      key = enum value of the widget
    //      value = address of the wui element in the array
    // store the states as wui_gbl_state_t

    //pomo_wui_state_t pomo_state = (pomo_wui_state_t) { .init = false, .pomo_timer = 0, .pomodoro_state = 0 };
    //wui_gbl_state[WUI_POMODORO] = (wui_gbl_state_t) { .wui_init_state = NOT_INIT, .wui_ui_state = HIDDEN, .pomo_wui_state = pomo_state };
}

void init_ui(void) {
}
/*
void set_label_clock_time(lv_obj_t *label, uint32_t curr_time) {
    uint32_t hours = curr_time / 3600;
    uint32_t mins = (curr_time %3600) / 60;
    uint32_t secs = curr_time % 60;
    lv_label_set_text_fmt(label, "%02ld:%02ld:%02ld", hours, mins, secs);
    //lv_label_set_text_fmt(pomodoro, "%ld", curr_time);
}*/

/*
void update(void) {
    set_label_clock_time(pomodoro, pomo_timer);
}
*/

void init_ui_action_button_bar(void) {
    lv_obj_t *action_button_bar = lv_obj_create(scr_home);
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

/* OK, Yes, or Continue button in the UI. Affirmative ui event */
void ui_btn_event_one(void) {
    init_widget_pomodoro(scr_home, THEME_TEXT_LIGHT);
}
/* Up or Alt Modifier 1 button in the UI */
void ui_btn_event_two(void) {
    pause_pomodoro();
}
/* Down or Alt M button in the UI */
void ui_btn_event_three(void) {
    start_pomodoro();
}
/* Cancel, Back, or No button in the UI. Negative action */
void ui_btn_event_four(void) {
    //reset_pomodoro();
    init_widget_wpm(scr_home, THEME_TEXT_LIGHT);
}
void ui_encoder_switch(void) {
    show_ui_widget_selector();
}
void ui_encoder_up(void) {
    if (current_scroll_pos > 0) {
        current_scroll_pos = current_scroll_pos -1;
        //lv_obj_scroll_to_view(lv_obj_get_child(cont, current_scroll_pos), LV_ANIM_ON);
        lv_obj_scroll_to_view(lv_obj_get_child(cont, current_scroll_pos), LV_ANIM_ON);
        //lv_event_send(lv_obj_get_child(cont, current_scroll_pos), LV_EVENT_CLICKED, NULL);

    }
}
void ui_encoder_down(void) {
    if (current_scroll_pos < NumberOfWuiTypes-1) {
        current_scroll_pos = current_scroll_pos +1;
        //lv_obj_get_child(cont, current_scroll_pos)
        //lv_event_send(cont, LV_EVENT_SCROLL, current_scroll_pos+1)
        lv_obj_scroll_to_view(lv_obj_get_child(cont, current_scroll_pos), LV_ANIM_ON);
        //lv_event_send(lv_obj_get_child(cont, current_scroll_pos), LV_EVENT_CLICKED, NULL);
    }
}
/*
example from discord:
typedef struct {
    painter_device_t device;
    painter_image_handle_t *frames; // pointer to an array containing them
    uint8_t i;
} gif_state_t;

uint32_t render_gif_wpm(uint32_t trigger_time, void *cb_arg) {
    gif_state_t*state = (gif_state_t*)cb_arg;
    bool        ret   = qp_drawimage(state->device, state->frames[state->i], ...);

    if (!ret) {
        // some handling if drawing fails?
    }

    // update the number, perhaps just loop it
    state->i = (state->i + 1) % n_frames;

    uint16_t delay_ms = some_math_with(get_current_wpm());
    // If successful, keep going -- returning 0 cancels the deferred execution
    return ret ? delay_ms : 0;
}
*/

void update_layer_state_text(void) {
    if (gbl_ui_state.active_layer_obj != NULL) {
        lv_label_set_text_fmt(gbl_ui_state.active_layer_obj, "Layer: %s", gbl_ui_state.active_layer_text);
    }
}
void update_ui_layer_state(char layer_name_text[]) {
    strcpy(gbl_ui_state.active_layer_text, layer_name_text);
    update_layer_state_text();
}
void init_ui_layer_state(void) {
    gbl_ui_state.active_layer_obj = lv_label_create(scr_home);
    lv_obj_set_style_text_color(gbl_ui_state.active_layer_obj, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(gbl_ui_state.active_layer_obj, &lv_font_montserrat_14, LV_PART_MAIN);
    lv_obj_align(gbl_ui_state.active_layer_obj, LV_ALIGN_TOP_LEFT, 10, 5);
    update_layer_state_text();
}



void init_screen_home(void) {
    scr_home = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr_home, THEME_PRIMARY_BG, LV_PART_MAIN);

    init_clock(scr_home, 3500);
    init_ui_action_button_bar();
    init_ui_layer_state();
    init_ui_cli(scr_home);

    lv_scr_load_anim(scr_home, LV_SCR_LOAD_ANIM_FADE_ON, 500, 3000, false);
}

void init_screen_startup(void) {
    lv_disp_set_bg_color(lv_disp_get_default(), lv_color_black());
    // create screen
    scr_startup = lv_scr_act();
    lv_obj_set_scrollbar_mode(scr_startup, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_bg_color(scr_startup, THEME_SECONDARY_BG, LV_PART_MAIN);

    lv_scr_load_anim(scr_startup, LV_SCR_LOAD_ANIM_FADE_ON, 500, 1000, false);

    lv_obj_t *phelix_text = lv_label_create(scr_startup);
    lv_label_set_text(phelix_text, "PHELIX\nKEYBOARDS");
    lv_obj_set_style_text_color(phelix_text, THEME_ACCENT, LV_PART_MAIN);
    lv_obj_set_style_text_font(phelix_text, &hooskai_font_36, LV_PART_MAIN);
    lv_obj_align(phelix_text, LV_ALIGN_CENTER, 0, 0);

    static lv_style_t style_bg;
    static lv_style_t style_indic;
    lv_style_init(&style_bg);
    lv_style_set_border_color(&style_bg, THEME_ACCENT);
    lv_style_set_border_width(&style_bg, 2);
    //lv_style_set_pad_all(&style_bg, 6);
    lv_style_set_radius(&style_bg, 10);
    lv_style_set_anim_time(&style_bg, 2000);

    lv_style_init(&style_indic);
    lv_style_set_bg_opa(&style_indic, LV_OPA_COVER);
    lv_style_set_bg_color(&style_indic, THEME_ACCENT);
    lv_style_set_radius(&style_indic, 3);

    lv_obj_t * bar = lv_bar_create(scr_startup);
    lv_obj_remove_style_all(bar);
    lv_obj_add_style(bar, &style_bg, 0);
    lv_obj_add_style(bar, &style_indic, LV_PART_INDICATOR);
    lv_obj_set_size(bar, 200, 20);
    lv_obj_align(bar, LV_ALIGN_CENTER, 0, 50);

    lv_obj_fade_in(phelix_text, 100, 500);
    lv_obj_fade_in(bar, 100, 500);

    lv_anim_t bar_anim;
    lv_anim_init(&bar_anim);
    lv_anim_set_var(&bar_anim, bar);
    lv_anim_set_delay(&bar_anim, 3000);

    lv_bar_set_value(bar, 100, LV_ANIM_ON);
}

bool init_display(void) {
    display = qp_st7789_make_spi_device(D_PHYSICAL_X, D_PHYSICAL_Y, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 0, 3);
    qp_set_viewport_offsets(display, D_VP_OFFSET_X, D_VP_OFFSET_Y);
    qp_init(display, QP_ROTATION_270);

    if (qp_lvgl_attach(display)) {
        init_ui();
        init_theme_colors();
        init_screen_startup();
        init_screen_home();
    }
    return true;
}


