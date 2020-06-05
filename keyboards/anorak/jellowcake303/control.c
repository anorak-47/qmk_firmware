#include "control.h"
#include "common.h"
#include "virtser.h"
#include "debug.h"
#include "jsonparser/jsmn.h"
#ifndef QMK_KEYBOARD_H
#    include "jellowcake303.h"
#    include "config.h"
#else
#    include QMK_KEYBOARD_H
#endif
#include "eeconfig.h"
#include "ch.h"
#include "hal.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define FPS_TO_DELAY(fps) (fps ? (1000 / fps) : 1)
#define DELAY_TO_FPS(delay) (delay ? (1000 / delay) : 1)

void eeconfig_update_rgb_matrix(void);

struct user_command_t {
    char *cmd;
    bool (*pfn_command)(uint8_t argc, char **argv);
    char *help_args;
    char *help_msg;
};

typedef struct user_command_t user_command;

bool cmd_user_help(uint8_t argc, char **argv);
bool cmd_user_qmk_device_info(uint8_t argc, char **argv);
bool cmd_user_chibios_info(uint8_t argc, char **argv);
bool cmd_user_key_hsv(uint8_t argc, char **argv);
bool cmd_user_sector(uint8_t argc, char **argv);
bool cmd_user_animation(uint8_t argc, char **argv);
bool cmd_user_map(uint8_t argc, char **argv);
bool cmd_user_debug_config(uint8_t argc, char **argv);
bool cmd_user_keymap_config(uint8_t argc, char **argv);
bool cmd_user_bootloader_jump(uint8_t argc, char **argv);
bool cmd_user_backlight(uint8_t argc, char **argv);
bool cmd_user_default_layer(uint8_t argc, char **argv);
bool cmd_user_issi(uint8_t argc, char **argv);

// clang-format off

const user_command user_command_table[] =
{
	{"?", &cmd_user_help, 0, "help"},
	{"help", &cmd_user_help, 0, "help"},
	{"info", &cmd_user_qmk_device_info, 0, "keyboard info"},
	{"chinfo", &cmd_user_chibios_info, 0, "chibios system info"},
	{"bl", &cmd_user_backlight, 0, "backlight"},
	{"sector", &cmd_user_sector, "# [0|1] | # h s v | save", "sector control"},
	{"animation", &cmd_user_animation, "list | # save | # [0|1] | # fps [#] | # c 0|1 [h s v]", "animation control"},
	{"map", &cmd_user_map, "# | # row# | save", "rgb map control"},
	{"issi", &cmd_user_issi, "pt [#] | ptc | cl d | gcc d [#]", "control"},
	{"debug", &cmd_user_debug_config, "[kw] | save", "debug config"},
	{"keymap", &cmd_user_keymap_config, 0, "keymap config"},
	{"layer", &cmd_user_default_layer, 0, "default layer"},
	{"boot", &cmd_user_bootloader_jump, 0, "jump to bootloader"},

	{0, 0, 0, 0}
};

// clang-format on

void dump_args(uint8_t argc, char **argv) {
    dprintf("args: ");
    for (uint8_t i = 0; i < argc; i++) dprintf("%s ", argv[i]);
    dprintf("\n");
}

bool cmd_user_help(uint8_t argc, char **argv) {
    uint8_t      pos = 0;
    user_command cmd;

    memcpy_P(&cmd, (const void *)&user_command_table[pos++], sizeof(struct user_command_t));

    while (cmd.pfn_command) {
        if (cmd.help_args)
            vserprintfln("%s [%s]: %s", cmd.cmd, cmd.help_args, cmd.help_msg);
        else
            vserprintfln("%s: %s", cmd.cmd, cmd.help_msg);

        memcpy_P(&cmd, (const void *)&user_command_table[pos++], sizeof(struct user_command_t));
    }

    vserprintf("\n");
    return true;
}

bool cmd_user_issi(uint8_t argc, char **argv) {
    // pt [#] | ptc | cl d | gcc d [#]
#if 0
    if (argc == 1 && strcmp_P(argv[0], PSTR("pt")) == 0)
    {
        vserprintfln(".pt %u", issi.global_power_target_milliampere);
        return true;
    }

    if (argc == 1 && strcmp_P(argv[0], PSTR("ptc")) == 0)
    {
        vserprintfln(".ptc %u", issi.global_power_target_milliampere);
        return true;
    }

    /*
    if (argc == 2 && (strcmp_P(argv[0], PSTR("cl")) == 0)
    {
        IS31FL3733 *device = ((atoi(argv[1]) == 0) ? issi.lower->device : issi.upper->device);

        is31fl3733_detect_led_open_short_states(device);

        vserprintfln("open states:");
        is31fl3733_read_led_open_states(device);
        dump_led_buffer(device);
        // dump_led_buffer_inverted(device);

        vserprintfln("short states:");
        is31fl3733_read_led_short_states(device);
        dump_led_buffer(device);

        return true;
    }
    */

    if (argc == 2 && strcmp_P(argv[0], PSTR("pt")) == 0)
    {
        uint16_t power = atoi(argv[1]);
        is31fl3733_91tkl_power_target(&issi, power);
        vserprintfln(".pt %u", issi.global_power_target_milliampere);
        return true;
    }

    if (argc == 2 && strcmp_P(argv[0], PSTR("gcc")) == 0)
    {
        IS31FL3733 *device = ((atoi(argv[1]) == 0) ? issi.lower->device : issi.upper->device);
        vserprintfln(".gcc %u", device->gcc);
        return true;
    }

    if (argc == 2 && strcmp_P(argv[0], PSTR("bri")) == 0)
	{
    	uint8_t gcc = atoi(argv[2]);
    	issi.lower->device->gcc = gcc;
    	issi.upper->device->gcc = gcc;
		is31fl3733_update_global_current_control(issi.lower->device);
		is31fl3733_update_global_current_control(issi.upper->device);
		vserprintfln(".gcc %u", gcc);
		return true;
	}

    if (argc == 3 && strcmp_P(argv[0], PSTR("gcc")) == 0)
    {
        IS31FL3733 *device = ((atoi(argv[1]) == 0) ? issi.lower->device : issi.upper->device);
        device->gcc = atoi(argv[2]);
        is31fl3733_update_global_current_control(device);
        vserprintfln(".gcc %u", device->gcc);
        return true;
    }
#endif
    return false;
}

bool cmd_user_backlight(uint8_t argc, char **argv) {
#ifdef BACKLIGHT_ENABLE
    if (argc == 1 && strcmp_P(argv[0], PSTR("save")) == 0) {
        if (backlight_config.raw != eeconfig_read_backlight()) eeconfig_write_backlight(backlight_config.raw);
        return true;
    } else if (argc == 2) {
        if (strcmp_P(argv[0], PSTR("enable")) == 0) {
            bool    enable = atoi(argv[1]);
            uint8_t level  = enable ? backlight_config.level : 0;
            backlight_level(level);
            return true;
        } else if (strcmp_P(argv[0], PSTR("level")) == 0) {
            uint8_t level = atoi(argv[0]);
            backlight_level(level);
            return true;
        } else if (strcmp_P(argv[0], PSTR("ee")) == 0) {
            backlight_config_t bc;
            bc.raw = eeconfig_read_backlight();
            vserprint(".backlight_config.raw: ");
            vserprint_hex(bc.raw);
            vserprint("\n");
            vserprint(".enable: ");
            vserprint_dec(bc.enable);
            vserprint("\n");
            vserprint(".level: ");
            vserprint_dec(bc.level);
            vserprint("\n");
            return true;
        }
    } else if (argc == 0) {
        backlight_config_t bc;
        bc.raw = backlight_config.raw;
        vserprint(".backlight_config.raw: ");
        vserprint_hex(bc.raw);
        vserprint("\n");
        vserprint(".enable: ");
        vserprint_dec(bc.enable);
        vserprint("\n");
        vserprint(".level: ");
        vserprint_dec(bc.level);
        vserprint("\n");
        return true;
    }
#endif
    return false;
}

bool cmd_user_key_hsv(uint8_t argc, char **argv) {
#if 0
    if (argc != 5)
        return false;

    HSV hsv;
    uint8_t row;
    uint8_t col;
    uint8_t device_number;

    uint8_t col_to_change = atoi(argv[0]);
    uint8_t row_to_change = atoi(argv[1]);
    hsv.h = atoi(argv[2]);
    hsv.s = atoi(argv[3]);
    hsv.v = atoi(argv[4]);

    if (!getLedPosByMatrixKey(row_to_change, col_to_change, &device_number, &row, &col))
        return false;

    IS31FL3733_RGB *device = (device_number == 0 ? issi.lower : issi.upper);

    // vserprintfln("HSV: d:%u, r:%u, c:%u, h:%u, s:%u, v:%u", device_number, row, col, hsv.h, hsv.s, hsv.v);

    is31fl3733_hsv_direct_set_pwm(device, col, row, hsv);
#endif
    return true;
}

bool cmd_user_animation(uint8_t argc, char **argv) {
    // list | # save | # [0|1] | # fps [#] | # c 0|1 [h s v]

    if (argc == 0) {
        vserprintfln(".animation %u", rgb_matrix_get_mode());
        vserprintfln(".name %s", get_effect_name(rgb_matrix_get_mode()));
        vserprintfln(".running %u", rgb_matrix_is_enabled());
        vserprintfln(".fps %u", rgb_matrix_get_speed());
        vserprintfln(".duration %u", rgb_matrix_get_speed());
        vserprintfln(".hsv1 %X %X %X", rgb_matrix_get_hue(), rgb_matrix_get_sat(), rgb_matrix_get_val());
        vserprintfln(".hsv2 %X %X %X", rgb_matrix_get_speed(), rgb_matrix_get_sat(), rgb_matrix_get_val());

        HSV hsv = rgb_matrix_get_hsv();
        RGB rgb = hsv_to_rgb(hsv);
        vserprintfln(".rgb %X %X %X", rgb.r, rgb.g, rgb.b);

        return true;
    }

    if (argc == 1 && strcmp_P(argv[0], PSTR("list")) == 0) {
        uint8_t     i    = 1;
        char const *name = get_effect_name(0);

        vserprintfln(".animation names");

        while (name) {
            ++i;
            name = get_effect_name(i);
            if (name) {
                vserprintfln(".name %u %s", i, name);
            }
        }

        return true;
    }

    if (argc == 1) {
        uint8_t selected_animation = atoi(argv[0]);
        vserprintfln(".animation %u %u", selected_animation, (selected_animation == rgb_matrix_get_mode() ? rgb_matrix_is_enabled() : 0));
        return true;
    }

    if (argc == 2 && strcmp_P(argv[1], PSTR("save")) == 0) {
        uint8_t selected_animation = atoi(argv[0]);
        eeconfig_update_rgb_matrix();
        vserprintfln(".saved %u", selected_animation);
        return true;
    }

    if (argc == 2 && strcmp_P(argv[1], PSTR("fps")) == 0) {
        uint8_t selected_animation = atoi(argv[0]);
        vserprintfln(".fps %u %u", selected_animation, rgb_matrix_get_speed());
        return true;
    }

    if (argc == 2) {
        uint8_t selected_animation = atoi(argv[0]);
        bool    run_animation      = atoi(argv[1]);

        rgb_matrix_mode_noeeprom(selected_animation);

        if (run_animation) {
            rgb_matrix_enable_noeeprom();
        } else {
            rgb_matrix_disable_noeeprom();
        }

        vserprintfln(".animation %u %u", rgb_matrix_get_mode(), rgb_matrix_is_enabled());
        return true;
    }

    if (argc == 3 && strcmp_P(argv[1], PSTR("fps")) == 0) {
        uint8_t  selected_animation = atoi(argv[0]);
        uint16_t speed              = atoi(argv[2]);  // FPS_TO_DELAY(atoi(argv[2]));
        rgb_matrix_set_speed(speed);
        // vserprintfln(".fps %u %u", selected_animation, DELAY_TO_FPS(animation.delay_in_ms));
        vserprintfln(".fps %u %u", selected_animation, rgb_matrix_get_speed());
        return true;
    }

    if (argc == 3 && strcmp_P(argv[1], PSTR("c")) == 0) {
        uint8_t selected_animation = atoi(argv[0]);
        uint8_t colorid            = atoi(argv[2]);
        HSV     hsv                = rgb_matrix_get_hsv();

        if (colorid == 0) {
            vserprintfln(".animation %u c %u %X %X %X", selected_animation, colorid, hsv.h, hsv.s, hsv.v);
        } else {
            vserprintfln(".animation %u c %u %X %X %X", selected_animation, colorid, rgb_matrix_get_speed(), hsv.s, hsv.v);
        }

        return true;
    }

    if (argc >= 5 && strcmp_P(argv[1], PSTR("c")) == 0) {
        uint8_t selected_animation = atoi(argv[0]);
        uint8_t colorid            = atoi(argv[2]);
        HSV     hsv;

        if (colorid == 0) {
            hsv.h = atoi(argv[3]);
            hsv.s = atoi(argv[4]);
            hsv.v = atoi(argv[5]);
            rgb_matrix_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
            hsv = rgb_matrix_get_hsv();
        } else {
            rgb_matrix_set_speed(atoi(argv[3]));
            hsv   = rgb_matrix_get_hsv();
            hsv.h = rgb_matrix_get_speed();
        }

        vserprintfln(".animation %u c %u %X %X %X", selected_animation, colorid, hsv.h, hsv.s, hsv.v);

        return true;
    }

    return false;
}

bool cmd_user_sector(uint8_t argc, char **argv) { return false; }

static int jsoneq(const char *json, jsmntok_t *tok, const char *s) {
    if (tok->type == JSMN_STRING && (int)strlen(s) == tok->end - tok->start && strncmp(json + tok->start, s, tok->end - tok->start) == 0) {
        return 0;
    }
    return -1;
}

bool cmd_user_map(uint8_t argc, char **argv) {
    if (argc == 0) {
        vserprintfln(".map %u", 0);
        return true;
    }

    if (argc == 1 && strcmp_P(argv[0], PSTR("save")) == 0) {
        vserprintfln(".saved");
        return true;
    }

    if (argc == 1) {
        uint8_t selected_map = atoi(argv[0]);
        vserprintfln(".map %u", selected_map);
        return true;
    }

    if (argc == 2 && strcmp_P(argv[0], PSTR("set")) == 0) {
        // map set {...}
        char const *jsonstring = argv[1];

        jsmn_parser parser;
        jsmntok_t   tokens[60];

        jsmn_init(&parser);

        // js - pointer to JSON string
        // tokens - an array of tokens available
        // 10 - number of tokens available
        int r = jsmn_parse(&parser, jsonstring, strlen(jsonstring), tokens, 60);
        dprintf("jsmn: tokens: %d\n", r);

        if (r < 0) {
            dprintf("jsmn: parse fail: %d\n", r);
            return false;
        }

        /* Assume the top-level element is an object */
        if (r < 1 || tokens[0].type != JSMN_OBJECT) {
            dprintf("jsmn: obj expected\n");
            return false;
        }

        // uint8_t key_column;
        // uint8_t key_row;
        uint8_t selected_map = 0;
        char    hexcolor[3];
        char    buf[10];

        for (int i = 1; i < r; i++) {
            if (jsoneq(jsonstring, &tokens[i], "map") == 0) {
                // char *mapidstr = strndup(jsonstring + tokens[i + 1].start, tokens[i + 1].end - tokens[i + 1].start);
                memset(buf, '\0', 10);
                strncpy(buf, jsonstring + tokens[i + 1].start, tokens[i + 1].end - tokens[i + 1].start);
                selected_map = atoi(buf);
                dprintf("map: %s %d\n", buf, selected_map);
                // free(mapidstr);

                // TODO: if (sector_get_custom_map() != selected_map) sector_set_custom_map(selected_map);

                i++;
            } else if (jsoneq(jsonstring, &tokens[i], "row") == 0) {
                // char *rowidstr = strndup(jsonstring + tokens[i + 1].start, tokens[i + 1].end - tokens[i + 1].start);
                memset(buf, '\0', 10);
                strncpy(buf, jsonstring + tokens[i + 1].start, tokens[i + 1].end - tokens[i + 1].start);
                // key_row = atoi(buf);
                // dprintf("row: %s %d\n", buf, key_row);
                // free(rowidstr);

                i++;
            } else if (jsoneq(jsonstring, &tokens[i], "cols") == 0) {
                if (tokens[i + 1].type != JSMN_ARRAY) {
                    dprintf("jsmn: not array of arrays\n");
                    return false;
                }

                // RGB rgb;
                int arraysize = tokens[i + 1].size;

                dprintf("cols: %d\n", arraysize);

                for (int j = 0; j < arraysize; j++) {
                    jsmntok_t *g = &tokens[i + j + 2];
                    // dprintf(" %d: %.*s\n", j, g->end - g->start, jsonstring + g->start);

                    if (g->type != JSMN_ARRAY) {
                        dprintf("jsmn: not array\n");
                        return false;
                    }

                    // char *colidstr = strndup(jsonstring + tokens[i + j + 1 + 2].start, tokens[i + j + 1 + 2].end - tokens[i + j + 1 + 2].start);
                    memset(buf, '\0', 10);
                    strncpy(buf, jsonstring + tokens[i + j + 1 + 2].start, tokens[i + j + 1 + 2].end - tokens[i + j + 1 + 2].start);
                    // key_column = atoi(buf);
                    // dprintf("col: %s %d\n", buf, column);
                    // free(colidstr);

                    // char *colorstr = strndup(jsonstring + tokens[i + j + 2 + 2].start, tokens[i + j + 2 + 2].end - tokens[i + j + 2 + 2].start);
                    memset(buf, '\0', 10);
                    strncpy(buf, jsonstring + tokens[i + j + 2 + 2].start, tokens[i + j + 2 + 2].end - tokens[i + j + 2 + 2].start);
                    // dprintf("color: %s\n", buf);

                    if (strlen(buf) != 6) {
                        dprintf("map: not color: %s", buf);
                        return false;
                    }

                    for (int c = 0; c < 3; ++c) {
                        strncpy(hexcolor, buf + (c * 2), 2);
                        hexcolor[2] = '\0';
                        // TODO: rgb.rgb[c]  = strtol(hexcolor, 0, 16);
                        // dprintf("color %d: '%s' %d %X\n", c, hexcolor, rgb.rgb[c], rgb.rgb[c]);
                    }

                    i += g->size;

                    // set the color

                    // uint8_t row;
                    // uint8_t col;

                    /*
                    if (getLedPosByMatrixKey(key_row, key_column, &dev, &row, &col)) {
                        vserprintfln("set: %u %u %u %u %u", key_row, key_column, dev, row, col);

                        IS31FL3733_RGB *device = DEVICE_BY_NUMBER(issi, dev);
                        is31fl3733_rgb_set_pwm(device, col, row, rgb);
                    }
                    else
                    */
                    { dprintf("map: no mx key"); }
                }

                i += arraysize + 1;
            } else {
                // char *key = strndup(jsonstring + tokens[i + 1].start, tokens[i + 1].end - tokens[i + 1].start);

                memset(buf, '\0', 10);
                strncpy(buf, jsonstring + tokens[i + 1].start, tokens[i + 1].end - tokens[i + 1].start);
                dprintf("jsmn: ?: %s", buf);

                // free(key);
            }
        }

        // TODO: add a "update" command for this
        // is31fl3733_91tkl_update_led_pwm(&issi);

        vserprintfln(".map set %u", selected_map);

        return true;
    }

    if (argc == 2) {
        uint8_t selected_map     = atoi(argv[0]);
        uint8_t selected_map_row = atoi(argv[1]);

        // TODO: if (sector_get_custom_map() != selected_map) sector_set_custom_map(selected_map);

        vserprintf(".map {\"map\":%u,\"row\":%u,\"cols\":[", selected_map, selected_map_row);

        // uint8_t row;
        // uint8_t col;

        // for (int8_t key_col = MATRIX_COLS - 1 ; key_col >= 0; key_col--)
        for (uint8_t key_col = 0; key_col < MATRIX_COLS; ++key_col) {
            /*
            if (getLedPosByMatrixKey(selected_map_row, key_col, &dev, &row, &col)) {
                IS31FL3733_RGB *device = DEVICE_BY_NUMBER(issi, dev);
                RGB             rgb    = is31fl3733_rgb_get_pwm(device, col, row);
                vserprintf("[%u,\"%X%X%X\"]", key_col, rgb.r, rgb.g, rgb.b);
                //	if (key_col > 0)
                if (key_col < MATRIX_COLS - 1) vserprint(",");
            }
            */

            RGB rgb;
            vserprintf("[%u,\"%X%X%X\"]", key_col, rgb.r, rgb.g, rgb.b);
            if (key_col < MATRIX_COLS - 1) vserprint(",");
        }
        vserprintln("]}");

        return true;
    }

    return false;
}

bool cmd_user_qmk_device_info(uint8_t argc, char **argv) {
    vserprintf(".device\n");
    vserprintf(".desc: " STR(DESCRIPTION) "\n");
    vserprintf(".vid: " STR(VENDOR_ID) "\n");
    vserprintf(".manufacturer: " STR(MANUFACTURER) "\n");
    vserprintf(".pid: " STR(PRODUCT_ID) "\n");
    vserprintf(".product: " STR(PRODUCT) "\n");
    vserprintf(".version: " STR(DEVICE_VER) "\n");
    vserprintf(".build: " STR(DEVICE_VER) " (" __TIME__ " " __DATE__ ")\n");
    return true;
}

bool cmd_user_chibios_info(uint8_t argc, char **argv) {
    vserprintfln("chibios system info");
    vserprintfln("kernel: %s", CH_KERNEL_VERSION);
#ifdef PORT_COMPILER_NAME
    vserprintfln("compiler: %s", PORT_COMPILER_NAME);
#endif
    vserprintfln("architecture: %s", PORT_ARCHITECTURE_NAME);
#ifdef PORT_CORE_VARIANT_NAME
    vserprintfln("core variant: %s", PORT_CORE_VARIANT_NAME);
#endif
#ifdef PORT_INFO
    vserprintfln("port info: %s", PORT_INFO);
#endif
#ifdef PLATFORM_NAME
    vserprintfln("platform: %s", PLATFORM_NAME);
#endif
#ifdef BOARD_NAME
    vserprintfln("board: %s", BOARD_NAME);
#endif
#ifdef __DATE__
#    ifdef __TIME__
    vserprintfln("build time: %s%s%s", __DATE__, " - ", __TIME__);
#    endif
#endif

    vserprintfln("memory info");

    size_t n, total, largest;
    n = chHeapStatus(NULL, &total, &largest);
    vserprintfln("core free memory: %u bytes", chCoreGetStatusX());
    vserprintfln("heap fragments: %u", n);
    vserprintfln("heap free total: %u bytes", total);
    vserprintfln("heap free largest: %u bytes", largest);

    vserprintfln("threads");

    static const char *states[] = {CH_STATE_NAMES};
    thread_t *         tp;
    vserprintfln("stklimit    stack     addr refs prio     state         name");
    tp = chRegFirstThread();
    do {
#if (CH_DBG_ENABLE_STACK_CHECK == TRUE) || (CH_CFG_USE_DYNAMIC == TRUE)
        uint32_t stklimit = (uint32_t)tp->wabase;
#else
        uint32_t stklimit = 0U;
#endif
        vserprintfln("%08lx %08lx %08lx %4lu %4lu %9s %12s", stklimit, (uint32_t)tp->ctx.sp, (uint32_t)tp, (uint32_t)tp->refs - 1, (uint32_t)tp->prio, states[tp->state], tp->name == NULL ? "" : tp->name);
        tp = chRegNextThread(tp);
    } while (tp != NULL);

    return true;
}

bool cmd_user_bootloader_jump(uint8_t argc, char **argv) {
    jc_oled_show_bootloader_msg();
    bootloader_jump();
    return true;
}

bool cmd_user_default_layer(uint8_t argc, char **argv) {
#ifdef BOOTMAGIC_ENABLE
    if (argc == 1 && strcmp_P(argv[0], PSTR("save")) == 0) {
        // if (debug_config.raw != eeconfig_read_debug())
        //    eeconfig_write_debug(debug_config.raw);
    } else if (argc == 2 && strcmp_P(argv[0], PSTR("set")) == 0) {
        uint8_t default_layer = atoi(argv[1]);

        if (default_layer) {
            eeconfig_update_default_layer(default_layer);
            default_layer_set((uint32_t)default_layer);
        } else {
            default_layer = eeconfig_read_default_layer();
            default_layer_set((uint32_t)default_layer);
        }
    } else {
        vserprint(".default_layer ");
        vserprint_dec(eeconfig_read_default_layer());
        vserprint("\n");
    }
#endif
    return true;
}

bool cmd_user_debug_config(uint8_t argc, char **argv) {
#ifdef BOOTMAGIC_ENABLE
    if (argc == 1 && strcmp_P(argv[0], PSTR("save")) == 0) {
        if (debug_config.raw != eeconfig_read_debug()) eeconfig_update_debug(debug_config.raw);
    } else if (argc == 2) {
        uint8_t value = atoi(argv[1]);
        if (strcmp_P(argv[0], PSTR("enable")) == 0) {
            debug_config.enable = value;
        } else if (strcmp_P(argv[0], PSTR("matrix")) == 0) {
            debug_config.matrix = value;
        } else if (strcmp_P(argv[0], PSTR("keyboard")) == 0) {
            debug_config.keyboard = value;
        } else if (strcmp_P(argv[0], PSTR("mouse")) == 0) {
            debug_config.mouse = value;
        } else if (strcmp_P(argv[0], PSTR("raw")) == 0) {
            debug_config.raw = value;
        }
    } else {
        vserprint(".debug_config.raw ");
        vserprint_hex(debug_config.raw);
        vserprint("\n");
        vserprint(".enable ");
        vserprint_dec(debug_config.enable);
        vserprint("\n");
        vserprint(".matrix ");
        vserprint_dec(debug_config.matrix);
        vserprint("\n");
        vserprint(".keyboard ");
        vserprint_dec(debug_config.keyboard);
        vserprint("\n");
        vserprint(".mouse ");
        vserprint_dec(debug_config.mouse);
        vserprint("\n");
    }
#endif
    return true;
}

#ifdef BOOTMAGIC_ENABLE
extern keymap_config_t keymap_config;
#endif

bool cmd_user_keymap_config(uint8_t argc, char **argv) {
#ifdef BOOTMAGIC_ENABLE
    if (argc == 1 && strcmp_P(argv[0], PSTR("save")) == 0) {
        if (keymap_config.raw != eeconfig_read_keymap()) eeconfig_update_keymap(keymap_config.raw);
    } else if (argc == 2) {
        uint8_t value = atoi(argv[1]);
        if (strcmp_P(argv[0], PSTR("swap_control_capslock")) == 0) {
            keymap_config.swap_control_capslock = value;
        } else if (strcmp_P(argv[0], PSTR("capslock_to_control")) == 0) {
            keymap_config.capslock_to_control = value;
        } else if (strcmp_P(argv[0], PSTR("swap_lalt_lgui")) == 0) {
            keymap_config.swap_lalt_lgui = value;
        } else if (strcmp_P(argv[0], PSTR("swap_ralt_rgui")) == 0) {
            keymap_config.swap_ralt_rgui = value;
        } else if (strcmp_P(argv[0], PSTR("no_gui")) == 0) {
            keymap_config.no_gui = value;
        } else if (strcmp_P(argv[0], PSTR("swap_grave_esc")) == 0) {
            keymap_config.swap_grave_esc = value;
        } else if (strcmp_P(argv[0], PSTR("swap_backslash_backspace")) == 0) {
            keymap_config.swap_backslash_backspace = value;
        } else if (strcmp_P(argv[0], PSTR("nkro")) == 0) {
            keymap_config.nkro = value;
#    ifdef NKRO_ENABLE
            // TODO: check this
            // keyboard_nkro = keymap_config.nkro;
#    endif
        } else if (strcmp_P(argv[0], PSTR("raw")) == 0) {
            keymap_config.raw = value;
        }
    } else {
        vserprint(".keymap_config.raw ");
        vserprint_hex(keymap_config.raw);
        vserprint("\n");
        vserprint(".swap_control_capslock ");
        vserprint_dec(keymap_config.swap_control_capslock);
        vserprint("\n");
        vserprint(".capslock_to_control ");
        vserprint_dec(keymap_config.capslock_to_control);
        vserprint("\n");
        vserprint(".swap_lalt_lgui ");
        vserprint_dec(keymap_config.swap_lalt_lgui);
        vserprint("\n");
        vserprint(".swap_ralt_rgui ");
        vserprint_dec(keymap_config.swap_ralt_rgui);
        vserprint("\n");
        vserprint(".no_gui ");
        vserprint_dec(keymap_config.no_gui);
        vserprint("\n");
        vserprint(".swap_grave_esc ");
        vserprint_dec(keymap_config.swap_grave_esc);
        vserprint("\n");
        vserprint(".swap_backslash_backspace ");
        vserprint_dec(keymap_config.swap_backslash_backspace);
        vserprint("\n");
        vserprint(".nkro ");
        vserprint_dec(keymap_config.nkro);
        vserprint("\n");
    }
#endif
    return true;
}

void shell_command(uint8_t *buffer, uint8_t length) {
    uint8_t               pos = 0;
    char *                str = (char *)buffer;
    char *                token;
    char *                command;
    uint8_t               argc = 0;
    char *                argv[10];
    struct user_command_t user_command;

    // dprintf("buffer: <%s> l:%u\n", buffer, length);
    command = strsep(&str, " ");

    while ((token = strsep(&str, " "))) {
        argv[argc] = token;
        argc++;
    }

    memcpy_P(&user_command, &user_command_table[pos++], sizeof(struct user_command_t));

    // dprintf("uc: [%s] [%s]\n", user_command.cmd, user_command.help_msg);

    while (user_command.pfn_command) {
        if (strcmp(user_command.cmd, command) == 0) {
            // dprintf("exec: %s\n", command);
            dump_args(argc, argv);

            bool success = user_command.pfn_command(argc, argv);

            if (success) {
                vserprintfln(">OK");
            } else {
                vserprintfln(">ERR");
            }

            break;
        }

        memcpy_P(&user_command, &user_command_table[pos++], sizeof(struct user_command_t));

        // dprintf("uc: [%s] [%s]\n", user_command.cmd, user_command.help_msg);
    }

    if (!user_command.pfn_command) {
        vserprintfln(">NC '!?' for help");
        vserprintfln(">NC");
    }
}
