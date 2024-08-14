#pragma once
#include "GumballMachine.h"

class NoQuarterState : public State
{
	std::shared_ptr<GumballMachine> gumballmachine;
public:
	NoQuarterState(std::shared_ptr< GumballMachine> gumballmachine);
	void insertQuarter() override;
	void ejectQuarter() override;
	void turnCrank() override;
	void dispense() override;
};

