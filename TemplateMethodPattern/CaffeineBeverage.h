#pragma once

class CaffeineBeverage
{
public:
    // template method (not virtual)
    void prepareRecipe();
protected:
    // primitive operations 
    virtual void brew() = 0;
    virtual void heatWater() = 0;
    // concrete operation
    void pourInCup();
    // hook
    virtual void hook();
};