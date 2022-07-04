#include "Assistant.h"
Assistant::Assistant(const char* name, const int fn, const double salary) : Person(name), Student(name, fn), Teacher(name, salary) {

}
const char* Assistant::getName() const {
	return this->Person::name;
}
const int Assistant::getFn() const {
	return this->Student::fn;
}
const double Assistant::getSalary() const {
	return this->Teacher::salary;
}