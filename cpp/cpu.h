#pragma once

#include "memory.h"
#include "vga.h"

class CPU {
private:
    int iar;
    Memory *memory;
    VGAController *vga;
public:
    CPU(Memory *_memory, VGAController *_vga);
    void executeOp();
    void executeOps(int n);
    bool running;
};