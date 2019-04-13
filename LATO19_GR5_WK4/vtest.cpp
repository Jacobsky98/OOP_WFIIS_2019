/* Celem zadania jest implementacja wzorca "wizytujacy" 
   W tym przykladze obiekty, ktore wizytator bedzie odwiedzal sa dwoch typow int lub float zapakowane w odpowiednie klasy.
   Ich implementacje sa zadane. 
   Nalezy napisac implementacje PrintingVisitor i AccumulatingVisitor (+ oczywiscie dodatkowe klasy jesli sa konieczne).
   

   UWAGA: Wizytator musi posiadac implementacje methody visit odpowiednie !!DLA KAZDEJ KONKRETNEJ KLASY!! poniewaz w kazdej z nich dostep do danych odbywa sie za pomoca innej metody.
   
 */

#include <iostream>
#include "ElData.h"
#include "PrintingVisitor.h"
#include "AccumulatingVisitor.h"


int main() {
  FloatData d1( 6.56 );
  IntData d2( 99 );

  PrintingVisitor v1;
  AccumulatingVisitor v2;
  
  d1.acceptVisitor( v1 );
  d2.acceptVisitor( v1 );
  std::cout << std::endl;
  d1 << 0.98;
  d2 << 3;

  d1.acceptVisitor( v1 );
  d2.acceptVisitor( v1 );
  std::cout << std::endl;
  
  d1.acceptVisitor( v2 );
  d2.acceptVisitor( v2 );
  std::cout << std::endl;
  std::cout << v2.getTotalSum() << std::endl;
  std::cout << std::endl;

}
/* wynik
 6.56 99
 0.98 3

3.98


 */
