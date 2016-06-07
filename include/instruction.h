#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include <cinttypes>

#include "cpu.h"

class Instruction {

public:
  virtual void execute() = 0;
  virtual void description() = 0;
};

#endif
