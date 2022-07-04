#pragma once
class Egg
{
private:
	char* length;
	char* height;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Egg();
	Egg(const Egg& other);
	Egg(const char* length, const char* height);
	
	void copy(const Egg& other);

	void setLength(const char* length);
	const char* getLength() const;
	void setHeight(const char* height);
	const char* getHeight() const;

	void printEgg();

	Egg& operator = (const Egg& other);
	~Egg();
};

