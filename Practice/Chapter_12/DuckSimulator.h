#pragma once
#include "Patterns.h"

class DuckSimulator
{
private:
	std::shared_ptr<Flock> flockOfDucks;
	std::shared_ptr<Flock> flockOfmallards;
	std::shared_ptr<Quackologist> quackologist;
public:
	DuckSimulator() = delete;
	DuckSimulator(std::unique_ptr<AbstractDuckFactory> duckFactory);
	void simulate();
	void simulate(std::shared_ptr<Quackable> duck);
};