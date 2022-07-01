#pragma once
#include "Clothes.h"
class Dress : public Clothes {
private:
	double lengthDress;

public:
	Dress();
	Dress(const char* color, const char* size, const double price, const double lengthDress);

	void printInfo();

	void setLength(const double lengthDress);
	const double getLength() const;
};
