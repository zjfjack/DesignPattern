#include "SingletonOnline.h"
#include <iostream>

SingletonOnline& SingletonOnline::getInstance()
{
	// Guaranteed to be destroyed.
	// Instantiated on first use. 
	// If you put it as a static variable outside like Singleton class
	// it might be instantiated before main (not sure but wrap it into a function is definitely safe)
	static SingletonOnline instance;
	return instance;
}

void SingletonOnline::print()
{
	std::cout << "Singleton online works" << std::endl;
}