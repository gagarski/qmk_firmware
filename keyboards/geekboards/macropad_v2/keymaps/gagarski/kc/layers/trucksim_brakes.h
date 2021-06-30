#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_trucksim_brakes {
    TD_LAYER_SPACE = TD_SAFE_RANGE,
    TD_F_O,
    TD_J_H_N,
    _TD_NEW_SAFE_RANGE_TRUCKSIM_BRAKES
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_TRUCKSIM_BRAKES
