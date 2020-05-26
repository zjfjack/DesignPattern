#include "GumballMachine.h"

int main()
{
    std::shared_ptr<GumballMachine> gumballMachine = std::make_shared<GumballMachine>(5);
    gumballMachine->setupStateThisWeakPointer();

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << *gumballMachine << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->ejectQuarter();
    gumballMachine->turnCrank();
    std::cout << *gumballMachine << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->ejectQuarter();
    std::cout << *gumballMachine << std::endl;

    gumballMachine->insertQuarter();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    gumballMachine->insertQuarter();
    gumballMachine->turnCrank();
    std::cout << *gumballMachine << std::endl;
}