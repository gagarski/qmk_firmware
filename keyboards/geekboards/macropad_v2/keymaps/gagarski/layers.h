#pragma once
#include QMK_KEYBOARD_H

#include "layers/basic.h"
#include "layers/idea.h"
#include "layers/rgb.h"
#include "layers/ind_bl.h"
#include "layers/layer_switch.h"

void explicitly_set_default_layer(uint8_t layer);

bool is_explicit_layer_handled(void);

void reset_explicit_layer_handled(void);

uint8_t next_layer(void);

uint8_t prev_layer(void);

bool current_layer_state_is(uint8_t num);

uint8_t get_active_layer(void);

enum layers {
    // default
    L_BASIC = 0,
    L_IDEA,
    L_RGB = 7,
    // non-default
    L_IND = 8,
    L_LAYER_SWITCH = 9
};

#define N_DEFAULT_LAYERS 8
