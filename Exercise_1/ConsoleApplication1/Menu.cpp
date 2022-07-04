#include "Menu.h"
Menu* Menu::getInstance() {
    if (instance == 0) {
        instance = new Menu();
    }

    return instance;
}

Menu::Menu(){
    Menu* instance = 0;

}