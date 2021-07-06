#pragma once

#include QMK_KEYBOARD_H

typedef enum oses {
    _OS_FIRST_GUARD = -1,
    WINDOWS_10 = 0,
    LINUX,
    MACOS,
    WINDOWS_7,
    _OS_LAST_GUARD
} os_t;

#define N_OS = (_OS_LAST_GUARD - _OS_FIRST_GUARD - 1)

os_t get_os(void);

void set_os(os_t os);

void eeconfig_init_os(void);

void post_init_os(void);
