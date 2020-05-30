#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "Duck.h"
#include <iostream>

Duck::Duck(FlyBehavior* flyBehavior, QuackBehavior* quackBehavior) : flyBehavior(flyBehavior), quackBehavior(quackBehavior) {}

Duck::~Duck()
{
    delete flyBehavior;
    delete quackBehavior;
}

void Duck::performFly()
{
    flyBehavior->fly();
}

void Duck::performQuack()
{
    quackBehavior->quack();
}

MallardDuck::MallardDuck() : Duck(new FlyWithWings(), new MuteQuack()) {}

MallardDuck::MallardDuck(const MallardDuck&) : Duck(new FlyWithWings(), new MuteQuack()) {}

MallardDuck& MallardDuck::operator=(const MallardDuck& rhs)
{
    return *this;
}

void MallardDuck::display()
{
    std::cout << "I'm mallard duck" << std::endl;
}

RedHeadDuck::RedHeadDuck() : Duck(new FlyWithWings(), new Quack()) {}

void RedHeadDuck::display()
{
    std::cout << "I'm read head duck" << std::endl;
}

RubberDuck::RubberDuck() : Duck(new FlyNoWay(), new Squeak()) {}

void RubberDuck::display()
{
    std::cout << "I'm rubber duck" << std::endl;
}