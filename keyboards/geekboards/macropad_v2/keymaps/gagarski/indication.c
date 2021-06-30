#include QMK_KEYBOARD_H

#include "eeprom.h"

#include "indication.h"
#include "layers.h"
#include "macro.h"
#include "reset.h"

enum ind_modes {
    IND_FIRST_GUARD = -1,
    IND_COLOR,
    IND_COLOR_ALL,
    IND_WHITE,
    IND_BLINK_COLOR_THEN_TRANSPARENT,
    IND_BLINK_COLOR_ALL_THEN_TRANSPARENT,
    IND_BLINK_COLOR_THEN_FORCE_OFF,
    IND_BLINK_COLOR_ALL_THEN_FORCE_OFF,
    IND_BLINK_WHITE_THEN_TRANSPARENT,
    IND_BLINK_WHITE_THEN_FORCE_OFF,
    // End of safe range
    IND_TRANSPARENT,
    IND_FORCE_OFF,
    IND_LAST_GUARD
};

enum bl_modes {
    BL_FIRST_GUARD = -1,
    BL_COLOR,
    BL_BLINK_THEN_TRANSPARENT,
    BL_BLINK_THEN_FORCE_OFF,
    // End of safe range
    BL_TRANSPARENT,
    BL_FORCE_OFF,
    BL_LAST_GUARD
};


typedef struct rgb {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} rgb_t;


const int N_IND_MODES = IND_LAST_GUARD - IND_FIRST_GUARD - 1;
const int N_IND_MODES_SAFE = IND_TRANSPARENT - IND_FIRST_GUARD - 1;

const int N_BL_MODES = BL_LAST_GUARD - BL_FIRST_GUARD - 1;
const int N_BL_MODES_SAFE = BL_TRANSPARENT - BL_FIRST_GUARD - 1;

uint8_t* const IND_SETTINGS_ADDR = (uint8_t*) EECONFIG_SIZE;
uint8_t* const BL_SETTINGS_ADDR = (uint8_t*) (EECONFIG_SIZE + 1);

const int MAX_BRIGHTNESS = 15;
const int MIN_BRIGHNTESS = 0;
const int MIN_BRIGHNTESS_SAFE = 1;

const int N_BLINK_STEPS = 4;
const uint16_t BLINK_MS = 300;

// do not change the size, ind_reset_snake will misbehave
#define N_KEY_LEDS 8
const uint16_t PROGMEM KEY_LEDS[N_KEY_LEDS] = {
    13, 19, 20, 26,
    6,  0,  38, 33
};

// do not change the size, bl_reset_snake will misbehave
#define N_BACKLIGHT_LEDS 34
const uint16_t PROGMEM BACKLIGHT_LEDS[N_BACKLIGHT_LEDS] = {
    21, 22, 23, 24, 25,
    27, 28, 29, 30, 31, 32,
    34, 35, 36, 37, 39, 40, 41, 1, 2, 3, 4, 5,
    7, 8, 9, 10, 11, 12,
    14, 15, 16, 17 ,18,
};


const rgb_t PROGMEM KEY_COLORS[] = {
    {.r = 0xff, .g = 0xff, .b = 0xff},
    {.r = 0xff, .g = 0x66, .b = 0x00},
    {.r = 0x00, .g = 0xff, .b = 0x00},
    {.r = 0xff, .g = 0xff, .b = 0x00},
    {.r = 0xff, .g = 0x00, .b = 0xff},
    {.r = 0xff, .g = 0x00, .b = 0x00},
    {.r = 0x00, .g = 0xff, .b = 0xff},
    {.r = 0x66, .g = 0x00, .b = 0xcc}
};

const rgb_t PROGMEM WHITE = {.r = 0xff, .g = 0xff, .b = 0xff};
const rgb_t PROGMEM BLACK = {.r = 0x0, .g = 0x0, .b = 0x0};
const rgb_t PROGMEM RED = {.r = 0xff, .g = 0x0, .b = 0x0};
const rgb_t PROGMEM ORANGE = {.r = 0xff, .g = 0x80, .b = 0x0};

uint8_t ind_mode = 0;
uint8_t ind_brightness = 15;
uint8_t bl_mode = 0;
uint8_t bl_brightness = 15;

bool blink_active_ind = false;
bool blink_active_bl = false;
uint8_t blink_ctr = 0;
bool blink_on = false;
uint16_t last_blink_timer = 0;

void reset_ind_and_bl_settings(void) {
    ind_mode = 0;
    ind_brightness = 15;
    bl_mode = 0;
    bl_brightness = 15;
}

uint8_t settings_to_persist(uint8_t mode, uint8_t brightness) {
    return mode << 4 | brightness;
}

void persist_ind_settings(void) {
    eeprom_update_byte(IND_SETTINGS_ADDR, settings_to_persist(ind_mode, ind_brightness));
}

void persist_bl_settings(void) {
    eeprom_update_byte(BL_SETTINGS_ADDR, settings_to_persist(bl_mode, bl_brightness));
}

void read_settings(uint8_t from_eeprom, uint8_t* mode, uint8_t* brightness) {
    *mode = from_eeprom >> 4;
    *brightness = from_eeprom & 0xf;
}

void read_ind_settings(void) {
    read_settings(eeprom_read_byte(IND_SETTINGS_ADDR), &ind_mode, &ind_brightness);
}

void read_bl_settings(void) {
    read_settings(eeprom_read_byte(BL_SETTINGS_ADDR), &bl_mode, &bl_brightness);
}

void change_mode(uint8_t* mode, bool rev, uint8_t min, uint8_t max) {
    if (rev) {
        (*mode)--;
    } else {
        (*mode)++;
    }
    if (*mode > max || *mode < min) {
        *mode = rev ? max : min;
    }
}

void change_brightness(uint8_t* brightness, bool rev, uint8_t min, uint8_t max) {
    if (rev) {
        (*brightness)--;
    } else {
        (*brightness)++;
    }
    if (*brightness > max || *brightness < min) {
        *brightness = rev ? min : max;
    }
}

bool is_bl_safe(void) {
    return bl_mode < N_BL_MODES_SAFE && bl_brightness >= MIN_BRIGHNTESS_SAFE;
}

bool is_ind_safe(void) {
    return ind_mode < N_IND_MODES_SAFE && ind_brightness >= MIN_BRIGHNTESS_SAFE;
}

uint8_t ind_mode_max(void) {
    if (is_bl_safe()) {
        return N_IND_MODES - 1;
    } else {
        return N_IND_MODES_SAFE - 1;
    }
}

uint8_t bl_mode_max(void) {
    if (is_ind_safe()) {
        return N_BL_MODES - 1;
    } else {
        return N_BL_MODES_SAFE - 1;
    }
}

uint8_t ind_brightness_min(void) {
    if (is_bl_safe()) {
        return MIN_BRIGHNTESS;
    } else {
        return MIN_BRIGHNTESS_SAFE;
    }
}

uint8_t bl_brightness_min(void) {
    if (is_ind_safe()) {
        return MIN_BRIGHNTESS;
    } else {
        return MIN_BRIGHNTESS_SAFE;
    }
}

void next_ind_mode(void) {
    change_mode(&ind_mode, false, 0, ind_mode_max());
    persist_ind_settings();
    start_blink(true, false);
}

void prev_ind_mode(void) {
    change_mode(&ind_mode, true, 0, ind_mode_max());
    persist_ind_settings();
    start_blink(true, false);
}

void next_bl_mode(void) {
    change_mode(&bl_mode, false, 0, bl_mode_max());
    persist_bl_settings();
    start_blink(false, true);
}

void prev_bl_mode(void) {
    change_mode(&bl_mode, true, 0, bl_mode_max());
    persist_bl_settings();
    start_blink(false, true);
}

void inc_ind_brightness(void) {
    change_brightness(&ind_brightness, false, ind_brightness_min(), MAX_BRIGHTNESS);
    persist_ind_settings();
}

void dec_ind_brightness(void) {
    change_brightness(&ind_brightness, true, ind_brightness_min(), MAX_BRIGHTNESS);
    persist_ind_settings();
}

void inc_bl_brightness(void) {
    change_brightness(&bl_brightness, false, bl_brightness_min(), MAX_BRIGHTNESS);
    persist_bl_settings();
}

void dec_bl_brightness(void) {
    change_brightness(&bl_brightness, true, bl_brightness_min(), MAX_BRIGHTNESS);
    persist_bl_settings();
}


rgb_t get_adjusted_color(const rgb_t* orig, uint8_t brightness) {
    rgb_t to_ret = {
        .r = (uint16_t) orig->r * brightness / MAX_BRIGHTNESS,
        .g = (uint16_t) orig->g * brightness / MAX_BRIGHTNESS,
        .b = (uint16_t) orig->b * brightness / MAX_BRIGHTNESS
    };
    return to_ret;
}

rgb_t get_adjusted_color_for_layer(uint8_t layer, uint8_t brightness) {
    return get_adjusted_color(&(KEY_COLORS[layer]), brightness);
}

rgb_t get_adjusted_white(uint8_t brightness) {
    return get_adjusted_color(&WHITE, brightness);
}



void ind_color(void) {
    int layer = get_active_layer();
    rgb_t color = get_adjusted_color_for_layer(layer, ind_brightness);
    for (int i = 0; i < NUMEL(KEY_LEDS); i++) {
        if (i == layer) {
            rgb_matrix_set_color(KEY_LEDS[i], color.r, color.g, color.b);
        } else {
            rgb_matrix_set_color(KEY_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
        }
    }
}

void ind_color_all(void) {
    rgb_t color = get_adjusted_color_for_layer(get_active_layer(), ind_brightness);
    for (int i = 0; i < NUMEL(KEY_LEDS); i++) {
        rgb_matrix_set_color(KEY_LEDS[i], color.r, color.g, color.b);
    }
}

void ind_white(void) {
    int layer = get_active_layer();
    rgb_t color = get_adjusted_white(ind_brightness);
    for (int i = 0; i < NUMEL(KEY_LEDS); i++) {
        if (i == layer) {
            rgb_matrix_set_color(KEY_LEDS[i], color.r, color.g, color.b);
        } else {
            rgb_matrix_set_color(KEY_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
        }
    }
}

void ind_transparent(void) {
    // do nothing
}

void ind_force_off(void) {
    for (int i = 0; i < NUMEL(KEY_LEDS); i++) {
        rgb_matrix_set_color(KEY_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
    }
}

void ind_blink_color_generic(void (*if_not_active)(void), const rgb_t* blink_color) {
    if (!blink_active_ind) {
        if_not_active();
        return;
    }

    const rgb_t* color = blink_on ? blink_color : &BLACK;
    uint8_t layer = get_active_layer();

    for (int i = 0; i < NUMEL(KEY_LEDS); i++) {
        if (blink_on && i == layer) {
            rgb_matrix_set_color(KEY_LEDS[i], color->r, color->g, color->b);
        } else {
            rgb_matrix_set_color(KEY_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
        }
    }
}

void ind_blink_color_all_generic(void (*if_not_active)(void), const rgb_t* blink_color) {
    if (!blink_active_ind) {
        if_not_active();
        return;
    }

    const rgb_t* color = blink_on ? blink_color : &BLACK;

    for (int i = 0; i < NUMEL(KEY_LEDS); i++) {
        if (blink_on) {
            rgb_matrix_set_color(KEY_LEDS[i], color->r, color->g, color->b);
        } else {
            rgb_matrix_set_color(KEY_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
        }
    }
}

void ind_blink_color_then_transparent(void) {
    rgb_t color = get_adjusted_color_for_layer(get_active_layer(), ind_brightness);
    ind_blink_color_generic(&ind_transparent, &color);
}

void ind_blink_color_all_then_transparent(void) {
    rgb_t color = get_adjusted_color_for_layer(get_active_layer(), ind_brightness);
    ind_blink_color_all_generic(&ind_transparent, &color);
}

void ind_blink_color_then_force_off(void) {
    rgb_t color = get_adjusted_color_for_layer(get_active_layer(), ind_brightness);
    ind_blink_color_generic(&ind_force_off, &color);
}

void ind_blink_color_all_then_force_off(void) {
    rgb_t color = get_adjusted_color_for_layer(get_active_layer(), ind_brightness);
    ind_blink_color_all_generic(&ind_force_off, &color);
}

void ind_blink_white_then_transparent(void) {
    rgb_t color = get_adjusted_white(ind_brightness);
    ind_blink_color_generic(&ind_transparent, &color);
}

void ind_blink_white_then_force_off(void) {
    rgb_t color = get_adjusted_white(ind_brightness);
    ind_blink_color_generic(&ind_force_off, &color);
}


#if N_RESET_STEPS != 32
#    error "Changing N_RESET_STEPS is not supported"
#endif

#if N_KEY_LEDS != 8
#    error "Changing N_KEY_LEDS is not supported"
#endif

// TODO make it more universal and properly reacting on N_RESET_STEPS/N_BACKLIGHT_LEDS change
void ind_reset_snake(void) {
    rgb_t color = is_reset_requested() ? RED : ORANGE;
    int led_active;
    int half = N_KEY_LEDS / 2;
    int led_step = (get_reset_step() / (N_RESET_STEPS / N_KEY_LEDS) + N_KEY_LEDS / 4) % N_KEY_LEDS;
    if (led_step < half) {
        led_active = led_step;
    } else {
        led_active = half + (N_KEY_LEDS - led_step) - 1;
    }

    for (int i = 0; i < N_KEY_LEDS; i++) {
        if (i == led_active) {
            rgb_matrix_set_color(KEY_LEDS[i], color.r, color.g, color.b);
            rgb_matrix_set_color(KEY_LEDS[i], color.r, color.g, color.b);
        } else {
            rgb_matrix_set_color(KEY_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
            rgb_matrix_set_color(KEY_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
        }
    }
}


void handle_indicators(void) {
    if (is_reset_requested() || is_eeprom_reset_requested()) {
        ind_reset_snake();
        return;
    }
    switch (ind_mode) {
        case IND_COLOR:
            ind_color();
            break;
        case IND_COLOR_ALL:
            ind_color_all();
            break;
        case IND_WHITE:
            ind_white();
            break;
        case IND_BLINK_COLOR_THEN_TRANSPARENT:
            ind_blink_color_then_transparent();
            break;
        case IND_BLINK_COLOR_ALL_THEN_TRANSPARENT:
            ind_blink_color_all_then_transparent();
            break;
        case IND_BLINK_COLOR_THEN_FORCE_OFF:
            ind_blink_color_then_force_off();
            break;
        case IND_BLINK_COLOR_ALL_THEN_FORCE_OFF:
            ind_blink_color_all_then_force_off();
            break;
        case IND_BLINK_WHITE_THEN_TRANSPARENT:
            ind_blink_white_then_transparent();
            break;
        case IND_BLINK_WHITE_THEN_FORCE_OFF:
            ind_blink_white_then_force_off();
            break;
        case IND_TRANSPARENT:
            ind_transparent();
            break;
        case IND_FORCE_OFF:
            ind_force_off();
            break;
    }
}

void bl_color(void) {
    rgb_t color = get_adjusted_color_for_layer(get_active_layer(), bl_brightness);

    for (int i = 0; i < NUMEL(BACKLIGHT_LEDS); i++) {
        rgb_matrix_set_color(BACKLIGHT_LEDS[i], color.r, color.g, color.b);
    }
}

void bl_transparent(void) {
    // do nothing
}

void bl_force_off(void) {
    for (int i = 0; i < NUMEL(BACKLIGHT_LEDS); i++) {
        rgb_matrix_set_color(BACKLIGHT_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
    }
}

void bl_blink_generic(void (*if_not_active)(void)) {
    if (!blink_active_bl) {
        if_not_active();
        return;
    }
    rgb_t color = get_adjusted_color_for_layer(get_active_layer(), bl_brightness);

    for (int i = 0; i < NUMEL(BACKLIGHT_LEDS); i++) {
        if (blink_on) {
            rgb_matrix_set_color(BACKLIGHT_LEDS[i], color.r, color.g, color.b);
        } else {
            rgb_matrix_set_color(BACKLIGHT_LEDS[i], BLACK.r, BLACK.g, BLACK.b);
        }
    }
}

void bl_blink_then_transparent(void) {
    bl_blink_generic(&bl_transparent);
}

void bl_blink_then_force_off(void) {
    bl_blink_generic(&bl_force_off);
}


#if N_RESET_STEPS != 32
#    error "Changing N_RESET_STEPS is not supported"
#endif

#if N_BACKLIGHT_LEDS != 34
#    error "Changing N_BACKLIGHT_LEDS is not supported"
#endif

// TODO make it more universal and properly reacting on N_RESET_STEPS/N_BACKLIGHT_LEDS change
void bl_reset_snake(void) {
    rgb_t color = is_reset_requested() ? RED : ORANGE;

    rgb_matrix_set_color(BACKLIGHT_LEDS[0], color.r, color.g, color.b);
    rgb_matrix_set_color(BACKLIGHT_LEDS[N_BACKLIGHT_LEDS - 1], color.r, color.g, color.b);

    for (int i = 0; i < N_RESET_STEPS; i++) {
        if (i == get_reset_step()) {
            rgb_matrix_set_color(BACKLIGHT_LEDS[i + 1], color.r, color.g, color.b);
            rgb_matrix_set_color(BACKLIGHT_LEDS[i + 1], color.r, color.g, color.b);
        } else {
            rgb_matrix_set_color(BACKLIGHT_LEDS[i + 1], BLACK.r, BLACK.g, BLACK.b);
            rgb_matrix_set_color(BACKLIGHT_LEDS[i + 1], BLACK.r, BLACK.g, BLACK.b);
        }
    }
}

void handle_backlight(void) {
    if (is_reset_requested() || is_eeprom_reset_requested()) {
        bl_reset_snake();
        return;
    }
    switch (bl_mode) {
        case BL_COLOR:
            bl_color();
            break;
        case BL_BLINK_THEN_TRANSPARENT:
            bl_blink_then_transparent();
            break;
        case BL_BLINK_THEN_FORCE_OFF:
            bl_blink_then_force_off();
            break;
        case BL_TRANSPARENT:
            bl_transparent();
            break;
        case BL_FORCE_OFF:
            bl_force_off();
            break;
    }
}

void start_blink(bool ind, bool bl) {
    blink_ctr = 0;
    blink_on = true;
    last_blink_timer = timer_read();
    blink_active_ind = ind;
    blink_active_bl = bl;
}

void stop_blink(void) {
    blink_ctr = 0;
    blink_on = false;
    last_blink_timer = 0;
    blink_active_ind = false;
    blink_active_bl = false;
}

void do_blink(void) {
    if (!blink_active_ind && !blink_active_bl) {
        return;
    }

    uint32_t n_elapsed = timer_elapsed(last_blink_timer) / BLINK_MS;

    blink_on = n_elapsed % 2 == 0;

    if (n_elapsed >= N_BLINK_STEPS) {
        stop_blink();
    }
}

void rgb_matrix_indicators_ind_bl(void) {
    do_blink();
    handle_indicators();
    handle_backlight();
}

void eeconfig_init_ind_bl(void) {
    reset_ind_and_bl_settings();
    persist_ind_settings();
    persist_bl_settings();
}

void post_init_ind_bl(void) {
    read_ind_settings();
    read_bl_settings();
}
