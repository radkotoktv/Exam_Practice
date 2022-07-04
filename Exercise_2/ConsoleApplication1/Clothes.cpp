#define _CRT_SECURE_NO_WARNINGS
#include "Clothes.h"
#include <iostream>
#include <cstring>
#include <cassert>
void Clothes::copyString(char*& destination, const char* source) {
	destination = new (std::nothrow) char[strlen(source) + 1];
	if (!destination) {
		this->deallocate();
		std::cout << "Memory problem!";
		exit(0);
	}
	strcpy(destination, source);
}
void Clothes::deallocate() {
	delete[] this->color;
	delete[] this->size;
}
Clothes::Clothes() {
	this->color = nullptr;
	this->size = nullptr;
	this->price = 0;
}
Clothes::Clothes(const char* color, const char* size, const double price) {
	this->setColor(color);
	this->setSize(size);
	this->setPrice(price);
}
Clothes::Clothes(const Clothes& other) {
	this->copy(other);
}
void Clothes::copy(const Clothes& other) {
	assert(other.color != nullptr);
	assert(other.size != nullptr);
	assert(other.price != 0);
	this->setColor(other.color);
	this->setSize(other.size);
	this->setPrice(other.price);
}
void Clothes::printInfo() {
	std::cout << "Color: " << this->getColor() << std::endl;
	std::cout << "Size: " << this->getSize() << std::endl;
	std::cout << "Price: $" << this->getPrice() << std::endl;
}
void Clothes::setColor(const char* color) {
	copyString(this->color, color);
}
const char* Clothes::getColor() const {
	return this->color;
}
void Clothes::setSize(const char* size) {
	copyString(this->size, size);
}
const char* Clothes::getSize() const {
	return this->size;
}
void Clothes::setPrice(const double price) {
	this->price = price;
}
double Clothes::getPrice() const {
	return this->price;
}
Clothes& Clothes::operator = (const Clothes& other) {
	if (this != &other) {
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
Clothes::~Clothes() {
	this->deallocate();
}