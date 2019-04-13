#pragma once
#include <iostream>
#include <vector>


class Number{
public:
    Number(const char* n, double l);
    virtual ~Number(){
        std::cout << "\t\t\tDestroying number " << liczba << std::endl;
           

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
    static std::vector <Number*> tab;
};

int Number::przedzialDol = 0;
int Number::przedzialGora = 0;
std::vector <Number*> Number::tab;

void Number::Print() const{
    std::cout << nazwa << " = " << liczba << std::endl;
}

void Number::SetRange(int d, int g){
    przedzialDol = d;
    przedzialGora = g;
}

void Number::DeleteAll(){
    std::cout << tab.size() << '\n';
    for(unsigned int i = 0; i < tab.size(); i++)
        tab.erase(tab.begin() + i);
}


Number* Number::Factory(const char* n, double l){
    std::cout << "Manufacturing number " << l << std::endl;

    Number* tmp = new Number(n, l);
    
    return tmp;
        
}










class OutOfRange{
public:
    OutOfRange(Number* wsk, const char* n, double liczba, int przedzialDol, int przedzialGora)
        : wskaznik(wsk), name(n), liczbaOut(liczba), przedzialDolOut(przedzialDol), przedzialGoraOut(przedzialGora) {}

    friend std::ostream& operator<<(std::ostream& o, const OutOfRange& K);
    ~OutOfRange();
private:
    Number* wskaznik;
    std::string name;
    double liczbaOut;
    int przedzialDolOut;
    int przedzialGoraOut;

};

std::ostream& operator<<(std::ostream& o, const OutOfRange& K){
    o << "Number named: " << K.name << " has value " << K.liczbaOut 
        << " which is outside of the allowed range: [" << K.przedzialDolOut << ", " 
        << K.przedzialGoraOut << ']';
    return o;
}


OutOfRange::~OutOfRange(){
    std::cout << "Destroying number " << liczbaOut << std::endl;
    wskaznik->DeleteAll();
}


Number::Number(const char* n, double l)
: nazwa(n), liczba(l) 
{
    tab.push_back(this);
    if((l > przedzialGora) || (l < przedzialDol))
        throw OutOfRange(this, n, l, Number::przedzialDol, Number::przedzialGora);

}
