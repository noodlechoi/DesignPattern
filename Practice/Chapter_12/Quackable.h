#pragma once
#include <vector>
#include <memory>

class QuackObservable;

class Observer
{
public:
	virtual void update(QuackObservable* duck) = 0;
};

class Quackologist : public Observer
{
public:
	void update(QuackObservable* duck) override;
};

class QuackObservable
{
public:
	virtual void registerObserver(Observer* observer) = 0;
	virtual void notifyObservers() = 0;
};

class Observable : public QuackObservable
{
	std::vector<Observer*> obeservers;
	std::shared_ptr<QuackObservable> duck;
public:
	Observable(QuackObservable* duck);
	void registerObserver(Observer* observer) override;
	void notifyObservers() override;
};

class Quackable : public QuackObservable
{
public:
	virtual void quack() = 0;
};