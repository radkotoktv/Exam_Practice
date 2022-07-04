#define _CRT_SECURE_NO_WARNINGS
#include "Egg.h"
#include <cstring>
#include <iostream>
void Egg::copyString(char*& destination, const char* source) {
	try
	{
		destination = new char[strlen(source) + 1];
	}
	catch (const std::bad_alloc& ba)
	{
		throw ba;
	}
	strcpy(destination, source);
}
void Egg::deallocate() {
	delete[] this->length;
	delete[] this->height;

	this->length = nullptr;
	this->height = nullptr;
}
Egg::Egg() {
	this->length = nullptr;
	this->height = nullptr;
}
Egg::Egg(const Egg& other) {
	this->copy(other);
}
Egg::Egg(const char* length, const char* height) {
	this->setLength(length);
	this->setHeight(height);
}
void Egg::copy(const Egg& other) {
	this->setLength(other.length);
	this->setHeight(other.height);
}
void Egg::setLength(const char* length) {
	copyString(this->length, length);
}
const char* Egg::getLength() const {
	return this->length;
}
void Egg::setHeight(const char* height) {
	copyString(this->height, height);
}
const char* Egg::getHeight() const {
	return this->height;
}
void Egg::printEgg() {
	std::cout << this->getHeight() << std::endl;
	std::cout << this->getLength() << std::endl;
}
Egg& Egg::operator = (const Egg& other) {
	if (this != &other) {
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
Egg::~Egg() {
	this->deallocate();
}