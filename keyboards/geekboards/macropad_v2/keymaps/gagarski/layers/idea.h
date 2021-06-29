#pragma once
#include QMK_KEYBOARD_H
#include "kc.h"
#include "tapdance.h"

void alt_f1_1(uint16_t tap);

#define IDEA_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_ALT_F1_1), LCTL(KC_B),     LCTL(LALT(KC_B)), LCTL(KC_U),\
    LALT(KC_INS),          LALT(KC_ENTER), LCTL(KC_SPACE),   LSFT(KC_F6)\
)

#define IDEA_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_ALT_F1_1] = LAYERS_TD_TOP_LEVEL

#define IDEA_LAYER_LAYERS_TD_PART \
    [TD_LAYER_ALT_F1_1] = FUN_LAYERS_TD(alt_f1_1)
