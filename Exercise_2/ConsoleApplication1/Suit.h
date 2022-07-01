#pragma once
#include "Clothes.h"
class Suit : public Clothes {
public:
	Suit();
	Suit(const char* color, const char* size, const double price);

	void printInfo();
};

