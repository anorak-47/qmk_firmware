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

#include "jellowcake303.h"
#include "rgb_matrix_types.h"
#include "command.h"

void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    palClearLine(LINE_SDB);

    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    palSetLine(LINE_SDB);
    rgb_matrix_set_suspend_state(false);

    suspend_wakeup_init_user();
}

bool led_update_kb(led_t led_state) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    bool res = led_update_user(led_state);

    /*
    if (res) {
        if (led_state.caps_lock)
            palClearLine(LINE_LED1);
        else
            palSetLine(LINE_LED1);
    }
    */

    return res;
}

void keyboard_pre_init_kb() {
    palSetLine(LINE_SDB);
    palClearLine(LINE_IICRST);
    // Wait 10ms to ensure the device has woken up.
    // wait_ms(10);
    keyboard_pre_init_user();
}

void keyboard_post_init_kb() {
    // Customise these values to desired behavior
    // debug_enable = true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;

    keyboard_post_init_user();
}

#ifdef OLED_DRIVER_ENABLE

bool command_extra(uint8_t code) {
    // jump to bootloader command
    switch (code) {
        case MAGIC_KC(MAGIC_KEY_BOOTLOADER):
        case MAGIC_KC(MAGIC_KEY_BOOTLOADER_ALT):
            oled_set_cursor(0, 0);
            oled_write("bl\n\n\n\n", true);
            oled_render();
            oled_render();
            oled_render();
            oled_render();
            oled_render();
            oled_render();
            oled_render();
            break;
    }

    return false;
}

#endif

// clang-format off

#ifdef RGB_MATRIX_ENABLE

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *    |  R location
 *    |  |    G location
 *    |  |    |    B location
 *    |  |    |    | */
	{ 0, A_1, C_1, B_1},
	{ 0, A_2, C_2, B_2},
	{ 0, A_3, C_3, B_3},
	{ 0, A_4, C_4, B_4},
	{ 0, A_5, C_5, B_5},
	{ 0, A_6, C_6, B_6},

	{ 0, D_1, F_1, E_1},
	{ 0, D_2, F_2, E_2},
	{ 0, D_3, F_3, E_3},
	{ 0, D_4, F_4, E_4},
	{ 0, D_5, F_5, E_5},
	{ 0, D_6, F_6, E_6},

	{ 0, G_1, I_1, H_1},
	{ 0, G_2, I_2, H_2},
	{ 0, G_3, I_3, H_3},
	{ 0, G_4, I_4, H_4},
	{ 0, G_5, I_5, H_5},
	{ 0, G_6, I_6, H_6},

	{ 0, A_9,  C_9,  B_9},
	{ 0, A_10, C_10, B_10},
	{ 0, A_11, C_11, B_11},
	{ 0, A_12, C_12, B_12},
	{ 0, A_13, C_13, B_13},
	{ 0, A_14, C_14, B_14},
	{ 0, A_15, C_15, B_15},
	{ 0, A_16, C_16, B_16},

	{ 0, D_11, F_11, E_11},
	{ 0, D_12, F_12, E_12},
	{ 0, D_13, F_13, E_13},
	{ 0, D_14, F_14, E_14},
	{ 0, D_15, F_15, E_15},
	{ 0, D_16, F_16, E_16}
};

#define Lx(col) (224 / (MATRIX_COLS - 1) * col)
#define Ly(row)  (64 / (MATRIX_ROWS - 1) * row)
#define Lxy(row, col) {Lx(col), Ly(row)}

/* struct led_config_t;
 *
  typedef struct PACKED {
    uint8_t matrix_co[MATRIX_ROWS][MATRIX_COLS];
    point_t point[DRIVER_LED_TOTAL];
    uint8_t flags[DRIVER_LED_TOTAL];
  } led_config_t;
 *
 */

led_config_t g_led_config = {
	// Key Matrix to LED Index (array of [MATRIX_ROWS][MATRIX_COLS])
	LAYOUT_JELLOWCAKE303_RGB(
			 0,  1,  2,  3,  4,  5,
			 6,  7,  8,  9, 10, 11,
			12, 13, 14, 15, 16, 17,
			18, 19, 20, 21, 22, 23, 24, 25,
			        26, 27, 28, 29, 30, 31),

	// LED Index to Physical Position (array of [DRIVER_LED_TOTAL])
	{

		Lxy(0,0), Lxy(0,1), Lxy(0,2), Lxy(0,3), Lxy(0,4), Lxy(0,5),
		Lxy(1,0), Lxy(1,1), Lxy(1,2), Lxy(1,3), Lxy(1,4), Lxy(1,5),
		Lxy(2,0), Lxy(2,1), Lxy(2,2), Lxy(2,3), Lxy(2,4), Lxy(2,5),
		Lxy(3,0), Lxy(3,1), Lxy(3,2), Lxy(3,3), Lxy(3,4), Lxy(3,5), Lxy(3,6), Lxy(3,7),
		                    Lxy(4,2), Lxy(4,3), Lxy(4,4), Lxy(4,5), Lxy(4,6), Lxy(4,7)
	},
	// LED Index to Flag (array of [DRIVER_LED_TOTAL])
	{
		4, 1, 4, 4, 4, 4,
		4, 1, 4, 4, 4, 4,
		4, 1, 4, 4, 4, 4,
		4, 1, 4, 4, 4, 4, 1, 1,
		      1, 1, 1, 1, 1, 1
	}
};

#endif

// clang-format on
