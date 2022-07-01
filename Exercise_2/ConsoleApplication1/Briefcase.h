#pragma once
#include <iostream>
#include "Clothes.h"
#include "Suit.h"
#include "Dress.h"
#include "Pants.h"
class Briefcase : public Clothes, public Suit, public Dress, public Pants {
private:
	char* color;
	char* name;
	char* address;
	long long int number;
	Clothes* clothes;
	std::size_t size;
	std::size_t capacity;
	std::size_t INITIAL_CAPACITY;
	std::size_t INCREASE_STEP;

	void resize();

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Briefcase();
	Briefcase(const char* color, const char* name, const char* address, const long long int number);
	Briefcase(const Briefcase& other);
	
	void copy(const Briefcase& other);
	void printInfo();

	void setColor(const char* color);
	const char* getColor() const;
	void setName(const char* name);
	const char* getName() const;
	void setAddress(const char* address);
	const char* getAddress() const;
	void setNumber(long long int number);
	long long int getNumber() const;
	
	Briefcase& operator = (const Briefcase& other);

	void addClothes(const Clothes& clothesToAdd);
	//void addSuit(const Suit& suitToAdd);
	//void addDress(const Dress& dressToAdd);
	//void addPants(const Pants& pantsToAdd);

	~Briefcase();
};

