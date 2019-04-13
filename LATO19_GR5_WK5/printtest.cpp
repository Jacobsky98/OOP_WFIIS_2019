/* Dziedziczenie wielokrotne: Printer
*
* Do napisania sa trzy glowne klasy: MyText (przechowujaca tekst i opcje 
* formatowania i kolorowania), MyLine (przechowujaca styl, dlugosc i kolor
* linii), MyPrinter - wypisze ladnie sformatowany kod, wycentrowany.
* 
* Nalezy dopisac kilka klas bazowych, dzieki ktorym bedzie mozna uzyc 
* mechanizmu polimorfizmu do obslugi danych. Klasa MyPrinter jest prawie gotowa,
* nalezy dopisac jedynie wnetrze funkcji print. Pozostalej czesci pliku 
* nie mozna zmieniac.
*
* Zadania do zrobienia w domu:
* ** mozliwosc ustawienia dwoch opcji formatowania, 
*    np. AttFormat::BOLD | AttFormat::UNDERLINED;
* ** zaimplementowac numerowanie linii. 
*/

#include "MyText.h"
#include "MyLine.h"
#include "MyPrinter.h"
#include <iostream>

int main()
{
	const AttFormat *ptrFor;
	const AttColor *ptrCol;

	////////////////////////////////////////////////////////////////////
	MyLine line('*', 60, AttColor::MAGENTA);

	ptrCol = &line;
	// ptrFor = &line; -> blad kompilacji!!!

	std::cout << MyPrinter::controlSeq(ptrCol->getColor());
	std::cout << line.rawString();
	std::cout << MyPrinter::resetSeq() << std::endl;

	////////////////////////////////////////////////////////////////////
	MyText text("ADAM MICKIEWICZ", AttFormat::BOLD, AttColor::GREEN);

	ptrCol = &text;
	ptrFor = &text;

	std::cout << MyPrinter::controlSeq(ptrFor->getFormat())
			  << MyPrinter::controlSeq(ptrCol->getColor());
	std::cout << std::string(22, ' ') << text.rawString() << std::endl;
	std::cout << line.rawString() << MyPrinter::resetSeq() << std::endl;

	////////////////////////////////////////////////////////////////////
	MyPrinter printer(60);

	line.setLength(50);
	line.setChar('-');
	line.setColor(AttColor::GRAY);
	printer.print(line);

	text.setFormat(AttFormat::RESET);
	text.setColor(AttColor::WHITE);
	text.setText("Litwo, Ojczyzno moja! Ty jestes jak zdrowie:");
	printer.print(text);
	text.setText("Ile Cie trzeba cenic, ten tylko sie dowie,");
	printer.print(text);

	printer.print(line);

	text.setColor(AttColor::RED);
	text.setText("Kto Cie stracil. Dzis pieknosc Twa w calej ozdobie");
	printer.print(text);
	text.setText("Widze i opisuje, bo tesknie po Tobie.");
	printer.print(text);

	printer.print(line);
	* /
		return 0;
}

/* Output (oczywiscie pokolorowany)
************************************************************
                      ADAM MICKIEWICZ
************************************************************
     --------------------------------------------------     
        Litwo, Ojczyzno moja! Ty jestes jak zdrowie:        
         Ile Cie trzeba cenic, ten tylko sie dowie,         
     --------------------------------------------------     
     Kto Cie stracil. Dzis pieknosc Twa w calej ozdobie     
           Widze i opisuje, bo tesknie po Tobie.            
     --------------------------------------------------     
*/
