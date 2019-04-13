#pragma once
#include <iostream>
#include <string>
class ZbieranieDanych;

class Stan{
public:
    Stan(){
        email_ = "default@mail.com";
    }
    virtual const char* nazwa() const = 0;
    virtual void operator()() {};
    virtual void podsumowanie() const {};
    virtual std::string getMail() const {};
    std::string email_;
};

class ZbieranieDanych : public Stan{
public:
    ZbieranieDanych(){
        adresEmail_ = "default@domain.com";
    };
    ZbieranieDanych(std::string adresEmail){
        adresEmail_ = "Nowak@mail.com";
    }
    virtual void operator()() {
		std::cout << "Prosze podac dana: Adres email = ?, podano '" << adresEmail_ << '\''<< std::endl;
	}
    virtual const char* nazwa() const { 
		return "ZbieranieDanych";
	}
    virtual std::string getMail() const{return adresEmail_;}
    std::string adresEmail_;
};



class Podsumowanie : public Stan{
public:
    Podsumowanie() = default;
    virtual const char* nazwa() const { 
		return "Podsumowanie";
	}
    virtual void operator()() {
        std::cout << "Podsumowanie: \n * Adres email = " << email_ << std::endl;
	}
    
};

#define STATE_TYPE(_state_) class _state_ : public Stan

