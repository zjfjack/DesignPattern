#pragma once

class QuackBehavior
{
public:
	virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
	virtual void quack() override;
};

class Squeak : public QuackBehavior
{
public:
	virtual void quack() override;
};

class MuteQuack : public QuackBehavior
{
public:
	virtual void quack() override;
};