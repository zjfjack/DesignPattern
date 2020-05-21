#include <iostream>
#include <memory>

// Target interface
class Duck
{
public:
    virtual ~Duck() = default;
    virtual void fly() = 0;
    virtual void quack() = 0;
};

class MallardDuck : public Duck
{
public:
    virtual void fly() override
    {
        std::cout << "I'm flying" << std::endl;
    }
    virtual void quack() override {
        std::cout << "Quack" << std::endl;
    }
};

// Adaptee interface
class Turkey
{
public:
    virtual ~Turkey() = default;
    virtual void fly() = 0;
    virtual void gobble() = 0;
};

// Adaptee concrete class
class WildTurkey : public Turkey
{
public:
    virtual void fly() override
    {
        std::cout << "I'm flying a short distance" << std::endl;
    }

    virtual void gobble() override
    {
        std::cout << "Gobble" << std::endl;
    }
};

class TurkeyAdapter : public Duck
{
private:
    std::unique_ptr<Turkey>& turkey;
public:
    TurkeyAdapter(std::unique_ptr<Turkey>& turkey) : turkey(turkey) {}

    virtual void fly() override
    {
        for (int i = 0; i < 5; i++)
            turkey->fly();
    }

    virtual void quack() override
    {
        turkey->gobble();
    }
};

void testDuck(const std::unique_ptr<Duck>& duck)
{
    duck->fly();
    duck->quack();
}

int main()
{
    std::unique_ptr<Duck> mallardDuck = std::make_unique<MallardDuck>();
    testDuck(mallardDuck);

    std::unique_ptr<Turkey> wildTurkey = std::make_unique<WildTurkey>();
    std::unique_ptr<Duck> turkeyAdpter = std::make_unique<TurkeyAdapter>(wildTurkey);
    testDuck(turkeyAdpter);
}