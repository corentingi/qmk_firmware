# MCU
MCU = atmega32u4
F_CPU = 16000000

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

## Features
CONSOLE_ENABLE = yes
ENCODER_ENABLE = no
LTO_ENABLE = no

# Features
CUSTOM_MATRIX = lite

# Sources
SRC += matrix.c
SRC += MCP23S17/MCP23S17.c
