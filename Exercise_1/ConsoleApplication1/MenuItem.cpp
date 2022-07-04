#define _CRT_SECURE_NO_WARNINGS
#include "MenuItem.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
void MenuItem::copyString(char*& destination, const char* source) {
	destination = new (std::nothrow) char[strlen(source) + 1];
	if (!destination) {
		this->deallocate();
		std::cout << "Memory problem!" << std::endl;
		exit(0);
	}
	strcpy(destination, source);
}
void MenuItem::deallocate() {
	delete[] this->name;
	delete[] this->description;
}
MenuItem::MenuItem(const char* name, const int quantity, const char* description, const double price) {
	this->setName(name);
	this->setQuantity(quantity);
	this->setDescription(description);
	this->setPrice(price);
}
MenuItem::MenuItem() {
	this->name = nullptr;
	this->setQuantity(0);
	this->description = nullptr;
	this->setPrice(0);
}
std::ostream& operator << (std::ostream& out, const MenuItem& menuItem) {
	out << "Name: " << menuItem.name << std::endl;
	out << "Quantity: " << menuItem.quantity << std::endl;
	out << "Description: " << menuItem.description << std::endl;
	out << "Price: " << menuItem.price << std::endl;
	return out;
}
void MenuItem::getMenuItemInfo() {
	std::cout << "Name: " << this->getName() << std::endl;
	std::cout << "Quantity: " << this->getQuantity() << std::endl;
	std::cout << "Description: " << this->getDescription() << std::endl;
	std::cout << "Price: " << this->getPrice() << std::endl;
}
const char* MenuItem::getName() const {
	return this->name;
}
const int MenuItem::getQuantity() const {
	return this->quantity;
}
const char* MenuItem::getDescription() const {
	return this->description;
}
const double MenuItem::getPrice() const {
	return this->price;
}
void MenuItem::setName(const char* name) {
	copyString(this->name, name);
}
void MenuItem::setQuantity(const int quantity) {
	this->quantity = quantity;
}
void MenuItem::setDescription(const char* description) {
	copyString(this->description, description);
}
void MenuItem::setPrice(const double price) {
	this->price = price;
}
MenuItem::~MenuItem() {
	this->deallocate();
}