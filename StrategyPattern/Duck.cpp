#include "FlyBehavior.h"
#include "QuackBehavior.h"
#include "Duck.h"

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