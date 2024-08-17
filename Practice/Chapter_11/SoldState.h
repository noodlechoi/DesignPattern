#pragma once
#include "GumballMachine.h"
class SoldState : public State
{
	GumballMachine* gumballmachine;
public:
	SoldState(GumballMachine* gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};

