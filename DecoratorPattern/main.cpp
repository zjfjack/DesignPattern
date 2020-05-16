#include <iostream>
#include "Espresso.h"
#include "HouseBlend.h"
#include "Mocha.h"
#include "Soy.h"
#include "Whip.h"

void printBaverage(const Beverage& beverage)
{
	std::cout << beverage.getDesciption() << " $" << beverage.getCost() << std::endl;
}

int main() 
{
	Beverage *beverage1 = new Espresso();
	printBaverage(*beverage1);

	Beverage *beverage2 = new HouseBlend();
	//beverage2 = new Mocha(beverage2); Memory LEAK!!!
	//beverage2->~Beverage();
	//beverage2 = new(beverage2) Mocha(beverage2);  CRASH
	//*beverage2 = Mocha(beverage2); PRINT: House Blend Coffee $0.89
	beverage2 = new Mocha(beverage2); // with virtual deconstructor in Beverage and delete new beverage memory in CondimentDecorator deconstructor
	beverage2 = new Mocha(beverage2);
	beverage2 = new Whip(beverage2);
	printBaverage(*beverage2);

	Beverage* beverage3 = new Espresso();
	beverage3 = new Mocha(beverage3);
	beverage3 = new Soy(beverage3);
	beverage3 = new Whip(beverage3);
	printBaverage(*beverage3);

	delete beverage1;
	delete beverage2;
	delete beverage3;
}