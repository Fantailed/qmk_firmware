#include QMK_KEYBOARD_H
#include "custom_def.h"
#include "lighting.h"

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Red caps lock light overrides all layer indicators
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i < led_max; i++) {
            rgb_matrix_set_color(i, RGB_RED);
        }
    } else {
        // Layer indicators
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case BASE:
                rgb_matrix_set_color_all(CSL_PEACH);
                break;
            case INTL:
                rgb_matrix_set_color_all(RGB_ORANGE);
                break;
            case KB_SYS:
                set_kb_sys_colors();
                break;
            case FN2:
                rgb_matrix_set_color_all(CSL_LAVENDER);
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
    rgb_matrix_set_color_all(CSL_WHITE);

    // Macros
    rgb_matrix_set_color(1, CSL_SPRINGGREEN);
    rgb_matrix_set_color(2, CSL_SPRINGGREEN);
    rgb_matrix_set_color(3, CSL_SPRINGGREEN);
    rgb_matrix_set_color(4, CSL_SPRINGGREEN);
    rgb_matrix_set_color(5, CSL_SPRINGGREEN);
    rgb_matrix_set_color(6, CSL_SPRINGGREEN);

    // prev/playpause/next
    rgb_matrix_set_color(7, CSL_CORAL);
    rgb_matrix_set_color(8, CSL_CORAL);
    rgb_matrix_set_color(9, CSL_CORAL);

    // mute
    rgb_matrix_set_color(10, CSL_BLUE);
    // vol up/down
    rgb_matrix_set_color(11, CSL_TEAL);
    rgb_matrix_set_color(12, CSL_TEAL);

    // left meta
    rgb_matrix_set_color(58, RGB_ORANGE);
}
