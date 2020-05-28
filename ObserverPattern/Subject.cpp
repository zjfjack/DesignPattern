#include "Subject.h"
#include <algorithm>

WeatherData::WeatherData(const WeatherMeasurements& measurements)
    : measurements(measurements) {}

void WeatherData::registerObserver(Observer* o)
{
    observers.push_back(o);
}

void WeatherData::removeObserver(Observer* o)
{
    observers.erase(std::remove(observers.begin(), observers.end(), o), observers.end());
}

void WeatherData::notifyObservers() const
{
    for (Observer* observer : observers)
        observer->update(measurements);
}

void WeatherData::measurementsChanged() const
{
    notifyObservers();
}

void WeatherData::setMeasurements(const WeatherMeasurements& measurements)
{
    this->measurements = measurements;
    measurementsChanged();
}