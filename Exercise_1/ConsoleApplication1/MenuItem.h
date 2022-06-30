#pragma once
class MenuItem {
private:
	char* name;
	int quantity;
	char* description;
	double price;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	MenuItem();
	MenuItem(const char* name, const int quantity, const char* description, const double price);
	~MenuItem();
};

