#pragma once
#include "PizzaStore.h"

// Concrete Creator
class NYPizzaStore : public PizzaStore
{
    virtual Pizza* createPizza(PizzaType type) const override;
};