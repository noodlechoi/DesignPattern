#pragma once

class Observer
{
public:
	virtual void update() = 0;
};

class Subject
{
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void removeObserver(Observer* o) = 0;
	virtual void notifyObservers() = 0;
};

class DisplayElement
{
public:
	virtual void display() = 0;
};