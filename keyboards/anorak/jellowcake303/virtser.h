#pragma once

#define vserprint(s) virtser_print(s)
#define vserprintln(s) virtser_print(s "\n")
#define vserprintf(fmt, ...) virtser_printf(fmt, ##__VA_ARGS__)
#define vserprintfln(fmt, ...) virtser_printf(fmt "\n", ##__VA_ARGS__)
#define vserprint_dec(i) vserprintf("%u", i)
#define vserprint_hex(i) vserprintf("%02X", i)

int virtser_printf(const char *fmt, ...);
int virtser_print(const char *s);
