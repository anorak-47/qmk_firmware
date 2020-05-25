#include "jellowcake_common.h"
#ifndef QMK_KEYBOARD_H
#    include "jellowcake303.h"
#    include "config.h"
#else
#    include QMK_KEYBOARD_H
#endif

// clang-format off
static const char *layerNames[] = {
		"TeamFortress2",
		"Egoshooter",
		"Media",
		"TF2 Extras"
};

static const char *rgb_matrix_effect_names[] = {
		"no animation",
#define RGB_MATRIX_EFFECT(name, ...) "name",
#include "rgb_matrix_animations/rgb_matrix_effects.inc"
#undef RGB_MATRIX_EFFECT
};

#if 0
static const char *rgb_matrix_effect_names[] = {
		//122345678901234567890
		"no animation"
		"solid color",
		"alpha mods",
		"gradient up down",
		"gradient left right",
		"breathing",
		"colorband sat",
		"colorband val",
		"colorband pinwheel sat",
		"colorband pinwheel val",
		"colorband spiral sat",
		"colorband spiral val",
		"cycle all",
		"cycle left right",
		"cycle up down",
		"rainbow moving chevron",
		"cycle out in",
		"cycle out in dual",
		"cycle pinwheel",
		"cycle spiral",
		"dual beacon",
		"rainbow beacon",
		"rainbow pinwheels",
		"raindrops",
		"jellybean raindrops",
		"typing heatmap",
		"digital rain",
		"solid reactive simple",
		"solid reactive",
		"solid reactive wide"
		"solid reactive cross"
		"solid reactive nexus"
		"splash",
		"solid splash"
};
#endif

// clang-format on

const char *get_layer_name(uint8_t layer) { return layerNames[layer]; }

const char *get_effect_name(uint8_t mode) { return rgb_matrix_effect_names[mode]; }

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
