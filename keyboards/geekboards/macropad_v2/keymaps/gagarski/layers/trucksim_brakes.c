#include QMK_KEYBOARD_H

#include "kc.h"
#include "tapdance.h"

void tap_dance_f_o_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_F);
    } else {
        register_code16(KC_O);
    }
}

void tap_dance_f_o_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_F);
    } else {
        unregister_code16(KC_O);
    }
}

void tap_dance_j_h_n_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_J);
    } else if (state->count == 2) {
        register_code16(KC_H);
    } else {
        register_code16(KC_N);
    }
}

void tap_dance_j_h_n_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code16(KC_J);
    } else if (state->count == 2) {
        unregister_code16(KC_H);
    } else {
        unregister_code16(KC_N);
    }
}
