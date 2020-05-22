#include <iostream>
#include "RedheadDuck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

RedHeadDuck::RedHeadDuck() : Duck(new FlyWithWings(), new Quack()) {}

void RedHeadDuck::display()
{
    std::cout << "I'm read head duck" << std::endl;
}