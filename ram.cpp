#include <ram.h>

RAM::RAM(size_t size) {
    this->data.reserve(size);
}

void RAM::write(unsigned int x, u8 ata) {
    this->data[x] = ata;
}

u8 RAM::read(unsigned int d) {
    return this->data[d];
}