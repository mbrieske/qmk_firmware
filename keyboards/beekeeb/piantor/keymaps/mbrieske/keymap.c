// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#ifdef PS2_MOUSE_ENABLE
#include "ps2_mouse.h"
#include "ps2.h"
#endif

#define LAYER_DEFAULT 0
#define LAYER_NUM     1
#define LAYER_SYMBOLS 2
#define LAYER_MOUSE   3

// Left-hand home row mods
#define HOME_O LGUI_T(KC_O)
#define HOME_S LALT_T(KC_S)
#define HOME_I LCTL_T(KC_I)
#define HOME_E LSFT_T(KC_E)

// Right-hand home row mods
#define HOME_T RSFT_T(KC_T)
#define HOME_N RCTL_T(KC_N)
#define HOME_R LALT_T(KC_R)
#define HOME_D LT(3, KC_D)

// Left-hand home row mods number-layer
#define HOME_LEFT LALT_T(KC_LEFT)
#define HOME_DOWN CTL_T(KC_DOWN)
#define HOME_RGHT LSFT_T(KC_RGHT)

// Right-hand home row mods numbers-layer
#define HOME_4 LSFT_T(KC_4)
#define HOME_5 CTL_T(KC_5)
#define HOME_6 LALT_T(KC_6)

const uint16_t PROGMEM combo_win[] = {HOME_O, HOME_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_win, KC_LGUI),
};

void ps2_mouse_init_user(void) {
    // trackpoint sensitivity
    PS2_MOUSE_SEND(0xE2, "trackpoint command");
    PS2_MOUSE_SEND(0x81, "write byte");
    PS2_MOUSE_SEND(0x4A, "sensitivity");
    PS2_MOUSE_SEND(0xC0, "data"); // default = x80 (1). range = 0x00 to 0xFF (0 to 1.99)

    // set TrackPoint Negative Inertia factor
    PS2_MOUSE_SEND(0xE2, "trackpoint command");
    PS2_MOUSE_SEND(0x81, "write byte");
    PS2_MOUSE_SEND(0x4D, "negative inertia");
    PS2_MOUSE_SEND(0x03, "data");

    // set TrackPoint speed
    // (transfer function upper plateau speed)
    PS2_MOUSE_SEND(0xE2, "trackpoint command");
    PS2_MOUSE_SEND(0x81, "write byte");
    PS2_MOUSE_SEND(0x60, "value6");
    PS2_MOUSE_SEND(0xFF, "data"); // default = x61

ps2_mouse_set_resolution(PS2_MOUSE_8_COUNT_MM);
ps2_mouse_set_sample_rate(PS2_MOUSE_200_SAMPLES_SEC);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (IS_LAYER_ON_STATE(state, LAYER_MOUSE))
    {
        register_code16(KC_BTN3);
    }
    else
    {
        unregister_code16(KC_BTN3);
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    unregister_code16(KC_BTN3);
    if (keycode == LT(2, KC_SPACE) && record->event.pressed) {
         // Check if either Shift key is active

        if (get_mods() & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) {
            clear_mods();          // Clear all active modifiers

            tap_code(KC_DOT);      // Send Dot
            tap_code(KC_SPC);      // Send Space

            return false;          // Prevent further processing of this key press
        }
    }
    return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_E:
        case HOME_T:
            return TAPPING_TERM - 40;
            break;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_O:
        case HOME_S:
        case HOME_I:
        case HOME_E:
        case HOME_T:
        case HOME_N:
        case HOME_R:
        case HOME_D:
	case HOME_LEFT:
	case HOME_RGHT:
	case HOME_DOWN:
	case HOME_4:
	case HOME_5:
	case HOME_6:
            // Do not force the mod-tap key press to be handled as a modifier
            // if any other key was pressed while the mod-tap key is held down.
            return false;
        default:
            // Force the dual-role key press to be handled as a modifier if any
            // other key was pressed while the mod-tap key is held down.
            return true;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │   │ Y │ U │ A │ Q │       │ P │ B │ M │ L │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ J │ C │ S │ I │ E │ O │       │ D │ T │ N │ E │ H │ ß │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ V │ X │ Ü │ Ä │ Ö │       │ K │ G │ W │ Z │ F │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │MO1├───┐           ┌───┤TAB│
      *               └───┤Spc├───┐   ┌───┤ . ├───┘
      *                   └───┤Ent│   │Bsp├───┘
      *                       └───┘   └───┘
      */
    [LAYER_DEFAULT] = LAYOUT_split_3x6_3(
        KC_MS_WH_UP,  KC_NO,    DE_Y,    DE_U,    DE_A,    DE_Q,                               DE_P,    DE_B,    DE_M,    DE_L,    KC_NO,  KC_NO,
        DE_J,   DE_C,   HOME_S, HOME_I, HOME_E, HOME_O,                                       HOME_D,  HOME_T,  HOME_N,  HOME_R,  DE_H,   DE_SS,
        KC_MS_WH_DOWN,  DE_V, DE_X, DE_UDIA, DE_ADIA, DE_ODIA,                                    DE_K,    DE_G,    DE_W,    DE_Z,    DE_F,   KC_NO,
                LT(3, KC_ESC), LT(2, KC_SPACE), LT(1, KC_ENTER),          KC_BSPC, LSFT_T(DE_DOT), DE_COMM
    ),

    // Numbers layer
    [LAYER_NUM] = LAYOUT_split_3x6_3(
        KC_NO,    KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,                              KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_NO, KC_NO, HOME_LEFT, HOME_DOWN, HOME_RGHT, KC_NO,                             KC_NO, HOME_4, HOME_5, HOME_6, KC_NO, KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,
                                           KC_TRNS, KC_TRNS, KC_TRNS,         KC_DEL, KC_0, KC_TAB
    ),

    // Symbol layer, must be one below top (layer-switch-) layer
    [LAYER_SYMBOLS] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO,   KC_NO, DE_LBRC, DE_RBRC, DE_CIRC,                               DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  KC_NO,   KC_NO,
        DE_EURO, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                             DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_DQUO, DE_GRV,
        KC_NO,   DE_DLR, DE_HASH, DE_PIPE, DE_TILD, DE_AMPR,                              DE_PLUS, DE_PERC, DE_AT,   DE_UNDS, DE_QUOT, KC_NO,
                                            KC_TRNS, KC_TRNS, KC_TRNS,         KC_DEL, DE_COLN, DE_SCLN
    ),

    // Symbol layer
    [LAYER_MOUSE] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_UP, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_WH_DOWN, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,         KC_BTN1  , KC_BTN2  , KC_BTN3
    ),

};
