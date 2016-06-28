#ifndef INSTRUCTION_H_
#define INSTRUCTION_H_

#include "registers.h"
#include "cpu6502.h"
#include "addressMode.h"
#include "util.h"

#include <cinttypes>
#include <stdexcept>

#define NOT_IMPLEMENTED throw std::runtime_error("Not implemented")

class Instruction {

public:
  virtual void execute(uint8_t operand) = 0;
};

class Instruction6502 : public Instruction {

public:
  void execute(uint8_t operand) {
#ifdef DEBUG_ON
    cpu.print_registers(operand);
#endif 
    addr->before(reg);
    operate(operand);
    addr->after(reg);
#ifdef DEBUG_ON
    cpu.print_registers(operand);
#endif
  }

  ~Instruction6502() {
    delete addr;
  }

protected:
  virtual void operate(uint8_t& operand) {} // Default is NOP.
  Instruction6502(Cpu6502& c, registers& r, AddressMode* a) :
    cpu(c), reg(r), addr(a) {
    ASSERT(addr != nullptr);
  }

  Cpu6502& cpu;
  registers& reg;
  AddressMode* addr;
};

#define NEW_INSTRUCTION(INST) class INST : public Instruction6502 {\
public:                                                            \
  virtual void operate(uint8_t& operand) override;                  \
  void description();                                              \
  INST(Cpu6502& c, registers& r, AddressMode *a) :                 \
    Instruction6502(c, r, a) {}                                    \
}

NEW_INSTRUCTION(ADC);
NEW_INSTRUCTION(AND);
NEW_INSTRUCTION(ASL);
NEW_INSTRUCTION(BCC);
NEW_INSTRUCTION(BCS);
NEW_INSTRUCTION(BEQ);
NEW_INSTRUCTION(BIT);
NEW_INSTRUCTION(BMI);
NEW_INSTRUCTION(BME);
NEW_INSTRUCTION(BPL);
NEW_INSTRUCTION(BRK);
NEW_INSTRUCTION(BVC);
NEW_INSTRUCTION(BVS);
NEW_INSTRUCTION(CLC);
NEW_INSTRUCTION(CLD);
NEW_INSTRUCTION(CLI);
NEW_INSTRUCTION(CLV);
NEW_INSTRUCTION(CMP);
NEW_INSTRUCTION(CPX);
NEW_INSTRUCTION(CPY);
NEW_INSTRUCTION(DEC);
NEW_INSTRUCTION(DEX);
NEW_INSTRUCTION(DEY);
NEW_INSTRUCTION(EOR);
NEW_INSTRUCTION(INC);
NEW_INSTRUCTION(INX);
NEW_INSTRUCTION(INY);
NEW_INSTRUCTION(JMP);
NEW_INSTRUCTION(JSR);
NEW_INSTRUCTION(LDA);
NEW_INSTRUCTION(LDX);
NEW_INSTRUCTION(LDY);
NEW_INSTRUCTION(LSR);
NEW_INSTRUCTION(NOP);
NEW_INSTRUCTION(ORA);
NEW_INSTRUCTION(PHA);
NEW_INSTRUCTION(PHP);
NEW_INSTRUCTION(PLA);
NEW_INSTRUCTION(PLP);
NEW_INSTRUCTION(ROL);
NEW_INSTRUCTION(ROR);
NEW_INSTRUCTION(RTI);
NEW_INSTRUCTION(RTS);
NEW_INSTRUCTION(SBC);
NEW_INSTRUCTION(SEC);
NEW_INSTRUCTION(SED);
NEW_INSTRUCTION(SEI);
NEW_INSTRUCTION(STA);
NEW_INSTRUCTION(STX);
NEW_INSTRUCTION(STY);
NEW_INSTRUCTION(TAX);
NEW_INSTRUCTION(TAY);
NEW_INSTRUCTION(TSX);
NEW_INSTRUCTION(TXA);
NEW_INSTRUCTION(TXS);
NEW_INSTRUCTION(TYA);

#endif
