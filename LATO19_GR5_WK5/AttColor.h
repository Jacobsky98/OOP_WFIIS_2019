#pragma once

// klasa zarzadzajaca kolorami
class AttColor
{
  public:
  // dostepne opcje kolorow
  enum Option
    {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        GRAY,
        WHITE,
        RESET
    };

    //konstruktor ustawiajacy kolor
    AttColor(Option opt) : optC_(opt) {}

    // metoda zwracaja aktualny kolor
    AttColor::Option getColor() const
    {
        return optC_;
    }

    // metoda ustawiajaca kolor
    void setColor(const Option opt){
        optC_ = opt;
    }

    protected:
      Option optC_; // aktualny kolor

};