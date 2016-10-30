#pragma once

#include <cinttypes>

typedef struct registers {
  uint8_t acc;  // Holds one of the operands and generally the result.
  uint8_t x, y; // Used mainly for forming effective addresses and loop counters.
  uint8_t p;    // Conditional register containing flags, conditions modes, etc.
  uint8_t sp;   // Stack pointer.
  uint16_t pc;  // Program counter.
} registers;

namespace Registers {

const uint8_t CARRY_FLAG      = 0x01;
const uint8_t ZERO_FLAG       = 0x02;
const uint8_t IRQ_FLAG        = 0x04;
const uint8_t BRK_FLAG        = 0x08;
const uint8_t DECIMAL_FLAG    = 0x10;
const uint8_t OVERFLOW_FLAG   = 0x40;
const uint8_t NEGATIVE_FLAG   = 0x80;

} // End Registers namespace
