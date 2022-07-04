#include "MenuItem.h"
#include "Food.h"
#include "Drink.h"
#include "Alcohol.h"
#include <iostream>
int main() {
	Alcohol alkohol("Ivan", 4, "Vkusno", 2.22, GlassType::JUG, 40);
	alkohol.getAlcoholInfo();
}