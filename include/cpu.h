#ifndef CPU_H_
#define CPU_H_

#include <cstdint>

#include "mmu.h"
#include "instruction.h"
#include "decoder.h"

/** Abstract class for a CPU.
  * This class provides the functionality common
  * to most CPUs.  This is done in an attempt to reuse exiting
  * code for future emulators.
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

  Cpu(Decoder *dec, Mmu *m) :
    decoder(dec), mmu(m) {
  }

  ~Cpu() {
    delete decoder;
    delete mmu;
  }

protected:
  State runningState;
  Mmu *mmu;
  Decoder *decoder; // Decodes instructions.

  virtual void execute(Instruction& inst) = 0;
  virtual void tick() = 0;
};

#endif
