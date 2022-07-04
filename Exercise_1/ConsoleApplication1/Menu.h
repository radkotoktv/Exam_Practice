#pragma once
#include "MenuItem.h"
#include "Food.h"
#include "Drink.h"
#include "Alcohol.h"
class Menu : public MenuItem, public Food, public Drink, public Alcohol {
private:
    static Menu* instance;
    Menu* menu;
    std::size_t capacity;
    std::size_t size;
    std::size_t INITIAL_CAPACITY;
    std::size_t INCREASE_STEP;

public:
    Menu();
    static Menu* getInstance();
};

