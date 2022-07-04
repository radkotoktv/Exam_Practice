#pragma once
#include "MenuItem.h"
class Food : public MenuItem {
protected:
	bool isLarge;
	bool isVegan;

public:
	Food();
	Food(const char* name, const int quantity, const char* description, const double price, const bool isLarge, const bool isVegan);
	
	void getFoodInfo();

	void setSize(const bool isLarge);
	const bool getSize() const;
	void setVegan(const bool isVegan);
	const bool getVegan() const;
};

