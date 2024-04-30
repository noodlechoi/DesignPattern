#pragma once
#include <list>
#include <iostream>
#include <string>
#include "Interface.h"

class WeatherData : public Subject	// Subject 구현
{
private:
	std::list<Observer*> observers;
	float temperature;
	float humidity;
	float pressure;
public:
	WeatherData()
	{
	}

	void registerObserver(Observer* o) override
	{
		observers.push_back(o);
	}

	void removeObserver(Observer* o) override
	{
		observers.remove(o);
	}

	void notifyObservers() override	// 모든 옵저버에게 상태 변화를 알려줌
	{
		for (Observer* observer : observers) {
			observer->update(temperature, humidity, pressure);
		}
	}

	void measurementsChanged()	// 기상 스테이션으로부터 갱신된 측정값을 옵저버들에게 알림
	{
		notifyObservers();
	}

	void setMeasurements(float t, float h, float p)
	{
		this->temperature = t;
		this->humidity = h;
		this->pressure = p;
		measurementsChanged();
	}
};