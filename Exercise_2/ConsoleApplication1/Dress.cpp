#include "Dress.h"
#include <iostream>
Dress::Dress() {
	this->lengthDress = 0;
}
Dress::Dress(const char* color, const char* size, const double price, const double lengthDress) : Clothes(color, size, price) {
	this->setLength(lengthDress);
}
void Dress::printInfo() {
	std::cout << "Dress:" << std::endl;
	Clothes::printInfo();
	std::cout << "Length: " << this->getLength() << "cm" << std::endl;
}
void Dress::setLength(const double lengthDress) {
	this->lengthDress = lengthDress;
}
const double Dress::getLength() const {
	return this->lengthDress;
}