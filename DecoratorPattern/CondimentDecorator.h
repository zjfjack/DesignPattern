#pragma once
#include "Beverage.h"

// Decorator
class CondimentDecorator : public Beverage 
{
public:
    virtual ~CondimentDecorator();
protected:
    CondimentDecorator(Beverage* beverage);
    Beverage *beverage;
};

// Concrete Decorator
class Mocha : public CondimentDecorator
{
public:
    Mocha(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual float getCost() const override;
};

// Concrete Decorator
class Soy : public CondimentDecorator
{
public:
    Soy(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual float getCost() const override;
};

// Concrete Decorator
class Whip : public CondimentDecorator
{
public:
    Whip(Beverage* beverage);
    virtual std::string getDescription() const override;
    virtual float getCost() const override;
};