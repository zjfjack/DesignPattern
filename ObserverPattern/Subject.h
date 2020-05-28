#pragma once
#include "Observer.h"
#include "WeatherMeasurements.h"
#include <vector>

class Subject
{
public:
    virtual ~Subject() = default;
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;

protected:
    virtual void notifyObservers() const = 0;
};

class WeatherData : public Subject
{
private:
    std::vector<Observer*> observers;
    WeatherMeasurements measurements;

    virtual void notifyObservers() const override;
    void measurementsChanged() const;

public:
    WeatherData(const WeatherMeasurements& measurements);

    virtual void registerObserver(Observer* o) override;
    virtual void removeObserver(Observer* o) override;

    void setMeasurements(const WeatherMeasurements& measurements);
};