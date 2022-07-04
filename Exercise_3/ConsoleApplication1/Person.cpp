#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <cstring>
#include <iostream>
Person::Person() {
	this->name = nullptr;
}
Person::Person(const char* name) {
	this->name = new (std::nothrow) char[strlen(name) + 1];
	if (!this->name) {
		delete[] this->name;
		std::cout << "Memory problem!" << std::endl;
		exit(0);
	}
	strcpy(this->name, name);
}
Person::~Person() {
	delete[] this->name;
}