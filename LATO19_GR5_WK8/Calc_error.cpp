#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Calc_error.h"


Calc_error::Calc_error(std::runtime_error* err, std::string napis, std::string fname , int l) 
    : std::runtime_error(*err), name(napis), fileName(fname), line(l)
{
    next = err;

}

void Calc_error::handler(){
    Calc_error* previousError;
    std::cout << " Zlapano wyjatek:\n";
    try
    {
        throw;
    }
    catch(Calc_error* err)
    {
        while(err->getLine() != 0)
        {   
            
            std::cout << " -- z powodu: " << err->getName() << ", [plik = " << err->getFileName() << ", linia = " << err->getLine() << "]\n";
            
            if(dynamic_cast<Calc_error*>(err->getNextError()))
            {
                previousError = err;
                err = dynamic_cast<Calc_error*>(err->getNextError());
                delete previousError;
            }
            else
            {   
                previousError = err;
                std::cout << " -- z powodu: " << err->getNextError()->what() << "\n";
                delete previousError;
                delete err->getNextError();
                break;

            }
            

        }
    }
        
}