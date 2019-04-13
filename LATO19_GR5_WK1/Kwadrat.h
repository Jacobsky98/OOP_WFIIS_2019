#pragma once
#include "Ksztalt.h"

class Kwadrat : public Ksztalt{
public:
    Kwadrat() = default;

    // konstruktor tworzacy kwadrat o boku a
    Kwadrat(double a) : a_(a) {};

    // wypisuje kwadrat z dlugosciami bokow do strumienia 
    virtual void wypisz(std::ostream& o = std::cout) const{
        o << "Kwadrat o boku: " << a_ << '\n';
    }

    // zwraca pole powierzchni kwadratu
    virtual double polePow() const{
        return a_*a_;
    }
private:
    double a_;
};