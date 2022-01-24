#include QMK_KEYBOARD_H

/*
    Read documentation for keycodes list
    https://docs.qmk.fm/#/keycodes?id=basic-keycodes
*/


// Modify keycodes (For use with MacOS)
#ifdef KC_VOLU
#undef KC_VOLU
#endif
#ifdef KC_VOLD
#undef KC_VOLD
#endif
#ifdef KC_MUTE
#undef KC_MUTE
#endif
#define KC_VOLU KC__VOLUP
#define KC_VOLD KC__VOLDOWN
#define KC_MUTE KC__MUTE

#include <stdio.h>

// Use Azerty layout for typing
#include "sendstring_french.h"

// Custom sendstring macros
#if __has_include("sendstring_macros.h")
#  include "sendstring_macros.h"
#endif

// Include MCP functions
#include "MCP23S17/MCP23S17.h"

enum layer_names {
  _MAIN,
  _TEXT,
  _CODE,
  _MOD,
  _FN,
  _NUM,
  _OFF,
};

enum custom_keycodes {
    LOGO = SAFE_RANGE,
    SETTINGS,
    C_M1,
    C_M2,
    C_M3,
    C_M4,
    C_M5,
    C_M6,
    C_M7,
    C_M8,
    C_M9,
    C_M10,
    C_DISPLAY_TIMER,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  C_DISPLAY_TIMER,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, XXXXXXX,
        KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, XXXXXXX,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_SLSH, KC_LSFT, KC_PGUP,
        MO(_FN), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_RCTL, KC_PGDN),

    [_MOD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LSFT, KC_CAPS,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, KC_LSFT, _______,
        MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_TEXT] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, _______, _______, _______,
        MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_CODE] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_FN] = LAYOUT(
        SETTINGS, KC_F13,      KC_F14,       KC_F15,       KC_F16,  KC_F17,  KC_INS,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  KC_PSCR,
        LOGO,     C_M1,        C_M2,         C_M3,         C_M4,    C_M5,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX,  C_M6,        C_M7,         C_M8,         C_M9,    C_M10,   XXXXXXX, C_M1,    C_M2,    C_M3,    C_M4,    C_M5,    XXXXXXX, XXXXXXX, XXXXXXX,
        KC_NUBS,  KC_NUBS,     S(KC_NUBS),   XXXXXXX,      XXXXXXX, XXXXXXX, KC_VOLU, C_M6,    C_M7,    C_M8,    C_M9,    C_M10,   XXXXXXX, XXXXXXX, KC_CAPS,
        KC_LSFT,  LCTL(KC_UP), LCA(KC_LEFT), LCA(KC_RGHT), XXXXXXX, LOGO,    KC_VOLD, XXXXXXX, XXXXXXX, KC_MPRV, KC_HOME, KC_F15,  KC_END,  XXXXXXX, XXXXXXX,
        MO(_FN),  MO(_NUM),    KC_LALT,      KC_APP,       KC_MPLY, KC_MPLY, KC_MUTE, KC_MSTP, KC_MSTP, KC_MNXT, XXXXXXX, KC_F14,  XXXXXXX, XXXXXXX, XXXXXXX),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_PSLS, KC_PAST, KC_PMNS,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PCMM,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PEQL,
        MO(_FN), MO(_NUM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PENT),

    [_OFF] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        MO(_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    // EXAMPLE
    // [_MAIN] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

};

// const char *const layer_labels[] PROGMEM = {
//     [_MAIN] = "Base",
//     [_MOD] = "Mod",
//     [_FN] = "FN",
//     [_NUM] = "Num",
//     [_OFF] = "Off",
// };


// Logo display
static bool display_logo = true;
static bool display_timer_pressed = false;

// System timer
uint32_t time_reference = 0;

char * current_time(void) {
    char *str = malloc(9);
    uint32_t elapsed_seconds = timer_elapsed32(time_reference) / 1000;
    uint16_t hour = elapsed_seconds / 3600;
    uint8_t min = elapsed_seconds / 60 % 60;
    uint8_t sec = elapsed_seconds % 60;
    sprintf(str, "%4d:%02d:%02d", hour, min, sec);
    return str;
}

// Persistent config
typedef union {
  uint32_t raw;
  struct {
    bool     macos_mode :1;
    uint8_t  oled_brightness :3;
    bool     display_clock :1;
  };
} user_config_t;
static user_config_t user_config;



// Handle user EEPROM default value on reset
void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.macos_mode = true; // MacOS mode enabled by default
  user_config.oled_brightness = 3; // Default oled brightness
  user_config.display_clock = true; // Display timer

  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}

static void toggle_macos_mode(void) {
    user_config.macos_mode ^= 1; // Toggles the status
    keymap_config.swap_lalt_lgui = user_config.macos_mode;
}

// static bool is_mod_pressed(uint16_t keycode) {
//     return keyboard_report->mods & (MOD_BIT(keycode));
// }

// Uptime
// static uint32_t startup_time;
// startup_time = timer_read32();


// Keyboard init
void keyboard_post_init_user(void) {

    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
    keymap_config.swap_lalt_lgui = user_config.macos_mode;
#ifdef OLED_ENABLE
    oled_set_brightness(user_config.oled_brightness * 36);
#endif

    // Set time
    time_reference = timer_read32();
}


// Settings menu
static uint8_t settings_cursor = 0;
static bool settings_mode = false;
enum settings_list {
    SETTINGS_OS,
    SETTINGS_OLED_BRIGHTNESS,
    SETTINGS_DISPLAY_CLOCK,
    SETTINGS_RESET_TIMER,
    SETTINGS_SAVE,
    SETTINGS_COUNT
};

void settings_enter(void) {
    settings_mode = true;
    settings_cursor = 0;
}

void settings_exit(bool save) {
    settings_mode = false;
    if (save) {
        eeconfig_update_user(user_config.raw);
    }
}

int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

void process_settings(uint16_t keycode) {
    switch (keycode) {
        case KC_ESC:
            settings_exit(false);
            break;

        case KC_ENTER:
            switch (settings_cursor) {
                case SETTINGS_SAVE:
                    settings_exit(true);
                    break;
                case SETTINGS_RESET_TIMER:
                    time_reference = timer_read32();
                    break;
            }
            break;

        case KC_UP:
            if (settings_cursor > 0) {
                settings_cursor--;
            }
            break;

        case KC_DOWN:
            if (settings_cursor < SETTINGS_COUNT - 1) {
                settings_cursor++;
            }
            break;

        case KC_RGHT:
            switch (settings_cursor) {
                case SETTINGS_OS:
                    toggle_macos_mode();
                    break;
                case SETTINGS_OLED_BRIGHTNESS:
#ifdef OLED_ENABLE
                    if (user_config.oled_brightness < 7) {
                        user_config.oled_brightness += 1;
                    }
                    oled_set_brightness(user_config.oled_brightness * 36);
#endif
                    break;
                case SETTINGS_DISPLAY_CLOCK:
                    user_config.display_clock ^= 1;
                    break;
            }
            break;

        case KC_LEFT:
            switch (settings_cursor) {
                case SETTINGS_OS:
                    toggle_macos_mode();
                    break;
                case SETTINGS_OLED_BRIGHTNESS:
#ifdef OLED_ENABLE
                    if (user_config.oled_brightness > 0) {
                        user_config.oled_brightness -= 1;
                    }
                    oled_set_brightness(user_config.oled_brightness * 36);
#endif
                    break;
                case SETTINGS_DISPLAY_CLOCK:
                    user_config.display_clock ^= 1;
                    break;
            }
            break;

        default:
            settings_exit(false);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Display logo or hide when any other key is pressed
    switch (keycode) {
        case LOGO:
            if (record->event.pressed) {
                display_logo = true;
            }
            return false;

        case C_DISPLAY_TIMER:
            display_timer_pressed = record->event.pressed;
            return false;

        default:
            if (record->event.pressed) {
                display_logo = false;
            }
    }

    // Keyboard state keycodes
    switch (keycode) {
        case SETTINGS:
            if (record->event.pressed) {
                if (settings_mode) {
                    settings_exit(false);
                } else {
                    settings_enter();
                }
            }
            return false;
    }

    // Handle settings mode
    if (settings_mode && record->event.pressed) {
        process_settings(keycode);
        return false;
    }

#ifdef MACRO_STRINGS
    // Macros to type pre-defined strings
    switch (keycode) {
        case C_M1:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M1);
            }
            break;

        case C_M2:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M2);
            }
            break;

        case C_M3:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M3);
            }
            break;

        case C_M4:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M4);
            }
            break;

        case C_M5:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M5);
            }
            break;

        case C_M6:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M6);
            }
            break;

        case C_M7:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M7);
            }
            break;

        case C_M8:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M8);
            }
            break;

        case C_M9:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M8);
            }
            break;

        case C_M10:
            if (record->event.pressed) {
                SEND_STRING(MACRO_STRING_M8);
            }
            break;
    }
#endif
    return true;
};


// Rotary encoder
bool encoder_update_user(uint8_t index, bool clockwise) {
    bool button_pressed = false;
    if (index == 0) { /* First encoder */
        button_pressed = !MCP_digitalRead(MCP23_ROTARY_ENCODER_BUTTON + 1);

        // Settings mode
        if (settings_mode) {
            if (clockwise) {
                process_settings(KC_RIGHT);
            } else {
                process_settings(KC_LEFT);
            }
            return false;
        }

        switch(biton32(layer_state)){
            case _FN:
#ifdef OLED_ENABLE
                if (clockwise){
                    if (user_config.oled_brightness < 7) {
                        user_config.oled_brightness += 1;
                    }
                } else {
                    if (user_config.oled_brightness > 1) {
                        user_config.oled_brightness -= 1;
                    }
                }
                oled_set_brightness(user_config.oled_brightness * 36);
                break;
#else
                if (clockwise){
                    tap_code(KC_UP);
                } else{
                    tap_code(KC_DOWN);
                }
                break;
#endif
            case _CODE:
                if (button_pressed) {
                    if (clockwise) {
                        tap_code(KC_VOLU); /*volume up*/
                    } else {
                        tap_code(KC_VOLD); /*volume down*/
                    }
                } else {
                    if (clockwise){
                        tap_code16(LCTL(LSFT(KC_6)));
                    } else{
                        tap_code16(LCTL(KC_6));
                    }
                }
                break;
            case _MOD:
                if (clockwise){
                    tap_code(KC_MS_WH_UP);
                } else{
                    tap_code(KC_MS_WH_DOWN);
                }
                break;
            default:
                if (user_config.macos_mode && !button_pressed) {
                    if (clockwise) {
                        tap_code16(LSA(KC_VOLU)); /*volume up*/
                    } else {
                        tap_code16(LSA(KC_VOLD)); /*volume down*/
                    }
                } else {
                    if (clockwise) {
                        tap_code(KC_VOLU); /*volume up*/
                    } else {
                        tap_code(KC_VOLD); /*volume down*/
                    }
                }
                break;
        }
    }
    return false;
}

#ifdef OLED_ENABLE
static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void render_layer_label(uint8_t layer) {
    switch (layer) {
        case _MAIN:
            oled_write_P(PSTR("Main"), false);
            break;
        case _MOD:
            oled_write_P(PSTR("Mod"), false);
            break;
        case _TEXT:
            oled_write_P(PSTR("Text"), false);
            break;
        case _CODE:
            oled_write_P(PSTR("Code"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN"), false);
            break;
        case _OFF:
            oled_write_P(PSTR("Off"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_P(PSTR("Undef"), false);
    }
}

static void render_layer_state(void) {
    // Host Keyboard Layer Status
    bool first = true;
    uint8_t i;
    const uint8_t highest_layer = get_highest_layer(layer_state);
    for (i = 0; i <= highest_layer; ++i)
    {
        if (layer_state_is(i)) {
            if (first) {
                first = false;
            } else {
                oled_write_P(PSTR(" > "), false);
            }
            // oled_write_P(layer_labels[i], false);
            render_layer_label(i);
        }
    }
    oled_advance_page(true);
}

void render_status_bar(void) {
    uint8_t modifiers = get_mods();
    led_t led_state = host_keyboard_led_state();
    oled_write_P(PSTR("\325\326"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("\327\330"), (modifiers & MOD_MASK_CTRL));
    if (user_config.macos_mode) {
        oled_write_P(PSTR("\331\332"), (modifiers & MOD_MASK_ALT));
        oled_write_P(PSTR("\333\334"), (modifiers & MOD_MASK_GUI));
    } else {
        oled_write_P(PSTR("\335\336"), (modifiers & MOD_MASK_GUI));
        oled_write_P(PSTR("\331\332"), (modifiers & MOD_MASK_ALT));
    }
    oled_write_P(PSTR("         "), false);
    oled_write_P(PSTR("\235\236"), led_state.caps_lock);
    oled_write_P(PSTR("\275\276"), led_state.num_lock);
}

void render_settings(void) {
    char temp_str[21];
    uint8_t i;
    uint8_t scroll = 0;
    char* time = current_time();
    while (settings_cursor - scroll > 2) scroll++;
    while (settings_cursor - scroll < 1 && scroll > 0) scroll--;

    for (i = 0; i < 4; ++i)
    {
        if (i + scroll == settings_cursor) {
            oled_write_P(PSTR("> "), false);
        } else {
            oled_write_P(PSTR("  "), false);
        }
        switch (i + scroll) {
            case SETTINGS_OS:
                oled_write_P(PSTR("OS mode"), false);
                if (i + scroll == settings_cursor) {
                    oled_write_P(PSTR(": "), false);
                    if (user_config.macos_mode) {
                        oled_write_P(PSTR("MacOS"), false);
                    } else {
                        oled_write_P(PSTR("Normal"), false);
                    }
                }
                break;
            case SETTINGS_OLED_BRIGHTNESS:
                oled_write_P(PSTR("Brightness"), false);
                if (i + scroll == settings_cursor) {
                    oled_write_P(PSTR(": "), false);
                    sprintf(temp_str, "%d", user_config.oled_brightness + 1);
                    oled_write(temp_str, false);
                }
                break;
            case SETTINGS_DISPLAY_CLOCK:
                oled_write_P(PSTR("Display clock"), false);
                if (i + scroll == settings_cursor) {
                    oled_write_P(PSTR(": "), false);
                    if (user_config.display_clock) {
                        oled_write_P(PSTR("Yes"), false);
                    } else {
                        oled_write_P(PSTR("No"), false);
                    }
                }
                break;
            case SETTINGS_RESET_TIMER:
                oled_write_P(PSTR("Time: "), false);
                if (i + scroll == settings_cursor) {
                    oled_write_P(PSTR("Reset"), false);
                } else {
                    oled_write(time, false);
                }
                break;
            case SETTINGS_SAVE:
                oled_write_P(PSTR("Save to EEPROM"), false);
                break;
        }
        oled_advance_page(true);
    }
    free(time);
}

void render_time(void) {
    char* time = current_time();
    oled_write_P(PSTR("           "), false);
    oled_write(time, false);
    free(time);
}

void oled_horizontal_bar(void) {
    uint8_t i = 0;
    while (i++ < oled_max_chars()) {
        oled_write_P(PSTR("\237"), false);
    }
}

void oled_task_user(void) {
    if (settings_mode) {
        render_settings();
    } else if (display_logo) {
        render_logo();
        oled_advance_page(true);
    } else {
        render_status_bar();
        oled_horizontal_bar();
        if (display_timer_pressed || user_config.display_clock) {
            render_time();
        } else {
            oled_advance_page(true);
        }
        render_layer_state();
        // render_os_mode();
    }
}
#endif

// const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
//     keyevent_t event = record->event;

//     switch (id) {

//     }
//     return MACRO_NONE;
// }

// void matrix_init_user(void) {
// }

// void matrix_scan_user(void) {
// }

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     return true;
// }
