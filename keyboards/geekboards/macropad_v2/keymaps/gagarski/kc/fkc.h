#pragma once

#include QMK_KEYBOARD_H
#include "kc.h"

#define N_FKC 32

enum fkc_keycodes {
    FKC_BASE = KC_SAFE_RANGE,
    _NEW_KC_SAFE_RANGE_FKC = FKC_BASE + N_FKC
};

#define FKC_SAFE_RANGE 0

#undef KC_SAFE_RANGE
#define KC_SAFE_RANGE _NEW_KC_SAFE_RANGE_FKC
