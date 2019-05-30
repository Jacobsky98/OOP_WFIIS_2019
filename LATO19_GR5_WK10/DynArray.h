#pragma once
#include <iostream>

template<typename T>
class DynArray{
public:
// Konstruktor alokujacy pamiec dla s elementow typu T
    DynArray(int s)
    : m_size(s)
    {
        m_tab = new T[m_size];
    }

// Konstruktor kopiujacy alokujacy pamiec dla nowej tablicy elementow T do ktorej zostana skopiowane elementy z innego obietu
    DynArray(const DynArray& K)
    : m_size(K.size())
    {
        m_tab = new T[m_size];
        for(int i = 0; i < m_size; i++)
            m_tab[i] = K.m_tab[i];
    }

// Konstruktor alokujacy pamiec dla s elementow typu T i przypisujacy im wartosci z przekazanej tablicy elementow typu T
    DynArray(int s, const T* tab)
    : m_size(s)
    {
        m_tab = new T[m_size];
        for(int i = 0; i < m_size; i++)
            m_tab[i] = tab[i];
    }

// Destruktor, zwalnia pamiec po zaalokowanej wczesniej tablicy m_tab
    ~DynArray()
    {
        delete [] m_tab;
    }

// Operator zwracajacy referencje do i-tego elementu typu T 
    T& operator[](int i) const { return m_tab[i]; }

// Operator wypisujacy elementy tablicy
    friend std::ostream& operator<<(std::ostream& o, const DynArray<T>& K){
        o << "{";
        for(int i = 0; i < K.size() - 1; i++)
            o << "\"" << K[i] << "\",";
        o << "\"" << K[K.size()-1] << "\"";
        o << "}";
        return o;
    }

// Metoda zwracajaca ilosc elementow tablicy
    int size() const { return m_size; }

// Podklasa Iterator ktora pozwala iterowac po elementach tablicy klasy DynArray
    class Iterator{
    public:
    // Konstruktor zapisujacy wskaznik do elementu tablicy m_tab z klasy DynArray
        Iterator(T* K)
        : el(K) {}

    // Operator przypisania nowego wskaznika do iteratora
        Iterator& operator=(T* K){
            return Iterator{K};
        }

    // Operator porownujacy dwa iteratory
        bool operator != (Iterator K){
            if(K.el == el)
                return false;
            return true;
        }
    
    // Operator preinkrementacji elementow tablicy m_tab z klasy DynArray 
        Iterator& operator++()
        {
            ++el;
            return *this;
        }

    //Operator zwracajacy adres elementu tablicy m_tab z klasy DynArray
        T& operator*() const { return *el; }
    
    //Operator zwracajacy wskaznik do elementu tablicy m_tab z klasy DynArray
        T* operator->() const { return el;}
    private:
        T* el;  // zmienna przechowujaca wskaznik do elementu tablicy m_tab z klasy DynArray
    };

// metoda zwracajaca obiekt klasy Iterator zawierajacy pierwszy element tablicy m_tab
    Iterator begin() { return Iterator{m_tab} ;}

// metoda zwracajaca obiekt klasy Iterator zawierajacy ostatni element tablicy m_tab
    Iterator end()  { return Iterator{m_tab + m_size} ;}

private:
    T* m_tab;   // Tablica przechowujaca elementy typu T
    int m_size; // Zmienna przechowujaca ilosc elementow tablicy m_tab
};


// template<typename T>
// std::ostream& operator<<(std::ostream& o, const T& K){
//     return o;
// }