#pragma once

#ifndef EEPROM_ADDR_H
#    error "Please do not include this file directly"
#endif

enum ind_eeprom_addrs {
    _IND_SETTINGS_ADDR = EEPROM_SAFE_ADDR,
    _BL_SETTINGS_ADDR,
    _EEPROM_NEW_SAFE_ADDR_IND_EEPROM
};

#define IND_SETTINGS_ADDR ((uint8_t*) _IND_SETTINGS_ADDR)
#define BL_SETTINGS_ADDR ((uint8_t*) _BL_SETTINGS_ADDR)

#undef EEPROM_SAFE_ADDR
#define EEPROM_SAFE_ADDR _EEPROM_NEW_SAFE_ADDR_IND_EEPROM
