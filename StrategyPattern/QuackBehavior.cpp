#include <iostream>
#include "QuackBehavior.h"

void Quack::quack()
{
    std::cout << "Quack" << std::endl;
}

void Squeak::quack()
{
    std::cout << "Squeak" << std::endl;
}

void MuteQuack::quack()
{
    std::cout << "Mute Quack" << std::endl;
}