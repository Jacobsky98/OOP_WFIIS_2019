#pragma once

// licznik poziomow bledow ktore wystapily
class LicznikPoziomow{
public:
    // glosny konstrukor informujacy o wejsciu do danego poziomu bledu
    LicznikPoziomow(){
        licznikPoz++;
        std::cout << "Rozpoczynamy poziom numer " << licznikPoz << ".\n";
    }
    
    // glosny destrukor informujacy o wyjsciu z danego poziomu bledu
    ~LicznikPoziomow(){
        std::cout << "Konczymy poziom numer " << licznikPoz << ".\n";
        licznikPoz--;
    }
private:
    static int licznikPoz; // przechowuje aktualna ilosc bledow (numer)
};

int LicznikPoziomow::licznikPoz = 0;