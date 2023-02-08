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

// Perceived colors after Akko CS Lavender Purple switches' purple skew
#define CSL_WHITE        255, 255,  35
#define CSL_CORAL        255, 240,  50
#define CSL_PEACH        255, 230,  20
#define CSL_SPRINGGREEN  120, 255,   0
#define CSL_TEAL          50, 255, 100
#define CSL_BLUE           0,  70, 240
#define CSL_LAVENDER     200, 200, 200
