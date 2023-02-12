#pragma once

enum layers {
    BASE,
    _INTL,
    _NAV,
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
    KC_POS   = DUMMY(KC_0),
    KC_KNOB  = DUMMY(KC_1),
    // Placeholders
    KC_SM0,     // Secret Macro 0
    KC_CHL,     // hl-combo
    // US-Intl. Un-dead-keying
    KC_IQT,     // '
    KC_IBT,     // `
    KC_ICX,     // ^
};

// Perceived colors after Akko CS Lavender Purple switches' purple skew
#define CSL_WHITE        200, 255,  35
#define CSL_CORAL        255, 240,  50
#define CSL_PEACH        255, 220,  20
#define CSL_GOLD         230, 200,  10
#define CSL_SPRINGGREEN  120, 255,   0
#define CSL_TEAL          50, 255, 100
#define CSL_BLUE           0,  70, 240
#define CSL_LAVENDER     200, 200, 200
#define CSL_PINK         255, 100,  50
