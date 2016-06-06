#include <iostream>

#include "cpu.h"

using namespace std;

/**
  * Powers on the CPU and immediately begins executing instructions.
  */
void
Cpu::power(bool on) {
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
Cpu::init() {
  // Nothing to initialize!
}

/**
  * Emulates one clock cycle of the CPU.
  */
void
Cpu::tick() {
  cout << "Tick!" << endl;
}
