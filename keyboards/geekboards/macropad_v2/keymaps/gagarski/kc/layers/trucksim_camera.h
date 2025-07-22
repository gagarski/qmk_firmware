#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_trucksim_camera {
    TD_LAYER_1 = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_TRUCKSIM_CAMERA
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_TRUCKSIM_CAMERA
