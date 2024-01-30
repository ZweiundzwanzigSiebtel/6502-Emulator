//
// Created by Silas Ruffner on 30.01.24.
//

#include "memory.h"

MemoryModel::MemoryModel() {

}

bool MemoryModel::write_byte(std::bitset<8> value, int address) {
    if(address >= (1 << 16)) {
        throw std::out_of_range("Address out of range");
    }
    this->memory[address] = value;
}

std::bitset<8> MemoryModel::read_byte(int address) {
    if(address >= (1 << 16)) {
        throw std::out_of_range("Address out of range");
    }
    return this->memory[address];
}