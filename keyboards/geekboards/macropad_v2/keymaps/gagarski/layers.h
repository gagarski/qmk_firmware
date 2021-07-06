#pragma once
#include QMK_KEYBOARD_H

#include "layers/basic.h"
#include "layers/idea.h"
#include "layers/idea_debug.h"
#include "layers/macros.h"
#include "layers/trucksim.h"
#include "layers/trucksim_brakes.h"
#include "layers/browser.h"
#include "layers/rgb.h"
#include "layers/ind_bl.h"
#include "layers/layer_switch.h"
#include "layers/os.h"

#define N_DEFAULT_LAYERS 8

void explicitly_set_default_layer(uint8_t layer);

bool is_explicit_layer_handled(void);

void reset_explicit_layer_handled(void);

uint8_t next_layer(void);

uint8_t prev_layer(void);

bool current_layer_state_is(uint8_t num);

uint8_t get_active_layer(void);

void eeconfig_init_layers(void);

bool is_layer_active(uint8_t layer_num);
