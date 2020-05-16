#pragma once
#include "PizzaStore.h"

class ChicagoPizzaStore : public PizzaStore
{
	virtual Pizza* createPizza(PizzaType type) const override;
};

