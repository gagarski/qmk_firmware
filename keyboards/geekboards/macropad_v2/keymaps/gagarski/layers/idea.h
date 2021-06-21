#pragma once
#include QMK_KEYBOARD_H
#include "kc.h"
#include "tapdance.h"

void alt_f1_1(uint16_t tap);

#define IDEA_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_ALT_F1_1), LSFT(KC_F6), KC_F9,       LCTL(KC_F2),\
    KC_F8,                 KC_F7,       LSFT(KC_F8), LALT(LSFT(KC_9))\
)

#define IDEA_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_ALT_F1_1] = LAYERS_TD_TOP_LEVEL

#define IDEA_LAYER_LAYERS_TD_PART \
    [TD_LAYER_ALT_F1_1] = FUN_LAYERS_TD(alt_f1_1)
