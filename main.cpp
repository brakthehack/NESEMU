#include <iostream>
#include "Config.h"
#include "cpu/cpu.h"

using namespace std;

int main() {
    Cpu cpu;
    cout << cpu.carry() << endl;
    cout << NESEMU_VERSION_MAJOR << endl;
    cout << "EMU Entry" << endl;
}
