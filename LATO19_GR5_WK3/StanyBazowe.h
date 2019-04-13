#pragma once

#include "Stan.h"
#include <iostream>
#include <string>
#include <vector>

STATE_TYPE( DostepneSystemy ) {
public:
	// Nie róbcie tego w domu...
	DostepneSystemy(const std::string * tab, unsigned int counter)
		: m_counter(counter)
	{
		m_systList = new std::string[ m_counter ];
		for( unsigned int i = 0; i<m_counter; ++i )
		{
			m_systList[i] = tab[i];
		}
	}
	
	~DostepneSystemy()
	{
		delete[] m_systList;
	}

	virtual void operator()() {
		std::cout << "Program mozna uruchomic na nastepujacych systemach: " << std::endl;
		for ( unsigned int i= 0; i < m_counter; i++ )
			std::cout << "   " << i+1 << ". " << m_systList[i] << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "DostepneSystemy";
	}
	
	virtual void podsumowanie() const {
		return;
	}
	
private:
	std::string * m_systList;
	unsigned int m_counter;
};

STATE_TYPE( Instalacja ) {
public:
	virtual void operator()() {
		std::cout << "Instalacja w toku... " << std::endl;
		std::cout << "OK!" << std::endl;
	}
	
	virtual const char* nazwa() const { 
		return "Instalacja";
	}
	
	virtual void podsumowanie() const {
		return;
	};
};
