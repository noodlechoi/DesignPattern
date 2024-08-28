#include "Ducks.h"
#include <iostream>

using namespace std;

MallardDuck::MallardDuck()
{
	observable = new Observable(this);
}

void MallardDuck::quack()
{
	cout << "�в�" << endl;
	notifyObservers();
}

void MallardDuck::registerObserver(Observer* observer)
{
	observable->registerObserver(observer);
}

void MallardDuck::notifyObservers()
{
	observable->notifyObservers();
}

// ==================================== //

RedheadDuck::RedheadDuck()
{
	observable = new Observable(this);
}

void RedheadDuck::quack()
{
	cout << "�в�" << endl;
	notifyObservers();
}

void RedheadDuck::registerObserver(Observer* observer)
{
	observable->registerObserver(observer);
}

void RedheadDuck::notifyObservers()
{
	observable->notifyObservers();
}

// ==================================== //

DuckCall::DuckCall()
{
	observable = new Observable(this);
}

void DuckCall::quack()
{
	cout << "�˲�" << endl;
	notifyObservers();
}

void DuckCall::registerObserver(Observer* observer)
{
	observable->registerObserver(observer);
}

void DuckCall::notifyObservers()
{
	observable->notifyObservers();
}

// ==================================== //

RubberDuck::RubberDuck()
{
	observable = new Observable(this);
}

void RubberDuck::quack()
{
	cout << "���" << endl;
	notifyObservers();
}

void RubberDuck::registerObserver(Observer* observer)
{
	observable->registerObserver(observer);
}

void RubberDuck::notifyObservers()
{
	observable->notifyObservers();
}

// ==================================== //

void Goose::honk()
{
	cout << "����" << endl;
}
