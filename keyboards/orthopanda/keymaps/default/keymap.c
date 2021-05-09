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

enum layer_names {
  _MAIN,
  _TEXT,
  _CODE,
  _MOD,
  _NUM,
  _FN,
  _OFF,
};

enum custom_keycodes {
    LOGO = SAFE_RANGE,
    DF_MAC,
    SETTINGS,
    C_M1,
    C_M2,
    C_M3,
    C_M4,
    C_M5,
    C_M6,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MAIN] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_SLSH,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_LSFT, KC_CAPS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_BSLS, KC_LSFT, KC_PGUP,
        MO(_FN), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_RCTL, KC_PGDN),

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

    [_MOD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_SLSH, KC_END,  KC_LSFT, KC_PGUP,
        MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGHT, KC_PGDN),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_PSLS, KC_PAST, KC_PMNS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PCMM,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PEQL,
        MO(_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PENT),

    [_FN] = LAYOUT(
        TG(_MOD),TG(_NUM), TG(_TEXT), TG(_CODE), XXXXXXX, DF_MAC, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, SETTINGS, KC_PSCR,
        XXXXXXX, C_M1,    C_M2,    C_M3,    C_M4,    C_M5,    KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, C_M6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_NUBS, KC_NUBS, S(KC_NUBS), XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOGO,    KC_VOLD, XXXXXXX, XXXXXXX, KC_MPRV, KC_HOME, KC_UP,   KC_END,  KC_LSFT, KC_PGUP,
        MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, KC_MPLY, KC_MPLY, KC_MUTE, KC_MSTP, KC_MSTP, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGHT, KC_PGDN),

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

static bool display_logo = true;
static bool settings_mode = false;
enum settings_list {
    SETTINGS_OS,
    SETTINGS_OLED_BRIGHTNESS,
    SETTINGS_SAVE,
    SETTINGS_COUNT
};


// Persistent config
typedef union {
  uint32_t raw;
  struct {
    bool     macos_mode :1;
  };
} user_config_t;
static user_config_t user_config;

// Settings menu
static uint8_t settings_cursor = 0;

// Handle user EEPROM default value on reset
void eeconfig_init_user(void) {
  user_config.raw = 0;
  user_config.macos_mode = true; // MacOS mode enabled by default
  eeconfig_update_user(user_config.raw); // Write default value to EEPROM now
}

static void toggle_macos_mode(void) {
    user_config.macos_mode ^= 1; // Toggles the status
    // eeconfig_update_user(user_config.raw); // Writes the new status to EEPROM
    keymap_config.swap_lalt_lgui = user_config.macos_mode;
}

static bool is_mod_pressed(uint16_t keycode) {
    return keyboard_report->mods & (MOD_BIT(keycode));
}

// Uptime
// static uint32_t startup_time;
void keyboard_post_init_user(void) {
    // startup_time = timer_read32();

    // Read the user config from EEPROM
    user_config.raw = eeconfig_read_user();
    keymap_config.swap_lalt_lgui = user_config.macos_mode;
}

// Custom keycodes
void process_settings(uint16_t keycode) {
    uint8_t temp_setting = 0;
    switch (keycode) {
        case KC_ESC:
        case KC_ENTER:
            if (settings_cursor == SETTINGS_SAVE) {
                eeconfig_update_user(user_config.raw);
            }
            settings_mode = false;
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
#ifdef OLED_DRIVER_ENABLE
                    temp_setting = oled_get_brightness();
                    if (temp_setting < 239) {
                        temp_setting += 16;
                    } else {
                        temp_setting = 255;
                    }
                    oled_set_brightness(temp_setting);
#endif
                    break;
            }
            break;

        case KC_LEFT:
            switch (settings_cursor) {
                case SETTINGS_OS:
                    toggle_macos_mode();
                    break;
                case SETTINGS_OLED_BRIGHTNESS:
#ifdef OLED_DRIVER_ENABLE
                    temp_setting = oled_get_brightness();
                    if (temp_setting > 15) {
                        temp_setting -= 16;
                    } else {
                        temp_setting = 0;
                    }
                    oled_set_brightness(temp_setting);
#endif
                    break;
            }
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

        default:
            if (record->event.pressed) {
                display_logo = false;
            }
    }

    // Keyboard state keycodes
    switch (keycode) {
        case DF_MAC:
            if (record->event.pressed) {
                toggle_macos_mode();
            }
            return false;

        case SETTINGS:
            if (record->event.pressed) {
                settings_mode ^= 1;
                if (settings_mode) {
                    settings_cursor = 0;
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
    }
#endif
    return true;
};


// Rotary encoder
void encoder_update_user(uint8_t index, bool clockwise) {
#ifdef OLED_DRIVER_ENABLE
    uint8_t oled_brightness = oled_get_brightness();
#endif
    if (index == 0) { /* First encoder */
        // Settings mode
        if (settings_mode) {
            if (clockwise) {
                process_settings(KC_RIGHT);
            } else {
                process_settings(KC_LEFT);
            }
            return;
        }

        switch(biton32(layer_state)){
            case _FN:
#ifdef OLED_DRIVER_ENABLE
                if (clockwise){
                    if (oled_brightness < 239) {
                        oled_brightness += 16;
                    } else {
                        oled_brightness = 255;
                    }
                } else {
                    if (oled_brightness > 15) {
                        oled_brightness -= 16;
                    } else {
                        oled_brightness = 0;
                    }
                }
                oled_set_brightness(oled_brightness);
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
                if (clockwise){
                    tap_code16(LCTL(LSFT(KC_6)));
                } else{
                    tap_code16(LCTL(KC_6));
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
                if (user_config.macos_mode && !is_mod_pressed(KC_LSFT)) {
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
}

#ifdef OLED_DRIVER_ENABLE
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
        case _TEXT:
            oled_write_P(PSTR("Text"), false);
            break;
        case _CODE:
            oled_write_P(PSTR("Code"), false);
            break;
        case _MOD:
            oled_write_P(PSTR("Mod"), false);
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
    while (settings_cursor - scroll < 0 && scroll > 0) scroll--;
    while (settings_cursor - scroll > 4) scroll++;

    for (i = 0; i < 4; ++i)
    {
        if (i - scroll == settings_cursor) {
            oled_write_P(PSTR("> "), false);
        } else {
            oled_write_P(PSTR("  "), false);
        }
        switch (i - scroll) {
            case SETTINGS_OS:
                oled_write_P(PSTR("OS mode"), false);
                if (i - scroll == settings_cursor) {
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
                if (i - scroll == settings_cursor) {
                    oled_write_P(PSTR(": "), false);
                    sprintf(temp_str, "%d", oled_get_brightness() / 16 + 1);
                    oled_write(temp_str, false);
                }
                break;
            case SETTINGS_SAVE:
                oled_write_P(PSTR("Save to EEPROM"), false);
                break;
        }
        oled_advance_page(true);
    }
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
        return;
    } else if (display_logo) {
        render_logo();
        // oled_write_P(PSTR("\n"), false);
        // oled_scroll_left();
        return;
    } else {
        render_status_bar();
        oled_horizontal_bar();
        oled_advance_page(true);
        render_layer_state();
        // render_os_mode();
        return;
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

// void led_set_user(uint8_t usb_led) {

//     if (usb_led & (1 << USB_LED_NUM_LOCK)) {
//         // USB_LED_NUM_LOCK ON
//     } else {
//         // USB_LED_NUM_LOCK OFF
//     }

//     if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
//         // USB_LED_CAPS_LOCK ON
//     } else {
//         // USB_LED_CAPS_LOCK OFF
//     }

//     if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
//         // USB_LED_SCROLL_LOCK ON
//     } else {
//         // USB_LED_SCROLL_LOCK OFF
//     }

//     if (usb_led & (1 << USB_LED_COMPOSE)) {
//         // USB_LED_COMPOSE ON
//     } else {
//         // USB_LED_COMPOSE OFF
//     }

//     if (usb_led & (1 << USB_LED_KANA)) {
//         // USB_LED_KANA ON
//     } else {
//         // USB_LED_KANA OFF
//     }

// }
