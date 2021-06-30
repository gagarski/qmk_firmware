#pragma once

#include QMK_KEYBOARD_H

#include "kc.h"

#define FKC(n) (FKC_BASE + n)
#define IS_FKC(keycode) (keycode >= FKC_BASE && keycode < (FKC_BASE + N_FKC))
#define FKC_INDEX(keycode) (keycode - FKC_BASE)

bool handle_fkc(uint16_t keycode, const keyrecord_t* record);

// To be defined in keymap.c
extern bool (* const PROGMEM FKCS[])(uint16_t keycode, const keyrecord_t* record);
