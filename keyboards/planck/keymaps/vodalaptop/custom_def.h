#pragma once

enum planck_layers {
    _BASE,
    _INTL,
    _LOWER,
    _RAISE,
    _NAV,
    _ADJUST
};

// LT(0, ...) keycodes are dummies used for dual function (tap/hold) keys
// Keycode defined inside dummy is tap action if desired
// or arbitrary unique keycode if tap should also be handled specially.
#define DUMMY(KC) LT(0, (KC))

enum custom_keycodes {
    // === Aliases for normal keycodes ===
    CK_RSCL  = RSFT_T(KC_CAPS),     // RShift/Caps-Lock
    CK_YAK   = LGUI(KC_F12),        // Yakuake with Meta+F12
    CK_MYAK  = MEH(KC_F12),         // Yakuake with meh
    CK_SPNV  = LT(_NAV, KC_SPC),    // Hold space for toggle nav layer
    // === Hold/tap dual-function dummies ===
    CK_LSCW  = DUMMY(KC_0),
    // === Plain Placeholders ===
    CK_BASE = SAFE_RANGE,           // For switching base layer to BASE
    CK_INTL,                        // For switching base layer to INTL
    CK_SM0,                         // Secret Macro 0
    // US-Intl. Un-dead-keying
    CK_IQT,     // '
    CK_IBT,     // `
    CK_ITIL,    // ~
    CK_ICX,     // ^
};
