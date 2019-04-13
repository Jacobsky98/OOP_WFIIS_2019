#ifndef BitArray_h
#define BitArray_h

class Bit;

// klasa zawieracja tablice bajtow
class BitArray{
public:
    BitArray(int size, bool var = false);   // tworzy obiekt klasy BitArray zawierajcy size bitow, ustawionych na wartosc var
    Bit operator[](int) const; // pozwala na ustawienie konkretnego bitu oraz wypisanie go
    void print() const; // wypisuje wszystkie bity bit po bicie
    BitArray& operator=(const BitArray& K){
        if(&K == this)
            return *this;
        delete [] bytes_;
        bytes_ = new unsigned char[K.iloscBitow_];
        bytes_ = K.bytes_; // for trzeba przeleciec
        return *this;
    }
    ~BitArray();
private:
    int iloscBitow_; // ilosc wszystkich bitow
    unsigned char* bytes_; // yablica char zawierajca bajt
};


//klasa zawierajaca jeden bajt
class Bit{
public:
    void operator =(bool var); // operator pozwalajacy na ustawienie konkretnego bitu na wartosc var
    Bit(unsigned char* byte, int ktory) : byte_(byte), ktory_(ktory%8) {} // tworzy obiekt klasy bit zawierajacy jeden bajt z klasy BitArray
    operator bool(); // zwraca wartosc bool do przypisywania tej wartosci dla innych zmiennych
private:
    unsigned char* byte_;
    int ktory_;
};

#endif