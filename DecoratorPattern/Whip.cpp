#include "Whip.h"

Whip::Whip(Beverage* beverage)
{
	this->beverage = beverage;
}

std::string Whip::getDesciption() const
{
	return this->beverage->getDesciption() + ", Whip";
}

float Whip::getCost() const
{
	return this->beverage->getCost() + 0.15f;
}
