#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#include "vga.h"
#include "hardware.h"

using namespace emscripten;

VGAController::VGAController(Memory *_memory) : vga_memory(new int32_t[640*480]),
    memory(_memory) {

}

VGAController::~VGAController(){
    delete[] vga_memory;
}

void VGAController::update(){
    
    if ((*memory)[vga_command] == 0){
        (*memory)[vga_response] = 0;
    } else { // vga_command == 1
        if ((*memory)[vga_write] == 0){
            readRect();
        } else { // vga_write == 1
            putRect();
        }

        (*memory)[vga_response] = 1;
    }
}

void VGAController::putRect(){
    int32_t x1 = (*memory)[vga_x1];
    int32_t y1 = (*memory)[vga_y1];
    int32_t x2 = (*memory)[vga_x2];
    int32_t y2 = (*memory)[vga_y2];
    int32_t color = (*memory)[vga_color_write];

    for (int32_t i = x1; i < x2; ++i){
        for (int32_t j = y1; j < y2; ++j){
            vga_memory[i + j*640] = color;
        }
    }
    int32_t r = (color >> 16) & 0xff;
    int32_t g = (color >> 8) & 0xff;
    int32_t b = color & 0xff;
    //ctx.fillStyle = "rgb(" + r + ", " + g + ", " + b + ")";
    //ctx.fillRect(x1, y1, x2-x1, y2-y1);
    EM_ASM({
        vgaCtx.fillStyle = 'rgb(' + $0 + ',' + $1 + ',' + $2 + ')';
        vgaCtx.fillRect($3, $4, $5, $6);
    }, r, g, b, x1, y1, x2-x1, y2-y1);
}

void VGAController::readRect(){
    int32_t x1 = (*memory)[vga_x1];
    int32_t y1 = (*memory)[vga_y1];
    (*memory)[vga_color_read] = vga_memory[x1 + y1*640];
}