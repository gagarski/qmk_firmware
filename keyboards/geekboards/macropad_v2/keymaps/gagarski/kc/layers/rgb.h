#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_rgb {
    TD_LAYER_RGB_MOD = TD_SAFE_RANGE,
    TD_RGB_RMOD_OR_IND_LAYER,
    _TD_NEW_SAFE_RANGE_RGB
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_RGB
