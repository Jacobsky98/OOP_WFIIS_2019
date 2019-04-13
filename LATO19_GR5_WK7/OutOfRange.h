#pragma once
#include <iostream>

class Number;



class OutOfRange{
public:
    OutOfRange(Number* wsk, const char* n, double liczba, int przedzialDol, int przedzialGora)
        : wskaznik(wsk), name(n), liczbaOut(liczba), przedzialDolOut(przedzialDol), przedzialGoraOut(przedzialGora) {}

    friend std::ostream& operator<<(std::ostream& o, const OutOfRange& K);
    ~OutOfRange();
private:
    Number* wskaznik;
    std::string name;
    double liczbaOut;
    int przedzialDolOut;
    int przedzialGoraOut;

};

std::ostream& operator<<(std::ostream& o, const OutOfRange& K){
    o << "Number named: " << K.name << " has value " << K.liczbaOut 
        << " which is outside of the allowed range: [" << K.przedzialDolOut << ", " 
        << K.przedzialGoraOut << ']';
    return o;
}

OutOfRange::~OutOfRange(){
    std::cout << "Destroying number " << liczbaOut << std::endl;
    wskaznik->DeleteAll();
}