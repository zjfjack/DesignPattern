#include "Mocha.h"

Mocha::Mocha(Beverage* beverage) // Cannot use initializer list because beverage is from base class CondimentDecorator
{
	this->beverage = beverage;
}

std::string Mocha::getDesciption() const
{
	return this->beverage->getDesciption() + ", Mocha";
}

float Mocha::getCost() const
{
	return this->beverage->getCost() + 0.2f;
}