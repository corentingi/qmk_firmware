/*
    Inspired from: https://github.com/n0mjs710/MCP23S17/blob/master/MCP23S17/MCP23S17.cpp

*/

#include <spi_master.h>

#include "MCP23S17.h"            // Header files for this class

// Defines to keep logical information symbolic go here
#ifndef HIGH
#define    HIGH          (1)
#endif

#ifndef LOW
#define    LOW           (0)
#endif

#ifndef ON
#define    ON            (1)
#endif

#ifndef OFF
#define    OFF           (0)
#endif

// Here we have things for the SPI bus configuration

#define    CLOCK_DIVIDER (2)           // SPI bus speed to be 1/2 of the processor clock speed - 8MHz on most Arduinos

// Control byte and configuration register information - Control Byte: "0100 A2 A1 A0 R/W" -- W=0

#define    OPCODEW       (0b01000000)  // Opcode for MCP23S17 with LSB (bit0) set to write (0), address OR'd in later, bits 1-3
#define    OPCODER       (0b01000001)  // Opcode for MCP23S17 with LSB (bit0) set to read (1), address OR'd in later, bits 1-3
#define    ADDR_ENABLE   (0b00001000)  // Configuration register for MCP23S17, the only thing we change is enabling hardware addressing



// Temp arduino shorthands
#ifndef constrain
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#endif


static uint8_t address     = constrain(address, 0, 7);
static pin_t ss            = SPI_SS_PIN;
static uint8_t modeCache   = 0xFFFF;                // Default I/O mode is all input, 0xFFFF
static uint8_t outputCache = 0x0000;                // Default output state is all off, 0x0000
static uint8_t pullupCache = 0x0000;                // Default pull-up state is all off, 0x0000
static uint8_t invertCache = 0x0000;                // Default input inversion state is not inverted, 0x0000



