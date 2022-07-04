#define _CRT_SECURE_NO_WARNINGS
#include "Walker.h"
#include <iostream>
#include <cstring>
void Walker::copyString(char*& destination, const char* source) {
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
void Walker::deallocate() {
	delete[] this->description;
	this->description = nullptr;
}
Walker::Walker() {
	this->description = nullptr;
	this->averageSpeed = 0.0;
	this->startingSpeed = this->averageSpeed;
}
Walker::Walker(const char* description, const double averageSpeed) {
	this->setDescription(description);
	this->setAverageSpeed(averageSpeed);
	this->startingSpeed = averageSpeed;
}
void Walker::copy(const Walker& other) {
	this->setDescription(other.description);
	this->setAverageSpeed(other.averageSpeed);
	this->startingSpeed = other.startingSpeed;
}
Walker::Walker(const Walker& other) {
	this->copy(other);
}
void Walker::setDescription(const char* description) {
	this->copyString(this->description, description);
}
const char* Walker::getDescription() const {
	return this->description;
}
void Walker::setAverageSpeed(const double averageSpeed) {
	this->averageSpeed = averageSpeed;
}
const double Walker::getAverageSpeed() const {
	return this->averageSpeed;
}
Walker& Walker::operator = (const Walker& other) {
	if (this != &other)
	{
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
double Walker::walk(double distance) {
	return distance / this->averageSpeed;
}
Walker::~Walker() {
	this->deallocate();
}