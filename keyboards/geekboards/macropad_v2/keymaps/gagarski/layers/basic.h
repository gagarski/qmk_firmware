#pragma once

#include QMK_KEYBOARD_H

#include "fkc.h"
#include "kc.h"
#include "tapdance.h"

#define L_BASIC 0

#define BASIC_LAYER LAYOUT_ortho_2x4(\
        TD(TD_LAYER_ALT_SHIFT), LCTL(KC_W),        LALT(KC_F4),   KC_AUDIO_VOL_UP,\
        FKC(FKC_ALT_SHIFT_TAB), FKC(FKC_ALT_TAB),  KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN)

#define BASIC_LAYER_TAP_DANCE_ACTIONS_PART \
    [TD_LAYER_ALT_SHIFT] = LAYERS_TD_TOP_LEVEL

#define BASIC_LAYER_LAYERS_TD_PART \
    [TD_LAYER_ALT_SHIFT] = KEYCODE_LAYERS_TD(LALT(KC_LSHIFT))

#define BASIC_LAYER_FKCS_PART \
    [FKC_ALT_TAB] = alt_tab, \
    [FKC_ALT_SHIFT_TAB] = alt_shift_tab

bool alt_tab(uint16_t keycode, const keyrecord_t* record);

bool alt_shift_tab(uint16_t keycode, const keyrecord_t* record);

void matrix_scan_basic(void);
