#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

int main()
{
    PizzaStore* newYorkStore = new NYPizzaStore();

    Pizza* newYorkCheesePizza = newYorkStore->orderPizza(PizzaType::Cheese);
    std::cout << "Ordered -> " << newYorkCheesePizza->getDescription() << std::endl;

    Pizza* newYorkVeggiePizza = newYorkStore->orderPizza(PizzaType::Veggie);
    std::cout << "Ordered -> " << newYorkVeggiePizza->getDescription() << std::endl;

    PizzaStore* chicagoStore = new ChicagoPizzaStore();

    Pizza* chicagoCheesePizza = chicagoStore->orderPizza(PizzaType::Cheese);
    std::cout << "Ordered -> " << chicagoCheesePizza->getDescription() << std::endl;

    Pizza* chicagoVeggiePizza = chicagoStore->orderPizza(PizzaType::Veggie);
    std::cout << "Ordered -> " << chicagoVeggiePizza->getDescription() << std::endl;


    delete newYorkStore;
    delete newYorkCheesePizza;
    delete newYorkVeggiePizza;

    delete chicagoStore;
    delete chicagoCheesePizza;
    delete chicagoVeggiePizza;
}