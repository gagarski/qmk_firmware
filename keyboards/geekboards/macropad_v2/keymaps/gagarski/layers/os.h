#pragma once

#include QMK_KEYBOARD_H

#include "fkc.h"

#define L_OS 10

#define OS_LAYER LAYOUT_ortho_2x4(\
    FKC(FKC_OS_TO_WINDOWS_10), FKC(FKC_OS_TO_MACOS), FKC(FKC_OS_TO_LINUX), FKC(FKC_OS_TO_WINDOWS_7),\
    KC_TRNS,                   KC_NO,                KC_NO,                KC_NO\
)

#define OS_LAYER_FKCS_PART \
    [FKC_OS_TO_WINDOWS_10] = fkc_os_to_windows_10,\
    [FKC_OS_TO_MACOS] = fkc_os_to_macos,\
    [FKC_OS_TO_LINUX] = fkc_os_to_linux,\
    [FKC_OS_TO_WINDOWS_7] = fkc_os_to_windows_7

bool fkc_os_to_windows_10(uint16_t keycode, const keyrecord_t* record);
bool fkc_os_to_macos(uint16_t keycode, const keyrecord_t* record);
bool fkc_os_to_linux(uint16_t keycode, const keyrecord_t* record);
bool fkc_os_to_windows_7(uint16_t keycode, const keyrecord_t* record);
