#pragma once

#include QMK_KEYBOARD_H

void reset_ind_and_bl_settings(void);

void persist_ind_settings(void);

void persist_bl_settings(void);

void read_ind_settings(void);

void read_bl_settings(void);

void next_ind_mode(void);

void prev_ind_mode(void);

void next_bl_mode(void);

void prev_bl_mode(void);

void inc_ind_brightness(void);

void dec_ind_brightness(void);

void inc_bl_brightness(void);

void dec_bl_brightness(void);

void start_blink(bool ind, bool bl);

void do_blink(void);

void handle_indicators(void);

void handle_backlight(void);

void rgb_matrix_indicators_ind_bl(void);

void eeconfig_init_ind_bl(void);

void post_init_ind_bl(void);
