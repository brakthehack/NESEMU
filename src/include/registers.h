#ifndef REGISTERS_
#define REGISTERS_

#include <cinttypes>

typedef struct registers {
  uint8_t acc;  // Holds one of the operands and generally the result.
  uint8_t x, y; // Used mainly for forming effective addresses and loop counters.
  uint8_t p;    // Conditional register containing flags, conditions modes, etc.
  uint8_t sp;   // Stack pointer.
  uint16_t pc;  // Program counter.
} registers;

typedef enum {
  CARRY      = 0x01,
  ZERO       = 0x02,
  IRQ        = 0x04,
  BRK        = 0x08,
  DECIMAL    = 0x10,
  OVERFLOW   = 0x40,
  NEGATIVE   = 0x80
} STATUS;

#endif
