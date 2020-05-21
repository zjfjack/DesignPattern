#pragma once
#include "Dough.h"
#include "Cheese.h"
#include "Sauce.h"

// Abtract factory
class PizzaIngredientFactory
{
public:
    virtual ~PizzaIngredientFactory() = default;
    virtual Dough* createDough() const = 0;
    virtual Cheese* createCheese() const = 0;
    virtual Sauce* createSauce() const = 0;
};

// Concrete factory
class NYPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    virtual Dough* createDough() const override;
    virtual Cheese* createCheese() const override;
    virtual Sauce* createSauce() const override;
};

// Concrete factory
class ChicagoPizzaIngredientFactory : public PizzaIngredientFactory
{
public:
    virtual Dough* createDough() const override;
    virtual Cheese* createCheese() const override;
    virtual Sauce* createSauce() const override;
};