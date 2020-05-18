#pragma once
#include <iostream>

class Fan
{
public:
	enum Speed
	{
		Off, Low, Medium, High
	};

public:
	void high();
	void medium();
	void low();
	void off();
	int getSpeed() const;
private:
	int speed = 0;
};