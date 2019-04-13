#pragma once
#include <math.h>
#include <iostream>
#include "Ksztalt.h"
class Trojkat : public Ksztalt{
public:
    Trojkat() = default;

    //konstruktor bokow trojkata
    Trojkat(double a, double b, double c) : a_(a), b_(b), c_(c) {};
    
    // wypisuje trojkat z wymiarami bokow do strumienia
    virtual void wypisz(std::ostream& o = std::cout) const{
        o << "Trojkat o bokach: " << a_
        <<' '<<b_<<' '<<c_<<'\n';
    }

    // zwraca pole powierzchni trojkata
    virtual double polePow() const{
        double x = (a_ + b_ + c_) / 2.0;
        return sqrt(x*(x-a_)*(x-b_)*(x-c_));
    }
private:
    double a_;
    double b_;
    double c_;
};

