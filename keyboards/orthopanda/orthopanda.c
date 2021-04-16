// The following functions are typically defined in this file::
//
// void matrix_init_kb(void)
// void matrix_scan_kb(void)
// bool process_record_kb(uint16_t keycode, keyrecord_t *record)
// void led_set_kb(uint8_t usb_led)



// Search for MCP23017 to find alternatives
//
// >>    keyboards/ergodox_ez/ergodox_ez.c
// >>    keyboards/ergodox_ez/matrix.c
// >>    https://docs.qmk.fm/#/custom_matrix
//


// See https://docs.qmk.fm/#/custom_quantum_functions
// keyboard_pre_init_kb
// matrix_init_kb
// keyboard_post_init_kb



// This runs very early during startup, even before the USB has been started.
// Shortly after this, the matrix is initialized.
// For most users, this shouldn’t be used, as it’s primarily for hardware oriented initialization.
// However, if you have hardware stuff that you need initialized, this is the best place for it (such as initializing LED pins).
void keyboard_pre_init_kb(void) {
    // Setup SPI management

    // FIXME example: Set our LED pins as output
    setPinOutput(B0);
    setPinOutput(B1);
    setPinOutput(B2);
    setPinOutput(B3);
    setPinOutput(B4);

    matrix_init_user();
};

// void matrix_init_kb(void) {
//     matrix_init_user();
// };

// void keyboard_post_init_kb(void) {
//     keyboard_post_init_user();
// };

void matrix_scan_kb(void) {
    // This is where we define the SPI behavior for reading pins
    matrix_scan_user();
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
