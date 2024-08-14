#pragma once
#include <iostream>

class GumballMachine
{
private:
	static enum State
	{
		SOLD_OUT,
		NO_QUARTER,
		HAS_QUARTER,
		SOLD,
	};
	int state{ SOLD_OUT };
	int count{};
public:
	GumballMachine(int count);
	void insertQuarter();
	void ejectQuarter();
	void turnCrank();
	void dispense();
	void refill(int count);
	int getCount() const { return count; }
	void printState() const;

	friend std::ostream& operator<<(std::ostream& out, const GumballMachine& machine);
};

