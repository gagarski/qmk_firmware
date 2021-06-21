#include QMK_KEYBOARD_H
#include "reset.h"
#include "indication.h"

#define RESET_STEP_LENGTH 300

bool reset_requested = false;
bool eeprom_reset_requested = false;
uint32_t reset_start = 0;
uint8_t reset_step = 0;

void request_reset(void) {
    reset_requested = true;
    eeprom_reset_requested = false;
    reset_start = timer_read();
    reset_step = 0;
}

void request_eeprom_reset(void) {
    eeprom_reset_requested = true;
    reset_requested = false;
    reset_start = timer_read();
    reset_step = 0;
}

void cancel_reset(void) {
    eeprom_reset_requested = false;
    reset_requested = false;
    reset_start = 0;
    reset_step = 0;
}

bool is_reset_requested(void) {
    return reset_requested;
}

bool is_eeprom_reset_requested(void) {
    return eeprom_reset_requested;
}


uint8_t get_reset_step(void) {
    return reset_step;
}

// XXX this is probably not public API
void rgb_matrix_update_pwm_buffers(void);

void matrix_scan_reset(void) {
    if (!reset_requested && !eeprom_reset_requested) {
        return;
    }
    uint8_t elapsed = timer_elapsed(reset_start) / RESET_STEP_LENGTH;
    if (elapsed >= N_RESET_STEPS) {
        rgb_matrix_set_color_all(0, 0, 0);
        rgb_matrix_update_pwm_buffers();
        if (reset_requested) {
            eeconfig_init();
            reset_keyboard();
        } else if (eeprom_reset_requested) {
            eeconfig_init();
        }
        cancel_reset();
        return;
    }

    reset_step = elapsed;
}
