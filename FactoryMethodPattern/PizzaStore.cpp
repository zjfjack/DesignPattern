#include "PizzaStore.h"

Pizza* PizzaStore::orderPizza(PizzaType type) const
{
	return createPizza(type);
}