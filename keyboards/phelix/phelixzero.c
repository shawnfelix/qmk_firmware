#include "phelixzero.h"
#include <qp.h>
#include "qp_lvgl.h"
#include "qp_st7789.h"
#include <stdio.h>
#include <time.h>
#include "split_util.h"
#include "print.h"

static painter_device_t display;
static bool display_ready = false;

static const uint16_t D_PHYSICAL_X = 320;
static const uint16_t D_PHYSICAL_Y = 172;
static const uint16_t D_VP_OFFSET_X = 0;
static const uint16_t D_VP_OFFSET_Y = 34;

static void set_angle(void* obj, int32_t v) {
    lv_arc_set_value(obj, v);
}

uint32_t init_display(uint32_t trigger_time, void *cb_arg)
{
    display_ready = true;
    display = qp_st7789_make_spi_device(D_PHYSICAL_X, D_PHYSICAL_Y, LCD_CS_PIN, LCD_DC_PIN, LCD_RST_PIN, 0, 3);
    qp_set_viewport_offsets(display, D_VP_OFFSET_X, D_VP_OFFSET_Y);
    qp_init(display, QP_ROTATION_270);
    
    if (qp_lvgl_attach(display)) {
        /*Create an Arc*/
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
    return(0);
}

void keyboard_post_init_kb(void) {
    defer_exec(10, init_display, NULL);
}
