#pragma once

#include QMK_KEYBOARD_H

#include "kc.h"
#include "tapdance.h"

#define L_TRUCKSIM 4

#define TRUCKSIM_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_U), KC_RBRACKET, KC_KP_4, KC_KP_6,\
    KC_Y,           KC_LBRACKET, KC_KP_1, KC_KP_3\
)

#define TRUCKSIM_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_U] = LAYERS_TD_TOP_LEVEL

#define TRUCKSIM_LAYER_LAYERS_TD_PART \
    [TD_LAYER_U] = KEYCODE_LAYERS_TD(KC_U)
