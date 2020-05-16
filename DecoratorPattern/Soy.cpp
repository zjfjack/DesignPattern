#include "Soy.h"

Soy::Soy(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Soy::getDesciption() const
{
	return this->beverage->getDesciption() + ", Soy";
}

float Soy::getCost() const
{
	return this->beverage->getCost() + 0.1f;
}