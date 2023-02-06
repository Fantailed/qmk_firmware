#include QMK_KEYBOARD_H
#include "helper_functions.h"

// Helper functions for tap/hold dual functions
bool process_tap_hold(keyrecord_t *record, uint16_t tap_key, uint16_t hold_key) {
    // When tapped
    if (record->event.pressed && record->tap.count > 0) {
        tap_code16(tap_key);
    // When held
    } else if (record->event.pressed) {
        tap_code16(hold_key);
    }
    return false;
}

bool process_hold(keyrecord_t *record, uint16_t hold_key) {
    // When held
    if (record->event.pressed && record->tap.count == 0) {
        tap_code16(hold_key);
        return false;
    } else {
        return true;
    }
}

bool process_hold_sendstring(keyrecord_t *record, const char *hold_keys) {
    // When held
    if (record->event.pressed && record->tap.count == 0) {
        send_string(hold_keys);
        return false;
    } else {
        return true;
    }
}
