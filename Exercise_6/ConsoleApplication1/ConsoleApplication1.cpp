#include <iostream>
#include "Library.h"
int main()
{
	Book kniga1("Purva kniga", "Kireto99", 6.00);
	Book kniga2("Vtora kniga", "Danito Sofiq", 20.00);
	Book kniga3("Treta kniga", "Vikito Manqk", 13.13);
	Library biblioteka;
	biblioteka.addBook(kniga1);
	biblioteka.addBook(kniga2);
	biblioteka.addBook(kniga3);
	biblioteka.printInfo();
}