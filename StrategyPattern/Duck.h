#pragma once

class Duck
{
protected:
    Duck(class FlyBehavior* flyBehavior, class QuackBehavior* quackBehavior);
public:
    // Composition of strategies (Template method pattern is using inheritance)
    FlyBehavior* flyBehavior = nullptr;
    QuackBehavior* quackBehavior = nullptr;
public:
    virtual ~Duck();
    virtual void display() = 0;
    void performFly();
    void performQuack();
};