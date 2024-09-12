#include QMK_KEYBOARD_H

#include "utils.c"
#include "enums.c"

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [OPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_LCBR),
    [CPRN] = ACTION_TAP_DANCE_DOUBLE(KC_RPRN, KC_RCBR),
};

// Custom aliases
#define C_LCTL OSM(MOD_LCTL)
#define C_LSFT OSM(MOD_LSFT)
#define C_RCTL RCTL_T(KC_SLSH)
#define KC_V_UP KC_KB_VOLUME_UP
#define KC_V_DN KC_KB_VOLUME_DOWN

// Combos
const uint16_t PROGMEM custom_esc[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM qmk_boot[] = {KC_R, KC_TAB, COMBO_END};
const uint16_t PROGMEM arr_panic[] = {KC_UP, KC_DOWN, COMBO_END};
const uint16_t PROGMEM sym_panic[] = {KC_SCLN, KC_CIRC, COMBO_END};
combo_t                key_combos[] = {
    COMBO(custom_esc, KC_ESC),
    COMBO(qmk_boot, QK_BOOT),
    COMBO(arr_panic, TO(BASE)),
};

int16_t last_keycode = -1;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CZ_E:
            if (record->event.pressed) {
                send_czech_letter("e", "c");
                return false;
            }
        case CZ_EE:
            if (record->event.pressed) {
                send_czech_letter("e", "'");
                return false;
            }
        case CZ_R:
            if (record->event.pressed) {
                send_czech_letter("r", "c");
                return false;
            }
        case CZ_T:
            if (record->event.pressed) {
                send_czech_letter("t", "c");
                return false;
            }
        case CZ_Y:
            if (record->event.pressed) {
                send_czech_letter("y", "'");
                return false;
            }
        case CZ_U:
            if (record->event.pressed) {
                send_czech_letter("u", "o");
                return false;
            }
        case CZ_UU:
            if (record->event.pressed) {
                send_czech_letter("u", "'");
                return false;
            }
        case CZ_I:
            if (record->event.pressed) {
                send_czech_letter("i", "'");
                return false;
            }
        case CZ_O:
            if (record->event.pressed) {
                send_czech_letter("o", "'");
                return false;
            }
        case CZ_A:
            if (record->event.pressed) {
                send_czech_letter("a", "'");
                return false;
            }
        case CZ_S:
            if (record->event.pressed) {
                send_czech_letter("s", "c");
                return false;
            }
        case CZ_D:
            if (record->event.pressed) {
                send_czech_letter("d", "c");
                return false;
            }
        case CZ_Z:
            if (record->event.pressed) {
                send_czech_letter("z", "c");
                return false;
            }
        case CZ_C:
            if (record->event.pressed) {
                send_czech_letter("c", "c");
                return false;
            }
        case CZ_N:
            if (record->event.pressed) {
                send_czech_letter("n", "c");
                return false;
            }
        case FMT:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_SPACE) SS_DELAY(100) SS_TAP(X_EQUAL));
                return false;
            }
        case PR_SC:
            if (record->event.pressed) {
                SEND_STRING(SS_RGUI(SS_TAP(X_PSCR)));
                return false;
            }
        case BSP_DEL: {
            const uint8_t  mods          = get_mods();
            const uint8_t  one_shot_mods = get_oneshot_mods();
            const uint16_t key_to_send   = ((get_mods() | one_shot_mods) & MOD_MASK_SHIFT) ? KC_DEL : KC_BSPC;
            clear_mods();
            clear_oneshot_mods();
            if (record->event.pressed && last_keycode != key_to_send) {
                if (last_keycode != -1) {
                    unregister_code(last_keycode);
                }
                register_code(key_to_send);
                last_keycode = key_to_send;
            } else if (!record->event.pressed && last_keycode != -1) {
                unregister_code(last_keycode);
                last_keycode = -1;
            }
            set_mods(mods);
            set_oneshot_mods(one_shot_mods);
            return false;
        }
    }
    return true;
}
