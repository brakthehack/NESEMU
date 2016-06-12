#ifndef CPU6502_H_
#define CPU6502_H_

#include "cpu.h"
#include "registers.h"
#include "instruction.h"
#include "decoder.h"
#include "mmu.h"

#include <queue>

class Cpu6502 : Cpu {
public:

  inline bool carry()    { reg.p & 0x01 != 0; }
  inline bool zero()     { reg.p & 0x02 != 0; }
  inline bool irq()      { reg.p & 0x04 != 0; }
  inline bool decimal()  { reg.p & 0x08 != 0; }
  inline bool brk()      { reg.p & 0x10 != 0; }
  // 0x20 flag is not used.  It is used by stack copy.
  inline bool overflow() { reg.p & 0x40 != 0; }
  inline bool negative() { reg.p & 0x80 != 0; }

  // A set flag indicates a bit set at the appropriately described position.
  // An unset flag will result in the bit being cleared.
  inline void carry(bool set)    { set ? reg.p |= 0x01 : reg.p &= ~0x01; }
  inline void zero(bool set)     { set ? reg.p |= 0x02 : reg.p &= ~0x02; }
  inline void irq(bool set)      { set ? reg.p |= 0x04 : reg.p &= ~0x04; }
  inline void decimal(bool set)  { set ? reg.p |= 0x08 : reg.p &= ~0x08; }
  inline void brk(bool set)      { set ? reg.p |= 0x10 : reg.p &= ~0x10; }
  // Once again 0x20 is not used.
  inline void overflow(bool set) { set ? reg.p |= 0x40 : reg.p &= ~0x40; }
  inline void negative(bool set) { set ? reg.p |= 0x80 : reg.p &= ~0x80; }

  virtual void power(bool on);
  virtual void reset();

  Cpu6502(Decoder *d, Mmu *m) :
    Cpu::Cpu(d, m) {
    reg.sp = 0xff;
    reg.p = 0x20;
  }

private:
  registers reg;
  std::queue<Instruction6502 *> q;

  void execute();
  void tick();

  void init();
  void post();
};

#endif
