#pragma once
#include "Clothes.h"
class Suit : public Clothes {
public:
	Suit();
	Suit(const char* color, const char* size, const double price);

	void printInfo();

	void setColor(const char* color);
	const char* getColor() const;
	void setSize(const char* size);
	const char* getSize() const;
	void setPrice(const double price);
	double getPrice() const;
};

