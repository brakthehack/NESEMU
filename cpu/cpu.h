#include <cstdint>

/**
  * This is the CPU for the 6502 processor.
  */

class Cpu {

public:
	// Flag queries.
	bool carry() { return p & 0x1 != 0; }
	bool zero() { return p & 0x2 != 0; }
	bool irqEnabled() { return p & 0x4 != 0; }
	bool decimalEnabled() { return p & 0x8 != 0; }
	bool breakInterrupt() { return p & 0x10 != 0; }
  
  // Note: 0x20 is left unused.

	bool overflow() { return p & 0x40 != 0; }
	bool negative() { return p & 0x80 != 0; }

private:
	// Registers.

	uint8_t acc;  // Holds one of the operands and generally the result.
	uint8_t x, y; // Used mainly for forming effective addresses and loop counters.
	uint8_t p;    // Conditional register containing flags, conditions modes, etc.
	uint8_t sp;   // Stack pointer.
	uint16_t pc;  // Program counter.
};
