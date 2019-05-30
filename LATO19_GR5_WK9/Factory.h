#pragma once
#include "NicePrinter.h"


class Factory{
public:
    /*
     szablon ustawiajacy element typu T w fabryce na wartosc obj,
     jezeli flaga jest ustawiona na true, w przeciwnym wypadku 
     zwraca poprzednia zapisana wartosc objektu danego typu 
    */
    template<typename T>
    T base(T obj, bool flaga = true)
    {   
        static T temp;
        if(flaga) 
            temp = obj;
        return temp;
    }

    // szablon zwracajacy element typu T z fabryki
    template<typename T>
    T product()
    {
        return base(T{}, false);
    }   
};

