#pragma once
#include "Subject.h"
#include <vector>
#include "WeatherMeasurements.h"

class WeatherData : public Subject
{
private:
	std::vector<Observer *> observers;
	WeatherMeasurements measurements;

	virtual void notifyObservers() const override;
	void measurementsChanged() const;

public:
	WeatherData(const WeatherMeasurements& measurements);

	virtual void registerObserver(Observer *o) override;
	virtual void removeObserver(Observer *o) override;

	void setMeasurements(const WeatherMeasurements& measurements);
};