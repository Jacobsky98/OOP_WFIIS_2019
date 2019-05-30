// Nalezy napisac prosty szablon  Vect (opakowanie na tablice). 
// Klasa poza funkcja size i operatorem [] ma miec tylko jeszcze jedna 
// publiczna metode: buble_sort (implementacja jest trywialna)
// for ( i = 0; i < N; i++ )
//    for (j = i+1; j < N; ++j ) 
//       if ( porownanie(tablica[j], tablica[i]) )
//          swap( tablica[i], tablica[k] )
//
// Tu uogolnieniem powinna byc mozliwosc podania funkcji porownania (obie sa ponizej).
//
// Funkcja swap powinna istniec w dwoch wariantach: 
//  * dla typow "pod" (Plain Old Data) powinna korzystac z funkcji memcpy:
//        #include <string.h>
//        memcpy(cel, zrodlo, ilosc_bajtow);
//    pozwoli to skopiowac obiekt bit po bicie.
//  * dla skomplikowanych typow (nie "pod") nalezy uzyc obiektu tymczasowego 
//    i jego przypisania kopiujacego. 
// Nie mozna korzystac z bibliotecznej funkcji swap!
// 
// Przygotowano ponizej dwie klasy (w pliku NaszeKlasy.h): 
//  * ProstaKlasa, ktorej obiekty mozna kopiowac za pomoca memcpy;
//  * SkomplikowanaKlasa obiektow, ktorej nie mozna tak kopiowac.
//
// Kompilowac z -Wall -g. 
// Prosze zadbac aby w katalogu znalazl sie tylko jeden plik wykonywalny.

#include "main.h"
#include <iostream>

//----------------------------------------------------------------------
class ProstaKlasa {
public:
    int data;
    
public:
    ProstaKlasa() : data(0) {}
    ProstaKlasa& operator=(int rhs) {
        data = rhs;
        return *this;
    }

private:
    ProstaKlasa& operator=(const ProstaKlasa& rhs) {
        std::cout  << " * Dzialania tego operatora nie chcemy widziec!" << std::endl;
        data = rhs.data;
        return *this;
    }
};

template<> struct is_pod<ProstaKlasa> {
  const static bool pod = true;
};

//----------------------------------------------------------------------
class SkomplikowanaKlasa {
public:
    std::string data;
    
public:
    SkomplikowanaKlasa() : data("") {}
    SkomplikowanaKlasa& operator=(const std::string& rhs) {
        data = rhs;
        return *this;
    }
    
    SkomplikowanaKlasa& operator=(const SkomplikowanaKlasa& rhs) {
        std::cout  << " * Dzialane tego operatora musimy widziec." << std::endl;
        data = rhs.data;
        return *this;
    }
};

//----------------------------------------------------------------------
struct tools {
    template<typename T>
    static bool desc( const T& a, const T& b ) {
        return a.data < b.data;
    }

    template<typename T>
    static bool asc( const T& a, const T& b ) {
        return a.data > b.data;
    }
    
    template<typename Vec>
    static void printVec( const Vec& vec ) {
        for (unsigned index = 0 ; index < vec.size(); ++index )
            std::cout << vec[index].data << ",";
        std::cout << std::endl;
    }    
};

//----------------------------------------------------------------------
int main() {
    using namespace std;
    
    cout << "-----------------------------------------" << std::endl;
    cout << "klasa prosta" << endl;    
    Vect<ProstaKlasa> proste(5);
    proste[0] = 3;
    proste[1] = 1;
    proste[2] = 4;
    proste[3] = 2;
    proste[4] = 5;
    tools::printVec(proste);

    cout << "posortowane od max do min" << endl;
    proste.buble_sort(tools::desc<ProstaKlasa>);
    tools::printVec(proste);

    cout << "posortowane od min do max" << endl;
    proste.buble_sort(tools::asc<ProstaKlasa>);
    tools::printVec(proste);

    cout << "-----------------------------------------" << std::endl;
    cout << "klasa skomplikowana" << endl;
    Vect<SkomplikowanaKlasa> skomplikowane(4);
    skomplikowane[0] = "3";
    skomplikowane[1] = "A";
    skomplikowane[2] = "4";
    skomplikowane[3] = "5555";
    tools::printVec(skomplikowane);

    cout << "po posortowaniu" << endl;
    skomplikowane.buble_sort(tools::desc<SkomplikowanaKlasa>);
    tools::printVec(skomplikowane);
    
}
//----------------------------------------------------------------------
/* wyniki
-----------------------------------------
klasa prosta
3,1,4,2,5,
posortowane od max do min
5,4,3,2,1,
posortowane od min do max
1,2,3,4,5,
-----------------------------------------
klasa skomplikowana
3,A,4,5555,
po posortowaniu
 * Dzialane tego operatora musimy widziec.
 * Dzialane tego operatora musimy widziec.
 * Dzialane tego operatora musimy widziec.
 * Dzialane tego operatora musimy widziec.
 * Dzialane tego operatora musimy widziec.
 * Dzialane tego operatora musimy widziec.
 * Dzialane tego operatora musimy widziec.
 * Dzialane tego operatora musimy widziec.
A,5555,4,3,
*/
