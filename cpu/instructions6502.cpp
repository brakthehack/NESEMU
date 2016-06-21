#include "instruction.h"

#include <iostream>
#include <cinttypes>

using namespace std;

void
ADC::operate(uint8_t op) {
  int temp = reg.acc + op + cpu.carry();
  cpu.zero(temp & 0xFF);
  cpu.carry(temp);
  cpu.negative(temp & 0xFF);
  cpu.overflow(op, temp);
  reg.acc = temp & 0xFF;
}
