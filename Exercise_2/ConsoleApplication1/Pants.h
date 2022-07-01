#pragma once
#include "Clothes.h"
class Pants : public Clothes {
private:
	double lengthLeg;

public:
	Pants();
	Pants(const char* color, const char* size, const double price, const double lengthLeg);

	void printInfo();

	void setLength(const double lengthLeg);
	const double getLength() const;
};