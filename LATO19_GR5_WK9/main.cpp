/* Task: baza 
 * Executable file: baza 
 * 
 * Description: 
 * Funkcje szablonowe w nietypowym zastosowaniu: wyobrazmy sobie projekt,
 * w ktorym chcemy tworzyc stale te same wartosci, ale rozne dla roznych
 * typow. Tym ma sie zajac klasa Factory.
 * 
 * Prosze zworcic uwage ze sama Factory nie jest szablonowa, tylko jej
 * metody.
 * 
 * W rozwiazaniu nalezy skorzystac ze statycznych skladnikow funkcji,
 * oraz z tego ze kazda instancja szablonu to oddzielna funkcja.
 * 
 * Dodatkowo prosze napisac klase NicePrinter z operatorem() jako szablon,
 * ktory bedzie pomocny przy wypisywaniu. 
 * 
 * UWAGA: Do zachowania stalej szerokosci prefiksu z numerem linii 
 * najlatwiej uzyc manipulatora std::setw(int n), znajdujacy sie w <iomanip>:
 * std::cout << std::setw( width ) << numer_do_wypisania << ": " 
 *                                 << text_do_wypisania << std::endl;
 * 
 */ 
 

#include "main.h"
#include <string>


int main(){
    const NicePrinter printer(3); // ustawienie maksymalnej ilosci cyfr w prefiksie
    
    printer( "* dwa typy, pierwsza Fabryka *" );                        //  1: * dwa typy, pierwsza Fabryka *
    Factory pierwsza;
    pierwsza.base<int>( 7 );
    pierwsza.base<float>( 3.14 );
    printer( pierwsza.product<int>() );                                 //  2: 7
    printer( pierwsza.product<float>() );                               //  3: 3.14
    float liczba1 = pierwsza.product<float>();
    printer( liczba1 );                                                 //  4: 3.14

    printer( "* wymiana int, druga Fabryka *" );                        //  5: * wymiana int, druga Fabryka *
    Factory druga;
    druga.base<int>(9);
    printer( druga.product<int>() );                                    //  6: 9
    printer( druga.product<float>() );                                  //  7: 3.14

    printer( "* pierwsza Fabryka *" );                                  //  8: * pierwsza Fabryka *
    printer( pierwsza.product<int>() );                                 //  9: 9
    
    printer( "* nowy typ, pierwsza Fabryka *" );                        // 10: * nowy typ, pierwsza Fabryka *
    pierwsza.base<std::string>( std::string("Napis") );
    std::string text1 = pierwsza.product<std::string>();
    printer( text1 );                                                   // 11: Napis
    std::string text2 = pierwsza.product<std::string>();
    printer( text2 );                                                   // 12: Napis
    
    printer( "* pierwsza i druga Fabryka *" );                          // 13: * pierwsza i druga Fabryka *
    pierwsza.base( std::string("Cos innego") );
    std::string text3 = druga.product<std::string>();                    
    printer( text3 );                                                   // 14: Cos innego
    
    text3.append(" teraz");
    printer( text3 );
    printer( druga.product<std::string>() );
    
    const std::string & text4 = druga.product<std::string>();
    printer( text4 );
    pierwsza.base( std::string("Cos innego2") );
    return 0;
}


/* Output: 
  1: * dwa typy, pierwsza Fabryka *
  2: 7
  3: 3.14
  4: 3.14
  5: * wymiana int, druga Fabryka *
  6: 9
  7: 3.14
  8: * pierwsza Fabryka *
  9: 9
 10: * nowy typ, pierwsza Fabryka *
 11: Napis
 12: Napis
 13: * pierwsza i druga Fabryka *
 14: Cos innego
*/ 
