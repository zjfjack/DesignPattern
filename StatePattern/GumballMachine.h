#pragma once
#include <memory>
#include <iostream>

class State;

enum class GumballMachineState
{
    SoldOut, NoQuarter, HasQuarter, Sold, Winner
};

class GumballMachine : public std::enable_shared_from_this<GumballMachine>
{
public:
    GumballMachine(int numberGumballs);
    ~GumballMachine();

    void setupStateThisWeakPointer();
    void setState(GumballMachineState state);
    unsigned int getCount();

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void releaseBall();
    void refill(int numberGumballs);

    friend std::ostream& operator<<(std::ostream& stream, const GumballMachine& gumballMachine);
private:
    std::shared_ptr<State> soldOutState;
    std::shared_ptr<State> noQuarterState;
    std::shared_ptr<State> hasQuarterState;
    std::shared_ptr<State> soldState;
    std::shared_ptr<State> winnerState;

    std::shared_ptr<State> state = nullptr;
    int count = 0;
};