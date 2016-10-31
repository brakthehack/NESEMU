#define BOOST_TEST_MODULE InstructionTest 

#include "instruction.h"
#include "addressMode.h"
#include "cpu6502.h"
#include "registers.h"

#include <cinttypes>
#include <string>
#include <vector>
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

  void run() {
    cpu.power(true);
  }
  void queue(Instruction6502 *instruction) {
    // Push an instruction onto the instruction queue and power on the CPU.
    cpu.q->push(instruction);
  }

  registers& data() {
    return cpu.reg;
  }

  Cpu6502 cpu;
};

class Immediate : public AddressMode {
public:
  Immediate(uint8_t o) :
    operand(o) {}
  uint8_t fetch(registers&) { return operand; }

private:
  uint8_t operand;
};

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
  Immediate mode(operand);
  INSTRUCTION instruction(c.cpu, c.data(), &mode);
  c.queue(&instruction);
  c.run();
}

template<typename INSTRUCTION>
static void run(CpuTester& c, std::vector<uint8_t> operands)
{
  std::vector<Immediate *> storage;
  std::vector<INSTRUCTION *> storage2;
  for (uint8_t operand : operands) {
    Immediate *mode = new Immediate(operand);
    storage.push_back(mode);
    INSTRUCTION *instruction = new INSTRUCTION(c.cpu, c.data(), mode);
    storage2.push_back(instruction);
    c.queue(instruction);
  }
  c.run();
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
    std::vector<uint8_t> operands = { 1, 127 };
    run<ADC>(c, operands);
    verify_acc(c, 128, "1 + 127 = 128");
  }

  {
    CpuTester c;
    std::vector<uint8_t> operands = { 1, 255 };
    run<ADC>(c, operands);
    verify_acc(c, 0, "1 + 255 = 0");
    verify_status_one(c, Registers::CARRY_FLAG, "Carry FLAG");
  }
  {
    CpuTester c;
    std::vector<uint8_t> operands = { 255, 255 };
    run<ADC>(c, operands);
    verify_acc(c, 254, "255 + 255 = 254");
    verify_status_one(c, Registers::CARRY_FLAG, "Carry FLAG");
    verify_status_one(c, Registers::OVERFLOW_FLAG, "Overflow FLAG");
  }
  {
    CpuTester c;
    std::vector<uint8_t> operands = { 255, 255, 0 };
    run<ADC>(c, operands);
    verify_acc(c, 255, "255 + 255 = 254 + carry = 255");
  }
}

BOOST_AUTO_TEST_CASE(_sbc_)
{
  CpuTester c;
  // run<SBC>(c, 0);
}
