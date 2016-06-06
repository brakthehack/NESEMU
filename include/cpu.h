#ifndef CPU_H_
#define CPU_H_

#include <cstdint>

#include "instruction.h"
#include "decoder.h"

/**
  * The CPU for the 6502 processor.
  */

class Cpu {

public:
	
  void power(bool on);
  void reset();

  Cpu(Decoder* dec) :
    sp(0xFF), decoder(dec) {}

  ~Cpu() {}

private:

  enum State {
    STATE_RUNNING,
    STATE_OFF,
    STATE_HALT,
    STATE_ERROR
  };

  State state;

	// Registers.

	uint8_t acc;  // Holds one of the operands and generally the result.
	uint8_t x, y; // Used mainly for forming effective addresses and loop counters.
	uint8_t p;    // Conditional register containing flags, conditions modes, etc.
	uint8_t sp;   // Stack pointer.
	uint16_t pc;  // Program counter.

  // Instruction disassembler.
  Decoder* decoder;

  bool fetch(uint8_t data);
  Instruction& decode(uint8_t data);
  bool execute(Instruction& inst);

  void init();
  void tick();

  // Flag queries.
	bool carry() { return p & 0x1 != 0; }
	bool zero() { return p & 0x2 != 0; }
	bool irqEnabled() { return p & 0x4 != 0; }
	bool decimalEnabled() { return p & 0x8 != 0; }
	bool breakInterrupt() { return p & 0x10 != 0; }
  // Note: 0x20 is left unused.
	bool overflow() { return p & 0x40 != 0; }
	bool negative() { return p & 0x80 != 0; }
};

#endif
