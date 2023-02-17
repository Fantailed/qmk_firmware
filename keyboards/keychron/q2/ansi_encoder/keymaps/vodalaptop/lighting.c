#include QMK_KEYBOARD_H
#include "custom_def.h"
#include "lighting.h"

static bool caps_word = false;

void caps_word_set_user(bool active) {
    caps_word = active;
}

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Caps Lock/Word indicators override all layer indicators
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color_all(CRGB_RED);
    } else if (caps_word) {
        rgb_matrix_set_color_all(CRGB_PINK);
    } else {
        // Layer indicators
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case BASE:
                rgb_matrix_set_color_all(CRGB_ICE);
                break;
            case _INTL:
                rgb_matrix_set_color_all(CRGB_PEACH);
                break;
            case _NAV:
                rgb_matrix_set_color_all(CRGB_TEAL);
                break;
            case _FUN:
                rgb_matrix_set_color_all(CRGB_LAVENDER);
                break;
            case _GAME:
                rgb_matrix_set_color_all(CRGB_BLUE);
                break;
            case _SYS:
                set_kb_sys_colors();
                break;
            default:
                break;
        }
    }
    return false;
}

// Highlights different functional zones by color
void set_kb_sys_colors() {
    // Default white
    rgb_matrix_set_color_all(CRGB_WHITE);

    // Macros
    rgb_matrix_set_color(1, CRGB_SPRINGGREEN);
    rgb_matrix_set_color(2, CRGB_SPRINGGREEN);
    rgb_matrix_set_color(3, CRGB_GREEN);
    rgb_matrix_set_color(4, CRGB_GREEN);

    // prev/playpause/next
    rgb_matrix_set_color(7, CRGB_CORAL);
    rgb_matrix_set_color(8, CRGB_CORAL);
    rgb_matrix_set_color(9, CRGB_CORAL);

    // mute
    rgb_matrix_set_color(10, CRGB_BLUE);
    // vol up/down
    rgb_matrix_set_color(11, CRGB_TEAL);
    rgb_matrix_set_color(12, CRGB_TEAL);

    // G for game layer
    rgb_matrix_set_color(35, CRGB_BLUE);

    // left meta
    rgb_matrix_set_color(58, CRGB_PEACH);
}
