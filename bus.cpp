#include <bus.h>

Bus::Bus() {
    this->bus.reserve(32);
}

u8 Bus::get(unsigned short x) {
    return this->bus[x];
}

void Bus::put(unsigned short x, u8 data) {
    this->bus[x] = data;
}