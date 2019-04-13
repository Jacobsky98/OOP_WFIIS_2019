#pragma once
#include <iostream>

class PredkoscMaksymalna{
public:
    PredkoscMaksymalna() = default;
    PredkoscMaksymalna(double v) : vMax(v) {}
    friend std::ostream& operator<<(std::ostream& o, const PredkoscMaksymalna& p);

    virtual ~PredkoscMaksymalna() = default;
    double vMax;


};

std::ostream& operator<<(std::ostream& o, const PredkoscMaksymalna& p){
        o << p.vMax;
        o << "km/h";
        return o;
}