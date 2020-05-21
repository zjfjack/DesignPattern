#include "PizzaStore.h"

Pizza* PizzaStore::orderPizza(PizzaType type) const
{
    return createPizza(type);
}

Pizza* NYPizzaStore::createPizza(PizzaType type) const
{
    switch (type)
    {
    case PizzaType::Cheese:
        return new NYStyleCheesePizza();
    case PizzaType::Veggie:
        return new NYStyleVeggiePizza();
    case PizzaType::Clam:
        return new NYStyleClamPizza();
    }
}

Pizza* ChicagoPizzaStore::createPizza(PizzaType type) const
{
    switch (type)
    {
    case PizzaType::Cheese:
        return new ChicagoStyleCheesePizza();
    case PizzaType::Veggie:
        return new ChicagoStyleVeggiePizza();
    case PizzaType::Clam:
        return new ChicagoStyleClamPizza();
    }
}