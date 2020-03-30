#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#include "memory.h"
#include "cpu.h"
#include "vga.h"

using namespace emscripten;

class Computer {
public:
    Computer();

    Memory memory;
    VGAController vga;
    CPU cpu;
};

Computer::Computer() : memory(), vga(&memory), cpu(&memory, &vga) {

}

// Binding code
EMSCRIPTEN_BINDINGS(my_module) {
    class_<Computer>("Computer")
    .constructor<>()
    .property("memory", &Computer::memory)
    .property("cpu", &Computer::cpu)
    .property("vga", &Computer::vga)
    ;

    class_<Memory>("Memory")
    .constructor<>()
    .function("set", &Memory::set)
    ;

    class_<CPU>("CPU")
    .function("executeOps", &CPU::executeOps)
    .property("running", &CPU::running)
    ;
}
