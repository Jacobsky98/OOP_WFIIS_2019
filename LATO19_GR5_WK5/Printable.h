#pragma once 
#include <string>
 // klasa przeznaczona do dziediczenia 
class Printable{
public:
    Printable() = default;
    virtual std::string rawString() const = 0;
    virtual ~Printable() = default;
};