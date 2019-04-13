#pragma once

#include "AttColor.h"
#include "AttFormat.h"
#include "Printable.h"
#include <string>

class MyText : public AttFormat, public AttColor, public Printable
{

  public:
    // konstruktor domyslny klasy MyText
    MyText() = default;

    // konstruktor klasy MyText
    MyText(const std::string tekst, AttFormat::Option optF, AttColor::Option optC)
        : AttFormat(optF),
          AttColor(optC),
          tekst_(tekst)
    {
    }

    // metoda zwracaja tekst
    virtual std::string rawString() const
    {
        return tekst_;
    }

    // metoda ustawiajaca tekst
    void setText(const std::string tekst)
    {
        tekst_ = tekst;
    }

  private:
    std::string tekst_; // ustawiony tekst
};