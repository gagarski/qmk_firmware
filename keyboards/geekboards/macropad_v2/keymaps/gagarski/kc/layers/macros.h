#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum fkcs_macros {
    FKC_NDASH = FKC_SAFE_RANGE,
    FKC_LAQUO,
    FKC_RAQUO,
    FKC_LDQUO,
    FKC_RDQUO,
    FKC_MVN_CLEAN_PACKAGE,
    FKC_MVN_CLEAN_PACKAGE_WHATEVER,
    _FKC_NEW_SAFE_RANGE_MACROS
};

enum tap_dances_macros {
    TD_LAYER_MDASH = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_MACROS
};

#undef FKC_SAFE_RANGE
#define FKC_SAFE_RANGE _FKC_NEW_SAFE_RANGE_MACROS
#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_MACROS
