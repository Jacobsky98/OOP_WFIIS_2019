#pragma once
#include <iostream>
#include <string>
#include "PredkoscMaksymalna.h"

class Pojazd : public PredkoscMaksymalna{
public:
    friend std::ostream& operator<<(std::ostream& o, const Pojazd& p);
    virtual std::string name() const = 0;
    virtual ~Pojazd() = default;
};

std::ostream& operator<<(std::ostream& o, const Pojazd& p){
    return o << p.name();
}