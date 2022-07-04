#pragma once
#include "Egg.h"
#include <cstddef>
class Basket
{
private:
	char* name;
	Egg* eggs;
	std::size_t capacity;
	std::size_t size;
	std::size_t INITIAL_CAPACITY;
	std::size_t INCREASE_STEP;

	void copyString(char*& destination, const char* source);
	void deallocate();

	int getEggIndex(const Egg& eggToCompare);
	void resize();

public:
	Basket();
	Basket(const Basket& other);

	void copy(const Basket& other);

	void setName(const char* name);
	const char* getName() const;

	void addEgg(const Egg& eggToAdd);
	void removeEgg(const Egg& eggToRemove);

	void printBasketContents();

	Basket& operator = (const Basket& other);
	
	~Basket();
};

