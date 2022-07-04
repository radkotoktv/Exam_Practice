#pragma once
#include "Walker.h"
class Vehicle : public Walker
{
private:
	double amortisation;

public:
	Vehicle(const char* description, const double averageSpeed, const double amortisation);
	
	void copy(const Vehicle& other);

	Vehicle(const Vehicle& other);

	Vehicle& operator = (const Vehicle& other);

	const double getAmortisation() const;

	virtual double walk(double distance) override final;

	~Vehicle();
};

