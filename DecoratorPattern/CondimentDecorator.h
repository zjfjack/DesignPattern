#pragma once
#include "Beverage.h"

// Decorator
class CondimentDecorator : public Beverage 
{
public:
	virtual ~CondimentDecorator();
protected:
	Beverage *beverage;
};