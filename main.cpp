#include <iostream>
#include "config.h"
#include "cpu6502.h"

using namespace std;

int main() {
    Cpu6502 cpu(nullptr, nullptr);
    cout << "NESEMU version: " << NESEMU_VERSION_MAJOR \
         << "." << NESEMU_VERSION_MINOR << endl;
    cpu.power(true);
}
