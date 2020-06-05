#include "common.h"
#ifndef QMK_KEYBOARD_H
#    include "jellowcake303.h"
#    include "config.h"
#else
#    include QMK_KEYBOARD_H
#endif
#include <string.h>
#include <ctype.h>

// clang-format off
static const char *layerNames[] = {
		"TeamFortress2",
		"Egoshooter",
		"Media",
		"TF2 Extras"
};

static const char *rgb_matrix_effect_names[] = {
		"no animation",
#define RGB_MATRIX_EFFECT(name, ...) STR(name),
#include "rgb_matrix_animations/rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
		NULL
};

// clang-format on

const char *get_layer_name(uint8_t layer) { return layerNames[layer]; }

const char *get_effect_name(uint8_t mode) {
    static char str[32];
    strcpy(str, rgb_matrix_effect_names[mode]);

    for (uint8_t i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
        if (str[i] == '_') str[i] = ' ';
    }

    return str;
}

void update_status(kbd_status *status) {
    status->rgb_matrix_enabled = rgb_matrix_is_enabled();
    status->rgb_matrix_mode    = rgb_matrix_get_mode();
    status->rgb_matrix_speed   = rgb_matrix_get_speed();
    status->layer              = get_highest_layer(layer_state);
}

bool status_changed(kbd_status *news, kbd_status *olds) {
    bool changed = (olds->layer != news->layer) || (olds->rgb_matrix_mode != news->rgb_matrix_mode) || (olds->rgb_matrix_enabled != news->rgb_matrix_enabled) || (olds->rgb_matrix_speed != news->rgb_matrix_speed);

    if (changed) {
        olds->layer              = news->layer;
        olds->rgb_matrix_mode    = news->rgb_matrix_mode;
        olds->rgb_matrix_speed   = news->rgb_matrix_speed;
        olds->rgb_matrix_enabled = news->rgb_matrix_enabled;
    }

    return changed;
}

void jc_oled_show_bootloader_msg() {
    oled_set_cursor(0, 0);
    oled_write("bl\n\n\n\n", true);
    oled_render();
}
