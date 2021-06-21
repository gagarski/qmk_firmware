#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_idea {
    TD_LAYER_ALT_F1_1 = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_IDEA
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_IDEA
