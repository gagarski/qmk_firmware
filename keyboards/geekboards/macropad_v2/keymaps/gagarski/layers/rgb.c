#include QMK_KEYBOARD_H

void do_rgb_mod_rev(uint16_t tap) {
    rgb_matrix_step_reverse();
}
