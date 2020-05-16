#pragma once
#include "Beverage.h"

// Concrete Component
class Espresso : public Beverage
{
public:
	virtual std::string getDescription() const override;
	virtual float getCost() const override;
};