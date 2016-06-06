#include <iostream>
#include "config.h"
#include "cpu.h"

using namespace std;

int main() {
    Cpu cpu(nullptr);
    cout << "NESEMU version: " << NESEMU_VERSION_MAJOR \
         << "." << NESEMU_VERSION_MINOR << endl;
    cpu.power(true);
}
