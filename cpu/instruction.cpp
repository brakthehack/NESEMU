#include <iostream>
#include <cinttypes>

#include "cpu.h"
#include "instruction.h"

using namespace std;

class ADC : Instruction {
  
  void
  execute(Cpu::registers &regs, uint8_t data) { 
    cout << "Acc is " << regs.acc << endl;
    regs.acc = 0xFF;
    cout << "Acc is " << regs.acc << endl;
  }

  void
  description() {
    cout << "Add memory and carry to accumulator" << endl;
  }
};
