#include <iostream>
#include <memory>

// Target concrete class (Target in class adpater pattern has to be concrete class)
class Duck
{
public:
    virtual ~Duck() = default;
    virtual void flyDuck()
    {
        std::cout << "I'm flying" << std::endl;
    }
    virtual void quack() {
        std::cout << "Quack" << std::endl;
    }
};

// Adaptee concrete class (Adaptee in class adpater pattern has to be concrete class)
class Turkey
{
public:
    virtual ~Turkey() = default;
    virtual void flyTurkey()
    {
        std::cout << "I'm flying a short distance" << std::endl;
    }

    virtual void gobble()
    {
        std::cout << "Gobble" << std::endl;
    }
};

// Adapter is Multiple inheritance from Target and Adaptees
class TurkeyAdapter : public Duck, private Turkey
{
public:
    virtual void quack() override
    {
        Turkey::gobble();
    }

    virtual void flyDuck() override
    {
        for (int i = 0; i < 5; i++)
            Turkey::flyTurkey();
    }
};

void testDuck(const std::unique_ptr<Duck>& duck)
{
    duck->flyDuck();
    duck->quack();
}

int main()
{
    std::unique_ptr<Duck> duck = std::make_unique<Duck>();
    testDuck(duck);

    std::unique_ptr<Duck> turkeyAdpter = std::make_unique<TurkeyAdapter>();
    testDuck(turkeyAdpter);

    // std::unique_ptr<Turkey> wrongDuckAdpter = std::make_unique<TurkeyAdapter>(); not allowed because base class Turkey is private // Target is Duck!!!
}