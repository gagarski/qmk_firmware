#pragma once

#ifndef EEPROM_ADDR_H
#    error "Please do not include this file directly"
#endif

enum os_eeprom_addrs {
    _OS_SETTINGS_ADDR = EEPROM_SAFE_ADDR,
    _EEPROM_NEW_SAFE_ADDR_OS
};

#define OS_SETTINGS_ADDR ((uint8_t*) _OS_SETTINGS_ADDR)

#undef EEPROM_SAFE_ADDR
#define EEPROM_SAFE_ADDR _EEPROM_NEW_SAFE_ADDR_OS
