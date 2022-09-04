#pragma once
#include QMK_KEYBOARD_H

#include "kc.h"
#include "tapdance.h"

#define L_IDEA_DEBUG 2

#define IDEA_DEBUG_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_ALT_F8), LALT(LSFT(KC_F7)), KC_F9,       LCTL(KC_F2),\
    KC_F8,               KC_F7,             LSFT(KC_F8), LALT(LSFT(KC_9))\
)

#define IDEA_DEBUG_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_ALT_F8] = LAYERS_TD_TOP_LEVEL

#define IDEA_DEBUG_LAYER_LAYERS_TD_PART \
    [L_IDEA_DEBUG] = KEYCODE_LAYERS_TD(LALT(KC_F8))
