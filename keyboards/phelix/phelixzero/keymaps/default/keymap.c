// Copyright 2024 shawnfelix (@shawnfelix)
// SPDX-License-Identifier: GPL-3.0-or-later

#include QMK_KEYBOARD_H
#include "ui/ui.h"
#include "ui/features/ui_cli.h"
#include "globals.h"
#include "print.h"
#include <debug.h>

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
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,               KC_Y,   KC_U,  KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,               KC_H,   KC_J,  KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,               KC_N,   KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,     KC_DEL,
        KC_LCTL, KC_LGUI, MO(_UI_CONTROL),   KC_LALT, KC_SPC,                       KC_SPC, MO(_UI_CONTROL), KC_RALT, MO(_UI_CONTROL),  KC_LEFT, KC_DOWN, KC_RGHT,
                                                                          PB_1,   PB_2,  PB_3,    PB_4,   PB_5
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
        KC_TILD, PB_5,    PB_6,    KC_NO,    KC_NO, KC_NO, KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   UI_UP,   KC_NO,    KC_NO, KC_NO,            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO,   UI_LEFT, UI_DOWN, UI_RIGHT, KC_NO, KC_NO,            KC_LEFT, KC_DOWN,  KC_UP,  KC_RIGHT,  KC_NO, KC_NO, KC_NO,
        KC_NO,   DB_TOGG,   KC_VOLU,   KC_VOLD,    KC_NO, KC_NO,      KC_NO, UI_M,  UI_N,  KC_NO, PB_5, KC_NO, KC_NO, KC_NO,
        KC_NO,   KC_NO,   QK_BOOT, KC_NO,    KC_NO,                   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                                                      PB_1,   PB_2, PB_3,    PB_4,   PB_5
    )
};

// encoder map

/*
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_DEFAULT] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_UI_CONTROL]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)}
};
*/
bool encoder_update_user(uint8_t index, bool clockwise) {
    uprintf("[encoder]: %s \n", clockwise ? "CW" : "C_CW");
    if (IS_LAYER_ON(_UI_CONTROL)) {
        if (clockwise) {
            ui_encoder_up();
        } else {
            ui_encoder_down();
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }

    return false;
    /*if (index == 0) { // First encoder
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 1) { // Second encoder
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
*/
}
static bool display_enabled = false;
void keyboard_post_init_kb(void) {
    display_enabled = init_display();
}

void keyboard_post_init_user(void) {
    debug_enable = true;
}
const char keycode_to_char_lookup_2[] = {
    '\0', '\0', '\0', '\0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1',
    '2', '3', '4', '5', '6', '7', '8', '9', '0', '\n', '\0', '\0', '\0', ' ' // <- KC_SPC
    // Add more characters as needed
};
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (gbl_ui_state.cli_mode_active == true && record-> event.pressed) {
        uprintf("[UI CLI MODE] Keycode: 0x%04X\n", keycode);
        switch(keycode) {
            case QK_GESC:
                ui_cli_do_action(CLI_CLOSE);
                return false;
            break;
            case KC_ENT:
                ui_cli_do_action(CLI_SUBMIT);
                return false;
            break;
            case KC_BSPC:
                ui_cli_do_action(CLI_BSPC);
                return false;
            break;
            case KC_LEFT:
                ui_cli_do_action(CLI_LEFT);
                return false;
            case KC_RIGHT:
                ui_cli_do_action(CLI_RIGHT);
                return false;
            default:
                lv_textarea_add_char(gbl_ui_state.cli_ta, keycode_to_char_lookup_2[keycode]);
            break;
        }
        return false;
    }
    switch (keycode) {
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
                if (IS_LAYER_ON(_UI_CONTROL)) {
                    ui_btn_event_four();
                } else {
                    layer_on(_UI_CONTROL);
                }
            }
            return false;
        case PB_5:
            if (record->event.pressed) {
                //uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
                if (IS_LAYER_ON(_UI_CONTROL)) {
                    layer_off(_UI_CONTROL);
                } else {
                    layer_on(_UI_CONTROL);
                }
                return false;
            }
            break;
        case PB_6:
            if (record->event.pressed) {
                ui_encoder_switch();
            }
            return false;
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
            sprintf(c, "%x", state);// inefficient but whatever for now
            update_ui_layer_state(c);
            break;
        }
    }
    return state;
}
