#include "Patterns.h"

GooseAdapter::GooseAdapter(std::unique_ptr<Goose> goose) : goose(std::move(goose))
{
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

// ==================================== //

std::unique_ptr<Quackable> DuckFactory::createMallardDuck()
{
	return std::make_unique<MallardDuck>();
}

std::unique_ptr<Quackable> DuckFactory::createRedheadDuck()
{
	return std::make_unique<RedheadDuck>();
}

std::unique_ptr<Quackable> DuckFactory::createDuckCall()
{
	return std::make_unique<DuckCall>();
}

std::unique_ptr<Quackable> DuckFactory::createRubberDuck()
{
	return std::make_unique<RubberDuck>();
}

// ==================================== //

std::unique_ptr<Quackable> CountingDuckFactory::createMallardDuck()
{
	return std::make_unique<QuackCounter>(std::make_unique<MallardDuck>());
}

std::unique_ptr<Quackable> CountingDuckFactory::createRedheadDuck()
{
	return std::make_unique<QuackCounter>(std::make_unique<RedheadDuck>());
}

std::unique_ptr<Quackable> CountingDuckFactory::createDuckCall()
{
	return std::make_unique<QuackCounter>(std::make_unique<DuckCall>());
}

std::unique_ptr<Quackable> CountingDuckFactory::createRubberDuck()
{
	return std::make_unique<QuackCounter>(std::make_unique<RubberDuck>());
}

// ==================================== //

Flock::Flock()
{
}

void Flock::add(std::unique_ptr<Quackable>& quacker)
{
	quackers.push_back(std::move(quacker));
}

void Flock::quack()
{
	for (const auto& quacker : quackers) {
		quacker->quack();
	}
}
