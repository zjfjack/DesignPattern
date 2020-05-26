#include "GumballMachine.h"
#include "State.h"

GumballMachine::GumballMachine(int numberGumballs) :
    soldOutState(std::make_shared<SoldOutState>()), 
    noQuarterState(std::make_shared<NoQuarterState>()),
    hasQuarterState(std::make_shared<HasQuarterState>()),
    soldState(std::make_shared<SoldState>()),
    winnerState(std::make_shared<WinnerState>()),
    count(numberGumballs)
{
    if (count > 0)
        state = noQuarterState;
    else
        state = soldOutState;
}

GumballMachine::~GumballMachine()
{
    std::cout << "Gumball Machine destroyed" << std::endl;
}

void GumballMachine::setupStateThisWeakPointer()
{
    const auto& weakPtr = weak_from_this();
    soldOutState->gumballMachine = weakPtr;
    noQuarterState->gumballMachine = weakPtr;
    hasQuarterState->gumballMachine = weakPtr;
    soldState->gumballMachine = weakPtr;
    winnerState->gumballMachine = weakPtr;
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
    case GumballMachineState::Winner:
        this->state = winnerState;
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

void GumballMachine::refill(int numberGumballs)
{
    state = noQuarterState;
    count += numberGumballs;
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
    else if (gumballMachine.state == gumballMachine.soldState)
        stateString = "Sold";
    else
        stateString = "Winner";
        
    return stream << "GumballMachine state: " << stateString << " number of balls: " << gumballMachine.count << std::endl;
}