#define BOOST_TEST_MODULE InstructionTest 

#include "instruction.h"
#include "addressMode.h"
#include "cpu6502.h"

#include <cinttypes>
#include <boost/test/unit_test.hpp>

#define RUN(INST, ADDR, OP) INST inst(*c.cpu, c.data(), \
        new ADDR()); c.run(&inst, OP)

class CpuTester {
public:
  CpuTester() :
    cpu(new Cpu6502(nullptr, nullptr)) {
  }

  void print(uint8_t op) { cpu->print_registers(op); }

  void run(Instruction6502 *inst, uint8_t op) {
    cpu->load_operand(op);
    cpu->q->push(inst);
    cpu->power(true);
  }

  registers& data() {
    return cpu->reg;
  }

  ~CpuTester() {
    delete cpu;
  }

  Cpu6502 *cpu;
};

BOOST_AUTO_TEST_CASE(_adc_)
{
  CpuTester c;
  RUN(ADC, Immediate, 0);
}

BOOST_AUTO_TEST_CASE(_sbc_)
{
  CpuTester c;
  RUN(SBC, Immediate, 0);
}
