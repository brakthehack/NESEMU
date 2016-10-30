#ifndef CPU6502_H_
#define CPU6502_H_

#include <queue>

#include "cpu.h"
#include "registers.h"
#include "decoder.h"
#include "mmu.h"

class Instruction6502;

class Cpu6502: Cpu {

friend class CpuTester;

public:

  virtual void power(bool on);
  virtual void reset();

  virtual void print_registers(uint8_t operand);

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

  inline int carry()     { return (reg.p & STATUS::CARRY); }
  inline bool zero()     { return (reg.p & STATUS::ZERO) != 0; }
  inline bool irq()      { return (reg.p & STATUS::IRQ) != 0; }
  inline bool decimal()  { return (reg.p & STATUS::DECIMAL) != 0; }
  inline bool brk()      { return (reg.p & STATUS::BRK) != 0; }
  // 0x20 flag is not used.  It is used by stack copy.
  inline bool overflow() { return (reg.p & STATUS::OVERFLOW) != 0; }
  inline bool negative() { return (reg.p & STATUS::NEGATIVE) != 0; }

  void carry(int result) { 
    reg.p &= ~0x1;
    reg.p |= result >> 8;
  }
  
  void zero(uint8_t result){
    if (result == 0)
      reg.p |= STATUS::ZERO;
    else
      reg.p &= ~STATUS::ZERO;
  }

  void irq(bool set) { 
    set ? reg.p |= STATUS::IRQ : reg.p &= ~STATUS::IRQ; 
  }

  void decimal(bool set)  {
    set ? reg.p |= STATUS::DECIMAL : reg.p &= ~STATUS::DECIMAL;
  }
  
  void brk(bool set) {
    set ? reg.p |= STATUS::BRK : reg.p &= ~STATUS::BRK;
  }
  
  // Once again 0x20 is not used.
  
  void overflow(uint8_t op, uint8_t result) { 
    reg.p &= ~STATUS::OVERFLOW;
    // Check position 7; move answer to position 6.
    reg.p |= (~(op ^ reg.acc) | result) >> 1 & STATUS::OVERFLOW;
  }
  
  void negative(uint8_t result) {
    reg.p &= ~STATUS::NEGATIVE;
    reg.p |= result & STATUS::NEGATIVE;
  }
  
  void push(uint8_t op);
  uint8_t pop();

private:
 
  registers reg;

  uint8_t current_operand;
  
  Mmu *mmu;
  
  std::queue<Instruction6502 *> *q;

  void execute();
  void tick();

  void init();
  void post();

  void load_operand(uint8_t op) {
    current_operand = op;
  }

};

#endif
