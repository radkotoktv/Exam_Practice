#include "Vehicle.h"
Vehicle::Vehicle(const char* description, const double averageSpeed, const double amortisation) : Walker(description, averageSpeed) {
	this->amortisation = 0.0;
}
void Vehicle::copy(const Vehicle& other) {
	this->amortisation = other.amortisation;
}
Vehicle::Vehicle(const Vehicle& other) {
	this->copy(other);
}
Vehicle& Vehicle::operator = (const Vehicle& other) {
	if (this != &other)
	{
		this->copy(other);
	}
	return *this;
}
const double Vehicle::getAmortisation() const {
	return this->amortisation;
}
double Vehicle::walk(double distance) {
	this->amortisation += distance;
	double temp = amortisation;
	if (temp >= 100 && Walker::averageSpeed > (Walker::startingSpeed / 2))
	{
		Walker::averageSpeed--;
		temp = 0;
	}
	return this->amortisation;
}
Vehicle::~Vehicle() = default;