#include QMK_KEYBOARD_H
#include "kc.h"
#include "tapdance.h"

void tap_dance_mdash(uint16_t tap) {
    send_unicode_string("—");
}

bool mvn_clean_package(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        SEND_STRING("mvn clean package\n");
    }
    return false;
}
bool mvn_cleaan_package_whatever(uint16_t keycode, const keyrecord_t* record) {
    if (record->event.pressed) {
        SEND_STRING("mvn clean package -T2C -PdevBoot -DskipTests=true\n");
    }
    return false;
}
