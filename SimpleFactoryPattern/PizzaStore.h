#pragma once
#include "SimpleFactory.h"

class PizzaStore
{
private:
    SimpleFactory factory;

public:
    PizzaStore(const SimpleFactory &factory);
    
    Pizza* orderPizza(PizzaType type) const;
};