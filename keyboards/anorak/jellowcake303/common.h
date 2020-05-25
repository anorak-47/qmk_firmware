#ifndef KEYBOARDS_ANORAK_JELLOWCAKE303_COMMON_H_
#define KEYBOARDS_ANORAK_JELLOWCAKE303_COMMON_H_

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    bool     rgb_matrix_enabled;
    uint8_t  rgb_matrix_mode;
    uint8_t  rgb_matrix_speed;
    uint16_t layer;
} kbd_status;

void update_status(kbd_status *status);
bool status_changed(kbd_status *news, kbd_status *olds);

const char *get_layer_name(uint8_t layer);
const char *get_effect_name(uint8_t mode);

void jc_oled_show_bootloader_msg(void);

#endif /* KEYBOARDS_ANORAK_JELLOWCAKE303_COMMON_H_ */
