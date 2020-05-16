#pragma once
#include <string>

// Abstract Product
class Sauce
{
public:
	virtual ~Sauce() = default;
	std::string description;
};

// Concrete Product
class MarinaraSauce : public Sauce
{
public:
	MarinaraSauce()
	{
		description = "Marinara Sauce";
	}
};