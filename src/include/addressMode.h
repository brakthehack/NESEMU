#pragma once
#include "registers.h"

/**
  * AddressMode defines an interface for adressing
  * modes of the 6502 CPU. Upon instruction invocation
  * the CPU will fulfill the contract of executing
  * the before and after functions of the implementing
  * AddressMode class, which will allow the instructions
  * to remain separate from addressing modes, and will
  * allow address mode reuse.
  */

class AddressMode {
public:
  virtual uint8_t fetch(registers& reg) = 0;
};
