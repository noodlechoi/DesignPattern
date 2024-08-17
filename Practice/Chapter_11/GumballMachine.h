#pragma once
#include "State.h"
#include <iostream>

class GumballMachine
{
private:
	std::shared_ptr<State> soldOutState;
	std::shared_ptr<State> noQuarterState;
	std::shared_ptr<State> hasQuarterState;
	std::shared_ptr<State> soldState;
	std::shared_ptr<State> winnerState;

	std::shared_ptr<State> state;
	int count{};
public:
	GumballMachine(int count);
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void setState(std::shared_ptr<State> state);
	void releaseBall();

	std::shared_ptr<State> getNoQuarterState();
	std::shared_ptr<State> getHasQuarterState();
	std::shared_ptr<State> getSoldOutState();
	std::shared_ptr<State> getSoldState();
	std::shared_ptr<State> getWinnerState();

	void refill(int count);
	int getCount() const { return count; }
	void printState() const;

	friend std::ostream& operator<<(std::ostream& out, const GumballMachine& machine);
};

