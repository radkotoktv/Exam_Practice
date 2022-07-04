#pragma once
#include "MenuItem.h"
enum class GlassType {
	GLASS,
	JUG,
	BOTTLE
};
class Drink : public MenuItem {
protected:
	GlassType glassType;

public:
	Drink();
	Drink(const char* name, const int quantity, const char* description, const double price, GlassType glassType);

	void getDrinkInfo();

	void setGlass(const GlassType glassType);
	GlassType getGlass() const;
};

