#include <iostream>

#include "config.h"
#include "cpu.h"
#include "cpu6502.h"
#include "instruction.h"
#include "addressMode.h"

#include <cstdlib>
#include <queue>

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
  while (!q.empty()) {
    Instruction6502* inst = q.front();
    inst->execute();
#ifdef EMU_DEBUG
    inst->description();
#endif
    q.pop();
    tick();
  }
}

/**
  * Powers on the CPU.
  * The power function first initializes the running state.  Then
  * it attempts to load the game. If the game load is successful, we can
  * begin executing 6502 instructions.
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
  // TEST, add some instructions
  q.push(new ADC(*this, this->reg, new Immediate()));
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
