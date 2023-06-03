#pragma once

// LT(0, ...) keycodes are dummies used for dual function (tap/hold) keys
// Keycode defined inside dummy is tap action if desired
// or arbitrary unique keycode if tap should also be handled specially.
#define DUMMY(KC) LT(0, (KC))

enum custom_keycodes {
    // === Plain Placeholders ===
    CK_BASE = SAFE_RANGE,  // For switching base layer to BASE
    CK_INTL,    // For switching base layer to INTL
    CK_SM0,     // Secret Macro 0
    // US-Intl. Un-dead-keying
    CK_IQT,     // '
    CK_IBT,     // `
    CK_ICX,     // ^
};
