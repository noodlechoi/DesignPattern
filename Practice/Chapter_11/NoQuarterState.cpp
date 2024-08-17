#include "NoQuarterState.h"

using namespace std;

NoQuarterState::NoQuarterState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
}

void NoQuarterState::insertQuarter()
{
	cout << "동전을 넣으셨습니다." << endl;
	gumballmachine->setState(gumballmachine->getHasQuarterState());
}

void NoQuarterState::ejectQuarter()
{
	cout << "동전을 넣어주세요." << endl;
}

void NoQuarterState::turnCrank()
{
	cout << "동전을 넣어주세요." << endl;
}

void NoQuarterState::dispense()
{
	cout << "동전을 넣어주세요." << endl;
}
