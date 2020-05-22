#pragma once

// Strategy
class FlyBehavior
{
public:
    virtual void fly() = 0;
};

// ConcreteStrategyA
class FlyWithWings : public FlyBehavior
{
public:
    virtual void fly() override;
};

// ConcreteStrategyB
class FlyNoWay : public FlyBehavior
{
public:
    virtual void fly() override;
};

// ConcreteStrategyC
class FlyWithRocket : public FlyBehavior
{
public:
    virtual void fly() override;
};