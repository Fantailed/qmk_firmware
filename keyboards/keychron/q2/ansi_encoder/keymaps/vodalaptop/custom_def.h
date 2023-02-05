#pragma once

enum layers {
    BASE,
    KB_SYS,
    FN2
};

enum custom_kc {
    // LT(0, ...) keycodes are dummies used for special handling further down
    KC_POS   = LT(0, KC_0),
    KC_KNOB  = LT(0, KC_1),
    // Aliases for normal keycodes
    KC_SHCL  = MT(MOD_LSFT, KC_CAPS),  // Shift/Caps-Lock
    KC_VBMIN = RCTL(KC_F),
    // Placeholders
    KC_SM0,     // Secret Macro 0
    KC_CHL      // hl-combo
};
