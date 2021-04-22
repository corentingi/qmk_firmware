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

# Features
CUSTOM_MATRIX = lite
CONSOLE_ENABLE = no
ENCODER_ENABLE = no
LTO_ENABLE = no

# BOOTMAGIC_ENABLE ?= yes	# Virtual DIP switch configuration(+1000)
# MOUSEKEY_ENABLE ?= yes	# Mouse keys(+4700)
# EXTRAKEY_ENABLE ?= yes	# Audio control and System control(+450)
# CONSOLE_ENABLE ?= no	# Console for debug(+400)
# COMMAND_ENABLE ?= no    # Commands for debug and configuration
# SLEEP_LED_ENABLE ?= no  # Breathing sleep LED during USB suspend
# NKRO_ENABLE ?= yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# BACKLIGHT_ENABLE ?= no  # Enable keyboard backlight functionality
# AUDIO_ENABLE ?= no
# RGBLIGHT_ENABLE ?= no

# Sources
SRC += matrix.c
SRC += spi_master.c
SRC += MCP23S17/MCP23S17.c
