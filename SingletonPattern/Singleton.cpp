#include "Singleton.h"
#include <iostream>

// The definition for a static data member shall appear in a namespace scope enclosing the member¡¯s class definition.
Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance()
{
	return instance;
}

void Singleton::print()
{
	std::cout << "Singleton works!" << std::endl;
}
