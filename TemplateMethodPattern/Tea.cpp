#include "Tea.h"
#include <iostream>

void Tea::heatWater()
{
    std::cout << "Heating water to 70 degrees" << std::endl;
}

void Tea::brew()
{
    std::cout << "Steeping the tea" << std::endl;
}

void Tea::hook()
{
    addLemon();
}

void Tea::addLemon()
{
    std::cout << "Adding lemon" << std::endl;
}