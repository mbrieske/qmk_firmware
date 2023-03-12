// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_german.h"

const uint16_t PROGMEM combo_comma_0[] = {LSFT_T(KC_DOT), LSFT_T(DE_T), COMBO_END};
const uint16_t PROGMEM combo_semicolon_0[] = {LSFT_T(KC_DOT), CTL_T(DE_N), COMBO_END};
const uint16_t PROGMEM combo_colon_0[] = {LSFT_T(KC_DOT), LALT_T(DE_R), COMBO_END};
const uint16_t PROGMEM combo_comma_1[] = {LSFT_T(KC_DOT), LSFT_T(KC_4), COMBO_END};
const uint16_t PROGMEM combo_semicolon_1[] = {LSFT_T(KC_DOT), CTL_T(KC_5), COMBO_END};
const uint16_t PROGMEM combo_colon_1[] = {LSFT_T(KC_DOT), LALT_T(KC_6), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_comma_0, DE_COMM),
    COMBO(combo_semicolon_0, DE_SCLN),
    COMBO(combo_colon_0, DE_COLN),
    COMBO(combo_comma_1, DE_COMM),
    COMBO(combo_semicolon_1, DE_SCLN),
    COMBO(combo_colon_1, DE_COLN),
};

enum {
    TD_LAYER_DEFAULT_ESC,
    // TD_DOT_SEMICOLON,
    // TD_COMMA_COLON
};

void td_layer_default_esc_tap(tap_dance_state_t *state, void *user_data) {
    layer_clear();
    layer_on(2);
    layer_on(3);
    tap_code(KC_ESC);
}

void td_layer_default_esc_reset(tap_dance_state_t *state, void *user_data) {
    if (state->interrupting_keycode != TO(2))
        layer_off(2);
    layer_off(3);
}

// void td_dot_semicolon_tap(tap_dance_state_t *state, void *user_data) {
//     tap_code(KC_DOT);
// };

// void td_dot_semicolon_finish(tap_dance_state_t *state, void *user_data) {
//     if (state->pressed)
//     {
//         const uint8_t real_mods = get_mods();
//         clear_mods();
//         tap_code(KC_BACKSPACE);
//         tap_code16(LSFT(KC_COMMA));
//         set_mods(real_mods);
//     }
// };

// void td_comma_colon_tap(tap_dance_state_t *state, void *user_data) {
//     tap_code(KC_COMMA);
// };

// void td_comma_colon_finish(tap_dance_state_t *state, void *user_data) {
//     if (state->pressed)
//     {
//         const uint8_t real_mods = get_mods();
//         clear_mods();
//         tap_code(KC_BACKSPACE);
//         tap_code16(LSFT(KC_DOT));
//         set_mods(real_mods);
//     }
// };

tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER_DEFAULT_ESC] = ACTION_TAP_DANCE_FN_ADVANCED(td_layer_default_esc_tap, NULL, td_layer_default_esc_reset),
    //[TD_DOT_SEMICOLON] = ACTION_TAP_DANCE_FN_ADVANCED(td_dot_semicolon_tap, td_dot_semicolon_finish, NULL),
    //[TD_COMMA_COLON] = ACTION_TAP_DANCE_FN_ADVANCED(td_comma_colon_tap, td_comma_colon_finish, NULL),
};


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
        KC_NO ,  KC_NO,    DE_Y,    DE_U,    DE_A,    DE_Q,                               DE_P,    DE_B,    DE_M,    DE_L,    KC_NO,  KC_NO,
        DE_J, DE_C, LALT_T(DE_S), CTL_T(DE_I), LSFT_T(DE_E), DE_O,                DE_D,    LSFT_T(DE_T),    CTL_T(DE_N),    LALT_T(DE_R),    DE_H,   DE_SS,
        KC_NO,  DE_V, DE_X, DE_UDIA, DE_ADIA, DE_ODIA,                            DE_K,    DE_G,    DE_W,    DE_Z,    DE_F,   KC_NO,
                TD(TD_LAYER_DEFAULT_ESC), LT(2, KC_SPACE), LT(1, KC_ENTER),          KC_BSPC, LSFT_T(KC_DOT), KC_TAB
    ),

    // Numbers layer
    [1] = LAYOUT_split_3x6_3(
        KC_NO,    KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,                              KC_NO,   KC_7,    KC_8,    KC_9,    KC_NO,   KC_NO,
        KC_NO, KC_NO, LALT_T(KC_LEFT), CTL_T(KC_DOWN), LSFT_T(KC_RGHT), KC_NO,            KC_NO, LSFT_T(KC_4), CTL_T(KC_5), LALT_T(KC_6), KC_NO, KC_NO,
        KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                              KC_NO,   KC_1,    KC_2,    KC_3,    KC_NO,   KC_NO,
                                           KC_TRNS, KC_TRNS, KC_TRNS,         KC_DEL, KC_TRNS, KC_0
    ),

    // Symbol layer, must be one below top (layer-switch-) layer
    [2] = LAYOUT_split_3x6_3(
        KC_NO,   KC_NO, DE_UNDS, DE_LBRC, DE_RBRC, DE_CIRC,                               DE_EXLM, DE_LABK, DE_RABK, DE_EQL,  KC_NO,   KC_NO,
        DE_EURO, DE_BSLS, DE_SLSH, DE_LCBR, DE_RCBR, DE_ASTR,                             DE_QUES, DE_LPRN, DE_RPRN, DE_MINS, DE_AT, DE_AMPR,
        KC_NO,   DE_DLR, DE_HASH, DE_PIPE, DE_TILD, DE_GRV,                               DE_PLUS, DE_PERC, DE_DQUO, DE_QUOT, KC_NO,   KC_NO,
                                            KC_TRNS, KC_TRNS, KC_TRNS,         KC_DEL, KC_TRNS, KC_TRNS
    ),

    // Symbol layer
    [3] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                            KC_TRNS, KC_TRNS, KC_TRNS,         TO(2)  , TO(1)  , KC_NO
    ),

};
