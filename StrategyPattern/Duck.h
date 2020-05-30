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

class MallardDuck : public Duck
{
public:
    MallardDuck();
    MallardDuck(const MallardDuck&); // copy constructor (Have to overload or delete, otherwise shallow copy will be default implemented. When the second object is destroyed, it will crash because we deleted the pointer in first object deconstructor)
    MallardDuck& operator=(const MallardDuck& rhs); // assignment constructor (Have to overload or delete)
    virtual void display() override;
};

class RedHeadDuck : public Duck
{
public:
    RedHeadDuck();
    RedHeadDuck(const RedHeadDuck&) = delete;
    RedHeadDuck& operator=(const RedHeadDuck&) = delete;
    virtual void display() override;
};

class RubberDuck : public Duck
{
public:
    RubberDuck();
    RubberDuck(const RubberDuck&) = delete;
    RubberDuck& operator=(const RubberDuck&) = delete;
    virtual void display() override;
};