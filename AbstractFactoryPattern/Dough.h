#pragma once
#include <string>

// Abstract Product
class Dough
{
public:
	virtual ~Dough() = default;
	std::string description;
};

// Concrete Product
class ThickCrustDough : public Dough
{
public:
	ThickCrustDough()
	{
		description = "Thick Crust Dough";
	}
};

// Concrete Product
class ThinCrustDough : public Dough
{
public:
	ThinCrustDough()
	{
		description = "Thin Crust Dough";
	}
};

