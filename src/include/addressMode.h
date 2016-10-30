#pragma once

#include "registers.h"

#include <iostream>

/**
  * AddressMode defines an interface for adressing
  * modes of the 6502 CPU. Upon instruction invocation
  * the CPU will fulfill the contract of executing
  * the before and after functions of the implementing
  * AddressMode class, which will allow the instructions
  * to remain separate from addressing modes, and will
  * allow address mode reuse.
  */

typedef uint8_t (* AddressCallback)(registers& reg);

class AddressMode {
public:
  AddressMode(AddressCallback f) :
    fetch(f) {}

  AddressCallback fetch;
};

namespace Immediate {
  uint8_t fetch(registers& reg);
}
