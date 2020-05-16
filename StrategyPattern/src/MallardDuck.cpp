#include <iostream>
#include "MallardDuck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

MallardDuck::MallardDuck()
{
	flyBehavior = new FlyWithWings();
	quackBehavior = new MuteQuack();
}

void MallardDuck::display()
{
	std::cout << "I'm mallard duck" << std::endl;
}
