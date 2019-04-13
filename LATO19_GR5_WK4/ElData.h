#ifndef ELData_h
#define ELData_h

#include "Visitor.h"
#include "Data.h"

/* wizytowalny konetener na liczbe typu int */
class IntData final : public Data {
public:
	IntData( int d ) : m_d( d ){}

	/* zmienia zawartosc kontenera */
	void operator<<( int d ) { 
		m_d = d; 
	}

	/* zwraca zawartosc kontenera */
	int getInt() const { 
		return m_d; 
	}

	/* wywoluje funkcje z klasy pochodnej klasy Visitor 
		(PrintingVisitor lub AccumulatingVisitor) */
	void acceptVisitor( Visitor& v) { 
		v.visit( this ); 
	}

private:
	int m_d;
};

/* wizytowalny konetener na liczbe typu float */
class FloatData final : public Data {
public:
	FloatData( float d ) : m_d( d ){}

	/* zmienia zawartosc kontenera */
	void operator<<( float d ) { 
		m_d = d; 
	}

	/* zwraca zawartosc kontenera */
	float getFloat() const { 
		return m_d; 
	}

	/* wywoluje funkcje z klasy pochodnej klasy Visitor (PrintingVisitor lub AccumulatingVisitor */
	void acceptVisitor( Visitor& v) { 
		v.visit( this ); 
	}
private:
	float m_d; 
};

#endif
