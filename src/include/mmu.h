#ifndef MMU_H_
#define MMU_H_

#include <cinttypes>
#include <cstddef>

class Mmu {
public:
  virtual uint8_t get(size_t offset) = 0;
  virtual void put(uint8_t data, size_t addr) = 0;

  Mmu(int memSize) {
    data = new uint8_t[memSize];
  }

  virtual ~Mmu() {
    delete[] data;
  }

private:
  uint8_t *data;
};

#endif
