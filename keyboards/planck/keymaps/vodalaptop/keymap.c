/* Copyright 2015-2021 Jack Humbert
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
#include "custom_def.h"
#include "g/keymap_combo.h"
#include "helper_functions.h"

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |LSftCW|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |RSftCL|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Meta | Alt  |Yakuak|Lower |  Space/Nav  |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_BASE] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    CK_LSCW, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, CK_RSCL,
    KC_LCTL, KC_LGUI, KC_LALT, CK_YAK, LOWER, CK_SPNV, CK_SPNV,   RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* INTL Dead Keys (Win Style)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_INTL] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, CK_IQT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | [I]~ |   !  |   @  |   #  |   $  |   %  | [I]^ |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |PrScr | Ins  | NumL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RCtrl |RMeta | Ralt |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    CK_ITIL, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, CK_ICX,  KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_PSCR, KC_INS,  KC_NUM,
    KC_RCTL, KC_RGUI, KC_RALT, _______, _______, _______, _______, _______,    KC_HOME,    KC_PGDN, KC_PGUP, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | [I]` |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |PrScr | Ins  | NumL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RCtrl |RMeta | Ralt |      |      |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    CK_IBT,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PSCR, KC_INS,  KC_NUM,
    KC_RCTL, KC_RGUI, KC_RALT, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

/* Navigation layer (Mouse emulation) + NumPad
 * ,-----------------------------------------------------------------------------------.
 * |RClick| M <  | M v  | M ^  | M >  |LClick|MClick|  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | W <  | W v  | W ^  | W >  |      |      |  4   |  5   |  6   |  +   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | A <  | A v  | A ^  | A >  |      |Space |  1   |  2   |  3   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |  0   |  ,   |  .   |  *   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN1, KC_BTN3, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______,
    _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, KC_PEQL,
    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_SPC,  KC_P1,   KC_P2,   KC_P3,   KC_PSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P0,   KC_COMM, KC_PDOT, KC_PAST, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | DM 1 | DM 2 |REC 1 |REC 2 | Prev | Play | Next | Mute | Vol- | Vol+ |Reset |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |AuTogg|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |MuTogg|MuMode|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BASE | INTL |      |      |      |             |      |      |      |      |Debug |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, DM_PLY1, DM_PLY2, DM_REC1, DM_REC2, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, QK_BOOT,
    _______, AU_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, MU_TOGG, MU_NEXT, _______, _______, _______,
    CK_BASE, CK_INTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, DB_TOGG
)

};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

// Define per-key tapping terms
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CK_LSCW:
        case CK_RSCL:
            return 90;
        case CK_SPNV:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool isShifted;
    static bool intlIsBase = false;

    if (!is_caps_word_on()) {
        planck_ez_left_led_off();
    }

    // On key down
    if (record->event.pressed) {
        isShifted = get_mods() & MOD_MASK_SHIFT;

        switch (keycode) {
            // LED Indicators
            case CK_LSCW:   // LShift/CapsWord
                // When tapped
                if (record->tap.count > 0) {
                    if (is_caps_word_on()) {
                        caps_word_off();
                        planck_ez_left_led_off();
                    } else {
                        caps_word_on();
                        planck_ez_left_led_on();
                        isShifted = true;
                    }
                // When held
                } else {
                    register_code16(KC_LSFT);
                }
                return false;
            case CK_RSCL:   // RShift/CapsLock
                // If tapped
                if (record->tap.count > 0) {
                    if (host_keyboard_led_state().caps_lock) {
                        print("Caps Lock: on -> OFF");
                        planck_ez_right_led_off();
                    } else {
                        print("Caps Lock: off -> ON");
                        planck_ez_right_led_on();
                    }
                }
                return true;

            // Un-dead-key in intl. layout + auto-shift
            case CK_IQT: // Intl. quote, triggered on _INTL only
                return process_noshift_shift_sendstring(isShifted, "' ", "\" ");
            // Triggered from _RAISE/_LOWER and thus need special logic
            case CK_IBT: // Intl. backtick
                return process_intl_off_on_sendstring(intlIsBase, "`", "` ");
            case CK_ITIL: // Intl. tilde
                return process_intl_off_on_sendstring(intlIsBase, "~", "~ ");
            case CK_ICX: // Intl. circumflex
                return process_intl_off_on_sendstring(intlIsBase, "^", "^ ");

            // Base layer changes
            case CK_BASE:
                if (record->event.pressed) {
                    print("Switched base layer to BASE\n");
                    set_single_persistent_default_layer(_BASE);
                    intlIsBase = false;
                }
                return false;
            case CK_INTL:
                if (record->event.pressed) {
                    print("Switched base layer to INTL\n");
                    set_single_persistent_default_layer(_INTL);
                    intlIsBase = true;
                }
                return false;
        }
    // On key up
    } else {
        switch (keycode) {
            case CK_LSCW: // LShift/Caps-Word
                unregister_code16(KC_LSFT);
        }
    }

    // Continue processing key events normally
    return true;
}

bool     muse_mode      = false;
uint8_t  last_muse_note = 0;
uint16_t muse_counter   = 0;
uint8_t  muse_offset    = 70;
uint16_t muse_tempo     = 50;

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case RAISE:
        case LOWER:
            return false;
        default:
            return true;
    }
}
