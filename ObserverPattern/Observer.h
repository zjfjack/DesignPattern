#pragma once

class Observer
{
public:
	virtual void update(const struct WeatherMeasurements &measurements) = 0;
};