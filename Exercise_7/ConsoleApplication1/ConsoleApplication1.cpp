#include <iostream>
#include "Vehicle.h"
#include "Fleet.h"
int main()
{
    Fleet fleet;
    Vehicle vehicle("Mnogo gotin", 5.6, 20);
    fleet.addWalker(vehicle);
    fleet.walkAll(100);
    std::cout << vehicle.getAmortisation();
}
