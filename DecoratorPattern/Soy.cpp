#include "Soy.h"

Soy::Soy(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Soy::getDescription() const
{
	return this->beverage->getDescription() + ", Soy";
}

float Soy::getCost() const
{
	return this->beverage->getCost() + 0.1f;
}