#pragma once

class FlyBehavior
{
public:
	virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
	virtual void fly() override;
};

class FlyNoWay : public FlyBehavior
{
public:
	virtual void fly() override;
};