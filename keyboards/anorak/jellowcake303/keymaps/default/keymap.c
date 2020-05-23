/* Copyright 2019 Moritz Wenk
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

#ifndef QMK_KEYBOARD_H
#include "../../jellowcake303.h"
#include "../../config.h"
#include "keycode.h"
#include <stdbool.h>
#include <stdint.h>
#else
#include QMK_KEYBOARD_H
#endif

#ifdef SERIAL_OUT_ENABLE
#include "chprintf.h"
#endif

//
// Keymap layers
// Each layer gets a name for readability.
//
#define L_TF2 0
#define L_DEFAULT 1
#define L_MEDIA 2

//
// Custom keycodes
//
enum custom_keycodes {
	KC_DJMP = SAFE_RANGE,
};

// clang-format off

#define KC_MO MO
#define KC_DF DF
#define KC_TG TG
#define KC_RGB_TOG RGB_TOG
#define KC_RGB_MOD RGB_MOD
#define KC_RGB_RMOD RGB_RMOD
#define KC_RGB_SPI RGB_SPI
#define KC_RGB_SPD RGB_SPD

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Default layer (DuckJump)
 *
 *    kx0|   kx1| kx2| kx3|    kx4|   kx5| kx6| kx7|
 * ,-----------------------------------------------,
 * | F12 |  Esc | F1 | F2 |    F3 |   F4 |    |    |
 * |-----------------------------------------------|
 * |   T |  Tab |  Q |  W |     E |    R |    |    |
 * |-----------------------------------------------|
 * |   G |    M |  A |  S |     D |    F |    |    |
 * |-----------------------------------------------|
 * |   B |Shift|   Z |  X |     C |    V |  L |  H |
 * |-----------------------------------------------|
 * |     |     |  FN0| FN1|  DJMP |  Ent |  , |  . |
 * `----------------------------------------------'
 *
 */
[L_TF2] = LAYOUT_JELLOWCAKE303(
		F12, ESC, F1, F2, F3, F4,
		T, TAB, Q, W, E, R,
		G, M, A, S, D, F,
		B, LSFT, Z, X, C, V, L, H,
		MO(L_MEDIA), MO(L_MEDIA), DJMP, ENT, COMMA, DOT ),
/*
 * Layer (Space)
 *
 *    kx0|   kx1| kx2| kx3| kx4| kx5|  kx6|  kx7|
 * ,--------------------------------------------,
 * |   5 |  Esc |  1 |  2 |  3 |  4 |     |     |
 * |--------------------------------------------|
 * |   T |  Tab |  Q |  W |  E |  R |     |     |
 * |--------------------------------------------|
 * |   G |    M |  A |  S |  D |  F |     |     |
 * |--------------------------------------------|
 * |   B |Shift|   Z |  X |  C |  V | SPC | ENT |
 * |--------------------------------------------|
 * |     |     |  FN0| FN1| FN2| FN3| SPC | SPC |
 * `--------------------------------------------'
 *
 */
[L_DEFAULT] = LAYOUT_JELLOWCAKE303(
		5, ESC, 1, 2, 3, 4,
		T, TAB, Q, W, E, R,
		G, M, A, S, D, F,
		B, LSFT, Z, X, C, V, L, H,
		MO(L_MEDIA), MO(L_MEDIA), SPC, ENT, SPC, SPC ),

/*
 *  Meida Layer
 *
 *    kx0|   kx1| kx2| kx3| kx4| kx5|  kx6|  kx7|
 * ,--------------------------------------------,
 * |   5 |  Esc |  1 |  2 |  3 |  4 |     |     |
 * |--------------------------------------------|
 * | VOLU|  Tab |  Q |  W |  E |  R |     |     |
 * |--------------------------------------------|
 * | VOLD|    M |  A |  S |  D |  F |     |     |
 * |--------------------------------------------|
 * | MUTE|Shift|   Z |  X |  C |  V | SPC | ENT |
 * |--------------------------------------------|
 * |     |     |  FN0| FN1| FN2| FN3| SPC | SPC |
 * `--------------------------------------------'
 *
 */
[L_MEDIA] = LAYOUT_JELLOWCAKE303(
		MUTE, RGB_TOG, RGB_MOD, RGB_RMOD, TRNS, TG(L_TF2),
		VOLU, RGB_SPI, TRNS, TRNS, TRNS, TG(L_DEFAULT),
		VOLD, RGB_SPD, TRNS, TRNS, TRNS, TRNS,
		MUTE, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS ) };

// clang-format on

/*
 void matrix_init_user(void) {

 }

 void matrix_scan_user(void) {

 }
 */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
	case KC_DJMP:
		if (record->event.pressed) {
			// when keycode DJMP is pressed
			// do a duck+jump (LCtrl + Space)
			SEND_STRING(SS_LCTL(" "));
		} else {
			// when keycode DJMP is released
		}
		break;
	}
	return true;
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180;  // flips the display 180 degrees
}

void oled_jellowcake_render_status(void) {
	static const char *layerNames[] = { "TeamFortress2", "Default", "Media" };
	static uint16_t old_layer = 0xffff;
	static led_t old_led_state = {};
	static bool old_rgb_matrix_enabled = false;
	static uint8_t old_rgb_matrix_mode = 255;
	bool changed = false;

	bool rgb_matrix_enabled = rgb_matrix_is_enabled();
	uint8_t rgb_matrix_mode = rgb_matrix_get_mode();
	led_t led_state = host_keyboard_led_state();
	uint16_t layer = get_highest_layer(layer_state);

	changed = (old_layer != layer) || (old_led_state.raw != led_state.raw)
			|| (old_rgb_matrix_mode != rgb_matrix_mode)
			|| (old_rgb_matrix_enabled != rgb_matrix_enabled);

	if (!changed)
		return;

	old_led_state = led_state;
	old_layer = layer;
	old_rgb_matrix_enabled = rgb_matrix_enabled;
	old_rgb_matrix_mode = rgb_matrix_mode;

	// Host Keyboard Layer Status
	char txtbuf[32];
	sprintf(txtbuf, "[%u] %s\n", layer, layerNames[layer]);
	oled_write_ln(txtbuf, false);

	// RGB Matrix Status
	sprintf(txtbuf, "RGB %s %u\n", rgb_matrix_enabled ? "on " : "off ", rgb_matrix_mode);
	oled_write_ln(txtbuf, false);

	// Host Keyboard LED Status
	oled_write(led_state.num_lock ? "NUM " : "    ", false);
	oled_write(led_state.caps_lock ? "CAP " : "    ", false);
	oled_write(led_state.scroll_lock ? "SCR " : "    ", false);
}

void oled_task_user(void) {
	oled_jellowcake_render_status();
}

#endif

void keyboard_post_init_user() {
#ifdef OLED_DRIVER_ENABLE
	//render_jellowcake303_logo();
#endif
}

/*
 * This function will be called when the state of one of those 5 LEDs changes.
 * It receives the LED state as a struct parameter.
 * By convention, return true from led_update_user() to get the led_update_kb() hook to run its code,
 * and return false when you would prefer not to run the code in led_update_kb().
 */
bool led_update_user(led_t led_state) {

	print("led_update_kb\n");

	if (led_state.caps_lock)
		palClearLine(LINE_LED1);
	else
		palSetLine(LINE_LED1);

	return false;
}
