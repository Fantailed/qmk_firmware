/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "config.h"
#include "custom_def.h"
#include "g/keymap_combo.h"
#include "helper_functions.h"
#include "lighting.h"
#include "secret_macros.h"

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,    KC_EQL,  KC_BSPC,          KC_KNOB,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,   KC_RBRC,  KC_BSLS,          KC_DEL,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,             KC_ENT,           KC_POS,
        KC_SHCL,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,             KC_RSFT, KC_UP,
        KC_LCTL, KC_LWIN, KC_LALT,                            LT(_NAV, KC_SPC),                   KC_MYAK, TT(_FUN), TT(_SYS),  KC_LEFT, KC_DOWN, KC_RGHT),

    [_INTL] = LAYOUT_ansi_67(
        KC_IBT,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_UE,   _______, KC_OE,   _______, _______,  _______,   _______,          _______,
        _______, KC_AE,   KC_SS,   _______, _______, _______, _______, _______, _______, _______, _______, KC_IQT,              _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,   _______, _______, _______),

    [_NAV] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          _______,
        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,  _______,   _______,          _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,             _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,   _______, _______, _______),

    [_FUN] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,   KC_F2  ,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10 , KC_F11 ,   KC_F12,   _______,          KC_KNOB,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          KC_PSCR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,          KC_INS,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, KC_PGUP,
        _______, _______, _______,                            _______,                            OSM(MOD_RALT), _______, OSM(MOD_RCTL),   KC_HOME, KC_WH_D, KC_WH_U),

    [_SYS] = LAYOUT_ansi_67(
        _______, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,   _______,          QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
        _______, TG(_INTL),_______,                            _______,                            _______, _______,  _______,   _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]   = { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)) },
    [_INTL]   = { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)) },
    [_FUN]    = { ENCODER_CCW_CW(LSFT(KC_TAB), KC_TAB) },
    [_SYS] = { ENCODER_CCW_CW(LCTL(KC_PMNS), LCTL(KC_PPLS)) },
};
#endif


// =============================================================================

// Define per-key tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_AE:
            return 190;
        case KC_OE:
            return 180;
        case KC_UE:
            return 160;
        case KC_SS:
            return 190;
        case KC_SHCL:
            return 120;
        case KC_POS:
            return 150;
        case KC_KNOB:
            return 5000;
        default:
            return TAPPING_TERM;
    }
}


// Define per-key special handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // bool shifted = keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT);

    switch (keycode) {
        case KC_AE:
            return process_hold(record, RALT(KC_A));
        case KC_OE:
            return process_hold(record, RALT(KC_O));
        case KC_UE:
            return process_hold(record, RALT(KC_U));
        case KC_SS:
            return process_hold(record, RALT(KC_S));
        case KC_IQT:
            return process_tap_sendstring(record, "' ");
        case KC_IBT:
            return process_tap_sendstring(record, "` ");
        case KC_POS:
            return process_tap_hold(record, KC_HOME, KC_END);
        case KC_KNOB:
            return process_tap_hold(record, KC_VBMIN, QK_BOOT);
#ifdef SECRET_MACRO_0
        case KC_SM0:
            if (record->event.pressed) {
                SECRET_MACRO_0;
                return false;
            }
            return true;
#endif
        default:
            // Just let QMK handle the event normally
            return true;
    }
    return true;
}

// Combo keys
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Scope combos to layers
    switch (combo_index) {
        case DELPOS_SM0:
            return layer_state_is(_SYS);
        case HL_EXPAND:
        case JK_SHRINK:
        case HJ_BEGIN:
        case KL_END:
            return layer_state_is(BASE);
        default:
            return true;
    }
    return true;
}
