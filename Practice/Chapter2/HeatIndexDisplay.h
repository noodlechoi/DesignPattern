#pragma once
#include "WeatherData.h"

class HID : public Observer, DisplayElement
{
private:
	float heatIndex{};
	WeatherData* weatherData;

	float computeHeatIndex(float t, float rh) {
		float index = (float)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh)
			+ (0.00941695 * (t * t)) + (0.00728898 * (rh * rh))
			+ (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
			(0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 *
				(rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) +
			(0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +
			0.000000000843296 * (t * t * rh * rh * rh)) -
			(0.0000000000481975 * (t * t * t * rh * rh * rh)));
		return index;
	}

public:
	HID(WeatherData* weatherData)
	{
		this->weatherData = weatherData;	// ������ ��Ͽ��� Ż���� �� ����� �� ����
		weatherData->registerObserver(this);
	}

	virtual void update() override
	{
		heatIndex = computeHeatIndex(weatherData->getTemperature(), weatherData->getHumidity());
		display();
	}
	virtual void display() override
	{
		std::cout << "Heat index is " + std::to_string(heatIndex) << std::endl;
	}
};