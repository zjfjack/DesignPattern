#pragma once
#include <string>

// Abstract Product
class Pizza
{
public:
    virtual ~Pizza() = default;
    std::string name;
};

// Concrete Product
class NYStyleCheesePizza : public Pizza
{
public:
    NYStyleCheesePizza();
};

// Concrete Product
class NYStyleClamPizza : public Pizza
{
public:
    NYStyleClamPizza();
};

// Concrete Product
class NYStyleVeggiePizza : public Pizza
{
public:
    NYStyleVeggiePizza();
};

// Concrete Product
class ChicagoStyleCheesePizza : public Pizza
{
public:
    ChicagoStyleCheesePizza();
};

// Concrete Product
class ChicagoStyleClamPizza : public Pizza
{
public:
    ChicagoStyleClamPizza();
};

// Concrete Product
class ChicagoStyleVeggiePizza : public Pizza
{
public:
    ChicagoStyleVeggiePizza();
};