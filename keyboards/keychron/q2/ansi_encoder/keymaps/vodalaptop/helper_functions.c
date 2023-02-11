#include QMK_KEYBOARD_H
#include "helper_functions.h"

// Helper functions for tap/hold dual functions
bool process_tap(keyrecord_t *record, uint16_t tap_key) {
    tap_code16(tap_key);
    return false;
}

bool process_tap_sendstring(keyrecord_t *record, const char *tap_keys) {
    send_string(tap_keys);
    return false;
}

bool process_hold(keyrecord_t *record, uint16_t hold_key) {
    // When held
    if (record->tap.count == 0) {
        tap_code16(hold_key);
        return false;
    } else {
        return true;
    }
}

bool process_hold_sendstring(keyrecord_t *record, const char *hold_keys) {
    // When held
    if (record->tap.count == 0) {
        send_string(hold_keys);
        return false;
    } else {
        return true;
    }
}

bool process_tap_hold(keyrecord_t *record, uint16_t tap_key, uint16_t hold_key) {
    // When tapped
    if (record->tap.count > 0) {
        tap_code16(tap_key);
    // When held
    } else {
        tap_code16(hold_key);
    }
    return false;
}
