#pragma once
#include <string>
#include "Stan.h"
#include "StanyBazowe.h"

class MaszynaStanow{
public:
    MaszynaStanow(){
        aktualny_ = 0;
        iloscStanow_ = 0;
    }
    void operator+=(Stan* K){
        if(K->nazwa() == "Podsumowanie"){
            for(int i = 0; i < iloscStanow_; i++){
                if(stany_[i]->nazwa() == "ZbieranieDanych")
                    K->email_ = stany_[i]->getMail();
            }
        }
        stany_[iloscStanow_] = K;
        iloscStanow_++;
    }

    void start(){
        std::cout << "Rozpoczynamy dzialanie maszyny stanow!\n";
        aktualnyStan_ = stany_[aktualny_];
    }
    Stan& operator() (){
        return *stany_[aktualny_];
    }

    void operator++(){
        ++aktualny_;
        aktualnyStan_ = stany_[aktualny_];
    }
    void operator--(){
        --aktualny_;
        aktualnyStan_ = stany_[aktualny_];
    }

    Stan* stany_[10];
    // static 
    int iloscStanow_;
    Stan* aktualnyStan_;
    // static 
    int aktualny_;
};

// int MaszynaStanow::aktualny_ = 0;
// int MaszynaStanow::iloscStanow_ = 0;


std::ostream& operator<<(std::ostream& o, const MaszynaStanow& K){
    for(int i = 0; i < K.iloscStanow_; i++){
        if(K.stany_[i]->nazwa() == K.aktualnyStan_->nazwa()){
            o << '>' << K.stany_[i]->nazwa() << '<'; 
        }
        
        else{
            o << K.stany_[i]->nazwa();
        }
        o << ' ';
    }
    
    return o;
}