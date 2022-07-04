#include "Drink.h"
Drink::Drink() {
	this->glassType = GlassType::GLASS;
}
Drink::Drink(const char* name, const int quantity, const char* description, const double price, GlassType glassType) : MenuItem(name, quantity, description, price) {
	this->glassType = glassType;
}
void Drink::getDrinkInfo() {
	getMenuItemInfo();
	std::cout << "Type of glass: ";
	if (this->glassType == GlassType::GLASS) {
		std::cout << "Glass" << std::endl;
	}
	else this->glassType == GlassType::BOTTLE ? std::cout << "Bottle" << std::endl : std::cout << "Jug" << std::endl;
}
void Drink::setGlass(const GlassType glassType) {
	this->glassType = glassType;
}
GlassType Drink::getGlass() const {
	return this->glassType;
}