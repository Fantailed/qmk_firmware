#pragma once

#include QMK_KEYBOARD_H

bool process_tap_hold(keyrecord_t*, uint16_t, uint16_t);
bool process_hold(keyrecord_t*, uint16_t);
bool process_hold_sendstring(keyrecord_t*, const char*);
