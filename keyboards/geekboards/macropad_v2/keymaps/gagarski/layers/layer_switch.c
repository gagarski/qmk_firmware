#include QMK_KEYBOARD_H
#include "kc.h"
#include "layers.h"
#include "indication.h"

bool to_layer(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        explicitly_set_default_layer(keycode - FKC(FKC_L0));
        start_blink(true, true);
        return true;
    }
    return false;
}
