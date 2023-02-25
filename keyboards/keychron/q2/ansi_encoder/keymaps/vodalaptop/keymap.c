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


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE] = LAYOUT_ansi_67(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,   KC_EQL,  KC_BSLS,          CK_KNOB,
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           CK_POS,
        CK_LSCW,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            CK_RSCL, KC_UP,
        CK_OSLC, KC_LWIN, CK_OSLA,                            CK_SPNV,                            CK_MYAK, CK_TTF ,  CK_TTS ,  KC_LEFT, KC_DOWN, KC_RGHT),

    [_INTL] = LAYOUT_ansi_67(
        CK_IBT,  _______, _______, _______, _______, _______, CK_ICX , _______, _______, _______, _______, _______,  _______,   _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CK_IQT ,             _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,   _______, _______, _______),

    [_GAME] = LAYOUT_ansi_67(
        KC_ESC , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   KC_BSPC,          _______,
        KC_TAB , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   KC_BSLS,          _______,
        KC_CAPS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,          _______,
        KC_LSFT,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             KC_RSFT, _______,
        KC_LCTL, KC_NO  , KC_LALT,                            KC_SPC ,                            KC_NO  , _______,  _______,   _______, _______, _______),

    [_NUM] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, KC_P7  , KC_P8  , KC_P9  , KC_P0  , KC_PMNS,  KC_PPLS,   _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P4  , KC_P5  , KC_P6  , _______, _______,  _______,   _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_P1  , KC_P2  , KC_P3  , KC_PENT, _______,             _______,          _______,
        _______,          _______, _______, _______, _______, _______, KC_PAST, KC_P0  , KC_COMM, KC_PDOT, KC_PSLS,             _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,   _______, _______, _______),

    [_NAV] = LAYOUT_ansi_67(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          _______,
        _______, _______, KC_BTN1, KC_MS_U, KC_BTN2, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,  _______,   _______,          _______,
        _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,             _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, _______,
        _______, _______, _______,                            _______,                            _______, _______,  _______,   _______, _______, _______),

    [_FUN] = LAYOUT_ansi_67(
        KC_TILD, KC_F1,   KC_F2  ,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10 , KC_F11 ,   KC_F12,   _______,          CK_KNOB,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          KC_PSCR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______,          KC_INS,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,             _______, KC_PGUP,
        _______, _______, _______,                            _______,                            CK_OSRA, _______,  CK_OSRC,   KC_HOME, KC_WH_D, KC_WH_U),

    [_SYS] = LAYOUT_ansi_67(
        _______, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,   _______,          QK_BOOT,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,          _______,
        _______, _______, _______, _______, _______, CK_TGG , _______, _______, _______, _______, _______, _______,             _______,          _______,
        _______,          _______, _______, _______, _______, _______, CK_TGN , _______, _______, _______, _______,             _______, _______,
        _______, CK_TGI , _______,                            _______,                            _______, _______,  _______,   _______, _______, _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE]   = { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)) },
    [_INTL]  = { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)) },
    [_NAV]   = { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)) },
    [_FUN]   = { ENCODER_CCW_CW(LSFT(KC_TAB), KC_TAB) },
    [_SYS]   = { ENCODER_CCW_CW(LCTL(KC_PMNS), LCTL(KC_PPLS)) },
    [_GAME]  = { ENCODER_CCW_CW(LCTL(KC_PGUP), LCTL(KC_PGDN)) },
};
#endif


// =============================================================================

// Define per-key tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_TTF:
        case CK_TTS:
        case CK_TGI:
            return 110;
        case CK_SPNV:
            return 150;
        case CK_LSCW:
        case CK_RSCL:
            return 100;
        case CK_POS:
            return 110;
        case CK_KNOB:
            return 5000;
        default:
            return TAPPING_TERM;
    }
}


// Define per-key special handling
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool isShifted;

    // On key down
    if (record->event.pressed) {

        isShifted = get_mods() & MOD_MASK_SHIFT;

        switch (keycode) {
            // Un-dead-key in intl. layout + auto-shift
            case CK_IQT:    // Intl. quote
                return process_tap_hold_sendstring(record, "' ", "\" ");
            case CK_IBT:    // Intl. backtick
                return process_tap_hold_sendstring(record, "` ", "~ ");
            case CK_ICX:    // Intl. circumflex
                if (isShifted) {
                    send_string("6 ");
                    return false;
                } else {
                    // Reproduce auto-shift
                    return process_tap_hold_sendstring(record, "6", "^ ");
                }
            // Simple tap/hold assignments
            case CK_POS:
                return process_tap_hold(record, KC_HOME, KC_END);
            case CK_KNOB:
                return process_tap_hold(record, CK_VBFC, QK_BOOT);
            case CK_LSCW:    // LShift/Caps-Word
                // When tapped
                if (record->tap.count > 0) {
                    caps_word_toggle();
                // When held
                } else {
                    register_code16(KC_LSFT);
                }
                return false;
#ifdef SECRET_MACRO_0
            case CK_SM0:
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
    // On key up
    } else {
        switch (keycode) {
            case CK_LSCW: // LShift/Caps-Word
                unregister_code16(KC_LSFT);
        }
    }

    return true;
}

// Combo keys
bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // Use this instead of layer_state_is if all layers are inactive and you need to catch the default layer
    uint8_t curr_layer = get_highest_layer(layer_state|default_layer_state);

    // Scope combos to layers
    switch (combo_index) {
        case HL_EXPAND:
        case JK_SHRINK:
        case HJ_BEGIN:
        case KL_END:
            return layer_state_is(BASE) || layer_state_is(_INTL);
        case DELPOS_SM0:
            return layer_state_is(_SYS);
        case AE_GU:
        case OE_GU:
        case UE_GU:
        case SE_GU:
        case EUR_EURO:
            return curr_layer == _INTL;
        case WR_MSMID:
            return layer_state_is(_NAV);
        default:
            return true;
    }
    return true;
}

// Do stuff on layer change
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state | default_layer_state)) {
        case _GAME:
            autoshift_disable();
            break;
        default:
            autoshift_enable();
            break;
    }
    return state;
}
