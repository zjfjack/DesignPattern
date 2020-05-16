#include "CondimentDecorator.h"
#include <iostream>

CondimentDecorator::~CondimentDecorator()
{
	delete beverage;
}
