#include "Beverage.h"

std::string Espresso::getDescription() const
{
    return "Espresso";
}

float Espresso::getCost() const
{
    return 1.99f;
}

std::string HouseBlend::getDescription() const
{
    return "House Blend Coffee";
}

float HouseBlend::getCost() const
{
    return 0.89f;
}