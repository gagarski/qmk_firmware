#pragma once

#include QMK_KEYBOARD_H

#include "fkc.h"
#include "kc.h"

#define LAYER_SWITCH_LAYER LAYOUT_ortho_2x4(\
        KC_TRNS,     FKC(FKC_L1), FKC(FKC_L2), FKC(FKC_L3),\
        FKC(FKC_L4), FKC(FKC_L5), FKC(FKC_L6), FKC(FKC_L7)\
    )

#define LAYER_SWITCH_LAYER_FKCS_PART \
    [FKC_L0] = to_layer,\
    [FKC_L1] = to_layer,\
    [FKC_L2] = to_layer,\
    [FKC_L3] = to_layer,\
    [FKC_L4] = to_layer,\
    [FKC_L5] = to_layer,\
    [FKC_L6] = to_layer,\
    [FKC_L7] = to_layer,

bool to_layer(uint16_t keycode, const keyrecord_t* record);
