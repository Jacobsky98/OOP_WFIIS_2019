#pragma once

// Szablon strukty zawierajacy informacje o typie klasy (wartosc pod flase dla ProstaKlasa, true dla SkomplikowanaKlasa)
template<typename T> struct is_pod{
  const static bool pod = false;
};

#include "Vect.h"

