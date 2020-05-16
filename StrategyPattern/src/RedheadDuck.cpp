#include <iostream>
#include "RedheadDuck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

RedHeadDuck::RedHeadDuck()
{
	flyBehavior = new FlyWithWings();
	quackBehavior = new Quack();
}

void RedHeadDuck::display()
{
	std::cout << "I'm read head duck" << std::endl;
}