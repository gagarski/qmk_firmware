#pragma once

#include <stdint.h>

uint8_t read_userconfig_byte(uint8_t* offset);
void update_userconfig_byte(uint8_t* offset, uint8_t value);
