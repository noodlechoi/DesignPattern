#include "NoQuarterState.h"

using namespace std;

NoQuarterState::NoQuarterState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
}

void NoQuarterState::insertQuarter()
{
	cout << "������ �����̽��ϴ�." << endl;
	gumballmachine->setState(gumballmachine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
	cout << "������ �־��ּ���." << endl;
}

void NoQuarterState::turnCrank()
{
	cout << "������ �־��ּ���." << endl;
}

void NoQuarterState::dispense()
{
	cout << "������ �־��ּ���." << endl;
}
