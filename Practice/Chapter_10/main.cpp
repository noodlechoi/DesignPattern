#include "GumballMachine.h"

using namespace std;

int main()
{
	std::unique_ptr<GumballMachine> machine = std::make_unique<GumballMachine>(5);
	
	cout << *machine;

	machine->insertQuarter();
	machine->turnCrank();
	cout << "\n";

	cout << *machine;

	machine->insertQuarter();
	machine->ejectQuarter();
	machine->turnCrank();

	cout << "\n";
	cout << *machine;

	machine->insertQuarter();
	machine->turnCrank();
	machine->insertQuarter();
	machine->turnCrank();
	machine->ejectQuarter();

	cout << "\n";
	cout << *machine;

	machine->insertQuarter();
	machine->insertQuarter();
	machine->turnCrank();
	machine->insertQuarter();
	machine->turnCrank();
	machine->insertQuarter();
	machine->turnCrank();

	cout << "\n";
	cout << *machine;
}