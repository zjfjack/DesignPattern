#pragma once
#include <string>

struct WeatherMeasurements
{
    float temperature, humidity;
    std::string forecast;
    WeatherMeasurements(float temp, float humid, std::string forecast) : temperature(temp), humidity(humid), forecast(forecast) {}
};