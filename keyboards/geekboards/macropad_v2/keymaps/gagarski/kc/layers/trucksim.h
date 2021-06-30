#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_trucksim {
    TD_LAYER_U = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_TRUCKSIM
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_TRUCKSIM
