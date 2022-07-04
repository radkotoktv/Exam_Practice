#include "Pants.h"
#include <iostream>
Pants::Pants() {
	this->lengthLeg = 0;
}
Pants::Pants(const char* color, const char* size, const double price, const double lengthLeg) : Clothes(color, size, price) {
	this->setLength(lengthLeg);
}
void Pants::printInfo() {
	std::cout << "Pants:" << std::endl;
	Clothes::printInfo();
	std::cout << "Length: " << this->getLength() << "cm" << std::endl;
}
void Pants::setLength(const double lengthLeg) {
	this->lengthLeg = lengthLeg;
}
const double Pants::getLength() const {
	return this->lengthLeg;
}