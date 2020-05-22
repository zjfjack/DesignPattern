#include "CaffeineBeverage.h"
#include <iostream>

void CaffeineBeverage::prepareRecipe()
{
    heatWater();
    brew();
    pourInCup();
    hook();
}

void CaffeineBeverage::pourInCup()
{
    std::cout << "Pouring into cup" << std::endl;
}

void CaffeineBeverage::hook()
{
    // Keep the hook function empty in base class and derived class can choose to override or not
}