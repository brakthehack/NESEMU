#include <iostream>

#include "cpu.h"
#include "cpu6502.h"

using namespace std;

void
Cpu6502::execute(Instruction& inst) {
  inst.execute();
}

/**
  * Powers on the CPU and immediately begins executing instructions.
  */
void
Cpu6502::power(bool on) {
  if (on) {
    runningState = STATE_RUNNING;
    cout << "CPU: ON" << endl;
    init();
    tick();
  }
  else { 
    runningState = STATE_OFF;
    cout << "CPU: OFF" << endl;
  }
}

/**
  * Initializes the CPU to default values per the specification.
  */
void
Cpu6502::init() {
  // TODO: Not implemented.
}

/**
  * Emulates one clock cycle of the CPU.
  */
void
Cpu6502::tick() {
  cout << "Tick!" << endl;
}

void
Cpu6502::reset() {
  // TODO: Not implemented.
}
