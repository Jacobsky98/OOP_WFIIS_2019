#pragma once
#include <iostream>
#include <vector>
#include "OutOfRange.h"

class Number{
public:
    Number(const char* n, double l);
    virtual ~Number(){
        std::cout << "Destroying number " << liczba << std::endl;
           

    }
    void Print() const;
    static void SetRange(int d, int g);
    void DeleteAll();
    static Number* Factory(const char* n, double l);
private:
    std::string nazwa;
    double liczba;
    static int przedzialDol;
    static int przedzialGora;
    std::vector <Number*> tab;
};

int Number::przedzialDol = 0;
int Number::przedzialGora = 0;

void Number::Print() const{
    std::cout << nazwa << " = " << liczba << std::endl;
}

void Number::SetRange(int d, int g){
    przedzialDol = d;
    przedzialGora = g;
}

void Number::DeleteAll(){
    // for(int i= 0; i < tab.size(); ++)
    //     tab.erase(tab.begin+i);    
}


Number* Number::Factory(const char* n, double l){
    std::cout << "Manufacturing number " << l << std::endl;

    Number* tmp = new Number(n, l);
    
    return tmp;
        
}


Number::Number(const char* n, double l)
: nazwa(n), liczba(l) 
{
    tab.push_back(this);
    if((l > przedzialGora) || (l < przedzialDol))
        throw OutOfRange(this, n, l, Number::przedzialDol, Number::przedzialGora);

}
