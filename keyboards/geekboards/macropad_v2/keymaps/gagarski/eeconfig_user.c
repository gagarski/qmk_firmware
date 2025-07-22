#include QMK_KEYBOARD_H
#include "eeconfig_user.h"

uint8_t read_userconfig_byte(uint8_t* offset) {
    uint8_t result;
    eeconfig_read_user_datablock(&result, (uint32_t)offset, 1);
    return result;
}
void update_userconfig_byte(uint8_t* offset, uint8_t value) {
    eeconfig_update_user_datablock(&value, (uint32_t)offset, 1);
}
