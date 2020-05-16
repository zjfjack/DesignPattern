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