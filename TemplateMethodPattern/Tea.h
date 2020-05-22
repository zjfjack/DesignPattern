#pragma once
#include "CaffeineBeverage.h"

class Tea : public CaffeineBeverage
{
protected:
    virtual void heatWater() override;
    virtual void brew() override;
    virtual void hook() override;
private:
    void addLemon();
};