#pragma once
#include <iostream>
#include <string>
#include "PojazdLadowy.h"
#include "PredkoscMaksymalna.h"

class Samochod : public virtual PojazdLadowy{
public:
   
    Samochod(PredkoscMaksymalna& v) : predkoscMax(v) {};
    virtual ~Samochod() = default;
    PredkoscMaksymalna predkoscMaksymalna() const{
        return predkoscMax;
    }
    virtual std::string name() const{
        return "Samochod";
    }
    
    PredkoscMaksymalna& predkoscMax;
    
};