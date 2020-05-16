#include <iostream>
#include "RubberDuck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

RubberDuck::RubberDuck()
{
	flyBehavior = new FlyNoWay();
	quackBehavior = new Squeak();
}

void RubberDuck::display()
{
	std::cout << "I'm rubber duck" << std::endl;
}