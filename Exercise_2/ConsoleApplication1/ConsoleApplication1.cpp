#include <iostream>
#include "Briefcase.h"
#include "Pants.h"
#include "Dress.h"
#include "Suit.h"
int main() {
	Suit suit("Red", "XL", 23.43);
	Dress dress("Pink", "XS", 50, 127);
	Pants pants("Black", "L", 100, 120);
	Clothes clothes("Orange", "M", 2);
	Briefcase briefcase;
	briefcase.addClothes(suit);
	briefcase.addClothes(dress);
	briefcase.addClothes(pants);
	briefcase.addClothes(clothes);
	briefcase.printInfo();
}