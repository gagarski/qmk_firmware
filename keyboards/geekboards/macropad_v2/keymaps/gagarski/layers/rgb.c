#include QMK_KEYBOARD_H

#include "layers.h"

void do_rgb_mod_rev(uint16_t tap) {
    rgb_matrix_step_reverse();
}

void tap_dance_rgb_to_ind_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (!state->interrupted && state->pressed) {
        layer_on(L_IND_BL);
    } else {
        rgb_matrix_step_reverse();
    }
}

void tap_dance_rgb_to_ind_reset(qk_tap_dance_state_t *state, void *user_data) {
    layer_off(L_IND_BL);
}
