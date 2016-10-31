#ifndef CPU6502_H_
#define CPU6502_H_

#include <queue>
#include <string>

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

  virtual std::string print_registers(uint8_t operand);

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

  inline int carry()     { return (reg.p & Registers::CARRY_FLAG); }
  inline bool zero()     { return (reg.p & Registers::ZERO_FLAG) != 0; }
  inline bool irq()      { return (reg.p & Registers::IRQ_FLAG) != 0; }
  inline bool decimal()  { return (reg.p & Registers::DECIMAL_FLAG) != 0; }
  inline bool brk()      { return (reg.p & Registers::BRK_FLAG) != 0; }
  // 0x20 flag is not used.  It is used by stack copy.
  inline bool overflow() { return (reg.p & Registers::OVERFLOW_FLAG) != 0; }
  inline bool negative() { return (reg.p & Registers::NEGATIVE_FLAG) != 0; }

  void carry(int result) {
    uint8_t flag = result > 0xFF || result < 0 ? 1 : 0;
    if (flag == 1) {
      reg.p |= Registers::CARRY_FLAG;
    } else {
      reg.p &= ~Registers::CARRY_FLAG;
    } 
  }
  
  void zero(uint8_t result){
    if (result == 0)
      reg.p |= Registers::ZERO_FLAG;
    else
      reg.p &= ~Registers::ZERO_FLAG;
  }

  void irq(bool set) { 
    set ? reg.p |= Registers::IRQ_FLAG : reg.p &= ~Registers::IRQ_FLAG; 
  }

  void decimal(bool set)  {
    set ? reg.p |= Registers::DECIMAL_FLAG : reg.p &= ~Registers::DECIMAL_FLAG;
  }
  
  void brk(bool set) {
    set ? reg.p |= Registers::BRK_FLAG : reg.p &= ~Registers::BRK_FLAG;
  }
  
  // Once again 0x20 is not used.
  
  void overflow(uint8_t op, uint8_t result) { 
    reg.p &= ~Registers::OVERFLOW_FLAG;
    // Check position 7; move answer to position 6.
    reg.p |= (~(op ^ reg.acc) | result) >> 1 & Registers::OVERFLOW_FLAG;
  }
  
  void negative(uint8_t result) {
    reg.p &= ~Registers::NEGATIVE_FLAG;
    reg.p |= result & Registers::NEGATIVE_FLAG;
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

};

#endif
