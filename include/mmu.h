#ifndef MMU_H_
#define MMU_H_

#include <cinttypes>

class Mmu {
public:
 virtual uint8_t fetch(uint16_t offset) = 0;
 virtual void store(uint8_t data, uint16_t addr) = 0;
};

#endif
