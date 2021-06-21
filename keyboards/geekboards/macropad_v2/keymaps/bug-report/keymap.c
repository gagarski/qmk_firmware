#include QMK_KEYBOARD_H
#include <string.h>


enum custom_keycodes {
  CUSTOM_MUTE = SAFE_RANGE,
  CUSTOM_A
};

enum tap_dance {
    TD_MUTE = 0,
    TD_A
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ortho_2x4(
        LT(1, KC_MUTE), KC_MUTE, CUSTOM_MUTE, TD(TD_MUTE),
        LT(1, KC_A),    KC_A,    CUSTOM_A,    TD(TD_A)
    ),
    [1] = LAYOUT_ortho_2x4(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

void tap_dance_mute_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            tap_code16(KC_MUTE);
        }
    }
}

void tap_dance_a_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) {
            tap_code16(KC_A);
        }
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MUTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_mute_finished, NULL),
    [TD_A] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, tap_dance_a_finished, NULL)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CUSTOM_MUTE:
            if (record->event.pressed) {
                tap_code16(KC_MUTE);
            }
            break;
        case CUSTOM_A:
            if (record->event.pressed) {
                tap_code16(KC_A);
            }
            break;
    }
    return true;
}
