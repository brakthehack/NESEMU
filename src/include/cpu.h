#ifndef CPU_H_
#define CPU_H_

#include "decoder.h"
#include "mmu.h"

#include <cstdint>

/** 
  * Abstract class for a CPU.
  * This class provides the functionality common to most CPUs.
  */
class Cpu {

public:
  enum State {
    STATE_RUNNING,
    STATE_OFF,
    STATE_HALT,
    STATE_ERROR
  };
  
  virtual void power(bool on) = 0;
  virtual void reset() = 0;

  State state() { return runningState; }

  Cpu(Decoder *dec) :
    decoder(dec) {}

  ~Cpu() {
    delete decoder;
  }

protected:
  State runningState;
  Decoder *decoder; // Decodes instructions.

  virtual void execute() = 0;
  virtual void tick() = 0;
  virtual void post() = 0;

};

#endif
