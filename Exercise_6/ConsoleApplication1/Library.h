#pragma once
#include "Book.h"
#include <iostream>
class Library
{
private:
	Book* books;
	std::size_t capacity;
	std::size_t size;
	std::size_t INITIAL_CAPACITY;
	std::size_t INCREASE_STEP;

	void copyString(char*& destination, const char* source);
	void deallocate();
	void resize();
	int getBookIndex(const Book& other);

public:
	Library();
	
	void copy(const Library& other);
	Library(const Library& other);

	void printInfo();

	void addBook(const Book& bookToAdd);
	void removeBook(const Book& bookToRemove);

	Library& operator = (const Library& other);

	~Library();
};

