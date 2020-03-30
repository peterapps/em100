#pragma once

#include "memory.h"

class VGAController {
private:
    int32_t *vga_memory;
    Memory *memory;

    void putRect();
    void readRect();
public:
    VGAController(Memory *_memory);
    ~VGAController();
    void update();
};