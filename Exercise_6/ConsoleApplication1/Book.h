#pragma once
class Book
{
private:
	char* name;
	char* author;
	double price;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	Book();
	Book(const char* name, const char* author, const double price);
	Book(const Book& other);

	void copy(const Book& other);

	void setName(const char* name);
	const char* getName() const;
	void setAuthor(const char* author);
	const char* getAuthor() const;
	void setPrice(const double price);
	const double getPrice() const;

	void printInfo();

	Book& operator = (const Book& other);

	~Book();
};

