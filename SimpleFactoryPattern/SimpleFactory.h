#pragma once

enum class PizzaType
{
    Cheese, Veggie, Clam
};

class SimpleFactory
{
public:
    class Pizza* createPizza(PizzaType type) const;
};