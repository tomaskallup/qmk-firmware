/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "version.h"
#include "string.h"

#include "custom.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *[CLEAN] = LAYOUT_moonlander(
     *    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
     *    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
     *    _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
     *    _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
     *    _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
     *                                        _______, _______, _______,        _______, _______, _______
     *),
     */
    [BASE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, QK_BOOT,        _______, _______, _______, _______, _______, _______, _______,
       OSL(CZE), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,        _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TO(ARR),
  OSM(MOD_LSFT), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,        _______, KC_H,    KC_J,    KC_K,    KC_L,    OSL(SYM), OSM(MOD_RSFT),
  OSM(MOD_LCTL), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_LALT,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            KC_LGUI, KC_SPC,  KC_BSPC,        OSL(NUM),KC_ENT,  KC_TAB
    ),
    [SYM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,        _______, _______, _______, _______, _______, PR_SC,   _______,
        KC_LSFT, KC_AMPR, KC_BSLS, OSL(NUM),TD(OPRN),TD(CPRN),_______,        _______, KC_QUOT, KC_SCLN, KC_CIRC, KC_PIPE, OSL(ARR),KC_RSFT,
        KC_LCTL, _______, KC_BSLS, KC_TILD, KC_LBRC, KC_RBRC,                          KC_GRV,  KC_COLN, _______, _______, FMT,     KC_LALT,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        TO(BASE),_______, _______
    ),
    [NUM] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
        KC_LSFT, KC_PPLS, KC_MINS, _______, KC_PAST, KC_PSLS, _______,        _______, KC_0,    KC_4,    KC_5,    KC_6,    KC_EQL,  KC_RSFT,
        KC_LCTL, _______, _______, _______, _______, _______,                          KC_DOT,  KC_1,    KC_2,    KC_3,    _______, KC_LALT,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        TO(BASE),_______, _______
    ),
    [CZE] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, CZ_EE,   CZ_E,    CZ_R,    CZ_T,    _______,        _______, CZ_Y,    CZ_U,    CZ_I,    CZ_O,    _______, _______,
        KC_LSFT, CZ_A,    CZ_S,    CZ_D,    _______, _______, _______,        _______, _______, CZ_UU,   _______, _______, _______, KC_RSFT,
        KC_LCTL, CZ_Z,    _______, CZ_C,    _______, _______,                          CZ_N,    _______, _______, _______, _______, KC_LALT,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        TO(BASE),_______, _______
    ),
    [ARR] = LAYOUT_moonlander(
        _______, _______, _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, KC_WH_U, _______,        _______, KC_V_UP, KC_V_DN, _______, _______, _______, TO(BASE),
        KC_LSFT, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, TO(BASE),KC_RSFT,
        KC_LCTL, _______, _______, _______, _______, KC_WH_D,                          _______, _______, _______, _______, _______, KC_LALT,
        _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,        KC_BTN1, _______, KC_BTN2
    ),
};
