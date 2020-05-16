#include "CurrentConditionDisplay.h"
#include "ForecastDisplay.h"
#include "WeatherData.h"
#include "WeatherMeasurements.h"

int main()
{
	WeatherMeasurements measurementsData1 = WeatherMeasurements(20.f, 30.f, "Average daytime maximum temperature will be around 16°„C, with a high for the two weeks of 30°„C");
	WeatherMeasurements measurementsData2 = WeatherMeasurements(15.f, 60.f, "Average daytime maximum temperature will be around 10°„C, with a high for the two weeks of 19°„C");
	WeatherMeasurements measurementsData3 = WeatherMeasurements(34.f, 10.f, "Average daytime maximum temperature will be around 29°„C, with a high for the two weeks of 34°„C");

	WeatherData weatherData = WeatherData(measurementsData1);
	CurrentConditionDisplay currentConditionDisplay = CurrentConditionDisplay(&weatherData);
	ForecastDisplay forecastDisplay = ForecastDisplay(&weatherData);

	weatherData.setMeasurements(measurementsData1);

	weatherData.removeObserver(&forecastDisplay);
	weatherData.setMeasurements(measurementsData2);

	weatherData.removeObserver(&currentConditionDisplay);
	weatherData.setMeasurements(measurementsData3);
}