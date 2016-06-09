#include <iostream>
#include <cinttypes>

#include "cpu6502.h"
#include "instruction.h"

using namespace std;

class ADC : Instruction {
 
  void
  execute() { 
    cout << "Acc is " << regs.acc << endl;
    regs.acc = 0xFF;
    cout << "Acc is " << regs.acc << endl;
  }

  void
  description() {
    cout << "Add memory and carry to accumulator" << endl;
  }

  ADC(Cpu6502& c, Cpu6502::registers& r) :
    cpu(c), regs(r) {}

private:
  Cpu6502 &cpu;
  Cpu6502::registers& regs;
};
