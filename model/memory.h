//
// Created by Silas Ruffner on 30.01.24.
//

#ifndef WS_EMULATOR_MEMORY_H
#define WS_EMULATOR_MEMORY_H

#include <bitset>

/**
 * represents the data in memory of the 6502
 */
class MemoryModel {
    MemoryModel();

    /**
     * Writes the specified `value` to memory address `address`
     * @param value the value to be written.
     * @param address the address
     * @throws std::out_of_range if address >= 2^16
     * @return true on success, false otherwise
     */
    bool write_byte(std::bitset<8> value, int address);

    /**
     * Reads a byte from the specified `address`
     * @param address the address to read from
     * @throws std::out_of_range if address >= 2^16
     * @return the read byte
     */
    std::bitset<8> read_byte(int address);

private:
    std::bitset<8> memory[1 << 16];

};


#endif //WS_EMULATOR_MEMORY_H
