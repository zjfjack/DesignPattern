#pragma once
#include "PizzaType.h"
#include "Pizza.h"

class PizzaStore
{
public:
    virtual ~PizzaStore() = default;
    Pizza* orderPizza(PizzaType type) const;
protected:
    // abstract Product factoryMethod(String type)
    virtual Pizza* createPizza(PizzaType type) const = 0;
};

class ChicagoPizzaStore : public PizzaStore
{
protected:
    virtual Pizza* createPizza(PizzaType type) const override;
};

class NYPizzaStore : public PizzaStore
{
protected:
    virtual Pizza* createPizza(PizzaType type) const override;
};