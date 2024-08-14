#pragma once
#include "GumballMachine.h"

class HasQuarterState : public State
{
	GumballMachine* gumballmachine;
public:
	HasQuarterState(GumballMachine* gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};
