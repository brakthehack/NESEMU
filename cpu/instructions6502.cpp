#include "instruction.h"

#include <iostream>
#include <cinttypes>

using namespace std;

void
ADC::operate(uint8_t op) {
  reg.acc = 0x40;
}

void
NOP::operate(uint8_t op) {/* No operation */}
