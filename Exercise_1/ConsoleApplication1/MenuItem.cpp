#define _CRT_SECURE_NO_WARNINGS
#include "MenuItem.h"
#include <cstring>
#include <stdlib.h>
#include <iostream>
void MenuItem::copyString(char*& destination, const char* source) {
	char* destination = new char[strlen(source + 1)];
	if (!destination) {
		this->deallocate();
		std::cout << "Memory problem!";
		exit(0);
	}
	strcpy(destination, source);
}
void MenuItem::deallocate() {
	delete[] this->name;
	delete[] this->description;
}
MenuItem::MenuItem(const char* name, const int quantity, const char* description, const double price) {
	copyString(this->name, name);
	this->quantity = quantity;
	copyString(this->description, description);
	this->price = price;
}
MenuItem::MenuItem() {
	this->name = nullptr;
	this->quantity = 0;
	this->description = nullptr;
	this->price = 0;
}
MenuItem::~MenuItem() {
	this->deallocate();
}