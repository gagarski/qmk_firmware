#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_trucksim_radio {
    TD_LAYER_INS = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_TRUCKSIM_RADIO
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_TRUCKSIM_RADIO
