#include "Food.h"
Food::Food() {
	this->setSize(false);
	this->setVegan(false);
}
Food::Food(const char* name, const int quantity, const char* description, const double price, const bool isLarge, const bool isVegan) : MenuItem(name, quantity, description, price) {
	this->setSize(isLarge);
	this->setVegan(isVegan);
}
void Food::getFoodInfo() {
	getMenuItemInfo();
	this->isLarge == 1 ? std::cout << "Large" : std::cout << "Small";
	this->isVegan == 1 ? std::cout << "Vegan" : std::cout << "Not vegan";
}
void Food::setSize(const bool isLarge) {
	this->isLarge = isLarge;
}
const bool Food::getSize() const {
	return this->isLarge;
}
void Food::setVegan(const bool isVegan) {
	this->isVegan = isVegan;
}
const bool Food::getVegan() const {
	return this->isVegan;
}