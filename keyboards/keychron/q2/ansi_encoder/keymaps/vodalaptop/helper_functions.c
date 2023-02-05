#include QMK_KEYBOARD_H
#include "helper_functions.h"

// Helper functions for tap/hold dual functions
bool define_tap_hold(keyrecord_t *record, uint16_t tap_key, uint16_t hold_key) {
    // When tapped
    if (record->event.pressed && record->tap.count > 0) {
        tap_code16(tap_key);
    // When held for 5s or longer
    } else if (record->event.pressed) {
        tap_code16(hold_key);
    }
    return false;
}
