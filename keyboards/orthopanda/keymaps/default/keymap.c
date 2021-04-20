#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX,
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, XXXXXXX,
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

    LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_INS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_MAIL,
        KC_BSLS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_CAPS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_PGUP, KC_LSFT, KC_PGUP,
        XXXXXXX, KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  XXXXXXX, KC_LCTL, KC_HOME, KC_PGDN, KC_END,  KC_PGDN),

    LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

};

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


// void encoder_update_user(uint8_t index, bool clockwise) {
//   if (index == 0) { /* First encoder below the controller */
//     if (clockwise) {
//       tap_code(KC_VOLD); /*volume down*/
//     } else {
//       tap_code(KC_VOLU); /*volume up*/
//     }
//   } else if (index == 1) { /* Second encoder */
//     if (clockwise) {
//       tap_code(KC_WH_U); /*mouse wheel up*/
//     } else {
//       tap_code(KC_WH_D); /*mouse wheel down*/
//     }
//   }
// }


// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     [0] = LAYOUT(
//                  KC_P7,   KC_P8,   KC_P9, KC_PMNS,
//                  KC_P4,   KC_P5,   KC_P6, KC_PPLS,
//         KC_MUTE, KC_P1,   KC_P2,   KC_P3, KC_TAB,
//         KC_ESC,  KC_DEL, KC_P0, KC_PDOT, KC_PENT
//     )
// };
