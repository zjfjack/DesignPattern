#include <iostream>
#include "MallardDuck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

MallardDuck::MallardDuck() : Duck(new FlyWithWings(), new MuteQuack()) {}

void MallardDuck::display()
{
    std::cout << "I'm mallard duck" << std::endl;
}
