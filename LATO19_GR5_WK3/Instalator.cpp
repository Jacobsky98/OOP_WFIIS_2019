/* Celem zadania jest zaimplementowanie prostej maszyny stanów. 
 * W naszym wypadku bedzie odpowiadała ona za okno instalatora,
 * ktory zbierze podstawowe informacje i uruchomi instalacje.
 * Mozna sie w nim przesuwac w przód i w tył (zmiany stanów).
 * Służyć do tego będą operatory: ++ i --. 
 * 
 * Bieżący stan można (zwrócić) za pomocą operatora (). 
 * Stan aktywuje się własnym operatorem (). 
 * 
 * Dodawanie stanów do maszyny będzie odbywać się za pomocą operatora +=.
 * 
 * W pliku BaseStates.hpp znajdują się przygotowane dwa stany, inne dwa stany
 * nalezy przygotowac samemu. 
 * 
 * Proszę zadbać o prawidłowe zarządzanie pamięcią.
 */
 
#include "MaszynaStanow.h"
#include "StanyBazowe.h"
#include <iostream>

int main()
{
	std::string systems[3] = {"Windows", "OS X", "Linux"};
	
	MaszynaStanow m;
	m += new DostepneSystemy(systems, 3);
	m += new ZbieranieDanych("Adres email");
	// Ten stan powinien zebrac inforacje o adresie email i zapisac go
	// Prosze o "zamockowanie" tej sytuacji, tj przyjac ze zostaje wpisany adres Nowak@mail.com
	// std::cint >> adres;    ----->     adres = "Nowak@mail.com";		
	m += new Podsumowanie();
	// W tym stanie wyswietlamy informacje o zebranych danych (np. adres email)
	
	 m.start();	
	m()();
	std::cout << std::endl;
	//-------
	++m;
	std::cout << "Po pierwszej inkrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	++m;
	std::cout << "Po drugiej inkrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	--m;
	std::cout << "Po pierwszej dekrementacji: \n" << "m = " << m << std::endl;
	m()();
	std::cout << std::endl;
	//-------
	++m;
	m()();
	std::cout << std::endl;
	//-------
	m += new Instalacja();
	++m;
	std::cout << "Na koncu: \n" << "m = " << (const MaszynaStanow&)m << std::endl;
	m()();
	
	return 0;
}

/* wynik działania programu:
Rozpoczynamy dzialanie maszyny stanow!
Program mozna uruchomic na nastepujacych systemach: 
   1. Windows
   2. OS X
   3. Linux

Po pierwszej inkrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Po drugiej inkrementacji: 
m = DostepneSystemy ZbieranieDanych >Podsumowanie< 
Podsumowanie: 
 * Adres email = Nowak@mail.com

Po pierwszej dekrementacji: 
m = DostepneSystemy >ZbieranieDanych< Podsumowanie 
Prosze podac dana: Adres email = ?, podano 'Nowak@mail.com'

Podsumowanie: 
 * Adres email = Nowak@mail.com

Na koncu: 
m = DostepneSystemy ZbieranieDanych Podsumowanie >Instalacja< 
Instalacja w toku... 
OK!
*/
