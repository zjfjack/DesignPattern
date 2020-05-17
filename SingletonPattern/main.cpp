#include "Singleton.h"
#include "SingletonOnline.h"

int main()
{
	Singleton* singleton = Singleton::getInstance();
	singleton->print();

	//Singleton singletonCopyConstructor = *singleton; copy constructor deleted
	//Singleton* singletonAssignmentOperator; assignment operator deleted
	//*singletonAssignmentOperator = *singleton

	SingletonOnline& singletonOnline1 = SingletonOnline::getInstance();
	singletonOnline1.print();
	SingletonOnline& singletonOnline2 = SingletonOnline::getInstance();
}