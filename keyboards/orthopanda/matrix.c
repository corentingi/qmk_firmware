/*
    Replace the matrix scanning mechanisms to use MCP23S17 chip
    See https://docs.qmk.fm/#/custom_matrix

    Original matrix_scan: quantum/matrix.c:210

*/

// TODO: Support DIRECT_PINS/ROW2COL/COL2ROW macros

#include <stdint.h>
#include <stdbool.h>
#include <spi_master.h>
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

// FIXME: DEBUG
#include "print.h"

// Custom MCP23S17 support
#include "MCP23S17/MCP23S17.h"

#ifdef DIRECT_PINS
static pin_t direct_pins[MATRIX_ROWS][MATRIX_COLS] = DIRECT_PINS;
#elif (DIODE_DIRECTION == ROW2COL) || (DIODE_DIRECTION == COL2ROW)
static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const uint8_t mcp_col_pins[MATRIX_COLS] = MCP23_COL_PINS;
#endif

static inline void setPinOutput_writeLow(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

static inline void setPinInputHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON { setPinInputHigh(pin); }
}

static inline uint8_t MCP_readPin(uint8_t mcp_pin) {
    return MCP_digitalRead(mcp_pin + 1);
}

static inline void MCP_setPinInputHigh_atomic(uint8_t mcp_pin) {
    bool status;
    status = MCP_pinMode(mcp_pin + 1, 1);
    dprintf("[debug] pinMode: %d ", status);

    status = MCP_pullupMode(mcp_pin + 1, 1);
    dprintf("[debug] pullupMode: %d\n", status);
}


// matrix code
#ifdef DIRECT_PINS
#    error DIRECT_PINS is not implemented!
#elif defined(DIODE_DIRECTION)
#    if (DIODE_DIRECTION == COL2ROW)

static void select_row(uint8_t row) { setPinOutput_writeLow(row_pins[row]); }

static void unselect_row(uint8_t row) { setPinInputHigh_atomic(row_pins[row]); }

static void unselect_rows(void) {
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh_atomic(row_pins[x]);
    }
}

static void init_pins(void) {
    // bool status;
    unselect_rows();
    for (uint8_t x = 0; x < MATRIX_COLS; x++) {
        MCP_setPinInputHigh_atomic(mcp_col_pins[x]);
    }
    // status = MCP_pinModeAll(0xFF);
    // dprintf("[debug] pinMode: %d ", status);

    // status = MCP_pullupModeAll(0xFF);
    // dprintf("[debug] pullupMode: %d\n", status);
}

static bool read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    // Select row
    select_row(current_row);
    matrix_output_select_delay();

    // For each col...
    // uint16_t col_pin_states = MCP_digitalReadAll();
    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        // Select the col pin to read (active low)
        uint8_t pin_state = MCP_readPin(mcp_col_pins[col_index]);
        // uint8_t pin_state = col_pin_states & (1 << (mcp_col_pins[col_index] - 1)) ? 1 : 0;

        // Populate the matrix row with the state of the col pin
        current_row_value |= pin_state ? 0 : (MATRIX_ROW_SHIFTER << col_index);
    }

    // Unselect row
    unselect_row(current_row);
    if (current_row + 1 < MATRIX_ROWS) {
        matrix_output_unselect_delay();  // wait for row signal to go HIGH
    }

    // If the row has changed, store the row and return the changed flag.
    if (current_matrix[current_row] != current_row_value) {
        current_matrix[current_row] = current_row_value;
        return true;
    }
    return false;
}

#    elif (DIODE_DIRECTION == ROW2COL)
#        error DIODE_DIRECTION == ROW2COL is not implemented!
#    else
#        error DIODE_DIRECTION must be one of COL2ROW or ROW2COL!
#    endif
#else
#    error DIODE_DIRECTION is not defined!
#endif


void matrix_init_custom(void) {
    bool status;

    debug_enable=true;
    debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;

    // Wait a bit to allow print to console
    wait_ms(100);

    MCP_init(0, MCP_SS_PIN);
    status = MCP_begin();
    if (status) {
        dprint("Communicating with MCP23S17.\n");
    } else {
        dprint("Could not communicate with MCP23S17.\n");
    }

    // initialize key pins
    init_pins();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool matrix_has_changed = false;

#if defined(DIRECT_PINS) || (DIODE_DIRECTION == COL2ROW)
    // Set row, read cols
    for (uint8_t current_row = 0; current_row < MATRIX_ROWS; current_row++) {
        matrix_has_changed |= read_cols_on_row(current_matrix, current_row);
    }
#endif

    return matrix_has_changed;
}
