#pragma once
#include "PizzaType.h"
#include "Pizza.h"

// Creator
class PizzaStore
{
public:
	virtual ~PizzaStore() = default;
	Pizza* orderPizza(PizzaType type) const;
protected:
	// abstract Product factoryMethod(String type)
	virtual Pizza* createPizza(PizzaType type) const = 0;
};

