#include <iostream>
#include "Assistant.h"
int main() {
	Assistant assistant("Miro", 1234, 1500);
	std::cout << assistant.getName();
	std::cout << assistant.getFn();
	std::cout << assistant.getSalary();
}