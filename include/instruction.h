#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "registers.h"
#include "addressMode.h"

#include <cinttypes>
#include <cassert>

class Cpu6502;

class Instruction {

public:
  virtual void execute() = 0;
  virtual void description() = 0;
};

class Instruction6502 : public Instruction {

public:
  virtual void execute() = 0;
  virtual void description() = 0;

  ~Instruction6502() {
    free(addr);
  }

protected:
  Instruction6502(Cpu6502& c, registers& r, AddressMode* a) :
    cpu(c), reg(r), addr(a) {
    assert(addr != nullptr);
  }

  Cpu6502& cpu;
  registers& reg;
  AddressMode* addr;
};

class ADC : public Instruction6502 {
public:
  void execute();
  void description();

  ADC(Cpu6502& c, registers& r, AddressMode* a) :
    Instruction6502(c, r, a) {} 
};

#endif
