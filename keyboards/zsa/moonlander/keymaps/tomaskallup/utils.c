#include QMK_KEYBOARD_H
#include "string.h"
#include "stdlib.h"

void send_czech_letter(char* key, char* accent) {
    const uint8_t mods = get_mods();
    const uint8_t one_shot_mods = get_oneshot_mods();
    clear_mods();
    clear_oneshot_mods();

    bool should_shift = (( mods | one_shot_mods ) & MOD_MASK_SHIFT);

    SEND_STRING(SS_DOWN(X_RALT));
    send_string(accent);
    SEND_STRING(SS_UP(X_RALT));

    char* modifier_down = should_shift ? SS_DOWN(X_LSFT) : "";
    char* modifier_up = should_shift ? SS_UP(X_LSFT) : "";

    char* key_to_send = malloc(sizeof(modifier_down) + sizeof(modifier_up) + sizeof(key));

    strcpy(key_to_send, modifier_down);
    strcat(key_to_send, key);
    strcat(key_to_send, modifier_up);

    send_string(key_to_send);

    free(key_to_send);

    set_mods(mods);
}
