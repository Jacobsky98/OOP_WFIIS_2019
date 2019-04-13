// Prosze napisac klase Number, ktora bedzie przechowywac nazwe oraz
// wartosc. Klasa moze przechowywac jedynie wartosci z wczesniej
// ustawionego zakresu. Klasa ma glosne konstruktor i destruktor.

// Prosze zwrocic uwage na zarzadzanie pamiecia. Tak aby nie bylo
// wyciekow, ani podwojnego usuwania obiektow.

#include "Main.h"
#include <iostream>

int main ()
{
	Number::SetRange(1, 6);

	try {
		Number* lowest = Number::Factory("lowest", 2.2);      // Manufacturing number 2.2
		lowest->Print();				                      // lowest = 2.2
		lowest->Print();				                      // lowest = 2.2

		Number* middle = Number::Factory("middle", 5.4);      // Manufacturing number 5.4
		middle->Print();				                      // middle = 5.4

		Number* highest = Number::Factory("highest", 8.3);    // Manufacturing number 8.3 \n Huston we've got problem
		highest->Print();

		std::cout << "END OF NUMBERS" << std::endl;
	}
	catch (const OutOfRange exception)
	{
		std::cout << "Huston we've got problem" << std::endl;
		std::cout << exception << std::endl;                  // Number named: highest has value 8.3 which is outside of the allowed range: [1, 6]
		std::cout << "Cleaning up" << std::endl;
	}

	std::cout<<"Good job, man!"<<std::endl;
}

/* Output:
Manufacturing number 2.2
lowest = 2.2
lowest = 2.2
Manufacturing number 5.4
middle = 5.4
Manufacturing number 8.3
Huston we've got problem
Number named: highest has value 8.3 which is outside of the allowed range: [1, 6]
Cleaning up
Delete numbers...
Destroying number 2.2
Destroying number 5.4
Destroying number 8.3
Good job, man!
*/
