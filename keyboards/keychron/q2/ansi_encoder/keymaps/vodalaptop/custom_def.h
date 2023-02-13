#pragma once

enum layers {
    BASE,
    _INTL,
    _GAME,
    _NAV,
    _FUN,
    _SYS,
};

// LT(0, ...) keycodes are dummies used for dual function (tap/hold) keys
// Keycode defined inside dummy is tap action if desired
// or arbitrary unique keycode if tap should also be handled specially.
#define DUMMY(KC) LT(0, (KC))

enum custom_keycodes {
    // === Aliases for normal keycodes ===
    CK_SHCL  = LSFT_T(KC_CAPS),     // Shift/Caps-Lock
    CK_SHSL  = RSFT_T(KC_SLSH),     // Mod-tap Slash/RShift
    CK_SPNV  = LT(_NAV, KC_SPC),    // Hold space for toggle nav layer
    CK_TTF   = TT(_FUN),            // Tap-toggle function layer
    CK_TTS   = TT(_SYS),            // Tap-toggle sys layer
    CK_TGI   = TG(_INTL),           // Toggle intl layer
    CK_TGG   = TG(_GAME),           // Toggle gaming layer
    CK_VBFC  = RCTL(KC_F),          // Toggle Fullscreen in vbox
    CK_MYAK  = MEH(KC_F12),         // Yakuake with meh
    CK_OSRA  = OSM(MOD_RALT),       // One-shot right alt
    CK_OSRC  = OSM(MOD_RCTL),       // One-shot right ctrl
    // === Hold/tap dual-function dummies ===
    CK_POS   = DUMMY(KC_0),
    CK_KNOB  = DUMMY(KC_1),
    // === Plain Placeholders ===
    CK_SM0,     // Secret Macro 0
    // US-Intl. Un-dead-keying
    CK_IQT,     // '
    CK_IBT,     // `
    CK_ICX,     // ^
};


// === Custom RGB ===
// Colors corrected for Akko CS Lavender Purple switches' purple tint
#define CRGB_WHITE        200, 255,  35
#define CRGB_RED          255,  42,   8
#define CRGB_CORAL        255, 240,  50
#define CRGB_PEACH        255, 220,  20
#define CRGB_GOLD         230, 200,  10
#define CRGB_SPRINGGREEN  120, 255,   0
#define CRGB_GREEN         75, 250,   0
#define CRGB_TEAL          50, 255, 100
#define CRGB_BLUE           0,  70, 240
#define CRGB_LAVENDER     200, 200, 200
#define CRGB_PINK         255, 100,  50
