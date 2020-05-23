/* Copyright 2019-2020 Moritz Wenk
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

#pragma once

#include "quantum.h"

// clang-format off

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT_JELLOWCAKE303(\
    k00, k01, k02, k03, k04, k05,           \
    k10, k11, k12, k13, k14, k15,           \
    k20, k21, k22, k23, k24, k25,           \
    k30, k31, k32, k33, k34, k35, k36, k37, \
              k42, k43, k44, k45, k46, k47  \
) { \
{ KC_##k00, KC_##k01, KC_##k02, KC_##k03, KC_##k04, KC_##k05, KC_NO,    KC_NO },    \
{ KC_##k10, KC_##k11, KC_##k12, KC_##k13, KC_##k14, KC_##k15, KC_NO,    KC_NO },    \
{ KC_##k20, KC_##k21, KC_##k22, KC_##k23, KC_##k24, KC_##k25, KC_NO,    KC_NO },    \
{ KC_##k30, KC_##k31, KC_##k32, KC_##k33, KC_##k34, KC_##k35, KC_##k36, KC_##k37 }, \
{ KC_NO,     KC_NO,   KC_##k42, KC_##k43, KC_##k44, KC_##k45, KC_##k46, KC_##k47 }  \
}

#define LAYOUT_JELLOWCAKE303_RGB(\
    k00, k01, k02, k03, k04, k05,           \
    k10, k11, k12, k13, k14, k15,           \
    k20, k21, k22, k23, k24, k25,           \
    k30, k31, k32, k33, k34, k35, k36, k37, \
              k42, k43, k44, k45, k46, k47  \
) { \
{ k00,    k01,    k02, k03, k04, k05, NO_LED, NO_LED }, \
{ k10,    k11,    k12, k13, k14, k15, NO_LED, NO_LED }, \
{ k20,    k21,    k22, k23, k24, k25, NO_LED, NO_LED }, \
{ k30,    k31,    k32, k33, k34, k35, k36,    k37 },    \
{ NO_LED, NO_LED, k42, k43, k44, k45, k46,    k47 }     \
}

// clang-format on
