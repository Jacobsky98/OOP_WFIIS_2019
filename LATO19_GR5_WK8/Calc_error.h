#pragma once

class Calc_error : public std::runtime_error{
public:
    // Konstruktor licznika bledow przechowujacy liste jednokierunkowa bledow ktore wystapily
    Calc_error(std::runtime_error* err, std::string napis, std::string fname = "", int l = 0);

    std::string getName() const { return name; } // zwraca nazwe bledu
    std::string getFileName() const { return fileName; }    // zwraca nazwe pliku w ktorym wystepuje blad
    int getLine() const { return line; } // zwraca numer linii w ktorej jest blad w pliku fileName
    std::runtime_error *getNextError() const { return next; } // zwraca wskaznik do nastepnego bledu
    static void handler();  // wypisuje kolejne bledy ktore wystapily wczesniej

private:
    std::string name;   // przechowuje nazwe bledu
    std::string fileName;   // przechowuje nazwe pliku w ktorym wystapil blad
    int line;   // przechowuje numer linii kodu w pliku w ktorym wystapil blad
    std::runtime_error *next;   // przechowuje wskaznik do nastepnego bledu 
};


