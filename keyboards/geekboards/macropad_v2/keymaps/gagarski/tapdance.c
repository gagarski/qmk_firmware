#include QMK_KEYBOARD_H
#include "tapdance.h"
#include "keymap.h"
#include "indication.h"
#include "layers.h"
#include "reset.h"
#include "print.h"

bool hold_registered = false;

void tap_dance_with_layers_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (!state->interrupted && state->pressed) {
        hold_registered = true;
        if (state->count == 1) {
            layer_on(L_LAYER_SWITCH);
        } else if (state->count == 2) {
            layer_on(L_LAYER_SWITCH);
        } else if (state->count == 3) {
            start_blink(true, true);
        } else if (state->count == 4) {
            request_eeprom_reset();
        } else if (state->count == 5) {
            request_reset();
        }
    } else {
        layers_td_t td = LAYERS_TDS[state->keycode & 0xff];
        td.on_tap(td.tap);
    }
}

void tap_dance_with_layers_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && hold_registered) {
        layer_off(L_LAYER_SWITCH);
        reset_explicit_layer_handled();
    } else if (state->count == 2 && hold_registered) {
        layer_off(L_LAYER_SWITCH);
        if (!is_explicit_layer_handled()) {
            explicitly_set_default_layer(0);
            start_blink(true, true);
        }
        reset_explicit_layer_handled();
    } else if (state->count == 4 || state->count == 5) {
        cancel_reset();
    }
    hold_registered = false;
}


void tap_dance_rgb_to_ind_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (!state->interrupted && state->pressed) {
        layer_on(L_IND);
    } else {
        rgb_matrix_step_reverse();
    }
}

void tap_dance_rgb_to_ind_reset(qk_tap_dance_state_t *state, void *user_data) {
    layer_off(L_IND);
}
