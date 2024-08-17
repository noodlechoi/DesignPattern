#pragma once
#include "GumballMachine.h"

class NoQuarterState : public State
{
	GumballMachine* gumballmachine;
public:
	NoQuarterState(GumballMachine* gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};

