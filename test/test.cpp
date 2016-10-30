#define BOOST_TEST_MODULE InstructionTest 

#include "instruction.h"
#include "addressMode.h"
#include "cpu6502.h"
#include "registers.h"

#include <cinttypes>
#include <string>
#include <boost/test/unit_test.hpp>

/*
 * These tests test the actual instructions with the associated permutations
 * of addressing modes. Notably, the translation of op code to instruction/mode
 * is skipped.
 */

class CpuTester {
public:

  CpuTester() : cpu(nullptr, nullptr) {}

  std::string print(const std::string& op_name, uint8_t op) {
    return '\n' + op_name + '\n' + cpu.print_registers(op);
  }

  void run(Instruction6502 *inst, uint8_t op) {
    // Push an instruction onto the instruction queue and power on the CPU.
    cpu.q->push(inst);
    cpu.power(true);
  }

  registers& data() {
    return cpu.reg;
  }

  Cpu6502 cpu;
};



/*
 * Bypass the addressing mode by retrieving an operand to
 * the requesting instruction.
 */

uint8_t fetch_val;
uint8_t fetch(registers& reg) { return fetch_val; }


// Verification funtions.

static void
verify_acc(CpuTester& c, uint8_t expected, const std::string& op_name="")
{
  BOOST_CHECK_MESSAGE(c.data().acc == expected, c.print(op_name, expected));
}

static void
verify_status_all(CpuTester& c, uint8_t expected, const std::string& op_name="")
{
  BOOST_CHECK_MESSAGE(c.data().p == expected, c.print(op_name, expected));
}

static void
verify_status_one(CpuTester& c, uint8_t expected,const std::string& op_name="")
{
  BOOST_CHECK_MESSAGE((c.data().p & expected) > 0, c.print(op_name, expected));
}

/*
 * Declares an instruction and subsequently executes it.  It then prints the output.
 * We assume that the addressing mode has been determined and so feed it directly to
 * the instructions.
 * 
 * INST        = The Instruction name.
 * ADDRESSMODE = The addressing mode.
 * OP          = The Operand on which the instruction operates.
 */

template<typename INSTRUCTION>
static void run(CpuTester& c, uint8_t operand)
{
  fetch_val = operand;
  AddressMode mode(&fetch);
  INSTRUCTION instruction(c.cpu, c.data(), &mode);
  c.run(&instruction, operand);
}


BOOST_AUTO_TEST_CASE(_adc_)
{
  // Test customs.
  // Simple case.
  {
    CpuTester c;
    run<ADC>(c, 0);
    verify_acc(c, 0, "0");
  }
  {
    CpuTester c;
    run<ADC>(c, 69);
    verify_acc(c, 69, "General");
  }
  {
    CpuTester c;
    run<ADC>(c, 1);
    run<ADC>(c, 127);
    verify_acc(c, 128, "ADC Max");
  }
  {
    CpuTester c;
    run<ADC>(c, -1);
    run<ADC>(c, -128);
    verify_acc(c, -129, "Carry ACC");
    verify_status_one(c, Registers::CARRY_FLAG, "Carry FLAG");
  }
}

BOOST_AUTO_TEST_CASE(_sbc_)
{
  CpuTester c;
  run<SBC>(c, 0);
}
