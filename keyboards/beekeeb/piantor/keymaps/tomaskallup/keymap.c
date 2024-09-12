// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "custom.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    /*
    [EMPTY] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,          _______, _______, _______
    )
    */
    [BASE] = LAYOUT_split_3x6_3(
       OSL(CZE), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     TO(ARR),
  OSM(MOD_LSFT), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    OSL(SYM), OSM(MOD_RSFT),
  OSM(MOD_LCTL), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_LALT,
                                            KC_LGUI, KC_SPC, KC_BSPC,           OSL(NUM),KC_ENT,  KC_TAB
    ),
    [SYM] = LAYOUT_split_3x6_3(
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            _______, _______, _______, _______, PR_SC,   _______,
        KC_LSFT, KC_AMPR, KC_BSLS, OSL(NUM),TD(OPRN),TD(CPRN),                           KC_QUOT, KC_SCLN, KC_CIRC, KC_PIPE, OSL(ARR),KC_RSFT,
        _______, _______, KC_BSLS, KC_TILD, KC_LBRC, KC_RBRC,                            KC_GRV,  KC_COLN, _______, _______, FMT,     _______,
                                            _______, _______, _______,          TO(BASE), _______, _______
    ),
    [NUM] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                            _______, KC_7,    KC_8,    KC_9,    _______, _______,
        KC_LSFT, KC_PPLS, KC_MINS, _______, KC_PAST, KC_PSLS,                            KC_0,    KC_4,    KC_5,    KC_6,    KC_EQL,  KC_RSFT,
        _______, _______, _______, _______, _______, _______,                            KC_DOT,  KC_1,    KC_2,    KC_3,    _______, _______,
                                            _______, _______, _______,          TO(BASE), _______, _______
    ),
    [CZE] = LAYOUT_split_3x6_3(
        _______, _______, CZ_EE,   CZ_E,    CZ_R,    CZ_T,                               CZ_Y,    CZ_U,    CZ_I,    CZ_O,    _______, _______,
        KC_LSFT, CZ_A,    CZ_S,    CZ_D,    _______, _______,                            _______, CZ_UU,   _______, _______, _______, KC_RSFT,
        _______, CZ_Z,    _______, CZ_C,    _______, _______,                            CZ_N,    _______, _______, _______, _______, _______,
                                            _______, _______, _______,          TO(BASE), _______, _______
    ),
    [ARR] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, KC_WH_U,                            KC_V_UP, KC_V_DN, _______, _______, _______, TO(BASE),
        KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TO(BASE),KC_RSFT,
        KC_LCTL, _______, _______, _______, _______, KC_WH_D,                            _______, _______, _______, _______, _______, KC_LALT,
                                            _______, _______, _______,          KC_BTN1, _______, KC_BTN2
    )
};
