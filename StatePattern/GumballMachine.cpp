#include "GumballMachine.h"
#include "State.h"

GumballMachine::GumballMachine(int numberGumballs) :
    soldOutState(std::make_shared<SoldOutState>()), 
    noQuarterState(std::make_shared<NoQuarterState>()),
    hasQuarterState(std::make_shared<HasQuarterState>()),
    soldState(std::make_shared<SoldState>()),
    count(numberGumballs)
{
    if (count > 0)
        state = noQuarterState;
    else
        state = soldOutState;
}

GumballMachine::~GumballMachine()
{
    std::cout << "Gumball Machine destoryed" << std::endl;
}

void GumballMachine::setupStateThisWeakPointer()
{
    const auto& weakPtr = weak_from_this();
    soldOutState->gumballMachine = weakPtr;
    noQuarterState->gumballMachine = weakPtr;
    hasQuarterState->gumballMachine = weakPtr;
    soldState->gumballMachine = weakPtr;
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
        this->state = soldState;
        break;
    }
}

unsigned int GumballMachine::getCount()
{
    return count;
}

void GumballMachine::insertQuarter()
{
    state->insertQuarter();
}

void GumballMachine::ejectQuarter()
{
    state->ejectQuarter();
}

void GumballMachine::turnCrank()
{
    state->turnCrank();
    state->dispense();
}

void GumballMachine::releaseBall()
{
    std::cout << "A gumball comes rolling out the slot..." << std::endl;
    if (count != 0)
        count -= 1;
}

std::ostream& operator<<(std::ostream& stream, const GumballMachine& gumballMachine)
{
    std::string stateString;
    if (gumballMachine.state == gumballMachine.soldOutState)
        stateString = "SoldOut";
    else if (gumballMachine.state == gumballMachine.hasQuarterState)
        stateString = "HasQuarter";
    else if (gumballMachine.state == gumballMachine.noQuarterState)
        stateString = "noQuarter";
    else
        stateString = "Sold";
        
    return stream << "GumballMachine state: " << stateString << " number of balls: " << gumballMachine.count << std::endl;
}