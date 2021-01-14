#include <ssdmap.h>

bool includes(u8 data, vector<u8> vect) {
    bool in = false;
    for(int i = 0; i < vect.size(); i++) {
        if(vect[i] == data) in = true;
    }
    return in;
}

USSD::USSD(size_t s) : ssd(s) {
    
}

vector<u8> USSD::readFile(FilePointer pointer) {
    vector<u8> fileData;
    bool found = false;
    AddressPointer eofPointer;
    for(int i = pointer.point; i < MAX_FILE_SIZE+pointer.point; i++) {
        if(found) continue;
        if(this->read(i) == eof[6] && this->read(i-1) == eof[5] && this->read(i-2) == eof[4] && this->read(i-3) == eof[3] && this->read(i-4) == eof[2] && this->read(i-5) == eof[1] && this->read(i-6) == eof[0]) {
            found = true;
            eofPointer.address = i-6;
        }
    }
    for(int i = pointer.point; i < eofPointer.address; i++) {
        fileData.push_back(this->read(i));
    } 
    return fileData;
}

AddressPointer USSD::getEOF(FilePointer pointer) {
    bool found = false;
    AddressPointer eofPointer;
    for(int i = pointer.point; i < MAX_FILE_SIZE+pointer.point; i++) {
        if(found) continue;
        if(this->read(i) == eof[6] && this->read(i-1) == eof[5] && this->read(i-2) == eof[4] && this->read(i-3) == eof[3] && this->read(i-4) == eof[2] && this->read(i-5) == eof[1] && this->read(i-6) == eof[0]) {
            found = true;
            eofPointer.address = i-6;
        }
    }
    return eofPointer;
}

void USSD::writeFile(FilePointer file, vector<u8> data) {
    AddressPointer eofPointer = this->getEOF(file);
    if(data.size() + file.point > eofPointer.address) {
        for(int i = file.point; i < eofPointer.address; i++) {
            this->write(i, data[i-file.point]);
        }
    } else {
        for(int i = file.point; i < data.size() + file.point; i++) {
            this->write(i, data[i-file.point]);
        }
    }
}

void USSD::setEOF(FilePointer file, AddressPointer rel) {
    for(int i = (file.point+rel.address)-6; i < rel.address + file.point; i++) {
        this->write(i, eof[i-(file.point+rel.address)]);
    }
}

void USSD::write(unsigned int a, u8 x) {
    this->ssd.write(a, x);
}

u8 USSD::read(unsigned a) {
    return this->ssd.read(a);
}