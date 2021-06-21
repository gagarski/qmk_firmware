#include QMK_KEYBOARD_H
#include "indication.h"

bool do_next_ind_mode(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        next_ind_mode();
        return true;
    } else {
        return false;
    }
}


bool do_next_bl_mode(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        next_bl_mode();
        return true;
    } else {
        return false;
    }
}

bool do_inc_ind_brightness(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        inc_ind_brightness();
        return true;
    } else {
        return false;
    }
}

bool do_dec_ind_brightness(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        dec_ind_brightness();
        return true;
    } else {
        return false;
    }
}

bool do_inc_bl_brightness(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        inc_bl_brightness();
        return true;
    } else {
        return false;
    }
}

bool do_dec_bl_brightness(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        dec_bl_brightness();
        return true;
    } else {
        return false;
    }
}

