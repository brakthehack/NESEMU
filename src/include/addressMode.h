#ifndef ADDRESS_MODE_H_
#define ADDRESS_MODE_H_

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
class AddressMode {
public:
  virtual void before(registers& reg) = 0;
  virtual void after(registers& reg) = 0;
};

class Immediate : public AddressMode {
public:
  void before(registers& reg) {}
  void after(registers& reg) {}
};

class ZeroPage : public AddressMode {
public:
  void before(registers& reg);
  void after(registers& reg);
};

class ZeroPageX : public ZeroPage {
public:
  void before(registers& reg);
  void after(registers& reg);
};

class Absolute : public AddressMode {
public:
  void before(registers& reg);
  void after(registers& reg);
};

class AbsoluteX : public Absolute {
public:
  void before(registers& reg);
  void after(registers& reg);
};

class AbsoluteY : public Absolute {
public:
  void before(registers& reg);
  void after(registers& reg);
};

class Relative : public AddressMode {
public:
  void before(registers& reg);
  void after(registers& reg);
};

class Implied : public AddressMode {
public:
  void before(registers& reg) {}
  void after(registers& reg) {}
};

class IndirectX : public AddressMode {
public:
  void before(registers& reg);
  void after(registers& reg);
};

class IndirectY : public AddressMode {
public:
  void before(registers& reg);
  void after(registers& reg);
};

#endif