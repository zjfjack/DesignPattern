#include "GumballMachine.h"
#include "State.h"

GumballMachine::GumballMachine() :
    soldOutState(std::make_shared<SoldOutState>()), 
    noQuarterState(std::make_shared<NoQuarterState>()),
    hasQuarterState(std::make_shared<HasQuarterState>()),
    soldState(std::make_shared<SoldState>())
{
    if (count > 0)
        state = noQuarterState;
    else
        state = soldOutState;
}

void GumballMachine::setState(GumballMachineState state)
{
    switch (state)
    {
    case GumballMachineState::SoldOut:
        this->state = soldOutState;
        break;
    case GumballMachineState::NoQuarter:
        this->state = noQuarterState;
        break;
    case GumballMachineState::HasQuarter:
        this->state = hasQuarterState;
        break;
    case GumballMachineState::Sold:
        this->state = soldOutState;
        break;
    }
}

unsigned int GumballMachine::getCount()
{
    return count;
}