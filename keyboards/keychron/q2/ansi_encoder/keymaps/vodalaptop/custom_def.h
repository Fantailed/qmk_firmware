#pragma once

enum layers {
    BASE,
    _INTL,
    _FUN,
    _SYS,
};

#define DUMMY(KC) LT(0, (KC))

enum custom_kc {
    // Aliases for normal keycodes
    KC_SHCL  = MT(MOD_LSFT, KC_CAPS),  // Shift/Caps-Lock
    KC_VBMIN = RCTL(KC_F),
    KC_MYAK  = MEH(KC_F12),           // Yakuake inside vbox
    // LT(0, ...) keycodes are dummies used for dual function (tap/hold) keys
    // Keycode defined inside dummy is tap action if desired
    // or arbitrary unique keycode if tap should also be handled specially.
    KC_AE    = DUMMY(KC_A),
    KC_OE    = DUMMY(KC_O),
    KC_UE    = DUMMY(KC_U),
    KC_SS    = DUMMY(KC_S),
    KC_IQT   = DUMMY(KC_QUOT),  // Un-deadkey quote on intl layout
    KC_IBT   = DUMMY(KC_GRV),   // Un-deadkey backtick/grave on intl layout
    KC_ICX   = DUMMY(KC_6),     // Un-deadkey ^ on intl layout
    KC_POS   = DUMMY(KC_0),
    KC_KNOB  = DUMMY(KC_1),
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
