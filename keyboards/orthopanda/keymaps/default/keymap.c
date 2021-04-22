#include QMK_KEYBOARD_H

enum layer_names {
  _BASE,
  _FN,
  _NUM,
  _NAV,
  _OFF,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // PC
    // [_BASE] = LAYOUT(
    //     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(_NUM),
    //     KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PSCR,
    //     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_HOME,
    //     KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_END,
    //     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_LSFT, KC_PGUP,
    //     MO(_FN), KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN),

    // MacOS
    [_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_DEL,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  TG(_NUM),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_BSPC, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_PSCR,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_HOME,
        KC_NUBS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_ENT,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS, KC_END,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_LSFT, KC_PGUP,
        MO(_FN), KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_SPC,  KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN),

    [_FN] = LAYOUT(
        TG(_OFF), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, KC_MPRV, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX,
        MO(_FN), XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MPLY, KC_MUTE, KC_MSTP, KC_MSTP, KC_MNXT, XXXXXXX, KC_HOME, KC_PGDN, KC_END,  XXXXXXX),

    [_NUM] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_NUM),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB,  KC_PSLS, KC_PAST, KC_PMNS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P4,   KC_P5,   KC_P6,   KC_PCMM,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PEQL,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_P0,   KC_P0,   KC_PDOT, KC_PENT),

    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),

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
