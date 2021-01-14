#ifndef _RAM_H_
#define _RAM_H_
#include <vector>
#include <iostream>

typedef unsigned char u8;

using std::vector;
using std::cerr;

class RAM {
    vector<u8> data;
    public:
        RAM(size_t);
        void write(unsigned int, u8);
        u8 read(unsigned int);
};

#endif