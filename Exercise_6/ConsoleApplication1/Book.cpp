#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <iostream>
#include <cstring>
void Book::copyString(char*& destination, const char* source) {
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
void Book::deallocate() {
	delete[] this->name;
	delete[] this->author;
}
Book::Book() {
	this->name = nullptr;
	this->author = nullptr;
	this->price = 0.0;
}
Book::Book(const char* name, const char* author, const double price) {
	this->setName(name);
	this->setAuthor(author);
	this->setPrice(price);
}
Book::Book(const Book& other) {
	this->copy(other);
}
void Book::copy(const Book& other) {
	this->setName(other.name);
	this->setAuthor(other.author);
	this->setPrice(other.price);
}
void Book::setName(const char* name) {
	copyString(this->name, name);
}
const char* Book::getName() const {
	return this->name;
}
void Book::setAuthor(const char* author) {
	copyString(this->author, author);
}
const char* Book::getAuthor() const {
	return this->author;
}
void Book::setPrice(const double price) {
	this->price = price;
}
const double Book::getPrice() const {
	return this->price;
}
void Book::printInfo() {
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Author: " << this->author << std::endl;
	std::cout << "Price: " << this->price << std::endl;
}
Book& Book::operator = (const Book& other) {
	if (this != &other)
	{
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
Book::~Book() {
	this->deallocate();
}