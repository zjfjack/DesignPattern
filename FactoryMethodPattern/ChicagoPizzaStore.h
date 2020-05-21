#pragma once
#include "PizzaStore.h"

// Concrete Creator
class ChicagoPizzaStore : public PizzaStore
{
    virtual Pizza* createPizza(PizzaType type) const override;
};