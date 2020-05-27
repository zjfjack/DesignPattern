#pragma once
#include <string>

// Component
class Beverage 
{
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const = 0;
    virtual float getCost() const = 0;
};

// Concrete Component
class Espresso : public Beverage
{
public:
    virtual std::string getDescription() const override;
    virtual float getCost() const override;
};

// Concrete Component
class HouseBlend : public Beverage
{
public:
    virtual std::string getDescription() const override;
    virtual float getCost() const override;
};