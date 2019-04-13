#pragma once

/* Klasy zdefiniowane w ElData.h */
class IntData;
class FloatData;

/* klasa pozwalajca na odwiedzanie konterenow pochodnych klasy Data */
class Visitor{
public:
    /* Obydwie funckje wywoluja dany visitor z klas pochodnych 
        klasy visitor dla odpowiedniego typu klasy pochodnej klasy Data */
    virtual void visit(IntData* K) = 0;
    virtual void visit(FloatData* K) = 0;
};