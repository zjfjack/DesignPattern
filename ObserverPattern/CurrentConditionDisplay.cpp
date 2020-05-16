#include "CurrentConditionDisplay.h"
#include "Subject.h"
#include "WeatherMeasurements.h"
#include <iostream>

CurrentConditionDisplay::CurrentConditionDisplay(Subject* weatherData) : weatherData(weatherData)
{
	this->weatherData->registerObserver(this);
}

void CurrentConditionDisplay::update(const WeatherMeasurements& measurements)
{
	temperature = measurements.temperature;
	humidity = measurements.humidity;
	display();
}

void CurrentConditionDisplay::display()
{
	std::cout << "Current conditions: " << temperature << "��C and " << humidity << "% humidity" << std::endl;
}