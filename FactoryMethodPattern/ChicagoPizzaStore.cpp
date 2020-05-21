#include "ChicagoPizzaStore.h"
#include "ChicagoStyleCheesePizza.h"
#include "ChicagoStyleClamPizza.h"
#include "ChicagoStyleVeggiePizza.h"

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