#include "Suit.h"
#include <iostream>
Suit::Suit() {

}
Suit::Suit(const char* color, const char* size, const double price) : Clothes(color, size, price) {

}
void Suit::printInfo() {
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "Size: " << this->getSize() << std::endl;
	std::cout << "Price: $" << this->getPrice() << std::endl;
}
void Suit::setColor(const char* color) {
	copyString(this->color, color);
}
const char* Suit::getColor() const {
	return this->color;
}
void Suit::setSize(const char* size) {
	copyString(this->size, size);
}
const char* Suit::getSize() const {
	return this->size;
}
void Suit::setPrice(const double price) {
	this->price = price;
}
double Suit::getPrice() const {
	return this->price;
}