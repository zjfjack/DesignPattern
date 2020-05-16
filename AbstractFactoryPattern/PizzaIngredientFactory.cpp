#include "PizzaIngredientFactory.h"

Dough* NYPizzaIngredientFactory::createDough() const
{
	return new ThickCrustDough();
}

Cheese* NYPizzaIngredientFactory::createCheese() const
{
	return new MozzarellaCheese();
}

Sauce* NYPizzaIngredientFactory::createSauce() const
{
	return new MarinaraSauce();
}

Dough* ChicagoPizzaIngredientFactory::createDough() const
{
	return new ThinCrustDough();
}

Cheese* ChicagoPizzaIngredientFactory::createCheese() const
{
	return new ReggianoCheese();
}

Sauce* ChicagoPizzaIngredientFactory::createSauce() const
{
	return new MarinaraSauce();
}