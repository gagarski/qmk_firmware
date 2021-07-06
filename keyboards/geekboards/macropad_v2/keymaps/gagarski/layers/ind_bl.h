#pragma once

#include QMK_KEYBOARD_H

#include "kc.h"
#include "fkc.h"

#define L_IND_BL 8

#define IND_BL_LAYER LAYOUT_ortho_2x4(\
    KC_NO,   FKC(FKC_NEXT_IND_MODE), FKC(FKC_INC_IND_BRIGHTNESS), FKC(FKC_INC_BL_BRIGHTNESS),\
    KC_TRNS, FKC(FKC_NEXT_BL_MODE),  FKC(FKC_DEC_IND_BRIGHTNESS), FKC(FKC_DEC_BL_BRIGHTNESS)\
)

#define IND_BL_LAYER_FKCS_PART \
    [FKC_NEXT_IND_MODE] = do_next_ind_mode,\
    [FKC_NEXT_BL_MODE] = do_next_bl_mode,\
    [FKC_INC_IND_BRIGHTNESS] = do_inc_ind_brightness,\
    [FKC_DEC_IND_BRIGHTNESS] = do_dec_ind_brightness,\
    [FKC_INC_BL_BRIGHTNESS] = do_inc_bl_brightness,\
    [FKC_DEC_BL_BRIGHTNESS] = do_dec_bl_brightness


bool do_next_ind_mode(uint16_t keycode, const keyrecord_t* record);

bool do_next_bl_mode(uint16_t keycode, const keyrecord_t* record);

bool do_inc_ind_brightness(uint16_t keycode, const keyrecord_t* record);

bool do_dec_ind_brightness(uint16_t keycode, const keyrecord_t* record);

bool do_inc_bl_brightness(uint16_t keycode, const keyrecord_t* record);

bool do_dec_bl_brightness(uint16_t keycode, const keyrecord_t* record);
