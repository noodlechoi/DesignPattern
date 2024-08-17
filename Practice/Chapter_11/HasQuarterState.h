#pragma once
#include "GumballMachine.h"
#include "Random.h"

class HasQuarterState : public State
{
	GumballMachine* gumballmachine;
	Random* randomWinner;
public:
	HasQuarterState(GumballMachine* gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};
