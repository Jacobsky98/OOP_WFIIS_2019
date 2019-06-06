// Prosze napisac szablon Power, ktory na etapie kompilacji oblicza
// potege danej liczby. Podstawy poteg jak i wykladniki sa liczbami
// calkowitymi, ktore moga przyjmowac wartosci dodatnie i ujemne. W
// przypadku podania wykladnika potegi rownego conajmniej 10, powinien
// pojawic sie blad kompilacji z informacja, ze wykladnik jest zbyt
// duzy. Wynik 

// UWAGA!
// Wszystkie obliczenia powinny wykonywac sie na etapie
// kompilacji. Jezeli obliczenia nie beda wykonywane w czasie
// kompilacji, rozwiazanie bedzie nie na temat, a wiec zostanie
// ocenione na 0 punktow.

// UWAGA!
// Po odkomentowaniu ERROR (kompilacja z -DERROR) powinien pojawic sie 
// blad kompilacji, ktory w swoim komunikacie bedzie zawieral tresc:
// "TooLargeExponentMustBeSmallerThan10".

// Cwiczenie do domu: Sprobowac zrobic to za pomoca wyrazenia constexpr
// zamiast na szablonach.

#include "main.h"
#include <iostream>
#include <iomanip>

// #define ERROR

// test czy obliczanie trwa faktycznie w trakcie kompilacji:
template<int POW> class TEST{};
double power_fun(int x, int e){ return e ? x * power_fun(x, e-1) : 1.0; }

int test_fun()
{
	const int x = Power< 3, 4>::value;
	const int z = power_fun(3, 4);
	TEST<x> a;  // <- to kompilator powinien lyknac
//  TEST<z> b;  // <- a to sie nie skompiluje
	
	return 0;
}

int main ()
{
	std::cout << "Values\n";
	std::cout << "3^4    = " << std::setw(10) << Power< 3, 4>::value << "\n";
	std::cout << "3^(-4) = " << std::setw(10) << Power< 3,-4>::value << "\n";
	std::cout << "4^0    = " << std::setw(10) << Power< 4, 0>::value << "\n";
	std::cout << "(-2)^3 = " << std::setw(10) << Power<-2, 3>::value << "\n";

#ifdef ERROR
	std::cout << "1^10   = " << std::setw(10) << Power< 1,15>::value << "\n";
#endif

	return test_fun();
}

// Wynik dzialania programu:
/*
Values
3^4    =         81
3^(-4) =  0.0123457
4^0    =          1
(-2)^3 =         -8
*/
