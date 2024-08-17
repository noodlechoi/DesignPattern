#pragma once
#include "GumballMachine.h"
class SoldOutState : public State
{
	GumballMachine* gumballmachine;
public:
	SoldOutState(GumballMachine* gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};

