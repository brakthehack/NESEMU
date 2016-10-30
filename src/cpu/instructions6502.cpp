#include "instruction.h"

#include <iostream>
#include <cinttypes>

using namespace std;

// Add memory to accumulator with carry.
void
ADC::operate(uint8_t& op) {
  int temp = reg.acc + op + cpu.carry();
  
  cpu.zero(temp & 0xFF);
  cpu.negative(temp & 0xFF);
  cpu.overflow(op, temp);
 
  if (cpu.decimal()) {

  }

  cpu.carry(temp);
  reg.acc = temp & 0xFF;
}

// Logical AND.
void
AND::operate(uint8_t& op) {
  reg.acc = reg.acc & op;
  cpu.negative(reg.acc);
  cpu.zero(reg.acc);
}

// Shift left one bit.
void
ASL::operate(uint8_t& op) {
  int temp = op << 1;
  cpu.carry(reg.acc);
  cpu.negative(reg.acc);
  cpu.zero(reg.acc);
}

// Branch on carry clear.
// Add 1 if branch occurs to same page, else add 2.
void
BCC::operate(uint8_t& op) {
  if (!cpu.carry()) {
    reg.pc = op;
  }
}

// Branch on carry set.
// Add 1 if branch occurs to same page, else add 2.
void
BCS::operate(uint8_t& op) {
  if (cpu.carry()) {
    reg.pc = op;
  }
}

// Branch on result zero.
// Add 1 if branch occurs to same page, else add 2.
void
BEQ::operate(uint8_t& op) {
  if (cpu.zero()) {
    reg.pc = op;
  }
}

// Test bits in memory with accumulator.
void
BIT::operate(uint8_t& op) {
  uint8_t temp = reg.acc & op;
  uint8_t overflow = temp & 0x40;
  reg.p &= ~0x40;
  reg.p |= overflow;

  cpu.negative(temp);
  cpu.zero(temp);
}

// Branch on negative result.
void
BMI::operate(uint8_t& op) {
  if (cpu.negative()) {
    reg.pc = op;
  }
}

// Branch on positive result.
void
BPL::operate(uint8_t& op) {
  if (!cpu.negative()) {
    reg.pc = op;
  }
}

// Force Interrupt PC + 2
void
BRK::operate(uint8_t& op) {
  //mmu.push()
}

// Branch if overflow cleared.
void
BVC::operate(uint8_t& op) {
  if (!cpu.overflow()) {
    reg.pc = op;
  }
}

// Branch if overflow set.
void
BVS::operate(uint8_t& op) {
  if (cpu.overflow()) {
    reg.pc = op;
  }
}

// Clear carry flag.
void
CLC::operate(uint8_t&) {
  reg.p &= ~0x01;
}

// Clear decimal mode.
void
CLD::operate(uint8_t&) {
  reg.p &= ~0x08;
}

// Clear interrupt flag.
void
CLI::operate(uint8_t&) {
  reg.p &= ~0x04;
}

// Clear overflow flag.
void
CLV::operate(uint8_t&) {
  reg.p &= ~0x40;
}

// Compare memory and accmumulator (A - M).
// Add 1 if page boundry is crossed.
void
CMP::operate(uint8_t& op) {
  // TODO: TESTfunction
  int temp = reg.acc + (0x80 ^ op);
  op = temp;
  cpu.carry(temp);
  cpu.negative(temp);
  cpu.zero(temp);
}

// Compare memory and Index X.
void
CPX::operate(uint8_t& op) {
  int temp = reg.x + (0x80 ^ op);
  op = temp;
  cpu.carry(temp);
  cpu.negative(temp);
  cpu.zero(temp);
}

// Compare memory and index Y.
void
CPY::operate(uint8_t& op) {
  int temp = reg.y + (0x80 ^ op);
  op = temp;
  cpu.carry(temp);
  cpu.negative(temp);
  cpu.zero(temp);
}

// Decrement memory by one.
void
DEC::operate(uint8_t& op) {
  op -= 1;
  cpu.negative(op);
  cpu.zero(op);
}

// Decrement index X by one.
void
DEX::operate(uint8_t&) {
  reg.x -= 1;
  cpu.negative(reg.x);
  cpu.zero(reg.x);
}

// Decrement index Y by one.
void
DEY::operate(uint8_t&) {
  reg.y -= 1;
  cpu.negative(reg.y);
  cpu.zero(reg.y);
}

// Exclusive OR memory with accmululator.
void
EOR::operate(uint8_t& op) {
  reg.acc = reg.acc ^ op;
  cpu.negative(reg.acc);
  cpu.zero(reg.acc);
}

// Increment memory by one.
void
INC::operate(uint8_t& op) {
  op += 1;
  cpu.negative(op);
  cpu.zero(op);
}

// Increment Index X by one.
void
INX::operate(uint8_t&) {
  reg.x += 1;
  cpu.negative(reg.x);
  cpu.zero(reg.x);
}

// Increment Index Y by one.
void
INY::operate(uint8_t&) {
  reg.y += 1;
  cpu.negative(reg.y);
  cpu.zero(reg.y);
}

// Jump to a new location.
void
JMP::operate(uint8_t& op) {
  // TODO: implement this function.
}

// Jump to a new location saving return address.
void
JSR::operate(uint8_t& op) {
  // TODO: implement this function.
}

// Load accumulator with memory.
void
LDA::operate(uint8_t& op) {
  reg.acc = op;
  cpu.negative(reg.acc);
  cpu.zero(reg.acc);
}

// Load Index X with memory.
void
LDX::operate(uint8_t& op) {
  reg.x = op;
  cpu.negative(reg.x);
  cpu.zero(reg.x);
}

// Load Index Y with memory.
void
LDY::operate(uint8_t& op) {
  reg.y = op;
  cpu.negative(reg.y);
  cpu.zero(reg.y);
}

// Shift right one bit (memory or acc).
void
LSR::operate(uint8_t& op) {
  // Set carry by hand.
  reg.p &= ~0x01;
  reg.p |= op & 0x01;
  op >>= 1;
  cpu.negative(op);
  cpu.zero(op);
}

// No operation.
void
NOP::operate(uint8_t&) {}

// Binary OR memory with accmumulator.
void
ORA::operate(uint8_t& op) {
  reg.acc |= op;
  cpu.negative(reg.acc);
  cpu.zero(reg.acc);
}

// Push accmumulator on stack.
void
PHA::operate(uint8_t&) {
  cpu.push(reg.acc);
}

// Push processor status on stack.
void
PHP::operate(uint8_t&) {
  cpu.push(reg.p);
}

// Pull accumulator from stack.
void
PLA::operate(uint8_t& op) {
  op = cpu.pop();
  cpu.zero(op);
  cpu.negative(op);
}

// Pull processor status from stack.
void
PLP::operate(uint8_t& op) {
  op = cpu.pop();
  reg.p = op;
}

// Rotate left one bit.
void
ROL::operate(uint8_t& op) {
  //TODO: TEST
  int temp = op << 1;
  temp |= temp >> 8;
  op = temp;
  cpu.carry(temp);
  cpu.negative(op);
  cpu.zero(op);
}

// Rotate right one bit.
void
ROR::operate(uint8_t& op) {
  //TODO: TEST
  int save = (op & 0x1) << 7;
  int temp = (op >> 1) | save;
  op = temp;
  cpu.carry(temp);
  cpu.negative(op);
  cpu.zero(op);
}

// Return from interrupt.
void
RTI::operate(uint8_t&) {
  // TODO: TEST
  reg.p = cpu.pop();
  reg.pc = cpu.pop();
  reg.pc |= (cpu.pop() << 8);
}

// Return from subroutine.
void
RTS::operate(uint8_t&) {
  reg.pc = cpu.pop();
  reg.pc += (cpu.pop() << 8) + 1;
}

// Subtract memory from accmuluator with borrow.
void
SBC::operate(uint8_t& op) {
  //TODO: TEST
  uint8_t temp = reg.acc - op - (cpu.carry() ? 1 : 0);
  cpu.zero(temp);
  cpu.overflow(reg.acc, temp);
  cpu.negative(temp);
  
  if (cpu.decimal()) {

  }

  cpu.carry(reg.acc < op ? -1 : 0);
  reg.acc = temp;
}

// Set carry flag.
void
SEC::operate(uint8_t&) {
  reg.p |= Registers::CARRY_FLAG;
}

// Set decimal mode.
void
SED::operate(uint8_t&) {
  reg.p |= Registers::DECIMAL_FLAG;
}

// Set interrupt disabled status.
void
SEI::operate(uint8_t&) {
  reg.p |= Registers::BRK_FLAG;
}

// Store accumulator in memory.
void
STA::operate(uint8_t& op) {
  op = reg.acc;
}

// Store index X in memory
void
STX::operate(uint8_t& op) {
  op = reg.x;
}

// Store index Y in memory.
void
STY::operate(uint8_t& op) {
  op = reg.y;
}

// Transfer accmumulator to index X.
void
TAX::operate(uint8_t&) {
  reg.x = reg.acc;
  cpu.negative(reg.x);
  cpu.zero(reg.x);
}

// Transfer accmuluator to index Y.
void
TAY::operate(uint8_t&) {
  reg.y = reg.acc;
  cpu.negative(reg.y);
  cpu.zero(reg.y);
}

// Transfer stack pointer to index X.
void
TSX::operate(uint8_t&) {
  reg.x = reg.sp;
  cpu.negative(reg.x);
  cpu.zero(reg.x);
}

// Transfer index X to accumulator.
void
TXA::operate(uint8_t&) {
  reg.acc = reg.x;
  cpu.negative(reg.acc);
  cpu.zero(reg.acc);
}

// Transfer index X to stack pointer.
void
TXS::operate(uint8_t&) {
  reg.sp = reg.x;
}

// Transfer index Y to accumulator.
void
TYA::operate(uint8_t&) {
  reg.acc = reg.y;
  cpu.negative(reg.acc);
  cpu.zero(reg.acc);
}
