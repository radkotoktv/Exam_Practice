#define _CRT_SECURE_NO_WARNINGS
#include "Basket.h"
#include <iostream>
#include <cstring>
#include <cassert>
void Basket::copyString(char*& destination, const char* source) {
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
void Basket::deallocate() {
	delete[] this->eggs;
	this->eggs = nullptr;
}
void Basket::resize() {
	Egg* newEggs = new Egg[this->capacity * this->INCREASE_STEP];
	for (std::size_t i = 0; i < this->size; ++i)
	{
		newEggs[i] = this->eggs[i];
	}
	this->capacity *= this->INCREASE_STEP;
	this->deallocate();
	this->eggs = newEggs;
}
Basket::Basket() {
	this->size = 0;
	this->INITIAL_CAPACITY = 2;
	this->capacity = INITIAL_CAPACITY;
	this->INCREASE_STEP = 2;
	this->name = nullptr;
	this->eggs = new Egg[INITIAL_CAPACITY];
}
Basket::Basket(const Basket& other) {
	this->copy(other);
}
void Basket::copy(const Basket& other) {
	this->eggs = new Egg[other.capacity];
	for (std::size_t i; i < other.size; ++i) {
		try
		{
			this->eggs[i] = other.eggs[i];
		}
		catch (const std::exception& e)
		{
			this->deallocate();
			throw e;
		}
	}
	this->size = other.size;
	this->capacity = other.capacity;
}
void Basket::setName(const char* name) {
	copyString(this->name, name);
}
const char* Basket::getName() const {
	return this->name;
}
void Basket::addEgg(const Egg& eggToAdd) {
	if (this->capacity == this->size)
	{
		this->resize();
	}
	this->eggs[this->size] = eggToAdd;
	++this->size;
}
int Basket::getEggIndex(const Egg& eggToCompare) {
	assert(eggToCompare.getHeight() != nullptr);
	assert(eggToCompare.getLength() != nullptr);
	for (std::size_t i = 0; i < this->size; ++i) {
		if ((strcmp(this->eggs[i].getHeight(), eggToCompare.getHeight()) == 0) && (strcmp(this->eggs[i].getLength(), eggToCompare.getLength()) == 0))
		{
			return i;
		}
	}
	return -1;
}
void Basket::removeEgg(const Egg& eggToRemove) {
	int eggIndex = this->getEggIndex(eggToRemove);
	if (eggIndex == -1)
	{
		std::cout << "No such egg in this basket!" << std::endl;
		return;
	}
	std::swap(this->eggs[eggIndex], this->eggs[size - 1]);
	--this->size;
	return;
}
void Basket::printBasketContents() {
	std::cout << "Basket Owner: " << this->name << std::endl;
	for (std::size_t i = 0; i < this->size; ++i) {
		this->eggs[i].printEgg();
		std::cout << std::endl;
	}
}
Basket& Basket::operator = (const Basket& other) {
	if (this != &other) {
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
Basket::~Basket() {
	delete[] this->name;
	this->deallocate();
}