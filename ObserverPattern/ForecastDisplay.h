#pragma once
#include "Observer.h"
#include "DisplayElement.h"
#include <string>

class ForecastDisplay : public Observer, public DisplayElement
{
private:
	std::string forecast;
	class Subject* weatherData = nullptr;

public:
	ForecastDisplay(Subject* weatherData);
	virtual void update(const struct WeatherMeasurements& measurements) override;
	virtual void display() override;
};