#include "NYPizzaStore.h"
#include "NYStyleCheesePizza.h"
#include "NYStyleClamPizza.h"
#include "NYStyleVeggiePizza.h"

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