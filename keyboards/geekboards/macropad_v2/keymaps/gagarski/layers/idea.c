#include QMK_KEYBOARD_H

void alt_f1_1(uint16_t tap) {
    SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_F1) SS_UP(X_LALT) "1");
}
