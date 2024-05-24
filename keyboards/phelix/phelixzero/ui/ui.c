// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include <qp.h>
#include "qp_lvgl.h"
#include <qp_st7789.h>
#include "ui_state.h"
#include "event_router.h"
#include "theme.h"

static const uint16_t D_PHYSICAL_X = 172;
static const uint16_t D_PHYSICAL_Y = 320;
static const uint16_t D_VP_OFFSET_X = 0;
static const uint16_t D_VP_OFFSET_Y = 34;

static painter_device_t display;

static lv_obj_t *scr_startup;
LV_FONT_DECLARE(hooskai_font_36);


void ui_btn_event(wui_btn_t btn) {
    println("ui.c calling routing ------");
    route_btn_event(btn);
}

/*
void set_label_clock_time(lv_obj_t *label, uint32_t curr_time) {
    uint32_t hours = curr_time / 3600;
    uint32_t mins = (curr_time %3600) / 60;
    uint32_t secs = curr_time % 60;
    lv_label_set_text_fmt(label, "%02ld:%02ld:%02ld", hours, mins, secs);
    //lv_label_set_text_fmt(pomodoro, "%ld", curr_time);
}

void update(void) {
    set_label_clock_time(pomodoro, pomo_timer);
}
*/

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

/* initialize the ui variables and start the UI. Runs once on startup */
void init_ui(void) {
    init_theme_colors();
    init_global_ui_state();
    init_screen_startup();
    init_screen_home();
}

bool init_display(void) {
    display = qp_st7789_make_spi_device(D_PHYSICAL_X, D_PHYSICAL_Y, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 0, 3);
    qp_set_viewport_offsets(display, D_VP_OFFSET_X, D_VP_OFFSET_Y);
    qp_init(display, QP_ROTATION_270);

    if (qp_lvgl_attach(display)) {
        init_ui();
    }
    return true;
}


