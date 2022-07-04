#define _CRT_SECURE_NO_WARNINGS
#include "Library.h"
#include <iostream>
#include <cstring>
void Library::copyString(char*& destination, const char* source) {
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
void Library::deallocate() {
	delete[] this->books;
	this->books = nullptr;
}
void Library::resize() {
	Book* newBooks = nullptr;
	try
	{
		newBooks = new Book[this->capacity * this->INCREASE_STEP];
	}
	catch (const std::bad_alloc& ba)
	{
		this->deallocate();
		throw ba;
	}
	for (std::size_t i = 0; i < this->size; ++i)
	{
		try
		{
			newBooks[i] = this->books[i];
		}
		catch (const std::exception& rofl)
		{
			this->deallocate();
			throw rofl;
		}
	}
	this->capacity *= INCREASE_STEP;
	this->deallocate();
	this->books = newBooks;
}
int Library::getBookIndex(const Book& other) {
	for (std::size_t i = 0; i < this->size; ++i)
	{
		if ((strcmp(this->books[i].getName(), other.getName()) == 0) && (strcmp(this->books[i].getAuthor(), other.getAuthor()) == 0) && (this->books[i].getPrice() == other.getPrice()))
		{
			return i;
		}
	}
	return -1;
}
Library::Library() {
	this->INITIAL_CAPACITY = 2;
	this->INCREASE_STEP = 2;
	this->capacity = INITIAL_CAPACITY;
	this->size = 0;
	this->books = new Book[INITIAL_CAPACITY];
}
void Library::copy(const Library& other) {
	this->books = new Book[other.capacity];
	for (std::size_t i = 0; i < other.size; ++i) {
		try
		{
			this->books[i] = other.books[i];
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
Library::Library(const Library& other) {
	this->copy(other);
}
void Library::printInfo() {
	for (std::size_t i = 0; i < this->size; ++i)
	{
		this->books[i].printInfo();
		std::cout << std::endl;
	}
}
void Library::addBook(const Book& bookToAdd) {
	if (this->size == this->capacity)
	{
		this->resize();
	}
	this->books[this->size] = bookToAdd;
	++this->size;
}
void Library::removeBook(const Book& bookToRemove) {
	int bookIndex = this->getBookIndex(bookToRemove);
	if (bookIndex == -1)
	{
		std::cout << "No such book in the library!" << std::endl;
		return;
	}
	std::swap(this->books[bookIndex], this->books[size - 1]);
	--this->size;
}
Library& Library::operator = (const Library& other) {
	if (this != &other) {
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
Library::~Library() {
	this->deallocate();
}