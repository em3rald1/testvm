#ifndef _CPU_H_
#define _CPU_H_
#include "ram.h"
#include "bus.h"
#include "cpuinstructions.h"
#include "ssdmap.h"
#ifdef u8
#undef u8
#endif

typedef unsigned char u8;
typedef unsigned short u16;

class Cpui {
    RAM ram;
    USSD ssd;
    Bus mainBus;
    u16 a = 0;
    u16 x = 0;
    u16 y = 0;
    u8 carryBit = 0;
    u8 zeroBit = 0;
    public:
        Cpui(size_t, size_t);
        u8 fetch();
};

#endif