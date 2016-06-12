#ifndef REGISTERS_
#define REGISTERS_

typedef struct registers {
  uint8_t acc;  // Holds one of the operands and generally the result.
  uint8_t x, y; // Used mainly for forming effective addresses and loop counters.
  uint8_t p;    // Conditional register containing flags, conditions modes, etc.
  uint8_t sp;   // Stack pointer.
  uint16_t pc;  // Program counter.
} registers;

#endif
