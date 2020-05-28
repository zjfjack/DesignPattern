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
    std::cout << "Current conditions: " << temperature << "¡ãC and " << humidity << "% humidity" << std::endl;
}