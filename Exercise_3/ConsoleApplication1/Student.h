#pragma once
#include "Person.h"
class Student : public Person {
protected:
	int fn;

public:
	Student();
	Student(const char* name, const int fn);
};

