#include <iostream>
#include <sstream>
#include <bitset>
#include <cstdlib>
#include <queue>
#include <thread>

#include "config.h"
#include "cpu.h"
#include "cpu6502.h"
#include "instruction.h"
#include "addressMode.h"

using namespace std;

/**
  * Traditional execution loop. Fetch, decode, execute,
  * and advance one clock cycle.
  * TODO: clock cycles will probably have to be pushed
  * to the instruction class, because instructions generally
  * take more than one clock cycle to complete.
  */
void
Cpu6502::execute() {
  while (!q->empty()) {
    Instruction6502* inst = q->front();
    inst->execute();
    q->pop();
    tick();
  }
}


/**
  * Powers on the CPU.
  * The power function first initializes the running state.  Then
  * it attempts to load the game. If the game load is successful,
  * we can begin executing 6502 instructions.
  */
void
Cpu6502::power(bool on) {
  if (on) {
    runningState = STATE_RUNNING;
    init();
    // load game
    execute();
  }
  else { 
    runningState = STATE_OFF;
    cout << "CPU: OFF" << endl;
  }
}

void
Cpu6502::post() {
    cout << "NESEMU version: " << NESEMU_VERSION_MAJOR \
         << "." << NESEMU_VERSION_MINOR << endl;

    cout << "Power state initialized." << endl;
}

/**
  * Initializes the CPU to default values per the specification.
  */
void
Cpu6502::init() {
  // TODO: Not fully implemented.
  post();
  // Reset All registers.
  reg.acc = 0;
  reg.x = 0;
  reg.y = 0;
  reg.p = 0x20;
  reg.pc = 0;
  reg.sp = 0xFF;
}


// Instructions.
void
Cpu6502::push(uint8_t op) {
  reg.sp -= 4;
  ASSERT(reg.sp != 0);
  mmu->put(op, reg.sp);
}

uint8_t
Cpu6502::pop() {
  uint8_t temp = mmu->get(reg.sp);
  reg.sp += 4;
  ASSERT(reg.sp <= 0xFF);
  return temp;
}

/**
  * Emulates one clock cycle of the CPU.
  */
void
Cpu6502::tick() {
#ifdef NO_TICK
  cout << "Tick!" << endl;
  this_thread::sleep_for(chrono::seconds(1));
  reg.pc += 4;
#endif
}

void
Cpu6502::reset() {
  // TODO: Not implemented.
}

string
Cpu6502::print_registers(uint8_t operand) {
  stringstream ss;
  bitset<8> ac(reg.acc);
  bitset<8> op(operand);
  bitset<8> stat(reg.p);
  ss << \
  "------Operand------"                    << endl << \
  "OP : " << op << " " << int16_t(operand) << endl << \
  "-----Registers-----"                    << endl << \
  "ACC: " << int16_t(reg.acc)              << endl << \
  "ACC: " << ac                            << endl << \
  "X  : " << int16_t(reg.x)                << endl << \
  "Y  : " << int16_t(reg.y)                << endl << \
  "     " << "SO_BDIZC"                    << endl << \
  "ST : " << stat                          << endl << \
  "SP : " << hex << unsigned(reg.sp)       << endl << \
  "PC : " << hex << unsigned(reg.pc)       << endl;
  return ss.str();
}
