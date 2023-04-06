// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

// Left-hand home row mods
#define HOME_O LGUI_T(KC_O)
#define HOME_S LALT_T(KC_S)
#define HOME_I LCTL_T(KC_I)
#define HOME_E LSFT_T(KC_E)

// Right-hand home row mods
#define HOME_T RSFT_T(KC_T)
#define HOME_N RCTL_T(KC_N)
#define HOME_R LALT_T(KC_R)
#define HOME_D RGUI_T(KC_D)

const uint16_t PROGMEM combo_win[] = {HOME_O, HOME_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_win, KC_LGUI),
};

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
    [0] = LAYOUT_split_3x6_3(
        KC_NO,  KC_NO,    DE_Y,    DE_U,    DE_A,    DE_Q,                               DE_P,    DE_B,    DE_M,    DE_L,    KC_NO,  KC_NO,
        DE_J,   DE_C,   HOME_S, HOME_I, HOME_E, HOME_O,                                       HOME_D,  HOME_T,  HOME_N,  HOME_R,  DE_H,   DE_SS,
        KC_NO,  DE_V, DE_X, DE_UDIA, DE_ADIA, DE_ODIA,                                    DE_K,    DE_G,    DE_W,    DE_Z,    DE_F,   KC_NO,
                LT(3, KC_ESC), LT(2, KC_ENTER), LT(1, KC_SPACE),          KC_BSPC, LSFT_T(DE_DOT), KC_TAB
    ),

    // Numbers layer
    [1] = LAYOUT_split_3x6_3(
        KC_NO,    KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,                              KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_NO, KC_NO, LALT_T(KC_LEFT), CTL_T(KC_DOWN), LSFT_T(KC_RGHT), KC_NO,            KC_NO, LSFT_T(KC_4), CTL_T(KC_5), LALT_T(KC_6), KC_NO, KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,
                                           KC_TRNS, KC_TRNS, KC_TRNS,         KC_DEL, DE_COMM, KC_0
    ),

    // Symbol layer, must be one below top (layer-switch-) layer
    [2] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                               DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  KC_NO,   KC_NO,
        DE_EURO, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                             DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_AT, DE_AMPR,
        KC_NO,   DE_DLR, DE_HASH, DE_PIPE, DE_TILD, DE_GRV,                               DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, KC_NO,   KC_NO,
                                            KC_TRNS, KC_TRNS, KC_TRNS,         KC_DEL, DE_SCLN, KC_TRNS
    ),

    // Symbol layer
    [3] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS  , DE_COLN  , KC_TRNS
    ),

};
