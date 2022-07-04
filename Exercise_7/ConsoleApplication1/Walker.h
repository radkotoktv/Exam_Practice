#pragma once
class Walker
{
protected:
	double averageSpeed;
	double startingSpeed;

private:
	char* description;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Walker();
	Walker(const char* description, const double averageSpeed);

	void copy(const Walker& other);

	Walker(const Walker& other);

	void setDescription(const char* description);
	const char* getDescription() const;
	void setAverageSpeed(const double averageSpeed);
	const double getAverageSpeed() const;

	Walker& operator = (const Walker& other);

	virtual double walk(double distance);

	virtual ~Walker();
};

