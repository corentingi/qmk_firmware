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

#ifndef INPUT
#define    INPUT            (1)
#endif

#ifndef OUTPUT
#define    OUTPUT           (0)
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


// Local variables to store register states
static uint8_t MCP_address = 0;
static pin_t MCP_slaveSelectPin = SPI_SS_PIN;
static unsigned int MCP_modeCache = 0xFFFF;         // Default I/O mode is all input, 0xFFFF
static unsigned int MCP_pullupCache = 0x0000;       // Default output state is all off, 0x0000
static unsigned int MCP_invertCache = 0x0000;       // Default pull-up state is all off, 0x0000
static unsigned int MCP_outputCache = 0x0000;       // Default input inversion state is not inverted, 0x0000

// Init MCP to a specific chip (address)
void MCP_init(uint8_t address, pin_t ss) {
    MCP_address = constrain(address, 0, 7);
    MCP_slaveSelectPin = ss;
    MCP_modeCache   = 0xFFFF;                // Default I/O mode is all input, 0xFFFF
    MCP_outputCache = 0x0000;                // Default output state is all off, 0x0000
    MCP_pullupCache = 0x0000;                // Default pull-up state is all off, 0x0000
    MCP_invertCache = 0x0000;                // Default input inversion state is not inverted, 0x0000
    spi_init();
}


void MCP_begin() {
    setPinOutput(MCP_slaveSelectPin);               // Set SlaveSelect pin as an output
    writePinHigh(MCP_slaveSelectPin);             // Set SlaveSelect HIGH (chip de-selected)
    spi_start(MCP_slaveSelectPin, false, 0, CLOCK_DIVIDER); // Start up the SPI bus (MSB first, SPI mode 0)
    MCP_byteWrite(IOCON, ADDR_ENABLE);
}

// GENERIC BYTE WRITE - will write a byte to a register, arguments are register address and the value to write

void MCP_byteWrite(uint8_t reg, uint8_t value) {      // Accept the register and byte
    writePinLow(MCP_slaveSelectPin);                  // Take slave-select low
    spi_write(OPCODEW | (MCP_address << 1));          // Send the MCP23S17 opcode, chip address, and write bit
    spi_write(reg);                                   // Send the register we want to write
    spi_write(value);                                 // Send the byte
    writePinHigh(MCP_slaveSelectPin);                 // Take slave-select high
}

// GENERIC WORD WRITE - will write a word to a register pair, LSB to first register, MSB to next higher value register

void MCP_wordWrite(uint8_t reg, unsigned int word) {  // Accept the start register and word
    writePinLow(MCP_slaveSelectPin);                  // Take slave-select low
    spi_write(OPCODEW | (MCP_address << 1));          // Send the MCP23S17 opcode, chip address, and write bit
    spi_write(reg);                                   // Send the register we want to write
    spi_write((uint8_t) (word));                      // Send the low byte (register address pointer will auto-increment after write)
    spi_write((uint8_t) (word >> 8));                 // Shift the high byte down to the low byte location and send
    writePinHigh(MCP_slaveSelectPin);                 // Take slave-select high
}

// MODE SETTING FUNCTIONS - BY PIN AND BY WORD

void MCP_pinMode(uint8_t pin, uint8_t mode) {     // Accept the pin # and I/O mode
    if ((pin < 1) | (pin > 16)) return;               // If the pin value is not valid (1-16) return, do nothing and return
    if (mode == INPUT) {                          // Determine the mode before changing the bit state in the mode cache
        MCP_modeCache |= 1 << (pin - 1);          // Since input = "HIGH", OR in a 1 in the appropriate place
    } else {
        MCP_modeCache &= ~(1 << (pin - 1));       // If not, the mode must be output, so and in a 0 in the appropriate place
    }
    MCP_wordWrite(IODIRA, MCP_modeCache);         // Call the generic word writer with start register and the mode cache
}

void MCP_pinModeAll(unsigned int mode) {             // Accept the word…
    MCP_wordWrite(IODIRA, mode);                  // Call the the generic word writer with start register and the mode cache
    MCP_modeCache = mode;
}

// THE FOLLOWING WRITE FUNCTIONS ARE NEARLY IDENTICAL TO THE FIRST AND ARE NOT INDIVIDUALLY COMMENTED

// WEAK PULL-UP SETTING FUNCTIONS - BY WORD AND BY PIN

void MCP_pullupMode(uint8_t pin, uint8_t mode) {
    if ((pin < 1) | (pin > 16)) return;
    if (mode == ON) {
        MCP_pullupCache |= 1 << (pin - 1);
    } else {
        MCP_pullupCache &= ~(1 << (pin -1));
    }
    MCP_wordWrite(GPPUA, MCP_pullupCache);
}


void MCP_pullupModeAll(unsigned int mode) {
    MCP_wordWrite(GPPUA, mode);
    MCP_pullupCache = mode;
}


// INPUT INVERSION SETTING FUNCTIONS - BY WORD AND BY PIN

void MCP_inputInvert(uint8_t pin, uint8_t mode) {
    if ((pin < 1) | (pin > 16)) return;
    if (mode == ON) {
        MCP_invertCache |= 1 << (pin - 1);
    } else {
        MCP_invertCache &= ~(1 << (pin - 1));
    }
    MCP_wordWrite(IPOLA, MCP_invertCache);
}

void MCP_inputInvertAll(unsigned int mode) {
    MCP_wordWrite(IPOLA, mode);
    MCP_invertCache = mode;
}


// WRITE FUNCTIONS - BY WORD AND BY PIN

void MCP_digitalWrite(uint8_t pin, uint8_t value) {
    if ((pin < 1) | (pin > 16)) return;
    if (value) {
        MCP_outputCache |= 1 << (pin - 1);
    } else {
        MCP_outputCache &= ~(1 << (pin - 1));
    }
    MCP_wordWrite(GPIOA, MCP_outputCache);
}

void MCP_digitalWriteAll(unsigned int value) {
    MCP_wordWrite(GPIOA, value);
    MCP_outputCache = value;
}


// READ FUNCTIONS - BY BYTE, BYTE AND BY PIN
uint8_t MCP_byteRead(uint8_t reg) {              // This function will read a single register, and return it
    uint8_t value = 0;                           // Initialize a variable to hold the read values to be returned
    writePinLow(MCP_slaveSelectPin);             // Take slave-select low
    spi_write(OPCODER | (MCP_address << 1));     // Send the MCP23S17 opcode, chip address, and read bit
    spi_write(reg);                              // Send the register we want to read
    value = spi_read();                          // Send any byte, the function will return the read value
    writePinHigh(MCP_slaveSelectPin);            // Take slave-select high
    return value;                                // Return the constructed word, the format is 0x(register value)
}

unsigned int MCP_digitalReadAll(void) {             // This function will read all 16 bits of I/O, and return them as a word in the format 0x(portB)(portA)
    unsigned int value = 0;                      // Initialize a variable to hold the read values to be returned
    writePinLow(MCP_slaveSelectPin);   // Take slave-select low
    spi_write(OPCODER | (MCP_address << 1));     // Send the MCP23S17 opcode, chip address, and read bit
    spi_write(GPIOA);                            // Send the register we want to read
    value = spi_read();                          // Send any byte, the function will return the read value (register address pointer will auto-increment after write)
    value |= (spi_read() << 8);                  // Read in the "high byte" (portB) and shift it up to the high location and merge with the "low byte"
    writePinHigh(MCP_slaveSelectPin);  // Take slave-select high
    return value;                                // Return the constructed word, the format is 0x(portB)(portA)
}

uint8_t MCP_digitalRead(uint8_t pin) {                            // Return a single bit value, supply the necessary bit (1-16)
    if ((pin < 1) | (pin > 16)) return 0x0;                           // If the pin value is not valid (1-16) return, do nothing and return
    return MCP_digitalReadAll() & (1 << (pin - 1)) ? HIGH : LOW;  // Call the word reading function, extract HIGH/LOW information from the requested pin
}

void MCP_end() {
    spi_stop(); // Start up the SPI bus (MSB first, SPI mode 0)
}
