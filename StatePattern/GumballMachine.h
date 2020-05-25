#pragma once
#include <memory>

class State;

enum class GumballMachineState
{
    SoldOut, NoQuarter, HasQuarter, Sold
};

class GumballMachine : std::enable_shared_from_this<GumballMachine>
{
public:
    GumballMachine();
    void setState(GumballMachineState state);
    unsigned int getCount();
private:
    std::shared_ptr<State> soldOutState;
    std::shared_ptr<State> noQuarterState;
    std::shared_ptr<State> hasQuarterState;
    std::shared_ptr<State> soldState;

    std::shared_ptr<State> state = nullptr;
    int count = 0;
};