#pragma once

#include QMK_KEYBOARD_H

#include "kc.h"
#include "tapdance.h"

#define L_MACROS 3

#define MACROS_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_MDASH),         FKC(FKC_NDASH),                      FKC(FKC_LAQUO), FKC(FKC_RAQUO),\
    FKC(FKC_MVN_CLEAN_PACKAGE), FKC(FKC_MVN_CLEAN_PACKAGE_WHATEVER), FKC(FKC_LDQUO), FKC(FKC_RDQUO)\
)

#define MACROS_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_MDASH] = LAYERS_TD_TOP_LEVEL

#define MACROS_LAYER_LAYERS_TD_PART \
    [TD_LAYER_MDASH] = FUN_LAYERS_TD(tap_dance_mdash)

#define MACROS_LAYER_FKCS_PART \
    [FKC_NDASH] = ndash,\
    [FKC_LAQUO] = laquo,\
    [FKC_RAQUO] = raquo,\
    [FKC_LDQUO] = ldquo,\
    [FKC_RDQUO] = rdquo,\
    [FKC_MVN_CLEAN_PACKAGE] = mvn_clean_package,\
    [FKC_MVN_CLEAN_PACKAGE_WHATEVER] = mvn_cleaan_package_whatever


void tap_dance_mdash(uint16_t tap);
bool mvn_clean_package(uint16_t keycode, const keyrecord_t* record);
bool mvn_cleaan_package_whatever(uint16_t keycode, const keyrecord_t* record);
bool ndash(uint16_t keycode, const keyrecord_t* record);
bool laquo(uint16_t keycode, const keyrecord_t* record);
bool raquo(uint16_t keycode, const keyrecord_t* record);
bool ldquo(uint16_t keycode, const keyrecord_t* record);
bool rdquo(uint16_t keycode, const keyrecord_t* record);
