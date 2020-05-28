#pragma once
#include <string>

class Subject;

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void update(const struct WeatherMeasurements &measurements) = 0;
};

class DisplayElement
{
public:
    virtual ~DisplayElement() = default;
    virtual void display() = 0;
};

class ForecastDisplay : public Observer, public DisplayElement
{
private:
    std::string forecast;
    Subject* weatherData = nullptr;

public:
    ForecastDisplay(Subject* weatherData);
    virtual void update(const struct WeatherMeasurements& measurements) override;
    virtual void display() override;
};

class CurrentConditionDisplay : public Observer, public DisplayElement
{
private:
    float temperature;
    float humidity;
    Subject* weatherData = nullptr;

public:
    CurrentConditionDisplay(Subject* weatherData);
    virtual void update(const struct WeatherMeasurements& measurements) override;
    virtual void display() override;
};