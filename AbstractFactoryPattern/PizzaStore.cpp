#include "PizzaStore.h"

Pizza* PizzaStore::orderPizza(PizzaType type) const
{
    return createPizza(type);
}

Pizza* ChicagoPizzaStore::createPizza(PizzaType type) const
{
    ChicagoPizzaIngredientFactory* chicagoPizzaIngredientFactory = new ChicagoPizzaIngredientFactory();
    Pizza* pizza = nullptr;
    switch (type)
    {
    case PizzaType::Cheese:
        pizza = new CheesePizza(chicagoPizzaIngredientFactory, "Chicago Cheese Pizza");
        break;
    case PizzaType::Veggie:
        pizza = new VeggiePizza(chicagoPizzaIngredientFactory, "Chicago Veggie Pizza");
        break;
    }
    pizza->prepare();
    return pizza;
}

Pizza* NYPizzaStore::createPizza(PizzaType type) const
{
    NYPizzaIngredientFactory* nyPizzaIngredientFactory = new NYPizzaIngredientFactory();
    Pizza* pizza = nullptr;
    switch (type)
    {
    case PizzaType::Cheese:
        pizza = new CheesePizza(nyPizzaIngredientFactory, "New York Cheese Pizza");
        break;
    case PizzaType::Veggie:
        pizza = new VeggiePizza(nyPizzaIngredientFactory, "New York Veggie Pizza");
        break;
    }
    pizza->prepare();
    return pizza;
}