#include "Coffee.h"
#include <iostream>

void Coffee::heatWater()
{
    std::cout << "Boiling water" << std::endl;
}

void Coffee::brew()
{
    std::cout << "Dripping coffee through filter" << std::endl;
}

void Coffee::hook()
{
    addMilk();
    addSugar();
}

void Coffee::addMilk()
{
    std::cout << "Adding milk" << std::endl;
}

void Coffee::addSugar()
{
    std::cout << "Adding sugar" << std::endl;
}