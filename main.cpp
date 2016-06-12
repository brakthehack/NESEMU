#include <iostream>
#include "cpu6502.h"

using namespace std;

int main() {
    Cpu6502 cpu(nullptr, nullptr);
    cpu.power(true);
}
