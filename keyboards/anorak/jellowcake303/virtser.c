#include "virtser.h"
#include "control.h"
#include "debug.h"
#ifndef QMK_KEYBOARD_H
#    include "config.h"
#else
#    include QMK_KEYBOARD_H
#endif
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define VIRT_SER_PRINTF_BUFFER_SIZE 128
#define MAX_MSG_LENGTH 512

#define DATAGRAM_USER_START '!'
#define DATAGRAM_USER_STOP '\n'

enum recvStatus { recvStatusIdle = 0, recvStatusFoundUserStart = 2, recvStatusFindStop = 4 };

static enum recvStatus recv_status = recvStatusIdle;
static uint8_t         recv_buffer[MAX_MSG_LENGTH];
static char            buffer[VIRT_SER_PRINTF_BUFFER_SIZE];

void virtser_send(const uint8_t byte);

void virtser_send_data(uint8_t const *data, uint8_t length) {
    for (uint8_t i = 0; i < length; ++i) {
        virtser_send(*data++);
    }
}

int virtser_printf(const char *fmt, ...) {
    int     ret;
    va_list va;

    va_start(va, fmt);
    ret = vsnprintf(buffer, VIRT_SER_PRINTF_BUFFER_SIZE - 1, fmt, va);
    va_end(va);
    buffer[VIRT_SER_PRINTF_BUFFER_SIZE - 1] = '\0';

    virtser_send_data((uint8_t const *)buffer, ret);

    return ret;
}

int virtser_print(const char *s) {
    int ret = 0;

    while (*s) {
        virtser_send(*s++);
        ret++;
    }

    return ret;
}

bool datagram_is_userdata_start(uint8_t ucData) { return (ucData == DATAGRAM_USER_START && recv_status == recvStatusIdle); }

void parse_recv_data(uint8_t ucData) {
    static uint8_t buffer_pos = 0;

    dprintf("recv: [%02X] <%c> s:%u\n", ucData, (char)ucData, recv_status);

    if (datagram_is_userdata_start(ucData)) {
        dprintf("recv: user start\n");

        buffer_pos = 0;

        // do not store the user command start byte
        // recv_buffer[buffer_pos] = ucData;
        // buffer_pos++;

        recv_status = recvStatusFoundUserStart;
    } else if (recv_status == recvStatusFoundUserStart) {
        if (ucData == DATAGRAM_USER_STOP) {
            dprintf("recv: user stop\n");
            recv_buffer[buffer_pos] = '\0';
            shell_command(recv_buffer, buffer_pos);

            buffer_pos  = 0;
            recv_status = recvStatusIdle;
        } else if (buffer_pos + 1 >= MAX_MSG_LENGTH) {
            // bail out
            buffer_pos  = 0;
            recv_status = recvStatusIdle;
            vserprintfln("payload\n>ERR");
        }

        else {
            recv_buffer[buffer_pos] = ucData;
            buffer_pos++;
        }
    }
}

void virtser_recv(uint8_t c) { parse_recv_data(c); }
