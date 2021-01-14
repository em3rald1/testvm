#ifndef _SSD_H_
#define _SSD_H_
#include <iostream>
#include <vector>

typedef unsigned char u8;

using std::vector;

class SSD {
    vector<u8> data;
    public:
        SSD(size_t);
        void write(unsigned int, u8);
        u8 read(unsigned int);
};

#endif