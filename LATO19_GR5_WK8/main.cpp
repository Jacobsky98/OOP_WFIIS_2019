// Nalezy napisac dwie klasy: LicznikPoziomow, z glosnym konstruktorem i
// destruktorem, ktory bedzie nas informowac o rozpoczeciu i zakonczeniu
// obliczen na danym poziomie.  

// Druga klasa jest klasa wyjatku, ktora bedzie rzucana w momencie gdy 
// obliczenia sie nie udzadza. Klase nalezy zaimplmentowac tak, aby mozna 
// bylo odtworzyc kolejnosc pojawiania sie wyjatkow. 

// UWAGA: Prosze zauwazyc ze wyrzucane sa wkazniki. To powinno pozwolic 
// na "przechowanie" jednego wyjatku w drugim. Jednoczenie nalezy zadbac 
// o potencjalne wycieki pamieci z tym zwiazane.
// Prosze dodatkowo napisac handler do obslugi tych wyjatkow.

// Mozna korzystac ze wszelkich dobrodziejstw biblioteki standardowej.

#include "main.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

struct Obliczenia{   
    static void Start(){
        try {           
            cout << "Zaczynamy obliczenia." << endl;
            Obliczenia::Poziom_1();
        } catch (std::runtime_error* err) {
            throw new Calc_error(err, "Wyjatek w Obliczenia::Start()", __FILE__, __LINE__);
        }
    }
    
    static void Poziom_1(){
        try {
            LicznikPoziomow licznik;
            Obliczenia::Poziom_2();
        } catch (std::runtime_error* err) {          
            throw new Calc_error(err, "Wyjatek w Obliczenia::Poziom_1()", __FILE__, __LINE__);
        }
    }
    
    static void Poziom_2(){
        try {
            LicznikPoziomow licznik;
            Obliczenia::NajglebszyPoziom();
        } catch (std::runtime_error* err) {          
            throw new Calc_error(err, "Wyjatek w Obliczenia::Poziom_2()", __FILE__, __LINE__);
        }
    }
            
    static void NajglebszyPoziom(){
        cout << "Najglebszy poziom." << endl;
        throw new std::runtime_error("Pojawil sie problem na najglebszym poziomie!");
    }
   
};

int main(int argc, char** argv) {
    try {
        Obliczenia::Start(); 
    } catch (...) {
        Calc_error::handler();
    }
}

/*
Zaczynamy obliczenia.
Rozpoczynamy poziom numer 1.
Rozpoczynamy poziom numer 2.
Najglebszy poziom.
Konczymy poziom numer 2.
Konczymy poziom numer 1.
 Zlapano wyjatek:
 -- z powodu: Wyjatek w Obliczenia::Start(), [plik = main.cpp, linia = 30]
 -- z powodu: Wyjatek w Obliczenia::Poziom_1(), [plik = main.cpp, linia = 39]
 -- z powodu: Wyjatek w Obliczenia::Poziom_2(), [plik = main.cpp, linia = 48]
 -- z powodu: Pojawil sie problem na najglebszym poziomie!
*/
