#pragma once

#include "Printable.h"
#include "AttFormat.h"
#include "AttColor.h"

class MyPrinter
{
public:
	MyPrinter(unsigned int width);

	void print(const Printable &obj) const;

public:
	static const char *resetSeq();
	static const char *controlSeq(AttFormat::Option opt);
	static const char *controlSeq(AttColor::Option opt);

private:
	unsigned int m_width;
};
