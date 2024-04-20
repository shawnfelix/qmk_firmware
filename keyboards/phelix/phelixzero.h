#pragma once

#include <quantum.h>
#include "ui/ui.h"

enum phelix_keycodes {
    UI_UP = SAFE_RANGE,
    UI_DOWN,
    UI_LEFT,
    UI_RIGHT,
    UI_J,
    UI_K,
    UI_L,
    UI_M,
    UI_N
};

enum keyboard_state {
    NORM,
    UI
};

//#define LAYOUT

/*
#define LAYOUT_60( \
    L00, L01, L02, L03, L04, L05, L06,      R00, R01, R02, R03, R04, R05, R06, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, R16, R17, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, R26, \
    L30, L31, L32, L33, L34, L35,           R30, R31, R32, R33, R34, R35, R36, R37, \
    L40, L41, L42, L43, L44,                R40, R41, R42, R43, R44, R45, R46, \
                                            R50, R51, R52, R53, R54\
    ) \
    { \
        { L00, L01, L02, L03, L04, L05,   L06,   KC_NO }, \
        { L10, L11, L12, L13, L14, L15,   KC_NO, KC_NO }, \
        { L20, L21, L22, L23, L24, L25,   KC_NO, KC_NO }, \
        { L30, L31, L32, L33, L34, L35,   KC_NO, KC_NO }, \
        { L40, L41, L42, L43, L44, KC_NO, KC_NO, KC_NO }, \
        { R00, R01, R02, R03, R04, R05,   R06,   KC_NO }, \
        { R10, R11, R12, R13, R14, R15,   R16,   R17 }, \
        { R20, R21, R22, R23, R24, R25,   R26,   KC_NO }, \
        { R30, R31, R32, R33, R34, R35,   R36,   R37 }, \
        { R40, R41, R42, R43, R44, R45,   R46,   KC_NO } \
        { R50, R51, R52, R53, R54, KC_NO, KC_NO, KC_NO }\
    }

*/
