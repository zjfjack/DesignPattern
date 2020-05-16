#pragma once
#include "CondimentDecorator.h"

// Concrete Decorator
class Soy : public CondimentDecorator
{
public:
	Soy(Beverage* beverage);
	virtual std::string getDescription() const override;
	virtual float getCost() const override;
};