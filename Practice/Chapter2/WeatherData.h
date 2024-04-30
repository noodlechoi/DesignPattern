#pragma once
#include <list>
#include <iostream>
#include <string>
#include "Interface.h"

class WeatherData : public Subject	// Subject ����
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

	void notifyObservers() override	// ��� ���������� ���� ��ȭ�� �˷���
	{
		for (Observer* observer : observers) {
			observer->update(temperature, humidity, pressure);
		}
	}

	void measurementsChanged()	// ��� �����̼����κ��� ���ŵ� �������� �������鿡�� �˸�
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