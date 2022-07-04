#include "Teacher.h"
Teacher::Teacher() {
	this->salary = 0;
}
Teacher::Teacher(const char* name, const double salary) : Person(name) {
	this->salary = salary;
}