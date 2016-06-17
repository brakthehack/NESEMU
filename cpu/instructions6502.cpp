#include "instruction.h"

#include <iostream>
#include <cinttypes>

using namespace std;

void
ADC::operate(uint8_t op) {
  int temp = reg.acc + op + cpu.carry();
  bool zeroResult = temp == 0;
  reg.acc = temp & 0xFF;

  cpu.zero(zeroResult);
  if (!zeroResult) {
    cpu.carry((temp >> 8) & 0x1);
    cpu.negative(temp < 0);
    cpu.overflow(temp > 0xFF);
  }
}
