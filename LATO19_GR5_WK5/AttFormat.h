#pragma once

// klasa zarzadzajaca formatami wyswietlanego tekstu
class AttFormat
{
  public:
  // dostepne opcje formatowania
  enum Option
    {
        BOLD,
        DIM,
        UNDERLINED,
        RESET
    };
    // konstruktor klasy AttFormat
    AttFormat(Option opt) : optF_(opt) {}
    
    // metoda zwracaja aktualnie ustawiona opcje formatowania
    AttFormat::Option getFormat() const{
        return optF_;
    }

    // metoda ustawiaja opcje formatowania
    void setFormat(const Option opt){
      optF_ = opt;
    }
  protected:
    Option optF_; // ustawiona opcja formatowania
};
