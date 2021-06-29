#include QMK_KEYBOARD_H

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool alt_tab(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
    } else {
        unregister_code(KC_TAB);
    }
    return true;
}

bool alt_shift_tab(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
        alt_tab_timer = timer_read();
        register_code(KC_LSHIFT);
        register_code(KC_TAB);
    } else {
        unregister_code(KC_LSHIFT);
        unregister_code(KC_TAB);
    }
    return true;
}

void matrix_scan_alt_tab(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 2000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

void matrix_scan_basic(void) {
    matrix_scan_alt_tab();
}
