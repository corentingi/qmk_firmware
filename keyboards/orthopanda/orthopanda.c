/* Copyright 2019 corentingi
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "orthopanda.h"

// This runs very early during startup, even before the USB has been started.
// Shortly after this, the matrix is initialized.
// For most users, this shouldn’t be used, as it’s primarily for hardware oriented initialization.
// However, if you have hardware stuff that you need initialized, this is the best place for it (such as initializing LED pins).
void keyboard_pre_init_kb(void) {
    // oled_clear();

    matrix_init_user();
};

void matrix_init_kb(void) {
    // put your keyboard start-up code here
    // runs once when the firmware starts up

    matrix_init_user();
}

void keyboard_post_init_kb(void) {
    // Customise these values to desired behaviour
    debug_enable=true;
    debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;
    keyboard_post_init_user();
}

void matrix_scan_kb(void) {
    // put your looping keyboard code here
    // runs every cycle (a lot)

    matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    // put your per-action keyboard code here
    // runs for every action, just before processing by the firmware

#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
    // put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

    led_set_user(usb_led);
}

// void suspend_power_down_kb(void) {
//     rgb_matrix_set_color_all(0, 0, 0);
//     rgb_matrix_set_suspend_state(true);
//     suspend_power_down_user();
// }

// void suspend_wakeup_init_kb(void) {
//     rgb_matrix_set_suspend_state(false);
//     suspend_wakeup_init_user();
// }
