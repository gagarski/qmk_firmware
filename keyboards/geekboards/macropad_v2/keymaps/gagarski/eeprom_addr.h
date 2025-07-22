#pragma once

#include QMK_KEYBOARD_H

#define EEPROM_SAFE_ADDR 0

#define EEPROM_ADDR_H
#include "eeprom_addr/indication.h"
#include "eeprom_addr/os.h"
#undef EEPROM_ADDR_H
