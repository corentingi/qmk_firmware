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

// Use Azerty layout for typing
#include "sendstring_french.h"

// Custom sendstring macros
#if __has_include("sendstring_macros.h")
#  include "sendstring_macros.h"
#endif

enum layer_names {
  _BASE,
  _MACOS,
  _MOD,
  _FN,
  _NUM,
  _OFF,
};

enum custom_keycodes {
    LOGO = SAFE_RANGE,
    DF_MAC,
    C_M1,
    C_M2,
    C_M3,
    C_M4,
    C_M5,
    C_M6,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Base
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_SLSH,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_LSFT, KC_CAPS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_BSLS, KC_LSFT, KC_PGUP,
        MO(_FN), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT, KC_RCTL, KC_PGDN),

    // MacOS (Work)
    [_MACOS] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

    [_MOD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_NUBS, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_SLSH, KC_END,  KC_LSFT, KC_PGUP,
        MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGHT, KC_PGDN),

    [_FN] = LAYOUT(
        TG(_MOD), TG(_MACOS), TG(_NUM), XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
        XXXXXXX, C_M1,    C_M2,    C_M3,    C_M4,    C_M5,    KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, C_M6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOGO,    KC_VOLD, XXXXXXX, XXXXXXX, KC_MPRV, KC_HOME, KC_UP,   KC_END,  KC_LSFT, KC_PGUP,
        MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, KC_MPLY, KC_MPLY, KC_MUTE, KC_MSTP, KC_MSTP, KC_MNXT, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGHT, KC_PGDN),

    [_NUM] = LAYOUT(
        TG(_NUM), XXXXXXX, TG(_NUM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_NUM),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_PSLS, KC_PAST, KC_PMNS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PCMM,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PEQL,
        MO(_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PENT),

    [_OFF] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        MO(_FN), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    // EXAMPLE
    // [_BASE] = LAYOUT(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

};

static bool display_logo = true;

static bool is_mod_pressed(uint16_t keycode) {
    return keyboard_report->mods & (MOD_BIT(keycode));
}

// Uptime
// static uint32_t startup_time;
void keyboard_post_init_user(void) {
    // startup_time = timer_read32();
    layer_on(_MACOS);
}

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (layer_state_is(_MACOS)) {
    //     // Set MacOS behavior
    // }

    switch (keycode) {
        case LOGO:
            if (record->event.pressed) {
                display_logo = true;
            }
            return true;

        default:
            if (record->event.pressed) {
                display_logo = false;
            }
    }

#ifdef MACRO_STRINGS
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
            case _MOD:
                if (clockwise){
                    tap_code(KC_MS_WH_UP);
                } else{
                    tap_code(KC_MS_WH_DOWN);
                }
                break;
            default:
                if (layer_state_is(_MACOS) && !is_mod_pressed(KC_LSFT)) {
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

static void render_status(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("> "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _MACOS:
            oled_write_P(PSTR("Mac\n"), false);
            break;
        case _MOD:
            oled_write_P(PSTR("Mod\n"), false);
            break;
        case _FN:
            oled_write_P(PSTR("FN\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Num\n"), false);
            break;
        case _OFF:
            oled_write_P(PSTR("Off\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undef"), false);
    }

    // Empty line
    oled_write_ln_P(PSTR(""), false);
    oled_write_ln_P(PSTR(""), false);

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    if (led_state.num_lock) {
        oled_write_P(PSTR("NUM "), false);
    }
    if (led_state.caps_lock) {
        if (led_state.num_lock) {
            oled_write_P(PSTR(" | "), false);
        }
        oled_write_P(PSTR("CAP "), false);
    }
    if (led_state.scroll_lock) {
        if (led_state.num_lock || led_state.caps_lock) {
            oled_write_P(PSTR(" | "), false);
        }
        oled_write_P(PSTR("SCR "), false);
    }
    oled_write_ln_P(PSTR(""), false);

    // if (layer_state_is(_MACOS)) {
    //     oled_set_cursor(oled_max_chars() - 3, 0);
    //     oled_write_P(PSTR("\x94"), false);
    //     oled_write_P(PSTR("\x95"), false);
    //     oled_set_cursor(oled_max_chars() - 3, 1);
    //     oled_write_P(PSTR("\xB4"), false);
    //     oled_write_P(PSTR("\xB5"), false);
    // }
}

void oled_task_user(void) {
    if (display_logo) {
        render_logo();
        // oled_write_P(PSTR("\n"), false);
        // oled_scroll_left();
        return;
    } else {
        render_status();
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
