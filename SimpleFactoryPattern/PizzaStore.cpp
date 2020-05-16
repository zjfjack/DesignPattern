#include "PizzaStore.h"

PizzaStore::PizzaStore(const SimpleFactory &factory)
{
	this->factory = factory;
}

Pizza* PizzaStore::orderPizza(PizzaType type) const
{
	return factory.createPizza(type);
}