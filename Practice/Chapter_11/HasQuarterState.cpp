#include "HasQuarterState.h"

using namespace std;

HasQuarterState::HasQuarterState(GumballMachine* gumballmachine)
{
	this->gumballmachine = gumballmachine;
	randomWinner = new Random;
}

void HasQuarterState::insertQuarter()
{
	cout << "������ �� ���� �־��ּ���." << endl;
}

void HasQuarterState::ejectQuarter()
{
	cout << "������ ��ȯ�˴ϴ�." << endl;
}

void HasQuarterState::turnCrank()
{
	cout << "�����̸� �����̽��ϴ�." << endl;
	int winner = randomWinner->getInt(0, 11);
	if ((winner == 1) && gumballmachine->getCount() > 1) {
		gumballmachine->setState(gumballmachine->getWinnerState());
	}
	else {
		gumballmachine->setState(gumballmachine->getSoldState());
	}
}

void HasQuarterState::dispense()
{
	cout << "�˸��̸� ������ �� �����ϴ�." << endl;
}
