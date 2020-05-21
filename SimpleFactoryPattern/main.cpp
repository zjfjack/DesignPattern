#include <iostream>
#include "Pizza.h"
#include "PizzaStore.h"

int main()
{
    PizzaStore store = PizzaStore(SimpleFactory());

    Pizza* cheesePizza = store.orderPizza(PizzaType::Cheese);
    std::cout << "Ordered: " << cheesePizza->name << std::endl;

    Pizza* clamPizza = store.orderPizza(PizzaType::Clam);
    std::cout << "Ordered: " << clamPizza->name << std::endl;

    Pizza* veggiePizze = store.orderPizza(PizzaType::Veggie);
    std::cout << "Ordered: " << veggiePizze->name << std::endl;

    delete cheesePizza;
    delete clamPizza;
    delete veggiePizze;
}