#include "oled.h"
#include "common.h"
#ifndef QMK_KEYBOARD_H
#    include "jellowcake303.h"
#    include "config.h"
#    include "keycode.h"
#    include <stdbool.h>
#    include <stdint.h>
#else
#    include QMK_KEYBOARD_H
#endif

#ifdef OLED_DRIVER_ENABLE

static kbd_status status_old;
static kbd_status status_cur;

static void render_jellowcake303_logo(void) {
    static const char qmk_logo[] = {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00};
    oled_write(qmk_logo, false);
    oled_render();
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees
}

void oled_jellowcake_render_status(void) {
    // Host Keyboard Layer Status
    char txtbuf[32];
    sprintf(txtbuf, "[%u] %s\n", status_cur.layer, get_layer_name(status_cur.layer));
    oled_write(txtbuf, false);

    // RGB Matrix Status
    sprintf(txtbuf, "RGB [%u] %s %u\n", status_cur.rgb_matrix_mode, status_cur.rgb_matrix_enabled ? "an" : "aus", status_cur.rgb_matrix_speed);
    oled_write(txtbuf, false);
    sprintf(txtbuf, "%s\n", get_effect_name(status_cur.rgb_matrix_mode));
    oled_write(txtbuf, false);
}

void oled_task_user(void) {
    static uint32_t oled_show_logo_timeout = 0;
    static bool     oled_show_logo         = true;

    update_status(&status_cur);

    if (oled_show_logo) {
        if (oled_show_logo_timeout == 0) {
            oled_show_logo_timeout = timer_read32() + OLED_SHOW_LOGO_TIMEOUT;
            render_jellowcake303_logo();
            bool success = oled_scroll_left();
            dprintf("now scrolling: %d\n", success);
        }

        if (timer_expired32(timer_read32(), oled_show_logo_timeout) /*|| status_changed(&status_cur, &status_old)*/) {
            oled_scroll_off();
            oled_show_logo = false;
            oled_jellowcake_render_status();
        }
    } else {
        if (status_changed(&status_cur, &status_old)) oled_jellowcake_render_status();
    }
}

// Runs just one time when the keyboard initializes.
// void keyboard_post_init_user(void) { render_jellowcake303_logo(); };

#endif
