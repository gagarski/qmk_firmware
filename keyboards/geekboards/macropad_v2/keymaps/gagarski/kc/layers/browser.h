#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_browser {
    TD_LAYER_CTRL_L = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_BROWSER
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_BROWSER
