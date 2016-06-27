#ifndef CPU6502_H_
#define CPU6502_H_

#include <queue>

#include "cpu.h"
#include "registers.h"
#include "decoder.h"
#include "mmu.h"

class Instruction6502;

class Cpu6502: Cpu {
public:

  virtual void power(bool on);
  virtual void reset();

  virtual void printRegisters(uint8_t operand);

  Cpu6502(Decoder *d, Mmu *m) :
    Cpu::Cpu(d), mmu(m) {
    q = new std::queue<Instruction6502 *>();
    reg.sp = 0xff;
    reg.p = 0x20;
  }

  ~Cpu6502() {
    delete mmu;
    delete q;
  }

  inline int carry()     { return reg.p & 0x01; }
  inline bool zero()     { return reg.p & 0x02 != 0; }
  inline bool irq()      { return reg.p & 0x04 != 0; }
  inline bool decimal()  { return reg.p & 0x08 != 0; }
  inline bool brk()      { return reg.p & 0x10 != 0; }
  // 0x20 flag is not used.  It is used by stack copy.
  inline bool overflow() { return reg.p & 0x40 != 0; }
  inline bool negative() { return reg.p & 0x80 != 0; }

  void carry(int result) { 
    reg.p &= ~0x1;
    reg.p |= result >> 8;
  }
  
  void zero(uint8_t result){
    if (result == 0)
      reg.p |= 0x02;
    else
      reg.p &= ~0x02;
  }

  void irq(bool set) { 
    set ? reg.p |= 0x04 : reg.p &= ~0x04; 
  }

  void decimal(bool set)  {
    set ? reg.p |= 0x08 : reg.p &= ~0x08;
  }
  
  void brk(bool set) {
    set ? reg.p |= 0x10 : reg.p &= ~0x10;
  }
  
  // Once again 0x20 is not used.
  
  void overflow(uint8_t op, uint8_t result) { 
    reg.p &= ~0x40;
    // Check position 7; move answer to position 6.
    reg.p |= (~(op ^ reg.acc) | result) >> 1 & 0x40;
  }
  
  void negative(uint8_t result) {
    reg.p &= ~0x80;
    reg.p |= result & 0x80;
  }
  
  void push(uint8_t op);
  uint8_t pop();
  
private:
 
  registers reg;
  
  Mmu *mmu;
  
  std::queue<Instruction6502 *> *q;

  void execute();
  void tick();

  void init();
  void post();

};

#endif
