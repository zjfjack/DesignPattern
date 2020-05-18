#include "Fan.h"
#include <iostream>

void Fan::high()
{
	speed = High;
	std::cout << "Fan set high speed" << std::endl;
}

void Fan::medium()
{
	speed = Medium;
	std::cout << "Fan set medium speed" << std::endl;
}

void Fan::low()
{
	speed = Low;
	std::cout << "Fan set low speed" << std::endl;
}

void Fan::off()
{
	speed = Off;
	std::cout << "Fan turned off" << std::endl;
}

int Fan::getSpeed() const
{
	return speed;
}