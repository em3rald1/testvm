#ifndef _SSD_MAP_H_
#define _SSD_MAP_H_
#include "ssd.h"

#define MAX_FILE_SIZE 0xffffea

struct FilePointer {
    unsigned long long point;
};

struct AddressPointer {
    unsigned long long address;
};

const vector<u8> eof {0xff, 0xee, 0xaa, 0xfe, 0xef, 0xff, 0x55};

class USSD {
    SSD ssd;
    public:
        USSD(size_t);
        vector<u8> readFile(FilePointer);
        AddressPointer getEOF(FilePointer);
        void writeFile(FilePointer, vector<u8>);
        void setEOF(FilePointer, AddressPointer);
        //void unlinkFile(FilePointer);
        void write(unsigned int, u8);
        u8 read(unsigned int);
};

#endif