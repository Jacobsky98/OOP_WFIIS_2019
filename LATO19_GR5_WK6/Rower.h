#pragma once
#include <iostream>
#include <string>
#include "PojazdLadowy.h"

class Rower : public PojazdLadowy{
public:
    virtual std::string name() const{
        return "Rower";
    }
    virtual ~Rower() = default;
};