#pragma once
#include "GumballMachine.h"
class SoldState : public State
{
	std::unique_ptr<GumballMachine> gumballmachine;
public:
	SoldState(std::unique_ptr< GumballMachine> gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};

