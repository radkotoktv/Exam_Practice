#pragma once
#include "Walker.h"
#include "Vehicle.h"
#include <iostream>
class Fleet
{
private:
	std::size_t MAX_SIZE;
	Walker* arr;
	std::size_t size;

	void deallocate();

public:
	Fleet();
	
	void copy(const Fleet& other);

	Fleet(const Fleet& other);

	Fleet& operator = (const Fleet& other);

	void addWalker(const Walker& walkerToAdd);
	double walkAll(double distance);

	~Fleet();
};

