#include "mmu.h"

uint8_t
Mmu::get(size_t offset) {
  return data[offset]; 
}

void
Mmu::put(uint8_t in, size_t addr) {
  data[addr] = in;
}
