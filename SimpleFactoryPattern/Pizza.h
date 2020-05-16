#pragma once
#include <string>

class Pizza
{
public:
	virtual ~Pizza() = default; // Although it is not neccessary because no need to call derived classes' destrctor, it is better to leave it.
	std::string name;
};