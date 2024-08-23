#pragma once
#include "Patterns.h"

class DuckSimulator
{
private:
	
	std::unique_ptr<Flock> flockOfDucks;
	std::unique_ptr<Flock> flockOfmallards;
public:
	DuckSimulator() = delete;
	DuckSimulator(std::unique_ptr<AbstractDuckFactory> duckFactory);
	void simulate();
	void simulate(Quackable& duck);
};