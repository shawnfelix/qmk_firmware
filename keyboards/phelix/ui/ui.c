#include <qp.h>
#include "qp_lvgl.h"
#include "qp_st7789.h"
#include "features/pomodoro.h"
#include "ui_state.h"

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


void init_clock(lv_obj_t *screen, uint32_t time_offset) {
    lv_obj_t *clock = lv_label_create(scr_home);
    lv_label_set_text(clock, "12:48PM");
    lv_obj_set_style_text_color(clock, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(clock, &lv_font_montserrat_30, LV_PART_MAIN);
    lv_obj_align(clock, LV_ALIGN_TOP_RIGHT, -5, 5);
    lv_obj_fade_in(clock, 400, time_offset + 1000);
}

/*void init_wpm_widget(lv_obj_t *screen) {
    wpm_counter_widget = lv_label_create(screen);

}*/

// wui_gbl_state_t stores the state of all WUI widgets
wui_gbl_state_t wui_gbl_state[NumberOfWuiTypes];
//deferred_token pomodoro_timer_start_token;

void set_gbl_wui_ui_state(wui_t wui_enum, wui_ui_state_t state) {
    wui_gbl_state[wui_enum].wui_ui_state = state;
}
void set_gbl_wui_init_state(wui_t wui_enum, wui_init_state_t state) {
    wui_gbl_state[wui_enum].wui_init_state = state;
}
void set_gbl_wui(wui_t wui_enum, wui_init_state_t init_state, wui_ui_state_t ui_state) {
    set_gbl_wui_init_state(wui_enum, init_state);
    set_gbl_wui_ui_state(wui_enum, ui_state);
}

// runs one time on keyboard startup to enable all of the widgets
void init_firmware_enabled_widgets_all(void) {
    // init the list of enabled wuis and get the count
    // create an array of wui_gbl_state_t for each enabled wui
    // create map where:
    //      key = enum value of the widget
    //      value = address of the wui element in the array
    // store the states as wui_gbl_state_t
    pomo_wui_state_t pomo_state = (pomo_wui_state_t) { .init = false, .pomo_timer = 0, .pomodoro_state = 0 };
    wui_gbl_state[WUI_POMODORO] = (wui_gbl_state_t) { .wui_init_state = NOT_INIT, .wui_ui_state = HIDDEN, .pomo_wui_state = pomo_state };
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
void init_widget_pomodoro(void) {
    uprintf("init pomo\n");
    lv_obj_t *pomodoro = lv_label_create(scr_home);
    lv_label_set_text_fmt(pomodoro, "%02d:%02d:%02d", 0, 0, 0);
    lv_obj_set_style_text_color(pomodoro, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(pomodoro, &lv_font_montserrat_38, LV_PART_MAIN);
    lv_obj_align(pomodoro, LV_ALIGN_CENTER, 0, 0);
    lv_obj_fade_in(pomodoro, 400, 100);
    wui_gbl_state[WUI_POMODORO].pomo_wui_state = (pomo_wui_state_t){.pomo_timer = 0, .pomodoro_state= 0, .pomo_label = pomodoro};
}

/* OK, Yes, or Continue button in the UI. Affirmative ui event */
void ui_btn_event_one(void) {
    init_widget_pomodoro();
}
/* Up or Alt Modifier 1 button in the UI */
void ui_btn_event_two(void) {
    start_pomodoro();
}
/* Down or Alt M button in the UI */
void ui_btn_event_three(void) {
    reset_pomodoro();
}
/* Cancel, Back, or No button in the UI. Negative action */
void ui_btn_event_four(void) {

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

void read_timer(void) {
    //int i = 0;
    //set_label_clock_time(pomo_state.pomodoro, pomopomo_timer);
    return;
}

void init_screen_home(void) {
    scr_home = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(scr_home, THEME_PRIMARY_BG, LV_PART_MAIN);
    init_clock(scr_home, 3500);
    init_ui_action_button_bar();
    lv_scr_load_anim(scr_home, LV_SCR_LOAD_ANIM_FADE_ON, 500, 3000, false);

}
static void anim_x_cb(void * var, int32_t v) {
    lv_obj_set_x(var, v);
}

void init_screen_startup(void) {
    lv_disp_set_bg_color(lv_disp_get_default(), lv_color_black());
    // create screen
    scr_startup = lv_scr_act();
    lv_obj_set_scrollbar_mode(scr_startup, LV_SCROLLBAR_MODE_OFF);

    lv_obj_set_style_bg_color(scr_startup, THEME_SECONDARY_BG, LV_PART_MAIN);

    lv_scr_load_anim(scr_startup, LV_SCR_LOAD_ANIM_FADE_ON, 500, 1000, false);

    lv_obj_t *phelix_text = lv_label_create(scr_startup);
    lv_label_set_text(phelix_text, "phelix\nkeyboards");
    lv_obj_set_style_text_color(phelix_text, THEME_ACCENT, LV_PART_MAIN);
    lv_obj_set_style_text_font(phelix_text, &lv_font_montserrat_48, LV_PART_MAIN);
    lv_obj_align(phelix_text, LV_ALIGN_CENTER, 0, 0);

    lv_obj_t *underline_text = lv_label_create(scr_startup);
    lv_label_set_text(underline_text, "...");
    lv_obj_set_style_text_color(underline_text, THEME_TEXT_LIGHT, LV_PART_MAIN);
    lv_obj_set_style_text_font(underline_text, &lv_font_montserrat_38, LV_PART_MAIN);
    lv_obj_align(underline_text, LV_ALIGN_CENTER, 0, 50);


    lv_obj_fade_in(phelix_text, 500, 1500);
    lv_obj_fade_in(underline_text, 500, 1500);

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, phelix_text);
    lv_anim_set_values(&a, lv_obj_get_x(phelix_text), -400);
    lv_anim_set_time(&a, 500);
    lv_anim_set_exec_cb(&a, anim_x_cb);
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_delay(&a, 3000);
    lv_anim_start(&a);
}


static void set_angle(void* obj, int32_t v) {
    lv_arc_set_value(obj, v);
}
void example_loading_screen(void) {
    lv_obj_t* arc = lv_arc_create(lv_scr_act());
    lv_arc_set_rotation(arc, 270);
    lv_arc_set_bg_angles(arc, 0, 360);
    lv_obj_remove_style(arc, NULL, LV_PART_KNOB);  /*Be sure the knob is not displayed*/
    lv_obj_clear_flag(arc, LV_OBJ_FLAG_CLICKABLE); /*To not allow adjusting by click*/
    lv_obj_center(arc);

    static lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, arc);
    lv_anim_set_exec_cb(&a, set_angle);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_repeat_delay(&a, 500);
    lv_anim_set_values(&a, 0, 100);
    lv_anim_start(&a);
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
