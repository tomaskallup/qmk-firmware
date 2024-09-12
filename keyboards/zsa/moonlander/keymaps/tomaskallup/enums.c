#include QMK_KEYBOARD_H

enum layers {
    BASE, // default layer
    SYM,
    NUM,
    CZE,
    ARR,
};

enum custom_keycodes {
    CZ_E = SAFE_RANGE,
    CZ_EE,
    CZ_R,
    CZ_T,
    CZ_Y,
    CZ_U,
    CZ_UU,
    CZ_I,
    CZ_O,
    CZ_A,
    CZ_S,
    CZ_D,
    CZ_Z,
    CZ_C,
    CZ_N,
    FMT,
    PR_SC,
    BSP_DEL,
};

// Tap Dance declarations
enum {
    OPRN,
    CPRN,
};
