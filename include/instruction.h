#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <cinttypes>

#include "cpu.h"

class Cpu;

class Instruction {

public:
  virtual void execute(Cpu &cpu, uint8_t data) = 0;
  virtual void description() = 0;

};

#endif
