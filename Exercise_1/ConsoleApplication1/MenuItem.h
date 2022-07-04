#pragma once
#include <iostream>
class MenuItem {
protected:
	char* name;
	int quantity;
	char* description;
	double price;

	void copyString(char*& destination, const char* source);
	void deallocate();

public:
	MenuItem();
	MenuItem(const char* name, const int quantity, const char* description, const double price);

	void getMenuItemInfo();

	friend std::ostream& operator << (std::ostream& out, const MenuItem& menuItem);

	void setName(const char* name);
	const char* getName() const;
	void setQuantity(const int quantity);
	const int getQuantity() const;
	void setDescription(const char* description);
	const char* getDescription() const;
	void setPrice(const double price);
	const double getPrice() const;
	
	~MenuItem();
};

