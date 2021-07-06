#include QMK_KEYBOARD_H

#include "kc.h"
#include "../os.h"

bool fkc_os_to(uint16_t keycode, const keyrecord_t* record, os_t os) {
    if (record->event.pressed) {
        set_os(os);
        return true;
    } else {
        return false;
    }
}

bool fkc_os_to_windows_10(uint16_t keycode, const keyrecord_t* record) {
    return fkc_os_to(keycode, record, WINDOWS_10);
}

bool fkc_os_to_macos(uint16_t keycode, const keyrecord_t* record) {
    return fkc_os_to(keycode, record, MACOS);
}

bool fkc_os_to_linux(uint16_t keycode, const keyrecord_t* record) {
    return fkc_os_to(keycode, record, LINUX);
}

bool fkc_os_to_windows_7(uint16_t keycode, const keyrecord_t* record) {
    return fkc_os_to(keycode, record, WINDOWS_7);
}
