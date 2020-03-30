#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#include "cpu.h"

using namespace emscripten;

CPU::CPU(Memory *_memory, VGAController *_vga) : iar(0),
    memory(_memory), vga(_vga), running(false) {

}

void CPU::executeOps(int n){
    running = true;
    for (int i = 0; i < n; ++i){
        executeOp();
        vga->update();
        if (!running) break;
    }
}

void CPU::executeOp(){
    int32_t op = (*memory)[iar++];
    int32_t arg1 = (*memory)[iar++];
    int32_t arg2 = (*memory)[iar++];
    int32_t arg3 = (*memory)[iar++];

    switch (op){
        case 0: // halt
            running = false;
            iar -= 4;
            break;
        case 1: // add
            (*memory)[arg1] = (*memory)[arg2] + (*memory)[arg3];
            break;
        case 2: // sub
            (*memory)[arg1] = (*memory)[arg2] - (*memory)[arg3];
            break;
        case 3: // mult
            (*memory)[arg1] = (*memory)[arg2] * (*memory)[arg3];
            break;
        case 4: // div
            (*memory)[arg1] = (*memory)[arg2] / (*memory)[arg3];
            (*memory)[arg1] |= 0;
            break;
        case 5: // cp
            (*memory)[arg1] = (*memory)[arg2];
            break;
        case 6: // and
            (*memory)[arg1] = (*memory)[arg2] & (*memory)[arg3];
            break;
        case 7: // or
            (*memory)[arg1] = (*memory)[arg2] | (*memory)[arg3];
            break;
        case 8: // not
            (*memory)[arg1] = ~(*memory)[arg2];
            break;
        case 9: // sl
            (*memory)[arg1] = (*memory)[arg2] << (*memory)[arg3];
            break;
        case 10: // sr
            (*memory)[arg1] = (*memory)[arg2] >> (*memory)[arg3];
            break;
        case 11: // cpfa
            (*memory)[arg1] = (*memory)[arg2 + (*memory)[arg3]];
            break;
        case 12: // cpta
            (*memory)[arg2 + (*memory)[arg3]] = (*memory)[arg1];
            break;
        case 13: // be
            if ((*memory)[arg2] == (*memory)[arg3]){
                iar = arg1;
            }
            break;
        case 14: // bne
            if ((*memory)[arg2] != (*memory)[arg3]){
                iar = arg1;
            }
            break;
        case 15: // blt
            if ((*memory)[arg2] < (*memory)[arg3]){
                iar = arg1;
            }
            break;
        case 16: // call
            (*memory)[arg2] = iar;
            iar = arg1;
            break;
        case 17: // ret
            iar = (*memory)[arg1];
            break;
        default:
            // Invalid opcode
            running = false;
            break;
    }
}
