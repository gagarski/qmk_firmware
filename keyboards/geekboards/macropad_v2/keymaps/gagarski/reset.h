#pragma once

#define N_RESET_STEPS 32

void request_reset(void);

void request_eeprom_reset(void);

bool is_reset_requested(void);

bool is_eeprom_reset_requested(void);

uint8_t get_reset_step(void);

void cancel_reset(void);

void matrix_scan_reset(void);
