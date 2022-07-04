#pragma once
#include "Drink.h"
class Alcohol : public Drink {
protected:
	double percentage;

public:
	Alcohol();
	Alcohol(const char* name, const int quantity, const char* description, const double price, GlassType glassType, const double percentage);

	void getAlcoholInfo();

	void setPercentage(const double percentage);
	const double getPercentage();
};

