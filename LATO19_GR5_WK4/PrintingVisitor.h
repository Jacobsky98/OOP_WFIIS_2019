#pragma once
#include "Visitor.h"
#include "Data.h"
class PrintingVisitor final : public Visitor{
public:
    /* Funkcje wypisujace kontenery klas pochodnych klasy Data */
    virtual void visit(FloatData* K){
        std::cout << ' ' << K->getFloat();
    }
    virtual void visit(IntData* K){
        std::cout << ' ' << K->getInt();
    }
};