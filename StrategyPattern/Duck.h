#pragma once

class Duck
{
protected:
	class FlyBehavior* flyBehavior;
	class QuackBehavior* quackBehavior;
public:
	virtual ~Duck();
	virtual void display() = 0;
	void performFly();
	void performQuack();
};