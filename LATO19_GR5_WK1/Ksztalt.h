#pragma once

class Ksztalt{
public:
    // wypisuje figure k
    static void wypisz(const Ksztalt& k){
        k.wypisz();
    }

    // wypisuje (do strumienia) figure z dlugosciami bokow odpowiednio dla danej figury
    virtual void wypisz(std::ostream& o = std::cout) const = 0;
    
    // zwraca pole powierzchni danej figury
    virtual double polePow() const = 0;
    virtual ~Ksztalt() = default;
    
};