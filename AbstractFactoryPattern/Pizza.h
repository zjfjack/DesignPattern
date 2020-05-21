#pragma once
#include <string>
#include "Dough.h"
#include "Sauce.h"
#include "Cheese.h"
#include "PizzaIngredientFactory.h"

class Pizza
{
public:
    virtual ~Pizza();
    std::string getDescription() const;
    virtual void prepare() = 0;

protected:
    PizzaIngredientFactory* pizzaIngredientFactory = nullptr;
    std::string name;
    Dough* dough = nullptr;
    Sauce* sauce = nullptr;
    Cheese* cheese = nullptr;
};

class CheesePizza : public Pizza
{
public:
    CheesePizza(PizzaIngredientFactory* pizzaIngredientFactory, const std::string& name);
protected:
    virtual void prepare() override;
};

class VeggiePizza : public Pizza
{
public:
    VeggiePizza(PizzaIngredientFactory* pizzaIngredientFactory, const std::string& name);
protected:
    virtual void prepare() override;
};