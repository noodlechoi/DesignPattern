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
		this->weatherData = weatherData;	// ������ ��Ͽ��� Ż���� �� ����� �� ����
		weatherData->registerObserver(this);
	}

	virtual void update(float temperature, float humidity, float pressure) override
	{
		this->temperature = temperature;
		this->humidity = humidity;
		display();	// �̰� �ּ��ϱ�? 12�忡�� �ڼ��� ���
	}

	virtual void display() override
	{
		std::cout << "���� ����: �µ�" + std::to_string(temperature) + "F, ���� " + std::to_string(humidity) + "%" << std::endl;
	}
};