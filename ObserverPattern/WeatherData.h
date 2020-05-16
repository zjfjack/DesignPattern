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
	WeatherData(WeatherMeasurements measurements);

	virtual void registerObserver(Observer *o) override;
	virtual void removeObserver(Observer *o) override;

	void setMeasurements(WeatherMeasurements measurements);
};