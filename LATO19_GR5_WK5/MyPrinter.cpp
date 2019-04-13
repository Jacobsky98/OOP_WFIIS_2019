#include "MyPrinter.h"
#include "MyText.h"
#include "MyLine.h"
#include <iostream>

MyPrinter::MyPrinter(unsigned int width)
	: m_width(width)
{
}

////////////////////////////////////////////////////////////////////////
//  Jedyna metoda klasy MyPrinter ktora powinni Panstwo modyfikowac.  //
////////////////////////////////////////////////////////////////////////
void MyPrinter::print(const Printable &obj) const
{
	if(dynamic_cast<const MyLine*>(&obj)){
		const MyLine* line = dynamic_cast<const MyLine*>(&obj);
		std::cout << MyPrinter::controlSeq( line->getColor() );
		int widthTmp = (m_width - line->rawString().size())/2;
		std::cout << std::string(widthTmp, ' ') << line->rawString();
		std::cout << MyPrinter::resetSeq() << std::endl;
	}
	if(dynamic_cast<const MyText*>(&obj)){
		const MyText* text = dynamic_cast<const MyText*>(&obj);
		std::cout << MyPrinter::controlSeq( text->getFormat() ) 
	          << MyPrinter::controlSeq( text->getColor() );
		int widthTmp = (m_width - text->rawString().size())/2;
		std::cout << std::string(widthTmp, ' ') << text->rawString() << std::endl;
	}
}

////////////////////////////////////////////////////////////////////////
///                                                                  ///
///          ANSI/VT100 TERMINAL OUTPUT CONTROL SEQUENCES            ///
///                                                                  ///
////////////////////////////////////////////////////////////////////////

const char *MyPrinter::resetSeq()
{
	return "\e[0m";
}

// formats: BOLD, DIM, UNDERLINED, RESET
const char *MyPrinter::controlSeq(AttFormat::Option opt)
{
	switch (opt)
	{
	case AttFormat::BOLD:
		return "\e[1m";
	case AttFormat::DIM:
		return "\e[2m";
	case AttFormat::UNDERLINED:
		return "\e[4m";
	default:
		return MyPrinter::resetSeq();
	}
}

// colors: BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, GRAY, WHITE, RESET
const char *MyPrinter::controlSeq(AttColor::Option opt)
{
	switch (opt)
	{
	case AttColor::BLACK:
		return "\e[30m";
	case AttColor::RED:
		return "\e[31m";
	case AttColor::GREEN:
		return "\e[32m";
	case AttColor::YELLOW:
		return "\e[33m";
	case AttColor::BLUE:
		return "\e[34m";
	case AttColor::MAGENTA:
		return "\e[35m";
	case AttColor::CYAN:
		return "\e[36m";
	case AttColor::GRAY:
		return "\e[90m";
	case AttColor::WHITE:
		return "\e[97m";
	default:
		return MyPrinter::resetSeq();
	}
}
