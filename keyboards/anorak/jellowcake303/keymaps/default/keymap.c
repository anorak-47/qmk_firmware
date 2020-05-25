/* Copyright 2020 Moritz Wenk
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
#    include "../../jellowcake303.h"
#    include "../../config.h"
#    include "keycode.h"
#    include <stdbool.h>
#    include <stdint.h>
#else
#    include QMK_KEYBOARD_H
#endif

// clang-format off

//
// Keymap layers
// Each layer gets a name for readability.
//
#define L_TF2 0
#define L_FPS 1
#define L_MEDIA 2
#define L_TF2E 3

//
// Custom keycodes
//
enum custom_keycodes
{
	KC_DJMP = SAFE_RANGE,
	KC_RGB0
};

#define KC_MO MO
#define KC_DF DF
#define KC_TG TG
#define KC_TO TO
#define KC_mLT LT
#define KC_RGB_TOG RGB_TOG
#define KC_RGB_MOD RGB_MOD
#define KC_RGB_RMOD RGB_RMOD
#define KC_RGB_SPI RGB_SPI
#define KC_RGB_SPD RGB_SPD
#define KC_RGB_HUI RGB_HUI
#define KC_RGB_HUD RGB_HUD
#define KC_RGB_SAI RGB_SAI
#define KC_RGB_SAD RGB_SAD
#define KC_RGB_VAI RGB_VAI
#define KC_RGB_VAD RGB_VAD

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Duckjump layer for Team Fortress 2
 *
 * Left Shift -> quick switch to meele weapon
 * Slash  "/" -> quick switch to secondary weapon
 * Ctrl -> Duck
 * DJMP -> Jump and Duck
 * Tab  -> show scores
 * , -> change class
 * . -> change team
 *
 *    kx0|   kx1| kx2|  kx3|    kx4|   kx5| kx6| kx7|
 * ,----------------------------------------------------,
 * | F12 |   Esc |   F1 |   F2 |    F3 |   F4 |    |    |
 * |----------------------------------------------------|
 * |   T |   Tab |    Q |    W |     E |    R |    |    |
 * |----------------------------------------------------|
 * |   G | Shift |    A |    S |     D |    F |    |    |
 * |----------------------------------------------------|
 * |   B | LCtrl |    Z |    X |     C |    V |  L |  H |
 * |----------------------------------------------------|
 * |     |       | LMED | Ctrl |  DJMP | SLSH |  , |  . |
 * `----------------------------------------------------'
 *
 */
[L_TF2] = LAYOUT_JELLOWCAKE303(
		F12,   ESC,     F1,    F2,    F3,    F4,
		  T,   TAB,      Q,     W,     E,     R,
		  G,  LSFT,      A,     S,     D,     F,
		  B, LCTRL,      Z,     X,     C,     V,                  L,    H,
		       MO(L_MEDIA), LCTRL,  DJMP,  mLT(L_TF2E, KC_SLSH),  COMMA,  DOT ),
/*
 * Generic Egoshooter Layer
 *
 *    kx0|   kx1| kx2|  kx3| kx4| kx5|  kx6|  kx7|
 * ,---------------------------------------------,
 * |   5 |  Esc |  1 |   2 |  3 |  4 |     |     |
 * |---------------------------------------------|
 * |   T |  Tab |  Q |   W |  E |  R |     |     |
 * |---------------------------------------------|
 * |   G |    M |  A |   S |  D |  F |     |     |
 * |---------------------------------------------|
 * |   B | Shift|  Z |   X |  C |  V | SPC | ENT |
 * |---------------------------------------------|
 * |     |      | FN0| Ctrl| FN2| FN3| SPC | SPC |
 * `---------------------------------------------'
 *
 */
[L_FPS] = LAYOUT_JELLOWCAKE303(
		5, ESC, 1, 2, 3, 4,
		T, TAB, Q, W, E, R,
		G, LSFT, A, S, D, F,
		B, LCTRL, Z, X, C, V, L, H,
		MO(L_MEDIA), LCTRL, SPC, M, COMMA, DOT ),

/*
 *  Media Layer
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
		MUTE, RGB_TOG, RGB_RMOD,  RGB_MOD,    RGB0, TO(L_TF2),
		VOLU, RGB_SPI,  RGB_HUI,  RGB_SAI, RGB_VAI, TO(L_FPS),
		VOLD, RGB_SPD,  RGB_HUD,  RGB_SAD, RGB_VAD, TRNS,
		MUTE,    TRNS,     TRNS,     TRNS,    TRNS, TRNS, TRNS, TRNS,
		                   TRNS,     TRNS,    TRNS, TRNS, TRNS, TRNS ),

/*
*  TF2 extra keys layer
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
[L_TF2E] = LAYOUT_JELLOWCAKE303(
	TRNS, TRNS,    1,    2,    3,    4,
	TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
	TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
	TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
			    TRNS, TRNS, TRNS, TRNS, TRNS, TRNS )

};

// clang-format on

static void rgb_matrix_set_defaults(void) {
    rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
    rgb_matrix_enable();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_DJMP:
            if (record->event.pressed) {
                // when keycode DJMP is pressed
                // do a duckjump (Space + LCtrl)
                SEND_STRING(" " SS_DOWN(X_LCTRL));
            } else {
                // when keycode DJMP is released
                SEND_STRING(SS_UP(X_LCTRL));
            }
            break;
        case KC_RGB0:
            if (record->event.pressed) {
                rgb_matrix_set_defaults();
            }
            break;
    }
    return true;
}
