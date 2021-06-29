#pragma once

#ifndef KC_H
#    error "Please do not include this file directly"
#endif

enum tap_dances_idea_debug {
    TD_LAYER_ALT_F8 = TD_SAFE_RANGE,
    _TD_NEW_SAFE_RANGE_IDEA_DEBUG
};

#undef TD_SAFE_RANGE
#define TD_SAFE_RANGE _TD_NEW_SAFE_RANGE_IDEA_DEBUG
