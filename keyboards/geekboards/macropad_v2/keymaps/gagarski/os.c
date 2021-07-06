#include QMK_KEYBOARD_H

#include "eeprom.h"

#include "eeprom_addr.h"
#include "os.h"


const uint8_t DEFAULT_OS = (uint8_t) WINDOWS_10;
uint8_t os = DEFAULT_OS;

os_t get_os(void) {
    return os;
}

void set_os(os_t new_os) {
    os = new_os;
    eeprom_update_byte(OS_SETTINGS_ADDR, os);
}

void eeconfig_init_os(void) {
    os = DEFAULT_OS;
    eeprom_update_byte(OS_SETTINGS_ADDR, os);
}

void post_init_os(void) {
    os = eeprom_read_byte(OS_SETTINGS_ADDR);
}

