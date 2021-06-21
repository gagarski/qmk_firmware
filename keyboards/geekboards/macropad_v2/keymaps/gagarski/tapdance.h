#pragma once

#include QMK_KEYBOARD_H
#include "kc.h"

typedef struct layers_td {
    void (*on_tap)(uint16_t tap);
    uint16_t tap;
} layers_td_t;


extern const layers_td_t PROGMEM LAYERS_TDS[];

void tap_dance_with_layers_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_with_layers_reset(qk_tap_dance_state_t *state, void *user_data);

void tap_dance_rgb_to_ind_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_rgb_to_ind_reset(qk_tap_dance_state_t *state, void *user_data);


#define KEYCODE_LAYERS_TD(keycode) {.on_tap = tap_code16, .tap = keycode}
#define FUN_LAYERS_TD(fun) {.on_tap = fun, .tap = 0}
#define FUN_KEYCODE_LAYERS_TD(fun, keycode) {.on_tap = fun, .tap = keycode}

#define LAYERS_TD_TOP_LEVEL ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_with_layers_finished, tap_dance_with_layers_reset)
