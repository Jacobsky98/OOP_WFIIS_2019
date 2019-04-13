#pragma once
#include <iostream>
#include <string>
#include "Pojazd.h"

class Motorowka : public virtual Pojazd{
public:
    Motorowka(PredkoscMaksymalna v) : predkoscMax(v) {};
    virtual ~Motorowka() = default;
    PredkoscMaksymalna predkoscMaksymalna() const{
        return predkoscMax;
    }
    virtual std::string name() const{
        return "Motorowka";
    }
    PredkoscMaksymalna predkoscMax;
};