#pragma once

// Strategy
class QuackBehavior
{
public:
    virtual void quack() = 0;
};

// ConcreteStrategyA
class Quack : public QuackBehavior
{
public:
    virtual void quack() override;
};

// ConcreteStrategyB
class Squeak : public QuackBehavior
{
public:
    virtual void quack() override;
};

// ConcreteStrategyC
class MuteQuack : public QuackBehavior
{
public:
    virtual void quack() override;
};