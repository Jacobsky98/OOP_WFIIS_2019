#include <iostream>
#include "BitArray.h"

BitArray::BitArray(int size, bool var){
    int size_;
    if((size/ 8.0) > size/8)
        size_ = size/8 + 1;
    else
        size_ = size/8;
    iloscBitow_ = size;
    bytes_ = new unsigned char[size_];
    for(int i = 0; i < size_; i++){
        if(var)
            bytes_[i] = 0xFF;
        else
            bytes_[i] = 0;
    }
}


BitArray::~BitArray(){
    // delete [] bytes_;
}

Bit BitArray::operator [](int poz) const{
    return Bit(bytes_+(poz/8), poz);
}


void BitArray::print() const{
    for(int i = iloscBitow_-1; i >= 0; i--){
        if(bytes_[i/8] & ( 1 << (i%8)))
            std::cout << "1";
        else
             std::cout << "0";
        if(i % 8 == 0)
            std::cout << " <-" << i << ' ';
    }
}





// Bit


void Bit::operator=(bool var){
    if(var){
        *byte_ |= 1 << ktory_;
    }
    else{
        *byte_ &= ~(1<< ktory_);
    }
}

Bit::operator bool(){
    if(static_cast<bool>( *byte_ & (1 << ktory_)))
        return true;
    else
        return false;
}
