#pragma once
#include "Pojazd.h"
#include "PredkoscMaksymalna.h"
#include "Samochod.h"
#include "Motorowka.h"
#include "Rower.h"

class Amfibia : public Samochod, public Motorowka{
public:
    Amfibia(PredkoscMaksymalna lad, PredkoscMaksymalna woda) : Samochod(lad), Motorowka(woda) {};
    PredkoscMaksymalna predkoscMaksymalna_Lad(){
        return Samochod::predkoscMax;
    }
    PredkoscMaksymalna predkoscMaksymalna_Woda(){
        return Motorowka::predkoscMax;
    }
    virtual std::string name() const{
        return "Amfibia";
    }
    virtual ~Amfibia() = default;

    
};