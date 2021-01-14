#include <ssd.h>

SSD::SSD(size_t s) {
    this->data.reserve(s);
}

void SSD::write(unsigned int x, u8 d) {
    this->data[x] = d;
} 

u8 SSD::read(unsigned int x) {return this->data[x];}