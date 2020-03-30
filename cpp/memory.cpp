#include <emscripten/emscripten.h>
#include <emscripten/bind.h>

#include "memory.h"
#include "hardware.h"

using namespace emscripten;

Memory::Memory() : data(new int32_t[size]), hardware(new int32_t[259]) {
    
}

Memory::~Memory(){
    delete[] data;
    delete[] hardware;
}

void Memory::set(int i, int32_t value){
    data[i] = value;
}

int32_t & Memory::operator[](int i){
    if (i >= SW && i <= spi_receive_data){
        return hardware[i - SW];
    } else {
        return data[i];
    }
}