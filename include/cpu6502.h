#ifndef CPU6502_H_
#define CPU6502_H_

#include "cpu.h"
#include "decoder.h"
#include "mmu.h"

class Cpu6502 : Cpu {
public:

  // Registers.
  typedef struct registers {
    uint8_t acc;  // Holds one of the operands and generally the result.
    uint8_t x, y; // Used mainly for forming effective addresses and loop counters.
    uint8_t p;    // Conditional register containing flags, conditions modes, etc.
    uint8_t sp;   // Stack pointer.
    uint16_t pc;   // Program counter.
  } registers;

  bool carry()    { reg.p & 0x01 != 0; }
  bool zero()     { reg.p & 0x02 != 0; }
  bool irq()      { reg.p & 0x04 != 0; }
  bool decimal()  { reg.p & 0x08 != 0; }
  bool brk()      { reg.p & 0x10 != 0; }
  // 0x20 not used.
  bool overflow() { reg.p & 0x40 != 0; }
  bool negative() { reg.p & 0x80 != 0; }

  virtual void power(bool on);
  virtual void reset();

  Cpu6502(Decoder *d, Mmu *m) :
    Cpu(d, m) {
    reg.sp = 0xff;
  }

private:
  registers reg;

  virtual void execute(Instruction& inst);
  virtual void tick();

  void init();
};

#endif
