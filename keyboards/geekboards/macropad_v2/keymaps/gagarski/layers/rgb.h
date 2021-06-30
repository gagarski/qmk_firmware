#pragma once

#include QMK_KEYBOARD_H
#include "kc.h"
#include "tapdance.h"


void do_rgb_mod_rev(uint16_t tap);

void tap_dance_rgb_to_ind_finished(qk_tap_dance_state_t *state, void *user_data);
void tap_dance_rgb_to_ind_reset(qk_tap_dance_state_t *state, void *user_data);


#define RGB_LAYER LAYOUT_ortho_2x4(\
    TD(TD_LAYER_RGB_MOD),          RGB_VAI, RGB_HUI, RGB_SPI,\
    TD(TD_RGB_RMOD_OR_IND_LAYER),  RGB_VAD, RGB_HUD, RGB_SPD\
)

#define RGB_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_RGB_MOD] = LAYERS_TD_TOP_LEVEL,\
    [TD_RGB_RMOD_OR_IND_LAYER] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_rgb_to_ind_finished, tap_dance_rgb_to_ind_reset)

#define RGB_LAYER_LAYERS_TD_PART \
    [TD_LAYER_RGB_MOD] = FUN_LAYERS_TD(do_rgb_mod_rev)
