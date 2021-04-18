#ifndef CONFIG_H
#define CONFIG_H

#pragma once

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    OrthoPanda
#define PRODUCT         OrthoPanda
#define DESCRIPTION     Keyboard

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

/* key matrix pins */
// row0 -> row5
#define MATRIX_ROW_PINS { C6, D4, F4, D7, E6, B4, B5 }
#define MATRIX_COL_PINS {}
#define UNUSED_PINS

/* MCP23S17 GPIO pins */
#define    GPA0      (0)
#define    GPA1      (1)
#define    GPA2      (2)
#define    GPA3      (3)
#define    GPA4      (4)
#define    GPA5      (5)
#define    GPA6      (6)
#define    GPA7      (7)
#define    GPB0      (8)
#define    GPB1      (9)
#define    GPB2      (10)
#define    GPB3      (11)
#define    GPB4      (12)
#define    GPB5      (13)
#define    GPB6      (14)
#define    GPB7      (15)

/* pins MCP23S17 */
// GPA0_7: col14 -> col7
// GPB0_7: col0 -> col6 + rotary encoder button
#define MCP23_ROW_PINS {}
#define MCP23_COL_PINS { GPA0, GPA1, GPA2, GPA3, GPA4, GPA5, GPA6, GPB7, GPB6, GPB5, GPB4, GPB3, GPB2, GPB1, GPB0 }
#define MCP23_ROTARY_ENCODER_BUTTON GPA7

// Change SPI Slave Select pin
#ifdef SPI_SS_PIN
#undef SPI_SS_PIN
#endif
#define SPI_SS_PIN F5

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
#define PREVENT_STUCK_MODIFIERS


#endif
