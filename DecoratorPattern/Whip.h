#pragma once
#include "CondimentDecorator.h"

// Concrete Decorator
class Whip : public CondimentDecorator
{
public:
	Whip(Beverage* beverage);
	virtual std::string getDescription() const override;
	virtual float getCost() const override;
};