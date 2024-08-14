#pragma once
#include "GumballMachine.h"
class SoldOutState : public State
{
	std::unique_ptr<GumballMachine> gumballmachine;
public:
	SoldOutState(std::unique_ptr< GumballMachine> gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};

