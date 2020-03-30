#pragma once

#include <cstdint>

class Memory {
private:
    int32_t *data;
    int32_t *hardware;
    static const size_t size = 16384;
public:
    Memory();
    ~Memory();
    void set(int i, int32_t value);
    int32_t & operator[](int i);
};