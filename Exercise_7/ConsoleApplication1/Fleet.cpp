#include "Fleet.h"
void Fleet::deallocate() {
	delete[] this->arr;
	this->arr = nullptr;
}
Fleet::Fleet() {
	this->MAX_SIZE = 14;
	this->size = 0;
	this->arr = new Walker[this->MAX_SIZE];
}
void Fleet::copy(const Fleet& other) {
	for (std::size_t i = 0; i < other.size; ++i)
	{
		this->arr[i] = other.arr[i];
	}
	this->size = other.size;
}
Fleet::Fleet(const Fleet& other) {
	this->copy(other);
}
Fleet& Fleet::operator = (const Fleet& other) {
	if (this != &other)
	{
		this->deallocate();
		this->copy(other);
	}
	return *this;
}
void Fleet::addWalker(const Walker& walkerToAdd) {
	if (this->size == this->MAX_SIZE)
	{
		throw std::overflow_error("Kazarmata e pulna!!");
	}
	this->arr[this->size++] = walkerToAdd;
}
double Fleet::walkAll(double distance) {
	double sum = 0.0;
	for (std::size_t i = 0; i < this->size; ++i)
	{
		sum += this->arr[i].walk(distance);
	}
	return sum / this->size;
}
Fleet::~Fleet() {
	this->deallocate();
}