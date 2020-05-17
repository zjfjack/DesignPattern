#include "Pizza.h"

Pizza::~Pizza()
{
	delete pizzaIngredientFactory;
	delete dough;
	delete sauce;
	delete cheese;
}

std::string Pizza::getDescription() const
{
	std::string description = "Pizza name: " + name + ", Pizza ingredients: ";
	description += dough->description;
	if (sauce)
		description += (", " + sauce->description);
	if (cheese)
		description += (", " + cheese->description);
	return description;
}

CheesePizza::CheesePizza(PizzaIngredientFactory* pizzaIngredientFactory, const std::string& name)
{
	this->pizzaIngredientFactory = pizzaIngredientFactory;
	this->name = name;
}

void CheesePizza::prepare()
{
	dough = pizzaIngredientFactory->createDough();
	sauce = pizzaIngredientFactory->createSauce();
	cheese = pizzaIngredientFactory->createCheese();
}

VeggiePizza::VeggiePizza(PizzaIngredientFactory* pizzaIngredientFactory, const std::string& name)
{
	this->pizzaIngredientFactory = pizzaIngredientFactory;
	this->name = name;
}

void VeggiePizza::prepare()
{
	dough = pizzaIngredientFactory->createDough();
	sauce = pizzaIngredientFactory->createSauce();
	// cheese initialisation is optional here, it is the benefit from virtual function prepare
	// If prepare is defined in base class, then it cannot be overridden
}