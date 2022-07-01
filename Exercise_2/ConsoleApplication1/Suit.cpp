#include "Suit.h"
#include <iostream>
Suit::Suit() {

}
Suit::Suit(const char* color, const char* size, const double price) : Clothes(color, size, price) {

}
void Suit::printInfo() {
	std::cout << "Suit:" << std::endl;
	Clothes::printInfo();
}