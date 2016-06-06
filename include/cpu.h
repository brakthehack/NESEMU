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
	
  enum State {
    STATE_RUNNING,
    STATE_OFF,
    STATE_HALT,
    STATE_ERROR
  };
  
  // Registers.
  typedef struct registers {
    uint8_t acc;  // Holds one of the operands and generally the result.
    uint8_t x, y; // Used mainly for forming effective addresses and loop counters.
    uint8_t p;    // Conditional register containing flags, conditions modes, etc.
    uint8_t sp;   // Stack pointer.
    uint16_t pc;   // Program counter.
  } registers;

  void power(bool on);
  void reset();
  State state() { return runningState; }

  Cpu(Decoder* dec) :
    decoder(dec) {
    reg.sp = 0xff;
  }

  ~Cpu() {}

private:

  State runningState;

  registers reg;
	
  // Instruction disassembler.
  Decoder* decoder;

  bool fetch(uint8_t* data);
  Instruction& decode(uint8_t* data);
  bool execute(Instruction& inst);

  void init();
  void tick();

  // Flag queries.
	bool carry() { return reg.p & 0x1 != 0; }
	bool zero() { return reg.p & 0x2 != 0; }
	bool irqEnabled() { return reg.p & 0x4 != 0; }
	bool decimalEnabled() { return reg.p & 0x8 != 0; }
	bool breakInterrupt() { return reg.p & 0x10 != 0; }
  // Note: 0x20 is left unused.
	bool overflow() { return reg.p & 0x40 != 0; }
	bool negative() { return reg.p & 0x80 != 0; }
};

#endif
