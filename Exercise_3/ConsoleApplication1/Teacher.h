#pragma once
#include "Person.h"
class Teacher : public Person {
protected:
	double salary;

public:
	Teacher();
	Teacher(const char* name, const double salary);
};

