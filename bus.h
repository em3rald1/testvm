#ifndef _BUS_H_ 
#define _BUS_H_

#include <vector>

using std::vector;

typedef unsigned char u8;

class Bus {
    vector<u8> bus;
    public:
        Bus();
        void put(unsigned short, u8);
        u8 get(unsigned short);
};

#endif