/* Copyright 2020 Geekboards ltd. (geekboards.ru / geekboards.de)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include <string.h>

#include "macro.h"
#include "keymap.h"
#include "indication.h"
#include "tapdance.h"
#include "indication.h"
#include "layers.h"
#include "reset.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASIC] = BASIC_LAYER,
    [L_IDEA] = IDEA_LAYER,
    [2] = DUMMY,
    [3] = DUMMY,
    [4] = DUMMY,
    [5] = DUMMY,
    [6] = DUMMY,
    [L_RGB] = RGB_LAYER,
    [L_IND] = IND_BL_LAYER,
    [L_LAYER_SWITCH] = LAYER_SWITCH_LAYER
};

/*const*/ qk_tap_dance_action_t tap_dance_actions[] = {
    BASIC_LAYER_TAP_DANCE_ACTIONS_PART,
    IDEA_LAYER_TAP_DANCE_ACTIONS_PART,
    RGB_LAYER_TAP_DANCE_ACTIONS_PART
};

const layers_td_t PROGMEM LAYERS_TDS[] = {
    BASIC_LAYER_LAYERS_TD_PART,
    IDEA_LAYER_LAYERS_TD_PART,
    RGB_LAYER_LAYERS_TD_PART
};

bool (* const PROGMEM FKCS[])(uint16_t keycode, const keyrecord_t* record) = {
    BASIC_LAYER_FKCS_PART,
    IND_BL_LAYER_FKCS_PART,
    LAYER_SWITCH_LAYER_FKCS_PART
};

void matrix_scan_user(void) {
    matrix_scan_basic();
    matrix_scan_reset();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return handle_fkc(keycode, record);
}

void rgb_matrix_indicators_user(void) {
    rgb_matrix_indicators_ind_bl();
}

void eeconfig_init_user(void) {
    eeconfig_init_layers();
    eeconfig_init_ind_bl();
}

void keyboard_post_init_user(void) {
    post_init_ind_bl();
}
