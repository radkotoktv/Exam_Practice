#include "Alcohol.h"
Alcohol::Alcohol() {
	this->setPercentage(0);
}
Alcohol::Alcohol(const char* name, const int quantity, const char* description, const double price, GlassType glassType, const double percentage) : Drink(name, quantity, description, price, glassType) {
	this->percentage = percentage;
}
void Alcohol::getAlcoholInfo() {
	getDrinkInfo();
	std::cout << "Alcohol percentage: " << this->percentage << "%" << std::endl;
}
void Alcohol::setPercentage(const double percentage) {
	this->percentage = percentage;
}
const double Alcohol::getPercentage() {
	return this->percentage;
}