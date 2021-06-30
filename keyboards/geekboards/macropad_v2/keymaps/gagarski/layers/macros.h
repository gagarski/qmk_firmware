#pragma once

#include QMK_KEYBOARD_H

#include "kc.h"
#include "tapdance.h"

void tap_dance_mdash(uint16_t tap);
bool mvn_clean_package(uint16_t keycode, const keyrecord_t* record);
bool mvn_cleaan_package_whatever(uint16_t keycode, const keyrecord_t* record);


#define MACROS_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_MDASH),         UC(0x2013),                          UC(0x00AB), UC(0x00BB),\
    FKC(FKC_MVN_CLEAN_PACKAGE), FKC(FKC_MVN_CLEAN_PACKAGE_WHATEVER), UC(0x201E), UC(0x201C)\
)

#define MACROS_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_MDASH] = LAYERS_TD_TOP_LEVEL

#define MACROS_LAYER_LAYERS_TD_PART \
    [TD_LAYER_MDASH] = FUN_LAYERS_TD(tap_dance_mdash)

#define MACROS_LAYER_FKCS_PART \
    [FKC_MVN_CLEAN_PACKAGE] = mvn_clean_package,\
    [FKC_MVN_CLEAN_PACKAGE_WHATEVER] = mvn_cleaan_package_whatever
