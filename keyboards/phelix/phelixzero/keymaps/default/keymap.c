// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "ui/ui.h"
#include "ui/ui_state.h"
#include "globals.h"

enum custom_layer {
    _DEFAULT,
    _UI_CONTROL
};

char* custom_layer_label[] =  {
    [_DEFAULT]="DEFAULT",
    [_UI_CONTROL]="UI_CONTROL"
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    +--------+------+------+------+------+------+------+      +------+------+------+------+------+------+-------------+
    |  ESC   |  1   |  2   |  3   |  4   |  5   |  6   |      |  7   |  8   |  9   |  0   |  -_  |  =+  |  BACKSPACE  |
    +--------+------+------+------+------+------+------+    +------+------+------+------+------+------+------+--------+
    |  TAB   |  Q   |  W   |  E   |  R   |  T   |           |  Y   |  U   |  I   |  O   |  P   |  [}  |  ]}  |  \|    |
    +--------+------+------+------+------+------+           +------+------+------+------+------+-------+--------------+
    | LCTL   |  A   |  S   |  D   |  F   |  G   |            |  H   |  J   |  K   |  L   |  ;:  |  '"  |    ENTER     |
    +--------+------+------+------+------+------+             +------+-----+-------+------+------+------+------+-------+
    | LSFT   |  Z   |  X   |  C   |  V   |  B   |             |  N   |  M   |  ,<  |  .>  |  /?  | SHFT |  UP  | DEL  |
    +-------+------+---------+------+-----------+             +------+------+------+------+------+------+------+------+
    | LCTL  |  7   | QK_BOOT | LALT |    SPC    |             |     SPACE   |  tbd | BOOT | tbd  | LEFT | DOWN | RGHT |
    +-------+------+---------+------+-----------+             +-------------+------+------+------+------+------+------+

    */
    [_DEFAULT] = LAYOUT(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,   KC_6,       KC_7,   KC_8,  KC_9,    KC_0,   KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,               KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC,   KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,               KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,               KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,     KC_DEL,
        KC_LCTL, KC_LGUI, KC_NO,   KC_LALT, KC_SPC,                       KC_SPC, MO(_UI_CONTROL), KC_RALT, MO(_UI_CONTROL),  KC_LEFT, KC_DOWN, KC_RGHT,
        KC_NO,                                                            PB_1,   PB_2,  PB_3,    PB_4,   PB_5
    ),
    /*
    +--------+------+------+------+------+------+------+      +------+------+------+------+------+------+-------------+
    |        |      |      |      |      |      |      |      |      |      |      |      |      |       |            |
    +--------+------+------+------+------+------+------+    +------+------+------+------+------+------+------+--------+
    |        |      |      |      |      |      |           |      |      |      |      |      |      |      |        |
    +--------+------+------+------+------+------+           +------+------+------+------+------+-------+--------------+
    |        |      |      |      |      |      |            |      |      |      |      |      |     |    |          |
    +--------+------+------+------+------+------+            +------+-----+-------+------+-------+------+-------+-----+
    |        |      |      |      |      |      |             |      |      |      |      |      |      |       |     |
    +-------+------+---------+------+-----------+             +------+------+------+------+------+------+-------+-----+
    |       |      |         |      |           |             |             |      |      |      |      |       |     |
    +-------+------+---------+------+-----------+             +-------------------------------------------------------+

    ,---,---,---,---,---,---,---,   .---,---,---,---,---,---,-------,
    | ~ | 1 | 2 | 3 | 4 | 5 | 6 |   | 7 | 8 | 9 | 0 | [ | ] | <-    |
    |---'-,-'-,-'-,-'-,-'-,-'-,-' .-'-,-'-,-'-,-'-,-'-,-'-,-'-,-----|
    | ->| | Q | W | E | R | T |   | Y | U | I | O | P | [ | ] |  \  |
    |-----',--',--',--',--',--',  '.--',--',--',--',--',--',--'-----|
    | Caps | A | S | D | F | G |   | H | J | K | L | ; | - |  Enter |
    |------'-,-'-,-'-,-'-,-'-,-'-, '-,-'-,-'-,-'-,-'-,-'-,-'--------|
    |        | Z | X | C | V | B |   | N | M | W | V | Z |          |
    |------,-',--'--,'---,---'---:   '---'---'---'-,-'---',--,------|
    | ctrl |  | alt |    |       |   |         | alt  |  | ctrl |
    '------'  '-----'-------------   ----------'------'  '------'
    */
    [_UI_CONTROL] = LAYOUT(
        KC_TILD, KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   UI_UP,   KC_NO,    KC_NO, KC_NO,            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   UI_LEFT, UI_DOWN, UI_RIGHT, KC_NO, KC_NO,            KC_NO, UI_J,  UI_K,  UI_L,  KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO, KC_NO,            KC_NO, UI_M,  UI_N,  KC_NO, PB_6, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   QK_BOOT, KC_NO,    KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,                                                      PB_1,   PB_2, PB_3,    PB_4,   PB_5
    )
};

static bool display_enabled = false;
void keyboard_post_init_kb(void) {
    display_enabled = init_display();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (gbl_ui_state.cli_mode_active == true){

    }
    switch (keycode) {
        case PB_6:
        case PB_1:
            if (record-> event.pressed) {
                ui_btn_event_one();
            }
            return false;
        case PB_2:
            if (record-> event.pressed) {
                ui_btn_event_two();
            }
            return false;
        case PB_3:
            if (record-> event.pressed) {
                ui_btn_event_three();
            }
            return false;
        case PB_4:
            if (record-> event.pressed) {
                ui_btn_event_four();
            }
            return false;
        case PB_5:
            if (record->event.pressed) {
                uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
            }
            break;
        default:
            return true;
    }
    return true;
}

/* runs ever time layer gets changed */
layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t current_layer = get_highest_layer(state);
    switch (current_layer) {
        case 0:
            update_ui_layer_state("Default");
            break;
        case 1:
            update_ui_layer_state("UI Control");
            break;
        default: {
            char c[11];
            sprintf(c, "%x", state);
            update_ui_layer_state(c);
            break;
        }
    }
    return state;
}
