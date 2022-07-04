#include "Student.h"
Student::Student() {
	this->fn = 0;
}
Student::Student(const char* name, const int fn) : Person(name) {
	this->fn = fn;
}