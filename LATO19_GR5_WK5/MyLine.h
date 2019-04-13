#pragma once
#include <iostream>
#include <string>

#include "AttColor.h"
#include "Printable.h"


class MyLine : public AttColor, public Printable
{
public:
    // konstruktor domyslny klasy MyLine
    MyLine() = default;
    
    // konstruktor domyslny klasy MyLine
    MyLine(char znak, int dlugosc, AttColor::Option opt)
    :   AttColor(opt),
        znak_(znak),
        dlugosc_(dlugosc)
        {}

    // metoda zwracaja zadana dlugosc znakow
    virtual std::string rawString() const{
        return std::string(dlugosc_, znak_);
    }
    // metoda ustawiajaca dlugosc linii
    void setLength(const int dl){
        dlugosc_ = dl;
    }
    // metoda ustawiaja znak linii
    void setChar(const char znak){
        znak_ = znak;
    }
    
private:
    char znak_;     // znak linii
    int dlugosc_;   // dlugosc linii


};