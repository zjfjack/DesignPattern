#pragma once
#include <string>

// Abstract Product
class Cheese
{
public:
	virtual ~Cheese() = default;
	std::string description;
};

// Concrete Product
class MozzarellaCheese : public Cheese
{
public:
	MozzarellaCheese()
	{
		description = "Mozzarella Cheese";
	}
};

// Concrete Product
class ReggianoCheese : public Cheese
{
public:
	ReggianoCheese()
	{ 
		description = "Reggiano Cheese"; 
	}
};