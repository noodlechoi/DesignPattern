#pragma once
#include "GumballMachine.h"

class WinnerState : public State
{
	GumballMachine* gumballmachine;
public:
	WinnerState(GumballMachine* gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};

