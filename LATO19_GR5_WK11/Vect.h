#pragma once
#include <string.h>

// Szablon klasy zamieniajacy elementy klas w zaleznosci do wartosci is_pod
template<typename T, bool is_pod = false>
class swap{
public:
    // funkcja statyczna zmieniajaca dwa elementy typu T
    static void zamiana(T& a, T& b){
        T tmp = a;
        a = b;
        b = tmp;
    }
};

// Wyspecjalizowany szablon klasy zamieniajacy elementy klas dla skomplikowanych typow
template<typename T>
class swap<T, true>{
public:
    // funkcja statyczna zmieniajaca dwa elementy typu T
    static void zamiana(T& a, T& b){
        T tmp;
        size_t rozmiar = sizeof(T);
        memcpy(&tmp, &a, rozmiar);
        memcpy(&a, &b, rozmiar);
        memcpy(&b, &tmp, rozmiar);
    }
};


// Szablon klasy przechowujacy vector klas T
template<typename T>
class Vect{
public:
    // Konstruktor alokujacy miejsce na s obiektow tablicy typu T
    Vect(int s) {
        tablica = new T[s]; 
        m_size = s;
    }

    // Destruktor dealokujacy pamiec
    ~Vect(){
        delete [] tablica;
    }

    // funkcja zwracaja rozmiar vectora
    unsigned int size() const{
        return m_size; 
    }

    // funkcja zwracajaca referencje do i elementu w vectorze
    T& operator[](int i) const{
        return tablica[i];
    }
    
    // funkcja sortujaca przyjmujaca jako argument wskaznik do funkcji porownujacej
    void buble_sort(bool (*porownanie)(const T& a, const T& b))
    {
        for (unsigned int i = 0; i < m_size; i++ )
        {
            for (unsigned int j = i+1; j < m_size; ++j ) 
            {
                if ( porownanie(tablica[i], tablica[j]) )
                    swap<T, is_pod<T>::pod>::zamiana( tablica[i], tablica[j] );
            }
        }
    }


private:
    T* tablica;             // vector elementow typu T
    unsigned int m_size;    // zmienna przechowujaca rozmiar vektora
};