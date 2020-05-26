#include "State.h"
#include "GumballMachine.h"
#include <iostream>
#include <random>
#include <time.h>

SoldState::~SoldState()
{
    std::cout << "SoldState destroyed" << std::endl;
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
    std::cout << "SoldOutState destroyed" << std::endl;
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
    std::cout << "NoQuarterState destroyed" << std::endl;
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

HasQuarterState::HasQuarterState()
{
    srand((unsigned)time(0));
}

HasQuarterState::~HasQuarterState()
{
    std::cout << "HasQuarterState destroyed" << std::endl;
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

        int randomNumber = rand();
        bool isWinner = ((randomNumber % 10) == 0) && (sharedGumballMachine->getCount() > 1);

        auto setState = isWinner ? GumballMachineState::Winner : GumballMachineState::Sold;
        sharedGumballMachine->setState(setState);
    }
    else
        std::cout << "weak_ptr gumballMachine is expired" << std::endl;
}

void HasQuarterState::dispense()
{
    std::cout << "No gumball dispensed" << std::endl;
}

WinnerState::~WinnerState()
{
    std::cout << "WinnerState destroyed" << std::endl;
}

void WinnerState::insertQuarter()
{
    std::cout << "You can't insert another quarte" << std::endl;
}

void WinnerState::ejectQuarter()
{
    std::cout << "Sorry, you already turned the crank" << std::endl;
}

void WinnerState::turnCrank()
{
    std::cout << "Turning twice doesn't get you another gumball" << std::endl;
}

void WinnerState::dispense()
{
    if (auto sharedGumballMachine = gumballMachine.lock())
    {
        std::cout << "YOU ARE A WINNER! You get two gumballs for your quarter" << std::endl;
        sharedGumballMachine->releaseBall();
        // no need to check count because it is checked in HasQuarter turnCrank
        sharedGumballMachine->releaseBall();

        // The same code as SoldState::dispense()
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