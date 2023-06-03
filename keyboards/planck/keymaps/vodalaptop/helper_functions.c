#include QMK_KEYBOARD_H
#include "helper_functions.h"

// === Helper functions for tap/hold dual functions ===

bool process_tap(keyrecord_t *record, uint16_t tap_key) {
    // Only special-handle taps
    if (record->tap.count > 0) {
        tap_code16(tap_key);
        return false;
    } else {
        return true;
    }
}

bool process_tap_sendstring(keyrecord_t *record, const char *tap_string) {
    // Only special-handle taps
    if (record->tap.count > 0) {
        send_string(tap_string);
        return false;
    } else {
        return true;
    }
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

bool process_hold_sendstring(keyrecord_t *record, const char *hold_string) {
    // When held
    if (record->tap.count == 0) {
        send_string(hold_string);
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

bool process_tap_hold_sendstring(keyrecord_t *record, const char *tap_string, const char *hold_string) {
    // When tapped
    if (record->tap.count > 0) {
        send_string(tap_string);
        // When held
    } else {
        send_string(hold_string);
    }
    return false;
}

bool process_noshift_shift_sendstring(bool isShifted, const char *noshift_string, const char *shift_string) {
    if (isShifted) {
        send_string(shift_string);
    } else {
        send_string(noshift_string);
    }
    return false;
}

bool process_intl_off_on_sendstring(bool intlIsOn, const char *intl_off_string, const char *intl_on_string) {
    if (intlIsOn) {
        send_string(intl_on_string);
    } else {
        send_string(intl_off_string);
    }
    return false;
}
