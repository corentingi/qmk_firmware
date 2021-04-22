#ifndef MCP23S17_h
#define MCP23S17_h

#define    IODIRA    (0x00)      // MCP23x17 I/O Direction Register
#define    IODIRB    (0x01)      // 1 = Input (default), 0 = Output

#define    IPOLA     (0x02)      // MCP23x17 Input Polarity Register
#define    IPOLB     (0x03)      // 0 = Normal (default)(low reads as 0), 1 = Inverted (low reads as 1)

#define    GPINTENA  (0x04)      // MCP23x17 Interrupt on Change Pin Assignements
#define    GPINTENB  (0x05)      // 0 = No Interrupt on Change (default), 1 = Interrupt on Change

#define    DEFVALA   (0x06)      // MCP23x17 Default Compare Register for Interrupt on Change
#define    DEFVALB   (0x07)      // Opposite of what is here will trigger an interrupt (default = 0)

#define    INTCONA   (0x08)      // MCP23x17 Interrupt on Change Control Register
#define    INTCONB   (0x09)      // 1 = pin is compared to DEFVAL, 0 = pin is compared to previous state (default)

#define    IOCON     (0x0A)      // MCP23x17 Configuration Register
//                   (0x0B)      //     Also Configuration Register

#define    GPPUA     (0x0C)      // MCP23x17 Weak Pull-Up Resistor Register
#define    GPPUB     (0x0D)      // INPUT ONLY: 0 = No Internal 100k Pull-Up (default) 1 = Internal 100k Pull-Up

#define    INTFA     (0x0E)      // MCP23x17 Interrupt Flag Register
#define    INTFB     (0x0F)      // READ ONLY: 1 = This Pin Triggered the Interrupt

#define    INTCAPA   (0x10)      // MCP23x17 Interrupt Captured Value for Port Register
#define    INTCAPB   (0x11)      // READ ONLY: State of the Pin at the Time the Interrupt Occurred

#define    GPIOA     (0x12)      // MCP23x17 GPIO Port Register
#define    GPIOB     (0x13)      // Value on the Port - Writing Sets Bits in the Output Latch

#define    OLATA     (0x14)      // MCP23x17 Output Latch Register
#define    OLATB     (0x15)      // 1 = Latch High, 0 = Latch Low (default) Reading Returns Latch State, Not Port Value!


// Variables
// extern uint8_t MCP_address;                        // Address of the MCP23S17 in use
// extern pin_t MCP_slaveSelectPin;                   // Slave-select pin
// extern uint16_t MCP_modeCache;                 // Caches the mode (input/output) configuration of I/O pins
// extern uint16_t MCP_pullupCache;               // Caches the internal pull-up configuration of input pins (values persist across mode changes)
// extern uint16_t MCP_invertCache;               // Caches the input pin inversion selection (values persist across mode changes)
// extern uint16_t MCP_outputCache;               // Caches the output pin state of pins

// Functions
void MCP_init(uint8_t address, pin_t ss);            // Constructor to instantiate a discrete IC as an object, address 0-7, chipSelect any valid pin
bool MCP_begin(void);                                // Start the SPI Bus
bool MCP_wordWrite(uint8_t reg, uint16_t word);  // Typically only used internally, but allows the user to write any register pair if needed, so it's public
bool MCP_byteWrite(uint8_t reg, uint8_t value);      // Typically only used internally, but allows the user to write any register if needed, so it's public
bool MCP_pinMode(uint8_t pin, uint8_t mode);         // Sets the mode (input or output) of a single I/O pin
bool MCP_pinModeAll(uint16_t mode);              // Sets the mode (input or output) of all I/O pins at once
bool MCP_pullupMode(uint8_t pin, uint8_t mode);      // Selects internal 100k input pull-up of a single I/O pin
bool MCP_pullupModeAll(uint16_t mode);           // Selects internal 100k input pull-up of all I/O pins at once
bool MCP_inputInvert(uint8_t pin, uint8_t mode);     // Selects input state inversion of a single I/O pin (writing 1 turns on inversion)
bool MCP_inputInvertAll(uint16_t mode);          // Selects input state inversion of all I/O pins at once (writing a 1 turns on inversion)
bool MCP_digitalWrite(uint8_t pin, uint8_t value);   // Sets an individual output pin HIGH or LOW
bool MCP_digitalWriteAll(uint16_t value);        // Sets all output pins at once. If some pins are configured as input, those bits will be ignored on write
uint8_t MCP_byteRead(uint8_t reg);                   // Reads an individual register and returns the byte. Argument is the register address
uint8_t MCP_digitalRead(uint8_t pin);                // Reads an individual input pin
uint16_t MCP_digitalReadAll(void);               // Reads all input  pins at once. Be sure it ignore the value of pins configured as output!

#endif // MCP23S17
