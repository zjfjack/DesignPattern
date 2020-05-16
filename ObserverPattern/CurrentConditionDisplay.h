#pragma once
#include "Observer.h"
#include "DisplayElement.h"

class CurrentConditionDisplay : public Observer, public DisplayElement
{
private:
	float temperature;
	float humidity;
	class Subject *weatherData = nullptr;

public:
	CurrentConditionDisplay(Subject* weatherData);
	virtual void update(const struct WeatherMeasurements& measurements) override;
	virtual void display() override;
};