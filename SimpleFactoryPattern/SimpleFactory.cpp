#include "SimpleFactory.h"
#include "Pizza.h"

Pizza* SimpleFactory::createPizza(PizzaType type) const
{
    switch (type)
    {
    case PizzaType::Cheese:
        return new CheesePizza();
    case PizzaType::Veggie:
        return new VeggiePizza();
    case PizzaType::Clam:
        return new ClamPizza();
    }
}
// Cannot simply return &CheesePizza(), because memory will be released after return