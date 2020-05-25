#pragma once
#include <memory>

class GumballMachine;

class State
{
public:
    virtual ~State() = default;
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
    std::weak_ptr<GumballMachine> gumballMachine;
};

class SoldState : public State
{
public:
    virtual void insertQuarter() override;
    virtual void ejectQuarter() override;
    virtual void turnCrank() override;
    virtual void dispense() override;
};

class SoldOutState : public State
{
public:
    virtual void insertQuarter() override;
    virtual void ejectQuarter() override;
    virtual void turnCrank() override;
    virtual void dispense() override;
};

class NoQuarterState : public State
{
public:
    virtual void insertQuarter() override;
    virtual void ejectQuarter() override;
    virtual void turnCrank() override;
    virtual void dispense() override;
};

class HasQuarterState : public State
{
public:
    virtual void insertQuarter() override;
    virtual void ejectQuarter() override;
    virtual void turnCrank() override;
    virtual void dispense() override;
};