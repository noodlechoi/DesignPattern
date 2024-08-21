#include "Ducks.h"
#include <iostream>

using namespace std;

void MallardDuck::quack()
{
	cout << "²Ð²Ð" << endl;
}

void RedheadDuck::quack()
{
	cout << "²Ð²Ð" << endl;
}

void DuckCall::quack()
{
	cout << "²Ë²Ë" << endl;
}

void RubberDuck::quack()
{
	cout << "»à»à" << endl;
}

void Goose::honk()
{
	cout << "³£³£" << endl;
}

GooseAdapter::GooseAdapter(std::unique_ptr<Goose> goose)
{
	this->goose = std::move(goose);
}

void GooseAdapter::quack()
{
	goose->honk();
}

int QuackCounter::number = 0;

QuackCounter::QuackCounter(std::unique_ptr<Quackable> duck)
{
	this->duck = std::move(duck);
}

void QuackCounter::quack()
{
	duck->quack();
	number++;
}

std::unique_ptr<Quackable> DuckFactory::createMallardDuck()
{
	return std::move(std::make_unique<MallardDuck>());
}

std::unique_ptr<Quackable> DuckFactory::createRedheadDuck()
{
	return std::move(std::make_unique<RedheadDuck>());
}

std::unique_ptr<Quackable> DuckFactory::createDuckCall()
{
	return std::move(std::make_unique<DuckCall>());
}

std::unique_ptr<Quackable> DuckFactory::createRubberDuck()
{
	return std::move(std::make_unique<RubberDuck>());
}

std::unique_ptr<Quackable> CountingDuckFactory::createMallardDuck()
{
	return std::move(std::make_unique<QuackCounter>(std::make_unique<MallardDuck>()));
}

std::unique_ptr<Quackable> CountingDuckFactory::createRedheadDuck()
{
	return std::move(std::make_unique<QuackCounter>(std::make_unique<RedheadDuck>()));
}

std::unique_ptr<Quackable> CountingDuckFactory::createDuckCall()
{
	return std::move(std::make_unique<QuackCounter>(std::make_unique<DuckCall>()));
}

std::unique_ptr<Quackable> CountingDuckFactory::createRubberDuck()
{
	return std::move(std::make_unique<QuackCounter>(std::make_unique<RubberDuck>()));
}