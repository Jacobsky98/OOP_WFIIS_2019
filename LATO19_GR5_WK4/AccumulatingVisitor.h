#pragma once
#include "Visitor.h"
#include "Data.h"

/* Klasa dodajaca odwiedzajacych gosci z klasy pochodnych Data */
class AccumulatingVisitor final : public Visitor{
public:
    AccumulatingVisitor(){totalSum_ = 0.0;}
    
    /* Funkcje dodajace do totalSum_ wartosc odwiedzajacego konetenera 
        z klas pochodnych klasy Data */
    virtual void visit(FloatData* K) {
        totalSum_ +=  K->getFloat();
    }
    virtual void visit(IntData* K) {
        totalSum_ +=  K->getInt();
    }

    /* Zwraca wartosc aktualnej sumy */
    float getTotalSum() const{
        return totalSum_;
    }
private:
    /* Suma wartosci kontenerow wszystkich wizytujacych klase AccumulatingVisitor */
    float totalSum_;
};