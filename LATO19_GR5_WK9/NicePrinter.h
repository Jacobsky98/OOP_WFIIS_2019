#pragma once
#include <iostream>
#include <iomanip>


class NicePrinter{
public:
    // konstruktor klasy przyjmujacy za argument maksymalna liczbe cyfr prefiksu
    NicePrinter(int digitsMax)
    {
        maxDigits = digitsMax;
    }

    // szablon wypisywania kolejnych objektow z aktualnym numerem linii
    template<typename T>
    void operator()(T element) const
    {
        std::cout << std::setw( maxDigits ) << actualNum << ": " << element << std::endl;
        actualNum++;
    }

private:
    static int maxDigits;   // zmienna przechowujaca maksymalna ilosc cyfr w celu ladnego wypisywania outputu
    static int actualNum;   // zmienna okreslajaca ktora linia aktualnie jest wypisywanana
};


int NicePrinter::actualNum = 1;
int NicePrinter::maxDigits = 0;