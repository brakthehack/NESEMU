#include <iostream>
#include <cinttypes>

#include "cpu6502.h"
#include "instruction.h"

using namespace std;

void
ADC::execute() {
  addr->before(reg);
  cout << "Acc is " << hex << unsigned(reg.acc) << endl;
  reg.acc = 0x40;
  cout << "Acc is " << hex << unsigned(reg.acc) << endl;
  addr->after(reg);
}

void
ADC::description() {
  cout << "Add memory and carry to accumulator" << endl;
}
