#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum fkcs_layer_switch {
    // FKC_Lx are expected to be sequencial
    FKC_L0 = FKC_SAFE_RANGE,
    FKC_L1,
    FKC_L2,
    FKC_L3,
    FKC_L4,
    FKC_L5,
    FKC_L6,
    FKC_L7,
    _FKC_NEW_SAFE_RANGE_LAYER_SWITCH
};

#undef FKC_SAFE_RANGE
#define FKC_SAFE_RANGE _FKC_NEW_SAFE_RANGE_LAYER_SWITCH
