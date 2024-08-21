#pragma once
#include "Ducks.h"

class DuckSimulator
{
private:
	std::unique_ptr<Quackable> mallardDuck;
	std::unique_ptr<Quackable> redheadDuck;
	std::unique_ptr<Quackable> duckCall;
	std::unique_ptr<Quackable> rubberDuck;
	std::unique_ptr<Quackable> gooseDuck;
public:
	DuckSimulator();
	void simulate();
	void simulate(std::unique_ptr<Quackable>& duck);
};

