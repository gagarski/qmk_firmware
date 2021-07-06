#include QMK_KEYBOARD_H
#include "macro.h"
#include "layers.h"
#include "keymap.h"

bool explicit_layer_handled = false;

void explicitly_set_default_layer(uint8_t layer) {
    set_single_persistent_default_layer(layer);
    explicit_layer_handled = true;
}

bool is_explicit_layer_handled(void) {
    return explicit_layer_handled;
}

void reset_explicit_layer_handled(void) {
    explicit_layer_handled = false;
}

uint8_t next_layer(void) {
    uint8_t layer = get_active_layer();
    if (layer == N_DEFAULT_LAYERS - 1) {
        layer = 0;
    } else {
        layer++;
    }
    return layer;
}

uint8_t prev_layer(void) {
    uint8_t layer = get_active_layer();
    if (layer == 0) {
        layer = N_DEFAULT_LAYERS - 1;
    } else {
        layer--;
    }
    return layer;
}

bool current_layer_state_is(uint8_t num) {
    return (1 << num & default_layer_state) != 0;
}

uint8_t get_active_layer(void) {
    return biton32(default_layer_state);
}

void eeconfig_init_layers(void) {
    set_single_persistent_default_layer(0);
}

bool is_layer_active(uint8_t layer_num) {
    return (layer_state >> layer_num) & 0x1;
}
