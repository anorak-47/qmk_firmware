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

//# If you want to be able to jump to bootloader from firmware on STM32 MCUs,
//# set the correct BOOTLOADER_ADDRESS. Either set it here, or define it in
//# ./bootloader_defs.h or in ./boards/<FOO>/bootloader_defs.h (if you have
//# a custom board definition that you plan to reuse).
//# If you're not setting it here, leave it commented out.
//# It is chip dependent, the correct number can be looked up here (page 175):
//# http://www.st.com/web/en/resource/technical/document/application_note/CD00167594.pdf
//# This also requires a patch to chibios:
//#   <tmk_dir>/tmk_core/tool/chibios/ch-bootloader-jump.patch

void enter_bootloader_mode_if_requested(void)
{

}

// Optional override functions below.
// You can leave any or all of these undefined.
// These are only required if you want to perform custom actions.

#if 0
extern uint8_t blinkLed;

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	//blinkLed = 1;

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}
#endif

void suspend_power_down_kb(void) {
	//print("suspend_power_down_kb\n");
    //rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
    palClearLine(LINE_SDB);
}

void suspend_wakeup_init_kb(void) {
	//print("suspend_wakeup_init_kb\n");
    //rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
    palSetLine(LINE_SDB);
}

bool led_update_kb(led_t led_state) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	print("led_update_kb\n");

	bool res = led_update_user(led_state);

	if (res) {

		if (led_state.caps_lock)
			palClearLine(LINE_LED1);
		else
			palSetLine(LINE_LED1);
	}

	return res;
}

#ifdef OLED_DRIVER_ENABLE
static void render_jellowcake303_logo(void) {
	static const char qmk_logo[] = {
		0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
		0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
		0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
	};

	oled_write(qmk_logo, false);
}
#endif

void keyboard_post_init_kb() {
	print("keyboard_post_init_user\n");

	// Customise these values to desired behaviour
	debug_enable=true;
	debug_matrix=true;
	debug_keyboard=true;
	//debug_mouse=true;

#ifdef OLED_DRIVER_ENABLE
	render_jellowcake303_logo();
	oled_scroll_left();
#endif

	keyboard_post_init_user();

	//rgb_matrix_enable_noeeprom();
}


// clang-format off

#ifdef RGB_MATRIX_ENABLE

const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *    |  R location
 *    |  |    G location
 *    |  |    |    B location
 *    |  |    |    | */
	{ 0, C_1, A_1, B_1},
	{ 0, C_2, A_2, B_2},
	{ 0, C_3, A_3, B_3},
	{ 0, C_4, A_4, B_4},
	{ 0, C_5, A_5, B_5},
	{ 0, C_6, A_6, B_6},

	{ 0, F_1, D_1, E_1},
	{ 0, F_2, D_2, E_2},
	{ 0, F_3, D_3, E_3},
	{ 0, F_4, D_4, E_4},
	{ 0, F_5, D_5, E_5},
	{ 0, F_6, D_6, E_6},

	{ 0, I_1, G_1, H_1},
	{ 0, I_2, G_2, H_2},
	{ 0, I_3, G_3, H_3},
	{ 0, I_4, G_4, H_4},
	{ 0, I_5, G_5, H_5},
	{ 0, I_6, G_6, H_6},

	{ 0, C_9,  A_9,  B_9},
	{ 0, C_10, A_10, B_10},
	{ 0, C_11, A_11, B_11},
	{ 0, C_12, A_12, B_12},
	{ 0, C_13, A_13, B_13},
	{ 0, C_14, A_14, B_14},
	{ 0, C_15, A_15, B_15},
	{ 0, C_16, A_16, B_16},

	{ 0, F_11, D_11, E_11},
	{ 0, F_12, D_12, E_12},
	{ 0, F_13, D_13, E_13},
	{ 0, F_14, D_14, E_14},
	{ 0, F_15, D_15, E_15},
	{ 0, F_16, D_16, E_16}
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
		Lxy(2,0), Lxy(2,1), Lxy(2,2), Lxy(2,3), Lxy(2,4), Lxy(2,5), Lxy(2,4), Lxy(2,5),
		                    Lxy(3,2), Lxy(3,3), Lxy(3,4), Lxy(3,5), Lxy(3,4), Lxy(3,5)
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

