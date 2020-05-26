#include "State.h"
#include "GumballMachine.h"
#include <iostream>

SoldState::~SoldState()
{
    std::cout << "SoldState destoryed" << std::endl;
}

void SoldState::insertQuarter()
{
    std::cout << "Please wait, we're already giving you a gumball" << std::endl;
}

void SoldState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank" << std::endl;
}

void SoldState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball" << std::endl;
}

void SoldState::dispense()
{
    if (auto sharedGumballMachine = gumballMachine.lock())
    {
        sharedGumballMachine->releaseBall();
        if (sharedGumballMachine->getCount() > 0)
            sharedGumballMachine->setState(GumballMachineState::NoQuarter);
        else
        {
            std::cout << "Oops, out of gumballs" << std::endl;
            sharedGumballMachine->setState(GumballMachineState::SoldOut);
        }
    }
    else
        std::cout << "weak_ptr gumballMachine is expired" << std::endl;
}

SoldOutState::~SoldOutState()
{
    std::cout << "SoldOutState destoryed" << std::endl;
}

void SoldOutState::insertQuarter()
{
    std::cout << "You can't insert a quarter, the machine is sold out" << std::endl;
}

void SoldOutState::ejectQuarter()
{
    std::cout << "You can't eject, you haven't inserted a quarter yet" << std::endl;
}

void SoldOutState::turnCrank()
{
    std::cout << "You turned, but there are no gumballs" << std::endl;
}

void SoldOutState::dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

NoQuarterState::~NoQuarterState()
{
    std::cout << "NoQuarterState destoryed" << std::endl;
}

void NoQuarterState::insertQuarter()
{
    std::cout << "You inserted a quarter" << std::endl;
    if (auto sharedGumballMachine = gumballMachine.lock())
    {
        sharedGumballMachine->setState(GumballMachineState::HasQuarter);
    }
    else
        std::cout << "weak_ptr gumballMachine is expired" << std::endl;
}

void NoQuarterState::ejectQuarter()
{
    std::cout << "You haven't inserted a quarter" << std::endl;
}

void NoQuarterState::turnCrank()
{
    std::cout << "You turned, but there is no quarter" << std::endl;
}

void NoQuarterState::dispense()
{
    std::cout << "You need to pay first" << std::endl;
}

HasQuarterState::~HasQuarterState()
{
    std::cout << "HasQuarterState destoryed" << std::endl;
}

void HasQuarterState::insertQuarter()
{
    std::cout << "You can't insert another quarter" << std::endl;
}

void HasQuarterState::ejectQuarter()
{
    std::cout << "Quarter returned" << std::endl;
    if (auto sharedGumballMachine = gumballMachine.lock())
    {
        sharedGumballMachine->setState(GumballMachineState::NoQuarter);
    }
    else
        std::cout << "weak_ptr gumballMachine is expired" << std::endl;
}

void HasQuarterState::turnCrank()
{
    if (auto sharedGumballMachine = gumballMachine.lock())
    {
        std::cout << "You turned..." << std::endl;
        sharedGumballMachine->setState(GumballMachineState::Sold);
    }
    else
        std::cout << "weak_ptr gumballMachine is expired" << std::endl;
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}