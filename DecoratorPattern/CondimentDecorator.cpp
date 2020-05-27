#include "CondimentDecorator.h"
#include <iostream>

CondimentDecorator::~CondimentDecorator()
{
    Beverage::~Beverage();
    delete beverage;
}

CondimentDecorator::CondimentDecorator(Beverage* beverage) : beverage(beverage) {}

Mocha::Mocha(Beverage* beverage) : CondimentDecorator(beverage) {}

std::string Mocha::getDescription() const
{
    return beverage->getDescription() + ", Mocha";
}

float Mocha::getCost() const
{
    return beverage->getCost() + 0.2f;
}

Soy::Soy(Beverage* beverage) : CondimentDecorator(beverage) {}

std::string Soy::getDescription() const
{
    return beverage->getDescription() + ", Soy";
}

float Soy::getCost() const
{
    return beverage->getCost() + 0.1f;
}

Whip::Whip(Beverage* beverage) : CondimentDecorator(beverage) {}

std::string Whip::getDescription() const
{
    return beverage->getDescription() + ", Whip";
}

float Whip::getCost() const
{
    return beverage->getCost() + 0.15f;
}