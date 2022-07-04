#pragma once
class Clothes {
protected:
	char* color;
	char* size;
	double price;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Clothes();
	Clothes(const char* color, const char* size, const double price);
	Clothes(const Clothes& other);

	void copy(const Clothes& other);
	void printInfo();

	void setColor(const char* color);
	const char* getColor() const;
	void setSize(const char* size);
	const char* getSize() const;
	void setPrice(const double price);
	double getPrice() const;

	Clothes& operator = (const Clothes& other);

	virtual ~Clothes();
};

