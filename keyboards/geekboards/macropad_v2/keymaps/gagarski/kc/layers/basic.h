#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_basic {
    TD_LAYER_ALT_SHIFT = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_BASIC
};

enum fkcs_basic {
    FKC_ALT_TAB = FKC_SAFE_RANGE,
    FKC_ALT_SHIFT_TAB,
    _FKC_NEW_SAFE_RANGE_BASIC
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_BASIC
#undef FKC_SAFE_RANGE
#define FKC_SAFE_RANGE _FKC_NEW_SAFE_RANGE_BASIC
