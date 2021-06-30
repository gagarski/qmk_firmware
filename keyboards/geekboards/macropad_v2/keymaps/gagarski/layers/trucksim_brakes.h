#pragma once

#include QMK_KEYBOARD_H

#include "kc.h"
#include "tapdance.h"

#define L_TRUCKSIM_BRAKES 5

void tap_dance_f_o_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_f_o_reset(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_j_h_n_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_j_h_n_reset(qk_tap_dance_state_t *state, void *user_data);


#define TRUCKSIM_BRAKES_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_SPACE), TD(TD_F_O),   KC_A, KC_W,\
    KC_C,               TD(TD_J_H_N), KC_D, KC_S\
)

#define TRUCKSIM_BRAKES_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_SPACE] = LAYERS_TD_TOP_LEVEL,\
    [TD_F_O] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_f_o_finished, tap_dance_f_o_reset),\
    [TD_J_H_N] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_j_h_n_finished, tap_dance_j_h_n_reset)

#define TRUCKSIM_BRAKES_LAYER_LAYERS_TD_PART \
    [TD_LAYER_SPACE] = KEYCODE_LAYERS_TD(KC_SPACE)
