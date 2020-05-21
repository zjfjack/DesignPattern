#include <iostream>
#include "Pizza.h"
#include "NYPizzaStore.h"
#include "ChicagoPizzaStore.h"

int main()
{
    PizzaStore* newYorkStore = new NYPizzaStore();

    Pizza* newYorkCheesePizza = newYorkStore->orderPizza(PizzaType::Cheese);
    std::cout << "Ordered: " << newYorkCheesePizza->name << std::endl;

    Pizza* newYorkClamPizza = newYorkStore->orderPizza(PizzaType::Clam);
    std::cout << "Ordered: " << newYorkClamPizza->name << std::endl;

    Pizza* newYorkVeggiePizza = newYorkStore->orderPizza(PizzaType::Veggie);
    std::cout << "Ordered: " << newYorkVeggiePizza->name << std::endl;

    PizzaStore* chicagoStore = new ChicagoPizzaStore();

    Pizza* chicagoCheesePizza = chicagoStore->orderPizza(PizzaType::Cheese);
    std::cout << "Ordered: " << chicagoCheesePizza->name << std::endl;

    Pizza* chicagoClamPizza = chicagoStore->orderPizza(PizzaType::Clam);
    std::cout << "Ordered: " << chicagoClamPizza->name << std::endl;

    Pizza* chicagoVeggiePizza = chicagoStore->orderPizza(PizzaType::Veggie);
    std::cout << "Ordered: " << chicagoVeggiePizza->name << std::endl;


    delete newYorkStore;
    delete newYorkCheesePizza;
    delete newYorkClamPizza;
    delete newYorkVeggiePizza;

    delete chicagoStore;
    delete chicagoCheesePizza;
    delete chicagoClamPizza;
    delete chicagoVeggiePizza;
}