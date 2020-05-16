#pragma once
#include "CondimentDecorator.h"

// Concrete Decorator
class Mocha : public CondimentDecorator
{
public:
	Mocha(Beverage* beverage);
	virtual std::string getDescription() const override;
	virtual float getCost() const override;
};