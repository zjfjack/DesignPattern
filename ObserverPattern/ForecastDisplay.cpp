#include "ForecastDisplay.h"
#include "Subject.h"
#include "WeatherMeasurements.h"
#include <iostream>

ForecastDisplay::ForecastDisplay(Subject* weatherData) : weatherData(weatherData)
{
	this->weatherData->registerObserver(this);
}

void ForecastDisplay::update(const WeatherMeasurements& measurements)
{
	forecast = measurements.forecast;
	display();
}

void ForecastDisplay::display()
{
	std::cout << "Weather forecast: " << forecast << std::endl;
}