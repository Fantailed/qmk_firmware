#pragma once

enum layers {
    BASE,
    INTL,
    KB_SYS,
    FN2,
};

enum custom_kc {
    // LT(0, ...) keycodes are dummies used for special handling further down
    KC_AE    = LT(0, KC_A),
    KC_OE    = LT(0, KC_O),
    KC_UE    = LT(0, KC_U),
    KC_SS    = LT(0, KC_S),
    KC_IQT   = LT(0, KC_QUOT),  // Un-deadkey quote on intl layout
    KC_IBT   = LT(0, KC_GRV),   // Un-deadkey backtick/grave on intl layout
    KC_ICX   = LT(0, KC_6),     // Un-deadkey ^ on intl layout
    KC_POS   = LT(0, KC_0),
    KC_KNOB  = LT(0, KC_1),
    // Aliases for normal keycodes
    KC_SHCL  = MT(MOD_LSFT, KC_CAPS),  // Shift/Caps-Lock
    KC_VBMIN = RCTL(KC_F),
    // Placeholders
    KC_SM0,     // Secret Macro 0
    KC_CHL,     // hl-combo
};
