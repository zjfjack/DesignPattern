#pragma once
#include "Pizza.h"

enum class PizzaType
{
    Cheese, Veggie, Clam
};

// Abstract Creator
class PizzaStore
{
public:
    virtual ~PizzaStore() = default;
    Pizza* orderPizza(PizzaType type) const;
protected:
    // abstract Product factoryMethod(String type)
    virtual Pizza* createPizza(PizzaType type) const = 0;
};

// Concrete Creator
class NYPizzaStore : public PizzaStore
{
    virtual Pizza* createPizza(PizzaType type) const override;
};

// Concrete Creator
class ChicagoPizzaStore : public PizzaStore
{
    virtual Pizza* createPizza(PizzaType type) const override;
};