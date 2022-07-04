#define _CRT_SECURE_NO_WARNINGS
#include "Briefcase.h"
#include <iostream>
#include <cstring>
#include <cassert>
void Briefcase::copyString(char*& destination, const char* source) {
	destination = new (std::nothrow) char[strlen(source) + 1];
	if (!destination) {
		this->deallocate();
		std::cout << "Memory problem!";
		exit(0);
	}
	strcpy(destination, source);
}
void Briefcase::deallocate() {
	delete[] this->color;
	delete[] this->name;
	delete[] this->address;
}
Briefcase::Briefcase() {
	this->color = nullptr;
	this->name = nullptr;
	this->address = nullptr;
	this->number = 0;

	INCREASE_STEP = 2;
	INITIAL_CAPACITY = 2;
	this->clothes = new (std::nothrow) Clothes[INITIAL_CAPACITY];
	if (!this->clothes) {
		this->deallocate();
		std::cout << "Memory problem!" << std::endl;
		exit(0);
	}
	this->capacity = INITIAL_CAPACITY;
	this->size = 0;

}
Briefcase::Briefcase(const char* briefcaseColor, const char* briefcaseName, const char* address, const long long int number) {
	this->setColor(color);
	this->setName(name);
	this->setAddress(address);
	this->setNumber(number);
}
Briefcase::Briefcase(const Briefcase& other) {
	this->copy(other);
}
void Briefcase::copy(const Briefcase& other) {
	assert(other.color != nullptr);
	assert(other.name != nullptr);
	assert(other.address != nullptr);
	assert(other.number != 0);
	this->setColor(other.color);
	this->setName(other.name);
	this->setAddress(other.address);
	this->setNumber(other.number);
}
void Briefcase::printInfo() {
	for (std::size_t i = 0; i < this->size; ++i) {
		this->clothes[i].printInfo();
		std::cout << std::endl;
	}
}
void Briefcase::setColor(const char* color) {
	copyString(this->color, color);
}
const char* Briefcase::getColor() const {
	return this->color;
}
void Briefcase::setName(const char* name) {
	copyString(this->name, name);
}
const char* Briefcase::getName() const {
	return this->name;
}
void Briefcase::setAddress(const char* address) {
	copyString(this->address, address);
}
const char* Briefcase::getAddress() const {
	return this->address;
}
void Briefcase::setNumber(long long int number) {
	this->number = number;
}
long long int Briefcase::getNumber() const {
	return this->number;
}
Briefcase& Briefcase::operator = (const Briefcase& other) {
	if (this != &other) {
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
void Briefcase::resize() {
	Clothes* newClothes = new (std::nothrow) Clothes[this->capacity * INCREASE_STEP];
	if (!newClothes) {
		this->deallocate();
		std::cout << "Memory problem!" << std::endl;
		exit(0);
	}

	for (std::size_t i = 0; i < this->size; ++i) {
		newClothes[i] = this->clothes[i] ;
	}

	this->deallocate();
	this->clothes = newClothes;
	this->capacity *= INCREASE_STEP;
}
void Briefcase::addClothes(const Clothes& clothesToAdd) {
	if (this->size == this->capacity) {
		this->resize();
	}
	this->clothes[this->size++] = clothesToAdd;
}
Briefcase::~Briefcase() {
	this->deallocate();
}