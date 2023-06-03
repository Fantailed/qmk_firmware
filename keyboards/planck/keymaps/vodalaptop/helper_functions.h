#pragma once

#include QMK_KEYBOARD_H

bool process_tap(keyrecord_t*, uint16_t);
bool process_tap_sendstring(keyrecord_t*, const char*);
bool process_hold(keyrecord_t*, uint16_t);
bool process_hold_sendstring(keyrecord_t*, const char*);
bool process_tap_hold(keyrecord_t*, uint16_t, uint16_t);
bool process_tap_hold_sendstring(keyrecord_t *record, const char*, const char*);
bool process_noshift_shift_sendstring(bool isShifted, const char*, const char*);
