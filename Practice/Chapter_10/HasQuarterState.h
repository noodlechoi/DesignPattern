#pragma once
#include "GumballMachine.h"

class HasQuarterState : public State
{
	std::unique_ptr<GumballMachine> gumballmachine;
public:
	HasQuarterState(std::unique_ptr< GumballMachine> gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};
