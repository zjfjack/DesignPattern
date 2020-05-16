#pragma once
#include "Beverage.h"

// Concrete Component
class HouseBlend : public Beverage
{
public:
	virtual std::string getDescription() const override;
	virtual float getCost() const override;
};