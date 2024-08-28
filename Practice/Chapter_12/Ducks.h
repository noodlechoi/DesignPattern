#pragma once
#include "Quackable.h"

class MallardDuck : public Quackable
{
	Observable* observable;
public:
	MallardDuck();
	void quack() override;
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};

class RedheadDuck : public Quackable
{
	Observable* observable;
public:
	RedheadDuck();
	void quack() override;
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};

class DuckCall : public Quackable
{
	Observable* observable;
public:
	DuckCall();
	void quack() override;
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};

class RubberDuck : public Quackable
{
	Observable* observable;
public:
	RubberDuck();
	void quack() override;
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};

class Goose
{
	Observable* observable;
public:
	void honk();
};
