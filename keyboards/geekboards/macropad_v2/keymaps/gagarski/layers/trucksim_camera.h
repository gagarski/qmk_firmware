#pragma once

#include QMK_KEYBOARD_H

#include "kc.h"
#include "tapdance.h"

#define L_TRUCKSIM_CAMERA 5


#define TRUCKSIM_CAMERA_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_1), KC_KP_SLASH, MS_BTN2,        KC_KP_ASTERISK,\
    KC_5,           KC_KP_7,     KC_KP_5,        KC_KP_9\
)

#define TRUCKSIM_CAMERA_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_1] = LAYERS_TD_TOP_LEVEL(TD_LAYER_1)

#define TRUCKSIM_CAMERA_LAYER_LAYERS_TD_PART \
    [TD_LAYER_1] = KEYCODE_LAYERS_TD(KC_1)
