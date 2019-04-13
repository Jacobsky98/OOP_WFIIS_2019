#pragma once
#include "Ksztalt.h"

class Kolo : public Ksztalt{
public:
    Kolo() = default;

    // konstruktor tworzacy kolo o promieniu r
    Kolo(double r) : r_(r) {};

    // wypisuje kolo z dlugoscia promienia do strumienia
    virtual void wypisz(std::ostream& o = std::cout) const{
        o << "Kolo o promieniu: " << r_ << '\n';
    }

    // zwraca pole powierzchni kola
    virtual double polePow() const{
        return r_*r_*3.1415;
    }

private:
    double r_;

};

