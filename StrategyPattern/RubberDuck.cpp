#include <iostream>
#include "RubberDuck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

RubberDuck::RubberDuck() : Duck(new FlyNoWay(), new Squeak()) {}

void RubberDuck::display()
{
    std::cout << "I'm rubber duck" << std::endl;
}