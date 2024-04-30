#pragma once
#include "WeatherData.h"

// Current Condition Display
class CCD : public Observer, DisplayElement
{
private:
	float temperature{};
	float humidity{};
	WeatherData* weatherData;
public:
	CCD(WeatherData* weatherData)
	{
		this->weatherData = weatherData;	// 옵저버 목록에서 탈퇴할 때 써먹을 수 있음
		weatherData->registerObserver(this);
	}

	virtual void update(float temperature, float humidity, float pressure) override
	{
		this->temperature = temperature;
		this->humidity = humidity;
		display();	// 이게 최선일까? 12장에서 자세히 배움
	}

	virtual void display() override
	{
		std::cout << "현재 상태: 온도" + std::to_string(temperature) + "F, 습도 " + std::to_string(humidity) + "%" << std::endl;
	}
};