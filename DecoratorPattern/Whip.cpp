#include "Whip.h"

Whip::Whip(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Whip::getDescription() const
{
	return this->beverage->getDescription() + ", Whip";
}

float Whip::getCost() const
{
	return this->beverage->getCost() + 0.15f;
}
