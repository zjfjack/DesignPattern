#include "Mocha.h"

Mocha::Mocha(Beverage* beverage) // Cannot use initializer list because beverage is from base class CondimentDecorator
{
	this->beverage = beverage;
}

std::string Mocha::getDescription() const
{
	return this->beverage->getDescription() + ", Mocha";
}

float Mocha::getCost() const
{
	return this->beverage->getCost() + 0.2f;
}